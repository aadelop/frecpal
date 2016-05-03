/*
  Headers linkedList.h
  Author: Alfredo A. Delgado L.
  Carnet: 10-10195
*/
#ifndef MAKINGLIST_LINKEDLIST_H
#define MAKINGLIST_LINKEDLIST_H
typedef char bool;
#define true 1
#define false 0


struct listElem
{
    struct listElem * next;
};
typedef struct listElem listElem;

typedef struct
{
    listElem * first;
    listElem * last;
    int lenght;
}list;

void listInit(list * container);

bool listEmpty(list * container);

listElem * listStart (list * container);

listElem * listNext(listElem * element);

void listPush(list * container, listElem * element);

listElem * listPop(list * container);

int listLenght (list * container);

#endif //MAKINGLIST_LINKEDLIST_H+