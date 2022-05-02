/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Spaceship
	Datum:	02.05.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "console.c"

#define FIREPOWER 10
#define ENERGY 20
#define VELOCITY 100
#define SHIELD 5
#define X_POS 50
#define Y_POS 20

#define ESC 27

typedef struct spaceships spaceship;

struct spaceships {
   char name[20];
   int firepower;
   int energy;
   int velocity;
   int shield;
   int position[2]; 
};

spaceship* createSpaceship();
void printSpaceship(spaceship*);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);
    srand(time(0));

    char key;

    printf("Click any button to create Spaceship\n ESC to exit\n");

    while(1)
    {
        key = getch();
        if(key == ESC)
            break;
        spaceship* spaceshipPtr = createSpaceship();
        printSpaceship(spaceshipPtr);
    }

    getch();
    clrscr();
    closeConsole();
    return 0;
}

spaceship* createSpaceship()
{
    char name[20] = "Benni";
    spaceship* ptr = malloc(sizeof(spaceship));
    strcpy(ptr->name, name);
    ptr->firepower = rand()%FIREPOWER;
    ptr->energy = rand()%ENERGY;
    ptr->velocity = rand()%VELOCITY;
    ptr->shield = rand()%SHIELD;
    ptr->position[0] = rand()%X_POS;
    ptr->position[1] = rand()%Y_POS;
    return ptr;
}

void printSpaceship(spaceship* ptr)
{
    printf("\n Name:\t\t\t %s\n", ptr->name);
    printf(" Feuerkraft:\t\t %d von %d\n",  ptr->firepower, FIREPOWER);
    printf(" Energie:\t\t %d von %d\n",  ptr->energy, ENERGY);
    printf(" Geschwindigkeit:\t %d von %d\n",  ptr->velocity, VELOCITY);
    printf(" Schield:\t\t %d von %d\n",  ptr->shield, SHIELD);
    printf(" Position X:\t\t %d von %d\n",  ptr->position[0], X_POS);
    printf(" Position Y:\t\t %d von %d\n",  ptr->position[1], Y_POS);
}