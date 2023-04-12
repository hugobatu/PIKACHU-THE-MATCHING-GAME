#pragma once

#include "checking.h"
#include "gameView.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <stdlib.h>

#include <chrono>
#include <thread>

using namespace chrono;
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

#define W_UP 87
#define A_LEFT 65
#define S_DOWN 83
#define D_RIGHT 68

#define ARROW_UP 0x48
#define ARROW_LEFT 0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN 0x50

#define w_up 119
#define a_left 97
#define s_down 115
#define d_right 100



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

void shuffleBoard(pokemon** map, int height, int width, position& pos);
