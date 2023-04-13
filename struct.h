#pragma once

#include "console_settings.h"

#include <algorithm>
#include <ctime>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;


struct pokemon
{
	char chr = ' ';
	bool isValid = 1, isSelected = 0;
	int x;
	int y;
	void drawPlayingBox(int);
	void deleteBox();
};






