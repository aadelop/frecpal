/*
  Library of particular functions for "frecpal" program frecLib.C
  Author: Alfredo A. Delgado L.
  Carnet: 10-10195

*/
#include "frecLib.h"


/*
* Function: compare()
* --------------------------
* 
* Auxiliar comparison function used in the  
* qsort() function from the C library. 
*
* This feature extends to compare alphanumeric 
* way if the element count ​​are equal.
*
* elem1: pointer to  first element item to compare
* elem2: pointer to  second element item to compare
*
* returns: 1 if elem1 < elem2.
*		  -1 if elem1 > elem2.
		   0 if elem1 == elem2		
*/ 
int compare(item * elem1, item * elem2)
{
	if ( elem1->count < elem2->count)
      return 1;

	else if (elem1->count > elem2->count)
      return -1;

	else if (elem1->count == elem2->count)
      return strcmp(elem1->word,elem2->word);//Alphanumeric comparison

	
	
}

/*
* Function: inList()
* --------------------------
* Returns true or false if list is empty or not
*
* container: pointer to a list
* element: pointer to an item
*
* returns: true if item's word is in the list
		   false if is not.
*/ 

bool inList (list * container, item * element)
{ 
	item * aux;
	bool auxBool = false;
	for (aux = (item *)listStart(container);aux;
		 aux=(item *) listNext(&aux->header))
	{
		//printf("%s : %s\n", aux->word, element->word);
		
		if (strcmp(aux->word, element->word) == 0)
		{
			aux->count += 1;
			auxBool = true;
			break;
		}
		
	}
	return auxBool;
}

/*
* Function: loadList()
* --------------------------
* Load the global list with the data of file given 
* in the arguments by the user
* 
* name file: pointer to string with name of the file
* element: pointer to an item to insert.
* container: pointer to a global list.
*
* returns: void.
*/ 

void loadList(char *nameFile, item * element, list * container)
{
	FILE * ifp = fopen(nameFile,"r");

	while (fscanf(ifp,"%s", element->word) != EOF)
	{
		element -> count = 1;
		if (!inList(container,element))
		{
			listPush(container,&element->header);
			element++;			
		}
		

		//Checker of correct memory allocation
		while((element = (item *)malloc(sizeof(item)))==NULL)
		{
			printf("Not enough memmory ,waiting for more memory");
			sleep(3);
		}	
	}
	fclose(ifp);
}

/*
* Function: writeFile
* --------------------------
* Write in a file the data obtained from orderly array 
* 
* 
* ofp: pointer to a File to write.
* array: pointer to an Item of the orderly array
* lenght: number of elements in the list.
*
* returns: void.
*/
void writeFile(FILE * ofp, item array[], int lenght)
{
	int i;
	
	for (i = 0; i < lenght; i++)
    	fprintf(ofp,"%s %d \n",
               array[i].word, array[i].count);

  	close(ofp);
}

/*
* Function: orderFrecpal
* --------------------------
* sorts  the items found in the list and 
* write the results in the file indicated by the user 
* in the arguments.
* 
* 
* ofp: pointer to a File to write.
* array: pointer to an Item of the orderly array
* lenght: number of elements in the list.
*
* returns: void.
*/

void orderFrecpal(char * nameFile, list * container)
{
	int i = 0;
	int lenght = listLenght(container);
	FILE * ofp = fopen(nameFile,"w"); 
	item array[lenght];

	while (!listEmpty(container))
	{

		item * aux = (item *)listPop(container); 
		array[i] = * aux;
		free(aux);
		i += 1;

	}
	
	qsort((void *)&array,lenght,sizeof(item),(compfn)compare);
    writeFile(ofp,array, lenght);
}
