/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
//
// Demostración de la funcionalidad de la clase Secuencia
//
// Fichero: III_Demo-Secuencia.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Secuencia.h"
#include "Secuencia.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

void MuestraInfoComparativa (const Secuencia & s1, const Secuencia & s2);

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	
	// Constructor con un argumento
	Secuencia almacen (3);
		 
	cout << "almacen: " << endl;
	cout << almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;

	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl;
	cout << endl;
	

	// ******************************************************************

	TipoBaseSecuencia valor;

	cout << "Introducir un valor (para finalizar, un negativo): ";
	cin >> valor;

	while (valor >= 0) {

		almacen = almacen + valor; // Antes: almacen.Aniade (valor); 

		cout << "--> CAPACIDAD: " << almacen.Capacidad() << endl;
		cout << "--> OCUPADOS = " << almacen.TotalUtilizados() << endl;

		cout << "Introducir un valor (para finalizar, un negativo): ";
		cin >> valor;
	}

	cout << endl;
	cout << "almacen: " << endl;
	cout << almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;


	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl; 
	cout << endl;

	
	// ******************************************************************
	// Prueba de constructor de copia
	
	Secuencia copia_almacen (almacen);

	cout << "copia_almacen: " << endl;
	cout << copia_almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;
		
	if (copia_almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl;
	cout << endl;	
	

	// ******************************************************************
	// Prueba del operador de asignacion
	
	Secuencia nuevo;	// Constructor sin argumentos

	cout << "Se acaba de crear nuevo (Secuencia nuevo): " << endl;
	cout << nuevo.ToString () << endl;
	cout << "CAPACIDAD: " << nuevo.Capacidad() << endl;
	cout << "OCUPADOS = " << nuevo.TotalUtilizados() << endl;
	cout << endl;

	if (nuevo.EstaVacia()) 
		cout << "nuevo SI esta vacio. " << endl;
	else 
		cout << "nuevo NO esta vacio." << endl;
	cout << endl;


 	// Asignación desde Secuencia
	
	nuevo = almacen; // "nuevo" y "almacen" ya existen 

	cout << "nuevo tras nuevo = almacen" << endl;
	cout << nuevo.ToString () << endl;
	cout << "CAPACIDAD: " << nuevo.Capacidad() << endl;
	cout << "OCUPADOS = " << nuevo.TotalUtilizados() << endl;
	cout << endl;

	if (nuevo.EstaVacia()) 
		cout << "nuevo SI esta vacio. " << endl;
	else 
		cout << "nuevo NO esta vacio." << endl;
	cout << endl;


	// Constructor de copia

	Secuencia copia_nuevo (nuevo);

 	cout << endl; 
	cout << "Creado copia_nuevo (nuevo)" << endl;
	cout << copia_nuevo.ToString();
 	cout << endl; 


	// Asignación desde TipoBaseSecuencia

	copia_nuevo = ((TipoBaseSecuencia) 9);	
	
 	cout << endl; 	
	cout << "copia_nuevo tras copia_nuevo = 9" << endl;
	cout << copia_nuevo.ToString () << endl;
	cout << "CAPACIDAD: " << copia_nuevo.Capacidad() << endl;
	cout << "OCUPADOS = " << copia_nuevo.TotalUtilizados() << endl;
	cout << endl;

	if (copia_nuevo.EstaVacia()) 
		cout << "copia_nuevo SI esta vacio. " << endl;
	else 
		cout << "copia_nuevo NO esta vacio." << endl;
	cout << endl;

 	cout << endl; 


	// ******************************************************************
	// Pruebas del operador de acceso []
	

	cout << "nuevo" << endl;
	cout << nuevo.ToString () << endl;

	if (!nuevo.EstaVacia()) {
		cout << "Primero = " << nuevo[1] << endl;
		cout << "Ultimo  = " << nuevo[nuevo.TotalUtilizados()] << endl;
		cout << endl;
			
		cout << "Intercambiando primero y ultimo." << endl;
		
		TipoBaseSecuencia tmp = nuevo[1];
		nuevo[1] = nuevo[nuevo.TotalUtilizados()]; // Acceso lvalue
		nuevo[nuevo.TotalUtilizados()] = tmp;      // Acceso lvalue
			
		cout << "nuevo despues de intercambiar extremos" << endl;
		cout << nuevo.ToString();
	 	cout << endl; 
	}
					
 	cout << endl; 
		
							

	cout << "almacen" << endl;
	cout << almacen.ToString () << endl;
 	cout << endl; 

	
	// Operador []

	Secuencia otro_almacen (3); // Secuencia de 3 casillas

	cout << "Creado otro_almacen (3)" << endl;
	cout << otro_almacen.ToString();
 	cout << endl; 

	if (otro_almacen.EstaVacia()) 
		cout << "otro_almacen SI esta vacio. " << endl;
	else 
		cout << "otro_almacen NO esta vacio." << endl;
	cout << endl;


	for (int pos = almacen.TotalUtilizados(); pos>0; pos--)	

		otro_almacen = otro_almacen + almacen[pos];	
		// Antes: otro_almacen.Aniade (almacen[pos]); // Operator []


	cout << "otro_almacen tiene los datos de almacen (invertidos)" << endl;
	cout << otro_almacen.ToString();
 	cout << endl; 
						
	// ******************************************************************
	// Pruebas de los operadores aritméticos y combinados 	

 	cout << endl; 
	cout << "..................................................." << endl; 	
 	cout << "Pruebas de los operadores arirtmeticos y combinados" << endl; 
 	cout << endl; 
					
	nuevo =  almacen + 88 + otro_almacen + 99;
	
	cout << "nuevo =  almacen + 88 + otro_almacen + 99" << endl;	
	cout << nuevo.ToString();
 	cout << endl << endl; 


	// Pruebas de los operadores combinados += y -=  

 	cout << endl; 
	cout << "Se va aniadir 55 y 66 a nuevo" << endl;	

	nuevo += 55;
	nuevo += 66;
					
	cout << "nuevo tras += 55 y +=66" << endl;
	cout << nuevo.ToString();
	cout << endl; 
	cout << "Num. elementos de nuevo = " <<nuevo.TotalUtilizados() << endl; 
	cout << endl; 

 	cout << endl; 
	cout << "Se va eliminar 88 y 77 de nuevo" << endl;		

	nuevo -= 88;
	nuevo -= 77; 

	cout << "nuevo tras -= 88 y -=77" << endl;	
	cout << nuevo.ToString();
	cout << endl; 
	cout << "Num. elementos de nuevo = " <<nuevo.TotalUtilizados() << endl; 
	cout << endl; 


	// Pruebas del operador binario -	
	
	cout << endl; 
	cout << "almacen" << endl;
	cout << almacen.ToString();
 	cout << endl; 
	cout << "Num. elementos de almacen = " <<almacen.TotalUtilizados() << endl; 
	cout << endl; 

	cout << endl; 
	cout << "Eliminar de nuevo todas las copias de almacen" << endl;

	Secuencia nuevo_menos_almacen = nuevo - almacen;
	
	cout << endl; 
	cout << "nuevo_menos_almacen" << endl;	
	cout << nuevo_menos_almacen.ToString();
	cout << endl; 	
	cout << "Num. elementos despues del primer borrado = " 
	     << nuevo_menos_almacen.TotalUtilizados() << endl; 
 	cout << endl; 
	
	int tam_anterior, tam_actual;
		
	do {
 		tam_anterior= nuevo_menos_almacen.TotalUtilizados();
					
		nuevo_menos_almacen = nuevo_menos_almacen - almacen;
	
		cout << "nuevo_menos_almacen" << endl;	
		cout << nuevo_menos_almacen.ToString();
		cout << endl; 
	
		tam_actual = nuevo_menos_almacen.TotalUtilizados(); 
		
	} while (tam_anterior != tam_actual); 


	cout << endl; 
	cout << "Finalmente, nuevo_menos_almacen" << endl;	
	cout << nuevo_menos_almacen.ToString();
	cout << endl; 
	
	
	otro_almacen = nuevo_menos_almacen - 55;
	otro_almacen = otro_almacen - 22;	
	
	cout << "otro_almacen = nuevo_menos_almacen - 55 y -22" << endl;	
	cout << otro_almacen.ToString();
	cout << endl; 


	// ******************************************************************
	// ******************************************************************

 	cout << endl; 
	cout << "......................................" << endl; 	
 	cout << "Pruebas de los operadores relacionales" << endl; 
 	cout << endl; 

	// Pruebas de los operadores relacionales  		
	
	Secuencia sec1(5);
	sec1 += 1;
	sec1 += 3;
	sec1 += 5;
	sec1 += 7;

	Secuencia sec2(5);
	sec2 += 1;
	sec2 += 3;
	sec2 += 5;
	sec2 += 7;

	// sec1 = 1, 3, 5, 7
	// sec2 = 1, 3, 5, 7
	MuestraInfoComparativa (sec1, sec2);

	sec1 -= 7;
	// sec1 = 1, 3, 5
	// sec2 = 1, 3, 5, 7
	MuestraInfoComparativa (sec1, sec2);
	
	sec2 -= 5;
	sec2 -= 7;
	// sec1 = 1, 3, 5
	// sec2 = 1, 3
	MuestraInfoComparativa (sec1, sec2);

	sec1 += 7;	
	sec2 += 6;
	sec2 += 8;
	sec2 += 9;
	// sec1 = 1, 3, 5, 7
	// sec2 = 1, 3, 6, 8, 9
	MuestraInfoComparativa (sec1, sec2);

	sec2[2] = 4;
	// sec1 = 1, 3, 5, 7
	// sec2 = 1, 3, 4, 8, 9
	MuestraInfoComparativa (sec1, sec2);

	return 0;
}


/***********************************************************************/
/***********************************************************************/

void MuestraInfoComparativa (const Secuencia & sec1, const Secuencia & sec2)
{
	cout << endl;
	cout << "sec1" << endl;	
	cout << sec1.ToString();
	cout << endl;

	cout << "sec2" << endl;	
	cout << sec2.ToString();
	cout << endl;

	if (sec1 == sec2)
		cout << "sec1 == sec2" << endl;
	else 
		cout << "sec1 NO == sec2" << endl;
	if (sec1 != sec2)
		cout << "sec1 != sec2" << endl;
	else 
		cout << "sec1 NO != sec2" << endl;
	if (sec1 > sec2)
		cout << "sec1 > sec2" << endl;
	else 
		cout << "sec1 NO > sec2" << endl;
	if (sec1 < sec2)
		cout << "sec1 < sec2" << endl;
	else 
		cout << "sec1 NO < sec2" << endl;
	if (sec1 >= sec2)
		cout << "sec1 >= sec2" << endl;
	else 
		cout << "sec1 NO >= sec2" << endl;
	if (sec1 <= sec2)
		cout << "sec1 <= sec2" << endl;
	else 
		cout << "sec1 NO <= sec2" << endl;
	cout << endl; 
}

/***********************************************************************/
/***********************************************************************/
