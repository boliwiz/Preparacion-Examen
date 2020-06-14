#include <iostream>
#include <cmath>

#include "Punto2D.h"

using namespace std;

// 2 numeros reales son iguales si su diferencia es menor que 
const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

// Constructor sin argumentos
Punto2D :: Punto2D (void) {}

// Destructor
Punto2D :: ~Punto2D (void) {}

// Constructor con argumentos
Punto2D :: Punto2D (double xPunto, double yPunto){
    SetCoordenadas (xPunto, yPunto);
}

// Metodo set
void Punto2D :: SetCoordenadas (double xPunto, double yPunto){
    x = xPunto;
    y = yPunto;
}

// Metodos Get
double Punto2D :: GetX (void) const{
    return (x);
}
double Punto2D :: GetY (void) const{
    return (y);
}

// Operadores == !=
bool Punto2D :: operator== (const Punto2D & otro) const{
    return (SonIguales(x, otro.x) && SonIguales(y, otro.y));
}
bool Punto2D :: operator!= (const Punto2D & otro) const{
    return (!(*this == otro));
}

// Distancia Euclidea
double Punto2D :: DistanciaEuclidea (const Punto2D & otro) const{
    double difx = pow (x - otro.x, 2);
    double dify = pow (y - otro.y, 2);
    return (sqrt(difx + dify));
}



// Funciones ajenas a la clase

bool SonIguales(double uno, double otro){
    return(fabs(uno-otro) <= PRECISION_SON_IGUALES);
}