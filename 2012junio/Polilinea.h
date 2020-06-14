#ifndef POLILINEA
#define POLILINEA

#include "Punto2D.h"

using namespace std;

class PoliLinea {
private:
    Punto *p;   // Vector de puntos
    int num;    // Numero de puntos

public:

    // Constructor sin argumentos
    PoliLinea (void);

    // Destructor
    ~PoliLinea (void);

private:

    // Reservar memoria
    void ReservaMemoria(const int num_casillas);

    // Liberar memoria
    void LiberarMemoria(void);
};


#endif