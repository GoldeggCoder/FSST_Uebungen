/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Array Duplikat
	Datum:	18.10.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void dupliziereArray(int *, int*, int);

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

    int eingabe[sizeArray], duplikat[sizeArray];
    for(i = 0; i < sizeArray; i++)
    {
        printf(" Gib die %d. Stelle ein: ", i+1);
        scanf("%d", &eingabe[i]);
    }

    sortiereArray(&eingabe, &duplikat, sizeArray);

    printf("\n\n ");
    for(i = 0; i < sizeArray; i++)
    {
        printf("%d\t", eingabe[i]);
    }
    printf("\n ");
    for(i = 0; i < sizeArray; i++)
    {
        printf("%d\t", duplikat[i]);
    }

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void sortiereArray(int eingabe[], int duplikat[], int size)
{
    for(int i = 0; i < size; i++)
    {
        duplikat[i] = eingabe[i];
    }
}
