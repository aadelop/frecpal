/*
  Principal program of...
  Author: Alfredo A. Delgado L.
  Carnet: 10-10195

*/
#include "frecLib.h"

int main (int argc, char * argv[])
{

	list items; //list of items to order
	item * pItem;//

	listInit(&items);

	/*Checker of correct memory allocation*/
	while (((pItem = (item *)malloc(sizeof(item)))==NULL))
	{
		printf("Not enough memmory ,waiting for more memory");
		sleep(3);
	}

	/*Loding list with content from user's file */
	loadList(argv[1],pItem, &items);

	/*Ordring */
	orderFrecpal(argv[2],&items);

} 