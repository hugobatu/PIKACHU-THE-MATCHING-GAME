#pragma once

#include "console_settings.h"

#include <algorithm>
#include <ctime>
#include <time.h>
#include <string>

using namespace std;


struct pokemon
{
	char chr = ' ';
	bool isValid = 1, isSelected = 0;
	int x;
	int y;
	void drawPlayingBox(int);
	void deleteBox();
	void drawSuggestedBox(int);
};




//Tao bang va in ra cac ky tu
void renderBoard(pokemon** map, int mapHeight, int mapWidth);

//Tao mang 2 chieu va random pokemon
void generateMap(pokemon **&map, int mapHeight, int mapWidth);


//Xoa cap phat dong mang 2 chieu
void deleteBoard(pokemon** map, int mapHeight, int mapWidth);



