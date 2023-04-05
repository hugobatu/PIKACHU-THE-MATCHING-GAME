#pragma once

#include "checkGame.h"
#include "gameView.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>

using namespace std;

//Key
#define KEY_UP 72	//Arrow up
#define KEY_DOWN 80 //Arrow down
#define KEY_LEFT 75 //Arrow left
#define KEY_RIGHT 77 //Arrow right
#define ESC_KEY 27 //Esc key
#define ENTER_KEY 13 //Enter key

#define W_UP 87//W
#define D_RIGHT 68//D
#define A_LEFT 65//A
#define S_DOWN 83//S

#define w_up 119//W
#define d_right 100//D
#define a_left 97//A
#define s_down 115//S

struct player
{
	int point, life;
	string name;

};

struct position 
{
	int x, y;
};


void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple);
void playGame(player& p);
void getPlayerInfo(player& p);