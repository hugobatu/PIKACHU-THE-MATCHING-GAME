#pragma once

#include "checking.h"
#include "struct.h"


#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <stdlib.h>


using namespace std;

//Key

#define KEY_UP 72	    //Arrow up
#define KEY_DOWN 80     //Arrow down
#define KEY_LEFT 75     //Arrow left
#define KEY_RIGHT 77    //Arrow right
#define ESC_KEY 27      //Esc key
#define ENTER_KEY 13    //Enter key
#define SPACE_KEY 32    //Space key
#define H_KEY 72        //Help key





struct player
{
	int point, life, hint, time;
	string name;

};

struct position 
{
	int x, y;
};

void moveSuggestion(pokemon** map, position guidePos[], int height, int width);

void getPlayerInfo(player& p);
void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple, int height, int width);
void playGame(player& p, int height, int width);


//Tao bang va in ra cac ky tu
void renderBoard(pokemon** map, int mapHeight, int mapWidth);

//Tao mang 2 chieu va random pokemon
void generateMap(pokemon**& map, int mapHeight, int mapWidth);


//Xoa cap phat dong mang 2 chieu
void deleteBoard(pokemon** map, int mapHeight, int mapWidth);

//Ve bang choi game
void DrawInfoBox(int height, int width);


