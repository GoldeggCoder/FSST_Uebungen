/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Kaugummiautomat
	Datum:	04.10.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void aufgeldwarten(char *);
int kaugummiausgeben(int *, int *);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,0);

    int geldstand = 0, kaugummistand = 100;
    char geldeinwurf = '0';

    do
    {
        aufgeldwarten(&geldeinwurf);
    }
    while(kaugummiausgeben(&geldstand, &kaugummistand) == 0);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void aufgeldwarten(char *geldeinwurf_pt)
{
    *geldeinwurf_pt = 0;
    while(*geldeinwurf_pt != '1')
    {
        *geldeinwurf_pt = 0;
        printf("\n Werfen Sie bitte 1$ ein: ");
        *geldeinwurf_pt = getch();
    }
}

int kaugummiausgeben(int *geldstand_pt, int *kaugummistand_pt)
{
    printf("\n ...Kaugummi wurde ausgebeben...\n");
    (*geldstand_pt)++;
    (*kaugummistand_pt)--;
    if((*geldstand_pt) >= 100)
    {
        printf("\n\n Geldkassette ist voll!");
        return 1;
    }
    else if((*kaugummistand_pt) <= 0)
    {
        printf("\n\nKeine Kaugummis mehr vorhanden!");
        return 1;
    }
    return 0;
}
