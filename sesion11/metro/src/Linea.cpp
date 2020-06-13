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
// Fichero: Linea.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>

#include "InfoParada.h"
#include "Linea.h"

//#define DEBUG

using namespace std;

/***************************************************************************/
// Calcula si dos datos double son iguales 

const double UMBRAL_IGUALES_LINEA = 1e-6;

bool SonIguales_Linea (double uno, double otro) 
{
	return (fabs(uno-otro)<UMBRAL_IGUALES_LINEA);
}

/***************************************************************************/


/***************************************************************************/
// Constructor sin argumentos (crea una red vacía)

Linea :: Linea (void) : num_paradas (0), paradas (0) { }

/***************************************************************************/
// Constructor de copia

Linea :: Linea (const Linea & otra)
{
	ReservarMemoria (otra.num_paradas);
	CopiarDatos (otra);
}

/***************************************************************************/
// Destructor

Linea :: ~Linea(void)
{
	LiberarMemoria ();
}

/***************************************************************************/
// Indica si una Linea está vacía.

bool Linea :: EstaVacia (void)
{
	return (num_paradas==0);
}

/***************************************************************************/
// Devuelve el número de paradas de una Linea

int Linea :: GetNumParadas (void)
{
	return (num_paradas);
}

/***************************************************************************/
// Devuelve true si la parada "indice_parada" está en la Linea

bool Linea :: ContieneParada (int indice_parada) const
{
	bool sigo = true;
	int  p=0;

	while (p<num_paradas) {

		InfoParada parada = paradas[p];

		if (parada.GetIndice() == indice_parada) sigo = false;
		else p++;
	}

	return (!sigo);
}
/***************************************************************************/
// Devuelve true si todas las paradas de la Linea están operativas

bool Linea :: EstaTotalmenteOperativa () const 
{
	bool sigo = true;
	int p=0;

	while ((sigo) && (p<num_paradas)) {

		InfoParada parada = paradas[p];
			
		if (!(parada.EstaActiva())) sigo = false;
		else p++; 
	}

	return (sigo);
}

/***************************************************************************/
// Operador de asignación (Sustituye al método Clona)

Linea & Linea :: operator = (const Linea & otra)
{		
	if (this != &otra) { // Evitar autoasignación 
		
		LiberarMemoria ();
		ReservarMemoria (otra.num_paradas);
		CopiarDatos (otra);
	}
	return (*this);
}

/***************************************************************************/
// Devuelve una referencia al objeto InfoParada "el_num_parada"
// (Sustituyen a los métodos GetInfoParada)
// PRE: 1 <= el_num_parada <= GetNumParadas()

InfoParada & Linea :: operator () (const int el_num_parada)
{
	return (GetInfoParada (el_num_parada));
}

InfoParada & Linea :: operator () (const int el_num_parada) const
{
	return (GetInfoParada (el_num_parada));
}

/***************************************************************************/
// Añade un objeto InfoParada a la Linea
// (Sustituye al método AniadeInfoParada)

Linea & Linea :: operator += (const InfoParada & nueva_parada)
{
	#ifdef DEBUG_LINEA
	cout << "Aniadiendo parada a linea ..." << endl;
	cout << "--> Actualmente tiene " << num_paradas << " paradas." << endl;
	#endif

	InfoParada * tmp = new InfoParada[num_paradas+1];

	for (int p=0; p<num_paradas; p++) 
		tmp[p] = paradas[p];	// Sin memoria dinámica

	tmp[num_paradas] = nueva_parada;  // Sin memoria dinámica


	delete [] paradas;

	paradas = tmp;
	num_paradas++;

	#ifdef DEBUG_LINEA
	cout << "Parada aniadida a la linea" << endl;
	cout << "--> Actualmente tiene " << num_paradas << " paradas." << endl;
	#endif

	return (*this);
}


/***********************************************************************/
// Operadores relacionales entre objetos Linea
// Se basan en la función ValorCalidad

bool Linea :: operator == (const Linea & otra) const
{
	return (SonIguales_Linea(ValorCalidad(), otra.ValorCalidad()));
}

bool Linea :: operator != (const Linea & otra) const
{
	return (!(*this == otra));
}

bool Linea :: operator >  (const Linea & otra) const
{
	return (ValorCalidad() > otra.ValorCalidad());
}

bool Linea :: operator >= (const Linea & otra) const
{
	return (!(*this < otra));
}

bool Linea :: operator <  (const Linea & otra) const
{
	return (ValorCalidad() < otra.ValorCalidad());
}

bool Linea :: operator <= (const Linea & otra) const
{
	return (!(*this > otra));
}


/***********************************************************************/
// Calcula un valor de calidad para la Linea

double Linea :: ValorCalidad (void) const
{
	// Contar paradas no activas de la linea
	int cont_paradas_no_activas = 0;		

	for (int p=1; p<=num_paradas; p++) {		
	
		InfoParada ip = GetInfoParada(p);

		if (!ip.EstaActiva())   // Operator () de "Linea"
			cont_paradas_no_activas++; 
	}

	// Calcular valor de calidad	
	int cont_paradas_activas = num_paradas-cont_paradas_no_activas; 
	double valor = 0.8*cont_paradas_activas + 0.2*num_paradas;
	
	return (valor);
}

/***************************************************************************/
// Serialización

string Linea :: ToString (void) const 
{
	string cad = to_string(num_paradas) + "\n";

	for (int p=1; p<=num_paradas; p++) {		
	
		InfoParada ip = GetInfoParada(p);

		cad = cad + ip.ToString();
	}

	return cad; 
}

/***************************************************************************/
// Lee de un flujo de entrada (cin) el contenido de una Linea

void Linea :: FromText (void)  
{	
	int el_num_paradas; 
	cin >> el_num_paradas; 

	#ifdef DEBUG_LINEA
	cout << endl;
	cout << "Paradas de la linea = " << el_num_paradas  << endl;
	cout << endl;
	#endif

	for (int p=1; p<=el_num_paradas; p++) {

		#ifdef DEBUG_LINEA
		cout << endl;
		cout << "--> leyendo parada " << p << endl;
		cout << endl;
		#endif

		InfoParada parada_nueva;
		parada_nueva.FromText();

		#ifdef DEBUG_LINEA
		cout << "Parada " << p << "--> ";
		parada_nueva.ToText();
		#endif

		(*this) += parada_nueva;

	} // parada

}


/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

void Linea :: ReservarMemoria (int el_num_paradas)
{
	paradas = new InfoParada[el_num_paradas];
}

/***************************************************************************/

void Linea :: LiberarMemoria ()
{
	if (paradas) 
		delete [] paradas; 

	paradas = 0;
	num_paradas = 0;
}

/***************************************************************************/

void Linea :: CopiarDatos (const Linea & otra)
{
	num_paradas = otra.num_paradas;
	
	for (int p=0; p<num_paradas; p++) 
		paradas[p] = otra.paradas[p];   // Sin memoria dinámica
}

/***************************************************************************/
// Devuelve una referencia al objeto "InfoParada" número "el_num_parada"
// PRE: 1 <= el_num_parada <= GetNumParadas()

InfoParada & Linea :: GetInfoParada (const int el_num_parada) const
{
	return (paradas[el_num_parada-1]);
}

/***************************************************************************/
/***************************************************************************/

