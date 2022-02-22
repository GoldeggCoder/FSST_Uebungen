/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Array Shuffle
	Datum:	18.10.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

#define RAND_RUNS 100

void shuffleArray(int *, int);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,0);
    srand(time(0));

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

    shuffleArray(array, sizeArray);

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

void shuffleArray(int array[], int arraySize)
{
    int randomNumbers[2], cache;
    for(int i = 0; i < RAND_RUNS; i++)
    {
        randomNumbers[0] = rand()%arraySize;
        randomNumbers[1] = rand()%arraySize;

        cache = array[randomNumbers[0]];
        array[randomNumbers[0]] = array[randomNumbers[1]];
        array[randomNumbers[1]] = cache;
    }
}
