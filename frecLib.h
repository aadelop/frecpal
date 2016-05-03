/*
  Headers frecLib.h
  Author: Alfredo A. Delgado L.
  Carnet: 10-10195

*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILE_FRECLIB_SEEN
#define FILE_FRECLIB_SEEN

/*
	Estructura Item define el tipo de elemento a utilizar
	en mi lista enlazada
*/

typedef struct
{
    listElem header; //Apuntador a los siguientes elementos en lista
    int count; //Contador de ocurrencias de la palabra
    char word[20];//Palabra contenida en elemento lista
}item;

typedef int (*compfn)(const void*, const void*);
/*
 	Tipo apuntador auxiliar para el uso de la funcion de comparacion
 	en la implementacion qsort() de C
 */

int compare(item * elem1, item * elem2);

bool inList(list * container, item * element);

void loadList(char *nameFile, item * element, list * container);

void writeFile(FILE * ofp, item array[], int lenght);

void orderFrecpal(char * nameFile, list * container);

#endif