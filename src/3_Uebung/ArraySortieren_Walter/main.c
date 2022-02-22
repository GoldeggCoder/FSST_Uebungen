/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Array Sortieren
	Datum:	18.10.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void sortiereArray(int *, int);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,0);

    int sizeArray, i;

    do
    {
        printf("\n Gib an wie gross das Array ist: ");
        scanf("%d", &sizeArray);
    }
    while(sizeArray < 1);

    int array[sizeArray];
    for(i = 0; i < sizeArray; i++)
    {
        printf(" Gib die %d. Stelle ein: ", i+1);
        scanf("%d", &array[i]);
    }

    sortiereArray(&array, sizeArray);

    printf("\n\n ");
    for(i = 0; i < sizeArray; i++)
    {
        printf("%d\t", array[i]);
    }

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void sortiereArray(int array[], int size)
{
    int cache, flag;
    do
    {
        flag = 0;
        for(int i = 0; i < (size-1); i++)
        {
            if(array[i] > array[i+1])
            {
                cache = array[i];
                array[i] = array[i+1];
                array[i+1] = cache;
                flag = 1;
            }
        }
    }
    while(flag);
}
