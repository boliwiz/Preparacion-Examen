/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
//
// Demostración de la funcionalidad de la clase Lista (2).
//
// Incluye: 
//		* constructor de copia
//		* destructor
//		* Operador =
// 		* Operadores de acceso
//		* Operadores varios
//
// Fichero: Demo-Lista.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	Lista lista(5);

	cout << lista.ToString("Despues de crear la lista con tamanio 5");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << "Tercer elemento = " << lista(3) << endl;
	cout << endl;

	// Operador de asignacion desde TipoBaseLista

	lista = (TipoBaseLista) 1;
	cout << lista.ToString("Despues de lista=1");
	cout << endl;

	// Inserta

	lista.Inserta(7,2);
	cout << lista.ToString("Despues de lista.Inserta(7,2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;	
	cout << endl;

	lista.Inserta(9,lista.Tamanio()+1);
	cout << lista.ToString("Despues de lista.Inserta(9, lista.Tamanio()+1)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	
	lista.Inserta(6,3);
	cout << lista.ToString("Despues de lista.Inserta(6,3)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;


	// Acceso con []

	for (int pos=1; pos<=lista.Tamanio(); pos++)
		cout << "Elemento " << setw(2) << pos 
		     << " = " << setw (3) << lista[pos] << endl;
	cout << endl;

	cout << endl; 
	cout << "Buscando el 7 ..." << endl;


	// Buscar

	int pos_7 = lista.Buscar (7);
	
	if (pos_7 != -1) 
		cout << "Encontrado en la posicion " << pos_7;
	else 
		cout << "No se encontró.";
	cout << endl; 

	cout << endl; 
	cout << "Buscando el 22 ..." << endl;

	int pos_22 = lista.Buscar (22);
	
	if (pos_22 != -1) 
		cout << "Encontrado en la posicion " << pos_22 << endl;
	else 
		cout << "No se ha encontrado." << endl;
	cout << endl; 

	// Elimina 

	lista.Elimina(2);

	cout << lista.ToString("Despues de Elimina(2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;

	lista.Elimina(6);

	cout << lista.ToString("Despues de Elimina(6)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	
	lista.Elimina(2);

	cout << lista.ToString("Despues de Elimina(2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	

	// Aniade

	lista += 3;
	cout << lista.ToString("Despues de Aniade(3)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl << endl;

	// Acceso lvalue
	lista(1) = 99;
	lista[4] = 22;

	cout << lista.ToString("Despues de cambiar dos elementos");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;

	// Elimina

	cout << endl;	
	cout << "Borrando " << lista.Tamanio() << " nodos..." << endl;
	cout << endl;

	int num_nodos = lista.Tamanio();

	for (int i=1; i<=num_nodos; i++) {
		
		cout << "Borrando nodo con " << lista(1) << endl; 
		
		lista.Elimina (1);
		
		cout << lista.ToString("Borrado nodo 1");
		cout << "Quedan " << lista.Tamanio() << " nodos..." << endl;
		cout << endl;
	}

	if (lista.EstaVacia())
		cout << "La lista esta vacia\n";
	else 
		cout << "La lista NO esta vacia\n";
	cout << lista.ToString("");
	cout << endl;


	Lista vacia;
	
	cout << vacia.ToString("Despues de crear lista vacia");
	cout << "Tamanio = " << vacia.Tamanio() << endl;
	cout << "Lista: ";
	if (vacia.EstaVacia())
		cout << "La lista esta vacia\n";
	else 
		cout << "La lista NO esta vacia\n";

	cout << endl;


	// Constructor con dos argumentos

	Lista lista_de_6_nodos (6, 9);

	cout << lista_de_6_nodos.ToString("Creada lista_de_6_nodos inicializada a 9");
	cout << "Tamanio = " << lista_de_6_nodos.Tamanio() << endl;
	cout << "Tercer elemento = " << lista_de_6_nodos[3] << endl;

	if (lista_de_6_nodos.EstaVacia())
		cout << "La lista esta vacia\n";
	else 
		cout << "La lista NO esta vacia\n";

	cout << endl;


	// Prueba de copia
	
	Lista copia (lista_de_6_nodos);
	
	cout << copia.ToString("copia de lista_de_6_nodos");


	// Prueba de asignacion

	Lista nueva;

	cout << nueva.ToString("Creada nueva");

	nueva = lista_de_6_nodos;

	cout << nueva.ToString("nueva tras nueva=lista_de_6_nodos");


	// Operador de asignacion desde TipoBaseLista

	Lista nueva_lista_de_6_nodos (6);
	nueva_lista_de_6_nodos = 9;

	cout << nueva_lista_de_6_nodos.ToString("nueva_lista_de_6_nodos con valor 9");
	cout << "Tamanio = " << nueva_lista_de_6_nodos.Tamanio() << endl;
	cout << "Tercer elemento = " << nueva_lista_de_6_nodos[3] << endl;

	if (nueva_lista_de_6_nodos.EstaVacia())
		cout << "La lista esta vacia\n";
	else 
		cout << "La lista NO esta vacia\n";
	cout << endl;


	// Prueba de copia
	
	Lista copia_lista_de_6_nodos (nueva_lista_de_6_nodos);
	cout << copia_lista_de_6_nodos.ToString("copia de lista_de_6_nodos");
	
	for (int pos=1; pos <= copia_lista_de_6_nodos.Tamanio(); pos++)
		// Poner ceros en las posiciones pares
		if (pos%2==0) copia_lista_de_6_nodos[pos] = 0;
		
	cout << copia_lista_de_6_nodos.ToString("Con posiciones pares a 0");	
	
	
	// Operador de asignación
	
	lista = copia_lista_de_6_nodos;

	cout << lista.ToString("lista despues de lista = copia_lista_de_6_nodos");
	
	lista = 5;
	cout << lista.ToString("lista despues de lista = 5");
		

	
	// Operadores binarios de suma

	cout << endl << endl;
	cout << "OPERADORES DE ADICION" << endl;
		
	Lista l1, l2, l3, l4;

	l1 = l1 + 5 + 7;
	l1 = 3 + l1;				
	cout << l1.ToString("l1 despues de aniadir 3, 5 y 7"); // 3 - 5 - 7
			
	l2 = l2 + 10;
	l2 = l2 + 12;
	cout << l2.ToString("l2 despues de aniadir 10 y 12"); // 10 - 12
					
	l3 = l1 + l2;
	cout << l3.ToString("l3 despues l3 = l1 + l2"); // 3 - 5 - 7 - 10 -12
	
	l4 = 1 + l3 + 15;
	cout << l4.ToString("l4 despues l4 = 1 + l3 + 15");	// 1-3-5-7-10-12-15
	
	// Operadores combinados
			
	l4 += 16; // 1 - 3 - 5 - 7 - 10 - 12 - 15 - 16
	cout << l4.ToString("l4 despues l4 += 16");	// 1-3-5-7-10-12-15-16


	l4 -= 15; // 1 - 3 - 5 - 7 - 10 - 12 - 16	
	l4 -= 7;  // 1 - 3 - 5 - 10 - 12 - 16		
	cout << l4.ToString("l4 despues de l4 -= 15 y l4 -= 7");		

 		 		

	// Operadores binarios de resta

	cout << endl << endl;
	cout << "OPERADORES DE RESTA" << endl;
	
	cout << l3.ToString("l3"); 
	cout << l2.ToString("l2"); 

	Lista l5, l6;
	
	l5 =  l3 - l2; // 3 - 5 - 7
	cout << l5.ToString("l5 despues de l5 =  l3 - l2");			


	l6 = l5; // 3 - 5 - 7
	cout << l6.ToString("l6 tras l6 = l5");	

	l5 = (l5 - 5) - 3 ; // 7
	cout << l5.ToString("l5 despues de l5 = (l5 - 5) - 3");			
	
	l5 -= 7 ; // 7			
	cout << l5.ToString("l5 despues de l5 -= 7");  // vacía		
	
	
					
	// Operadores relacionales
	

	cout << endl << endl;
	cout << "OPERADORES RELACIONALES" << endl;
	
	cout << l1.ToString("l1"); 
	cout << l6.ToString("l6"); 

	if (l1 == l6) 
		cout << "l1 == l6" << endl;
	else 
		cout << "l1 != l6" << endl;
	cout << endl; 
	

	cout << l1.ToString("l1"); 
	cout << l2.ToString("l2"); 

	if (l1 == l2) 
		cout << "l1 == l2" << endl;
	else 
		cout << "l1 != l2" << endl;
	cout << endl; 			

	if (l1 > l2) 
		cout << "l1 > l2" << endl;
	else 
		cout << "NO l1 > l2" << endl;
	cout << endl; 	

	cout << l1.ToString("l1"); 
	cout << l3.ToString("l3"); 
	cout << l4.ToString("l4"); 

	 		 
	cout << endl; 
	if (l1 < l3) 
		cout << "l1 < l3" << endl;
	else 
		cout << "l1 NO < l3" << endl;
	cout << endl; 

	if (l1 <= l3) 
		cout << "l1 <= l3" << endl;
	else 
		cout << "l1 NO <= l3" << endl;
	cout << endl; 

	if (l1 > l4) 
		cout << "l1 > l4" << endl;
	else 
		cout << "l1 NO > l4" << endl;
	cout << endl; 


	return (0);
}

/***************************************************************************/
/***************************************************************************/
