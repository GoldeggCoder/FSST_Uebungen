/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Sortiere Namensliste
	Datum:	7.12.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "console.cpp"

#define AE 132
#define UE 129

using namespace std;

class schueler
{
public: 
    char firstName[20];
    char lastName[20];
};

void sortSchueler(schueler *, int);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,0);

    int counter = 0;
    char key = '0';
    schueler *schuelerListe, *cache;

    do
    {
        counter++;
        cache = schuelerListe;
        delete[] schuelerListe;
        schuelerListe = new schueler[counter];
        for(int i = 0; i < counter; i++)
        {
            schuelerListe[i] = cache[i];
        }
        delete[] cache;
        cout << "\n Gib den Vornamen des " << counter << ". Sch" << (char)UE << "lers ein: ";
        cin >> schuelerListe[counter-1].firstName;
        cout << " Gib den Nachnamen des " << counter << ". Sch" << (char)UE << "lers ein: ";
        cin >> schuelerListe[counter-1].lastName;
        cout << " N" << (char)AE << "chster Name?(y/n)";
        do
        {
            key = getch();
        }
        while(key != 'y' && key != 'n');
    }
    while(key != 'n');

    sortSchueler(schuelerListe, counter);
    cout << "\n";
    for(int i = 0; i < counter; i++)
    {
        cout << "\n " << i+1 << ". " << schuelerListe[i].firstName << " " << schuelerListe[i].lastName;
    }

    delete[] schuelerListe;

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void sortSchueler(schueler *schuelerListe, int counter)
{
    int flag;
    char cache[20];
    do
    {
        flag = 0;
        for(int i = 0; i < counter-1; i++)
        {
            if(strcmp(schuelerListe[i].lastName, schuelerListe[i+1].lastName) > 0)
            {
                strcpy(cache, schuelerListe[i].firstName);
                strcpy(schuelerListe[i].firstName, schuelerListe[i+1].firstName);
                strcpy(schuelerListe[i+1].firstName, cache);
                strcpy(cache, schuelerListe[i].lastName);
                strcpy(schuelerListe[i].lastName, schuelerListe[i+1].lastName);
                strcpy(schuelerListe[i+1].lastName, cache);
                flag = 1;
            }
        }
    }
    while(flag);
}