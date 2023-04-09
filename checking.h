#pragma once


#include "gameView.h"
#include "gameController.h"


bool linecheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Icheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2);

//For easy level
bool UcheckEasyLevel(pokemon** map, int x1, int y1, int x2, int y2);
bool allCheckEasyLevel(pokemon** map, int x1, int y1, int x2, int y2);



//For medium level
bool UcheckMediumLevel(pokemon** map, int x1, int y1, int x2, int y2);
bool allCheckMediumLevel(pokemon** map, int x1, int y1, int x2, int y2); 

//Check if the game is over or not?
bool gameOver(pokemon** map, int height, int width);

bool checkValidPairsMediumLevel(pokemon** map, int height, int width);
