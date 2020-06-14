#ifndef PUNTO_2D
#define PUNTO_2D

#include <string>

using namespace std;

class Punto2D {
private:
    int x, y;   // Coordenadas de un punto 2D

public:

    // Constructor sin argumentos
    Punto2D(void);

    // Destructor
    ~Punto2D(void);

    // Constructor con argumentos
    Punto2D (double xPunto, double yPunto);

    // Metodo Set
    void SetCoordenadas (double xPunto, double yPunto);

    // Metodos Get
    double GetX (void) const;
    double GetY (void) const;

    // Operadores == !=
    bool operator == (const Punto2D & otro) const;
    bool operator != (const Punto2D & otro) const;

    // Distancia Euclidea
    double DistanciaEuclidea (const Punto2D & otro) const;

};

#endif