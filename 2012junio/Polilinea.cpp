#include <iostream>

#include "Punto2D.h"
#include "Polilinea.h"

using namespace std;

// Constructor sin argumentos
PoliLinea :: PoliLinea (void){
    p=0;
    num=0;
}

// Destructor
PoliLinea :: ~PoliLinea (void){
    LiberarMemoria();
}


// METODOS PRIVADOS
void PoliLinea :: LiberarMemoria (void){
    if(num){
        delete[] p;
        p = 0;
        num = 0;
    }
}
