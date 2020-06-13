/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Examen ordinario 2017/2018 (1)
//
// Fichero: III_Demo-Metropolitano.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "InfoParada.h"
#include "Linea.h"
#include "RedMetro.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	RedMetro red1; // La red está inicialmente vacía

	red1.FromText(); // Se lee la red de cin


	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;

	MuestraRed ("Red: red1", red1);

	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;


	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;

	cout << "Informacion sobre la operatividad de la red" << endl;
	cout << endl;


	for (int l=1; l<=red1.GetNumLineas(); l++) {

		cout << "\tLinea " << setw(3) << l << ": ";

		//Linea linea_l = red1.GetLinea (l); 
		Linea linea_l = red1(l); 

		cout << "Puntuacion =  " << setw(6) << setprecision(2) 
		     << linea_l.ValorCalidad() << ". ";	

 		if (linea_l.EstaTotalmenteOperativa()) 
			cout << "Totalmente operativa." << endl; 
		else 
			cout << "Tiene paradas no operativas." << endl; 

	} // for l


	Linea mejor_linea = red1(1); 
	int indice_mejor_linea; 

	for (int l=2; l<=red1.GetNumLineas(); l++) {

		//Linea linea_l = red1.GetLinea (l); 
		Linea linea_l = red1(l); 
 
		if (linea_l > mejor_linea) {
			mejor_linea = linea_l; 
			indice_mejor_linea = l; 
		}

	}// for l
	
	cout << endl;
	cout << "La mejor linea es : " << indice_mejor_linea << endl; 

	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;


	cout << "Parada mejor conectada de la red" << endl;
	cout << endl;

	cout << "\tEl indice de la parada mejor conectada es: " 
         << red1.MejorConectada() << endl;

	cout << endl;
	cout << "-------------------------------" << endl;


	return (0);
}

/***************************************************************************/
/***************************************************************************/
