/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Zeichen Ersetzen
	Datum:	22.11.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.c"


int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    int i;
    char string[80] = "", zeichen1 = '0', zeichen2 = '0';

    printf("Eingabestring: ");
    fgets(string, 80, stdin);
    printf(" Zu ersetzendes Zeichen: ");
    zeichen1 = getch();
    printf("%c", zeichen1);
    printf("\n Zu ersetzen Zeichen: ");
    zeichen2 = getch();
    printf("%c", zeichen2);

    i = 0;
    while(string[i] != '\n' && string[i] != '\0')
    {
        if(string[i] == zeichen1)
            string[i] = zeichen2;
        i++;
    }

    printf("\n\n Ausgabe: %s", string);

    getch();
    clrscr();
    closeConsole();
    return 0;
}
