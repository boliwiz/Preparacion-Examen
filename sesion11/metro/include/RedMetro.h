/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
//
// Examen ordinario 2017/2018 (2)
//
// Fichero: RedMetro.h
//
/***************************************************************************/

#ifndef RED_METRO
#define RED_METRO

//#define DEBUG_RED_METRO

#include <iostream>
#include <string>

#include "InfoParada.h"
#include "Linea.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////

class RedMetro 
{                   
    
private:                  

    int num_lineas;   // Número de lineas de la red  
    Linea * lineas;   // linea[i]: info. linea                        

public:                        

	/***********************************************************************/
	// Constructor sin argumentos (crea una red vacía), constructor de
	// copia y destructor

	RedMetro (void); 
	RedMetro (const RedMetro & otra); 
	~RedMetro(void);

	/***********************************************************************/
	// Indica si una red está vacía.

	bool EstaVacia (void);

	/***********************************************************************/
	// Devuelve el número de líneas,
	
	int GetNumLineas (void)  const;
	
	// Devuelve el número total de paradas
	
	int GetNumTotalParadas (void) const;

	/***********************************************************************/
	// Operador de asignación (sustituye al método Clona)

	RedMetro & operator = (const RedMetro & otra);

	/***********************************************************************/
	// Devuelve una referencia al objeto Linea cuyo número es "el_num_linea"
	// (Sustituyen a los métodos GetLinea)
 	// PRE: 1 <= el_num_linea <= GetNumLineas()

	Linea & operator () (int el_num_linea);
	Linea & operator () (int el_num_linea) const;	

	/***********************************************************************/
	// Añade una Linea a la red
	// (Sustituye al método AniadeLinea)

	RedMetro & operator += (const Linea & nueva_linea);

	/***********************************************************************/
	// Operadores relacionales entre objetos RedMetro
	// Se basan en la función ValorCalidad

	bool operator == (const RedMetro & otra) const;
	bool operator != (const RedMetro & otra) const;
	bool operator >  (const RedMetro & otra) const;
	bool operator >= (const RedMetro & otra) const;
	bool operator <  (const RedMetro & otra) const;
	bool operator <= (const RedMetro & otra) const;

	/***********************************************************************/
	// Lee de un flujo de entrada (cin) el contenido de una red.
	
	void FromText (void);

	/***********************************************************************/
	// Serialización

	string ToString (void) const;

	/***********************************************************************/
	// Permita obtener la parada (su índice) en la que confluyen el mayor 
	// número de líneas, independientemente de si están activas o no.

	int MejorConectada (void) const;	

	/***********************************************************************/
	// Calcula un valor de calidad para la RedMetro

	double ValorCalidad (void) const;

	/***********************************************************************/

private:
	
	/***********************************************************************/
	// Petición / liberación de memoria
	void ReservarMemoria (int el_num_lineas);
	void LiberarMemoria (void); 

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	void CopiarDatos (const RedMetro & otro);

	/***********************************************************************/
	// Devuelve una referencia al objeto "Linea" número "num_linea"
	// PRE: 1 <= num_linea <= GetNumLineas()

	Linea & GetLinea (int num_linea) const;
	
	/***********************************************************************/

};
   
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

void MuestraRed (const char * mensaje, RedMetro & red); 

/***************************************************************************/

#endif
