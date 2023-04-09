#pragma once


#include "gameView.h"

bool linecheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Icheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2);
bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2);
bool UcheckMedLevel(pokemon** map, int x1, int y1, int x2, int y2);
bool allCheck(pokemon** map, int x1, int y1, int x2, int y2);
