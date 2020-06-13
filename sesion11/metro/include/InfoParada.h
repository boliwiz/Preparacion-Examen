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
// Fichero: InfoParada.h
//
/***************************************************************************/

#ifndef INFO_PARADA
#define INFO_PARADA

#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////

class  InfoParada 
{
private:

	bool activa; //  ¿Activa?
	int  indice_parada; // parada en RedMetro

public:

	/***********************************************************************/
	// Constructor sin argumentos (crea una Linea vacía) y constructor con 
	// argumentos

	InfoParada (); 
	InfoParada (bool esta_activa, int el_indice_parada);

	/***********************************************************************/
	// Devuelve true si la parada está activa

	bool EstaActiva () const;
	
	/***********************************************************************/
	// Devuelve el número de la parada
	
	int  GetIndice () const;

	/***********************************************************************/
	// Lee de un flujo de entrada (cin) el contenido de una InfoParada

	void FromText (void);	


	/***********************************************************************/
	// Serialización 

	string ToString (void) const;

	/***********************************************************************/

};   

//////////////////////////////////////////////////////////////////////////
    
#endif
