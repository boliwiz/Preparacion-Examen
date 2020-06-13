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
// Fichero: InfoParada.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>

#include "InfoParada.h"

using namespace std;

/***********************************************************************/
// Constructor sin argumentos (crea una Linea vacía) 

InfoParada :: InfoParada () 
	: activa (false), indice_parada(0)
{
}

/***********************************************************************/
// Constructor con argumentos

InfoParada :: InfoParada (bool esta_activa, int el_indice_parada) 
	: activa (esta_activa), indice_parada(el_indice_parada)
{
}

/***********************************************************************/
// Devuelve true si la parada está activa

bool InfoParada :: EstaActiva () const
{
	return (activa);
}

/***********************************************************************/
// Devuelve el número de la parada

int InfoParada :: GetIndice () const
{
	return (indice_parada);
}

/***********************************************************************/
// Serrialización

string InfoParada :: ToString (void) const
{
	string cad =  to_string(indice_parada) + "  ";
	cad = cad + (activa ? "S" : "N") + "\n";
	
	return (cad);
}


/***********************************************************************/
// Lee de un flujo de entrada (cin) el contenido de una InfoParada

void InfoParada :: FromText (void)
{
	int el_num_parada;
	char esta_activa_sn;

	cin >> el_num_parada >> esta_activa_sn;

	indice_parada = el_num_parada;
	activa = ((esta_activa_sn == 'S') ? true : false);
}

/***************************************************************************/

