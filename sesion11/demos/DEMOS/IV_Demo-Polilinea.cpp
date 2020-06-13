/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Punto2D.h"
#include "Polilinea.h"

using namespace std;


/***************************************************************************/
// Muestra el contenido de un colección de puntos 

void MuestraPoliLinea (const char * msg, const PoliLinea & p);

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	/***********************************************************************/
	// Constructor sin argumentos y operador de asignación 

	PoliLinea vacia;

	MuestraPoliLinea ("Polilinea vacia", vacia);


	PoliLinea clonada; // vacía

	clonada = vacia;
	MuestraPoliLinea ("Polilinea tras clonada = vacia", clonada);


	/***********************************************************************/
	// Constructor con un dato Punto2D

	PoliLinea poli_con_un_punto (Punto2D(0.0, 0.0));
	MuestraPoliLinea ("poli_con_un_punto", poli_con_un_punto);


	/***********************************************************************/
	// Crear una PoliLinea desde cin

	PoliLinea la_polilinea;

	la_polilinea.FromText(); 
	
	MuestraPoliLinea ("Polilinea leida - la_polilinea", la_polilinea);


	/***********************************************************************/
	// Constructor de copia

	PoliLinea copia (la_polilinea);

	MuestraPoliLinea ("copia, tras PoliLinea copia (la_polilinea)", copia);

	PoliLinea otra (la_polilinea);
	MuestraPoliLinea ("otra, tras PoliLinea otra (la_polilinea)", otra);
 

	/***********************************************************************/
	// Concatenar dos datos PoliLinea con operador binario + 

	PoliLinea larga (la_polilinea + la_polilinea);
	
	MuestraPoliLinea ("larga, tras la_polilinea + la_polilinea", larga);
 

	/***********************************************************************/
	// Adicion de puntos con operador binario + 

	otra = otra + Punto2D (0.0, 0.0); // Añade al final
	
	MuestraPoliLinea ("otra, tras otra = otra + Punto2D (0.0, 0.0)", otra);

	otra = Punto2D (0.0, 0.0) + otra; // Inserta al principio 
	
	MuestraPoliLinea ("otra, tras otra = Punto2D (0.0, 0.0) + otra ", otra);
	

	/***********************************************************************/
	// Comparaciones

	if (la_polilinea == copia)
		cout << "la_polilinea y copia son iguales" << endl; 	
	else 
		cout << "la_polilinea y copia no son iguales" << endl; 	

	if (la_polilinea != copia)
		cout << "la_polilinea y copia son distintas" << endl; 	
	else 
		cout << "la_polilinea y copia no son distintas" << endl; 	
	cout << endl;

	if (la_polilinea == otra)
		cout << "la_polilinea y otra son iguales" << endl; 	
	else 
		cout << "la_polilinea y otra no son iguales" << endl; 	

	if (la_polilinea != otra)
		cout << "la_polilinea y otra son distintas" << endl; 	
	else 
		cout << "la_polilinea y otra no son distintas" << endl; 	
	cout << endl;


	/***********************************************************************/
	// Se va a invertir "la_polilinea" en  "la_polilinea_invertida1" y en 
	// "la_polilinea_invertida2"

	cout << "Se va a invertir la_polilinea en una nueva polilinea." << endl; 
	MuestraPoliLinea ("la_polilinea", la_polilinea);


	PoliLinea la_polilinea_invertida1; // Inicialmente vacía

	// Se toman los puntos de "la_polilinea" uno a uno, empezando por el 
	// último y terminando en el primero. Cada uno de ellos se añade a la 
	// PoliLinea "la_polilinea_invertida1"

	for (int n=la_polilinea.NumPuntos(); n>=1; n--) {

		// Acceso con operator [] respetando las precondiciones  
		la_polilinea_invertida1 = la_polilinea_invertida1 + la_polilinea[n]; 
	}

	MuestraPoliLinea ("la_polilinea_invertida1", la_polilinea_invertida1);


	// Comprobar si son iguales "la_polilinea" y "la_polilinea_invertida1"

	if (la_polilinea == la_polilinea_invertida1)
		cout<< "la_polilinea y la_polilinea_invertida1 son iguales" << endl; 	
	else 
		cout<< "la_polilinea y la_polilinea_invertida1 no son iguales" << endl; 	

	if (la_polilinea != la_polilinea_invertida1)
		cout<< "la_polilinea y la_polilinea_invertida1 son distintas" << endl; 	
	else 
		cout<< "la_polilinea y la_polilinea_invertida1 no son distintas"<< endl; 	
	cout << endl;


	// La adición de puntos se hace con el operador += 

	cout << "Se va a invertir la_polilinea en otra nueva polilinea." << endl; 

	PoliLinea la_polilinea_invertida2; // Inicialmente vacía

	// Se toman los puntos de "la_polilinea" uno a uno, empezando por el 
	// último y terminando en el primero. Cada uno de ellos se añade a la 
	// PoliLinea "la_polilinea_invertida2"

	for (int n=la_polilinea.NumPuntos(); n>=1; n--) {

		// Acceso con operator [] respetando las precondiciones  
		la_polilinea_invertida2 += la_polilinea[n]; 
	}

	MuestraPoliLinea ("la_polilinea_invertida2", la_polilinea_invertida1);


	// Comprobar si son iguales "la_polilinea_invertida1" 
	// y "la_polilinea_invertida2"

	if (la_polilinea_invertida1 == la_polilinea_invertida2)
		cout<< "OK: Las dos polilineas invertidas son iguales"; 
	else 
		cout<< "PROBLEMA: Las polilineas invertidas son diferentes"; 
	cout << endl << endl; 


	/***********************************************************************/
	// Vaciar una PoliLinea

	cout << endl; 

	cout << "Antes de eliminar todo de otra: ";
	if (otra.EstaVacia()) 
		cout << "Esta vacia" << endl;
	else
		cout << "No esta vacia" << endl;

	MuestraPoliLinea ("otra, antes de otra.EliminaTodos()", otra);

	otra.EliminaTodos();

	cout << "Despues de eliminar todo de otra: ";
	if (otra.EstaVacia()) 
		cout << "Esta vacia" << endl;
	else
		cout << "No esta vacia" << endl;
	
	MuestraPoliLinea ("otra, tras otra.EliminaTodos()", otra);

	cout << endl; 

	/***********************************************************************/

	return 0;
}


/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de una Polilinea 

void MuestraPoliLinea (const char * msg, const PoliLinea & poli)
{
	cout << endl;
	cout << "----------------------------------------" << endl;

	cout << msg << endl;
	cout << endl;

	int num_datos = poli.NumPuntos();

	cout << "Num.datos = " << setw(3) << num_datos << endl; 

	if (num_datos > 0) {

		for (int i=1; i<=num_datos; i++) {

			Punto2D punto_i = poli[i]; // operator []
			cout << "   " << punto_i.ToString() << endl;
		}

		cout << endl; 
	}

	cout << "----------------------------------------" << endl;
	cout << endl;
}

/***************************************************************************/
/***************************************************************************/
