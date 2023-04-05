#pragma once

#include "gameView.h"
#include <algorithm>
#include <string>


bool Icheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Lcheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Zcheck(pokemon **map, int x1, int y1, int x2, int y2);
bool Ucheck(pokemon **map, int x1, int y1, int x2, int y2);

int findMax(int x, int y);
int findMin(int x, int y);

bool checkTwoCharacter(pokemon **map, int x1, int y1, int x2, int y2);
bool CheckSelectedAndMatched(pokemon **map, int x1, int y1, int x2, int y2);
void matchedCell(pokemon **& map, int x1, int y1, int x2, int y2);
void selectedCell(pokemon **&map, int x1, int y1, int x2, int y2);
void unselectedCell(pokemon **&map, int x1, int y1, int x2, int y2);



bool allCheck(pokemon** map, int x1, int y1, int x2, int y2);