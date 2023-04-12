#pragma once


#include "gameView.h"
#include "gameController.h"


bool linecheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Icheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Ucheck(pokemon** map, int x1, int y1, int x2, int y2, int height, int width);
bool allCheck(pokemon** map, int x1, int y1, int x2, int y2, int height, int width);


//Check if the game is over or not?
bool checkValidPairs(pokemon** map, int height, int width);
bool gameOver(pokemon** map, int height, int width);

