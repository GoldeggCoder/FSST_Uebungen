/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Kreisfläche
	Datum:	27.09.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "console.h"

#define AE 132

void kreisflaeche(float, float *);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    float radius, flaeche;

    printf("Gib den Radius eines Kreises ein: ");
    scanf("%f", &radius);

    kreisflaeche(radius, &flaeche);

    printf(" Fl%cche des Kreises: %.3f", AE, flaeche);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void kreisflaeche(float radius, float *flaeche)
{
    *flaeche = pow(radius, 2.0) * M_PI;
}
