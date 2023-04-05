#pragma once

#include <cstring>
#include <string>
#include <iostream>
#include <Windows.h>

#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <iostream>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define YELLOW 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_YELLOW 14
#define WHITE 15


// Function to set the cursor at desire position
void gotoxy(int x, int y);

// Function to set the console window size
void setConsoleSize(int width, int height);

// Function to set the console font size and type
void setConsoleFont(int size, const wchar_t* font);

// Function to set the console window to be resizable
void setConsoleResizable(bool resizable);

// Function to set the console window to be maximizable
void setConsoleMaximizable(bool maximizable);

//Function to hide scroll bar
void hideConsoleScrollBar();


void clearConsole();
void disableMouseInput();
void showCursor(bool show);
void disableMaximize();
void setConsoleColor(int color);
void setAndCenterWindow();
void initConsole(int width, int height);

#endif // CONSOLE_H
