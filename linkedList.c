/*
  Library of generic linked list linkedList.c
  Author: Alfredo A. Delgado L.
  Carnet: 10-10195

*/

#include "linkedList.h"

void listInit(list * container)
{
    container -> first = 0;
    container -> last = 0;
    container -> lenght = 0;
}

bool listEmpty(list * container)
{
    return 0 == container->first;
}

listElem * listStart (list * container)
{
    return container -> first;
}

listElem * listNext(listElem * element)
{
    return element -> next;
}

void listPush(list * container, listElem * element)
{
    if(listEmpty(container))
    {
        container -> first = element;
        container -> last = element;
    }
    else
    {
        container -> last-> next = element;
        container -> last = element;
    }

    element -> next = 0;
    container -> lenght += 1;

}

listElem * listPop(list * container)
{
    listElem * element = container -> first;
    container -> first = container -> first -> next;
    container -> lenght -= 1;
    return element;
}

int listLenght (list * container)
{
    return (container->lenght);
}
