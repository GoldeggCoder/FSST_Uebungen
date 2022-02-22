/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Mittlere Wortlänge
	Datum:	7.12.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "console.cpp"

#define AE 132

using namespace std;

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    int stringLen[50], counter;
    float stringLenAverage, stringLenTotal = 0;
    char mainString[50], *string, delimiters[] = ",. ";

    cout << "Gib einen Satz ein:\t";
    fgets(mainString, 49, stdin);

    counter = 0;
    string = strtok(mainString, delimiters);
    while(string != NULL)
    {
        stringLen[counter] = strlen(string);
        counter++;
        string = strtok(NULL, delimiters);
    }

    cout << "\n Wortl" << (char)AE << "ngen:\t\t";
    for(int i = 0; i < counter; i++)
    {
        cout << stringLen[i] << " ";
        stringLenTotal += (float)stringLen[i]; 
    }

    stringLenAverage = stringLenTotal/counter;
    cout << "\n Mittlere Wortl" << (char)AE << "nge:\t" << stringLenAverage;

    getch();
    clrscr();
    closeConsole();
    return 0;
}