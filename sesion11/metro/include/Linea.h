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
// Fichero: Linea.h
//
/***************************************************************************/

#ifndef LINEA
#define LINEA

//#define DEBUG_LINEA

#include <iostream>
#include <string>

#include "InfoParada.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////

class Linea 
{                                           
private:
    int num_paradas; // Num. paradas de la linea              
    InfoParada * paradas; // paradas[i]: info. de una parada de la linea

public:  
    
	/***********************************************************************/
	// Constructor sin argumentos (crea una Linea vacía), constructor de
	// copia y destructor

	Linea (void);
	Linea (const Linea & otra);    
	~Linea(void);

	/***********************************************************************/
	// Indica si una Linea está vacía.

	bool EstaVacia (void);

	/***********************************************************************/
	// Devuelve el número de paradas de una Linea
	
	int  GetNumParadas (void);

	/***********************************************************************/
	// Operador de asignación (sustituye al método Clona)

	Linea & operator = (const Linea & otra);

	/***********************************************************************/
	// Devuelve una referencia al objeto InfoParada "el_num_parada"
	// (Sustituyen a los métodos GetInfoParada)
 	// PRE: 1 <= el_num_parada <= GetNumParadas()

	InfoParada & operator () (const int el_num_parada);
	InfoParada & operator () (const int el_num_parada) const;
	
	/***********************************************************************/
	// Añade un objeto InfoParada a la Linea
	// (Sustituye al método AniadeInfoParada)

	Linea & operator += (const InfoParada & nueva_parada);

	/***********************************************************************/
	// Operadores relacionales entre objetos Linea
	// Se basan en la función ValorCalidad

	bool operator == (const Linea & otra) const;
	bool operator != (const Linea & otra) const;
	bool operator >  (const Linea & otra) const;
	bool operator >= (const Linea & otra) const;
	bool operator <  (const Linea & otra) const;
	bool operator <= (const Linea & otra) const;
	
	/***********************************************************************/
	// Calcula un valor de calidad para la Linea

	double ValorCalidad (void) const;

	/***********************************************************************/
	// Devuelve true si la parada "indice_parada" está en la Linea

	bool ContieneParada (int indice_parada) const;

	/***********************************************************************/
	// Devuelve true si todas las paradas de la Linea están operativas

	bool EstaTotalmenteOperativa () const;


	/***********************************************************************/
	// Lee de un flujo de entrada (cin) el contenido de una Linea

	void FromText (void);

	/***********************************************************************/
	// Serialización

	string ToString (void) const;

	/***********************************************************************/

private:
	
	/***********************************************************************/
	// Petición / liberación de memoria
	
	void ReservarMemoria (int el_num_paradas);
	void LiberarMemoria (void); 
	
	/***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	
	void CopiarDatos (const Linea & otra);

	/***********************************************************************/
	// Devuelve una referencia al objeto "InfoParada" número "el_num_parada"
	// PRE: 1 <= el_num_parada <= GetNumParadas()

	InfoParada & GetInfoParada (int el_num_parada) const;

	/***********************************************************************/
	                        
};

//////////////////////////////////////////////////////////////////////////
    
#endif
