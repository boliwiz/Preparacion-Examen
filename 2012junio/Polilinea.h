#ifndef POLILINEA
#define POLILINEA

#include "Punto2D.h"

using namespace std;

class PoliLinea {
private:
    Punto2D *p;   // Vector de puntos
    int num;    // Numero de puntos

public:

    // Constructor sin argumentos
    PoliLinea (void);

    // Destructor
    ~PoliLinea (void);

    // Constructor Copia
    PoliLinea (const PoliLinea & otro);
    
    // Constructor a partir de Punto2D
    PoliLinea (const Punto2D & nuevo_punto);


    // Operador asignacion =
    PoliLinea & operator = (const PoliLinea & orig);

    // Operador asignacion =
    Punto2D & operator [] (const int indice);
    Punto2D & operator [] (const int indice) const;

    // Operador binario +
    friend PoliLinea operator + (const PoliLinea & p1, const PoliLinea & p2);
    friend PoliLinea operator + (const PoliLinea & poli, const Punto2D & punto);
    friend PoliLinea operator + (const Punto2D & punto, const PoliLinea & poli);

    // Operator +=
    PoliLinea & operator += (const Punto2D & nuevo_punto);

    // Flujo de entrada (cin) a PoliLinea
    void FromText (void);

    // PoliLinea a flujo de salida (cout)
    void ToText (void) const;

    // Serializar PoliLinea
    string ToString (void) const;

private:

    // Reservar memoria
    void ReservaMemoria(const int num_casillas);

    // Liberar memoria
    void LiberarMemoria(void);

    // Copiar datos de otro objeto de la clase
    void CopiarDatos (const PoliLinea & orig);

    // Devuelve referencia a un Punto2D de la PoliLinea
    Punto2D & el_valor (int indice) const;

    // Calcula si 2 PoliLineas son igules
    bool EsIgualA(const PoliLinea & otra);

    // Aniade Punto2D a PoliLinea
    void Aniade (const Punto2D & nuevo_punto);
};


#endif