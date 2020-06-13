/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero de cabecera asociado al tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Tipo básico descrito en el video dedicado a la implementación de Matriz2D
//
// Fichero: Matriz2D.h
//
/***************************************************************************/

#ifndef CLASS_MATRIZ2D_TIPOBASE_MATRIZ2D
#define CLASS_MATRIZ2D_TIPOBASE_MATRIZ2D

#include <string>
#include "TipoBase_Matriz2D.h"

using namespace std; 


/***************************************************************************/
// Definiciones de tipos

typedef struct {

	TipoBaseMatriz2D ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

} Matriz2D;


class Matriz2D{


/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor" (0 si TipoBase es int, 0.0 si TipoBase
// es double y 'x' si TipoBase es char). 
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas. 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils=0, int ncols=0, TipoBaseMatriz2D valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Recibe: matriz, la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta si una matriz está vacía.
// Recibe: true si la matriz "matriz" esta vacia. 

bool EstaVacia (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Recibe: matriz, la matriz que va a serializarse. 

string ToString (Matriz2D matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
//
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBaseMatriz2D & Valor (const Matriz2D & matriz, int num_fila, int num_columna); 

/***************************************************************************/
/***************************************************************************/
// Ecualizar una matriz: cambia todos los todos valores de la matriz y los 
// fija todos iguales e iguales a "valor".
// Recibe: matriz, la matriz que va a modificarse. 
//		   valor, el valor común  que se escribirá en todas las casillas.

void Ecualiza (Matriz2D & matriz, TipoBaseMatriz2D valor);

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de matrices.
// El contenido de la matriz "destino" se pierde, se sustituye por una  
// copia del contenido de "origen" . 
// Recibe: destino, matriz clon.
//         origen, matriz original.
 
void Clona (Matriz2D & destino, const Matriz2D & origen);

/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son exactamente iguales (dimensiones y contenido)
// Recibe: "una" y "otra", las dos matrices que se comparan.
// Devuelve true si las dos matrices son exactamente iguales.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son exactamente iguales (dimensiones y contenido)
// Recibe: "una" y "otra", las dos matrices que se comparan.
// Devuelve true si las dos matrices son exactamente iguales.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
/***************************************************************************/
// Construye una submatriz rectangular de una matriz dinámica.
// Extrae una submatriz de "original" y la deja en "resultado".  
// La submatriz "resultado" es una zona rectangular de "original" que 
// empieza en la casilla de coordenadas ("fila_inic", "col_inic") y que 
// tiene (un máximo de) "num_filas" filas y "num_cols" columnas.
//
// Parámetros:
// 		resultado (referencia), matriz resultante.
//		original, la matriz de la que se va a extraer la submatriz.
//		fila_inic, fila inicial de "matriz" para extraer la submatriz  
//		col_inic, fila inicial de "matriz" para extraer la submatriz  
//		num_filas, número (máximo) de filas a extraer
//		num_cols, número (máximo) de columnas a extraer
//
// PRE: 0 <= fila_inic < original.fils
// PRE: 0 <= col_inic < original.cols
// PRE: 0 <= num_filas,  PRE: 0 <= num_cols 
// 		Si no se cumplen, la matriz "resultado" es vacía.

void SubMatriz (Matriz2D & resultado, const Matriz2D & original, 
                int fila_inic, int col_inic,  int num_filas, int num_cols); 

/***************************************************************************/
/***************************************************************************/
// Modifica una matriz dinámica eliminando una fila/columna.
// Parámetros:
// 		matriz (referencia), matriz que se modifica.
//		num, el índice de la fila/columna que se elimina de "matriz"
// PRE (EliminaFila):    0<=num_fila<NumFilas(m)
// PRE (EliminaColumna): 0<=num_fila<NumColumnas(m)

void EliminaFila    (Matriz2D & matriz, int num);
void EliminaColumna (Matriz2D & matriz, int num);

/***************************************************************************/
/***************************************************************************/
// Modifica una matriz dinámica.
// Cambia de orden las filas de "matriz" (la primera pasa a ser la última y 
// la última la primera, la segunda la penúltima y la penúltima la segunda,... 
// Parámetros: matriz (referencia), matriz que se modifica.

void EspejoHorizontal (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Modifica una matriz dinámica.
// Cambia de orden las columnas de "matriz" (la primera pasa a ser la última y 
// la última la primera, la segunda la penúltima y la penúltima la segunda,... 
// Parámetros: matriz (referencia), matriz que se modifica.

void EspejoVertical (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
};
#endif
