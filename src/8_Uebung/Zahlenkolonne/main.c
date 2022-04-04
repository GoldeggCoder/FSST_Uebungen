/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Zahlenkolonne
	Datum:	4.4.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.c"

#define ESC 27

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);

    int counter = 0, *startPtr = malloc(0 * sizeof(int)), summe = 0;
    char key;

    do
    {
        counter++;
        startPtr = realloc(startPtr, counter * sizeof(int));
        printf("\n Gib eine Zahl ein: ");
        scanf("%d", &startPtr[counter-1]);
        summe += startPtr[counter-1];
        printf(" Weiter? (ESC zum abbrechen)");
        key = getch();
    }
    while((int)key != ESC);

    free(startPtr);

    printf("\n\n Summe: %d\n Durchschnitt: %.3f", summe, ((float)summe/counter));

    getch();
    clrscr();
    closeConsole();
    return 0;
}