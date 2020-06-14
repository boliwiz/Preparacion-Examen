#include <iostream>
#include <cstring>

#include "Punto2D.h"
#include "Polilinea.h"

using namespace std;

// Constructor sin argumentos
PoliLinea :: PoliLinea (void) : p(0), num (0) {}

// Destructor
PoliLinea :: ~PoliLinea (void){
    LiberarMemoria();
}

// Constructor Copia
PoliLinea :: PoliLinea(const PoliLinea & orig){
    ReservaMemoria(orig.num);
    CopiarDatos(orig);
}

// Constructor a partir de Punto2D
PoliLinea :: PoliLinea(const Punto2D & nuevo_punto): p(0), num (0) {
    Aniade(nuevo_punto);
}


// Operador asignacion =
PoliLinea & PoliLinea :: operator= (const PoliLinea & orig){
    if (this != &orig){
        LiberarMemoria();
        ReservaMemoria(orig.num);
        CopiarDatos(orig);
    }
    return (*this);
}

// Operador acceso []
Punto2D & PoliLinea :: operator[] (const int indice){
    return el_valor(indice);
}
Punto2D & PoliLinea :: operator[] (const int indice) const{
    return el_valor(indice);
}

// Operador binario +   (PoliLinea + PoliLinea)
PoliLinea operator + (const PoliLinea & p1, const PoliLinea & p2) {
    PoliLinea nueva (p1);
    for (int i=0; i<num; i++){
        nueva.Aniade (p2.p[i]);
    }
    return (nueva);
}
// Operador binario +   (PoliLinea + Punto2D)
PoliLinea operator+ (const PoliLinea & poli, const Punto2D & punto){
    PoliLinea nueva (punto);
    return (poli + nueva);
}
// Operador binario +   (Punto2D + PoliLinea)
PoliLinea operator+ (const Punto2D & punto, const PoliLinea & poli){
    PoliLinea nueva (punto);
    return (nueva + poli);
}

// Operator +=
PoliLinea & PoliLinea :: operator += (const Punto2D & nuevo_punto){
    this->Aniade (nuevo_punto);
    return (*this);
}

// Flujo de entrada (cin) a PoliLinea
void PoliLinea :: FromText (void){
    LiberarMemoria();

    int num_puntos;
    cin >> num_puntos;

    double puntox, puntoy;

    for (int cont_p = 0; cont_p<num_puntos; cont_p++){
        cin >> puntox;
        cin >> puntoy;

        Punto2D un_punto (puntox, puntoy);
        Aniade (un_punto);
    }
}

// PoliLinea a flujo de salida (cout)
void PoliLinea :: ToText (void) const{
    cout << ToString();
}

// Serializar PoliLinea
string PoliLinea :: ToString (void) const{
    string cad = to_string(num) + "\n";
    for (int i=0; i<num; i++){
        cad = cad + p[i].ToString() + "\n";
    }
    return (cad);
}


//--------- METODOS PRIVADOS ---------------------------------------------
void PoliLinea :: LiberarMemoria (void){
    if(num){
        delete[] p;
        p = 0;
        num = 0;
    }
}

void PoliLinea :: ReservaMemoria (const int num_casillas){
    num = num_casillas;
    if (num){
        p = new Punto2D [num];
    }
}

void PoliLinea :: CopiarDatos (const PoliLinea & orig){
    num = orig.num;
    // usamos memcpy
    memcpy(p, orig.p, num*sizeof(Punto2D));     
}

// Devuelve referencia a un Punto2D de la PoliLinea
Punto2D & PoliLinea :: el_valor (int indice) const{
    return (p [indice-1]);
}

// Calcula si 2 PoliLineas son igules
bool PoliLinea :: EsIgualA(const PoliLinea & otra){
    bool iguales = (num == otra.num);
    if(iguales){

        bool iguales1 = true;
        int pos = 0;
        while ((pos != num) && (iguales1)){
            if(p[pos] != otra.p[pos])
                iguales1 = false;
            else 
                pos++;
        }
        if(!iguales1){
            bool iguales2 = true;
            int pos = 0;
            int pos_otra = otra.num-1;
            while((pos !=num) && (iguales2)){
                if (p[pos] != otra.p[pos_otra])
                    iguales2 = false;
                else{
                    pos++;
                    pos_otra--;
                }
                
            }
            iguales = iguales2;
        }
        else iguales = true;
    }
    return (iguales);
}


// Aniade Punto2D a PoliLinea
void PoliLinea :: Aniade (const Punto2D & nuevo_punto){
    Punto2D * tmp = new Punto2D[num+1];
    memcpy(tmp, p, num*sizeof(Punto2D));
    delete [] p;

    p = tmp;
    p [num] = nuevo_punto;
    num++;
}
