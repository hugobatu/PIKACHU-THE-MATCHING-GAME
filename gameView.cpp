#include "gameView.h"

// 6X8 EASY
// 8X10 NORMAL


char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};

//char box[5][12] = {
//    {"╭─────────╮"},
//    {"│         │"},
//    {"│         │"},
//    {"│         │"},
//    {"╰─────────╯"}
//};


void generateMap(pokemon **&map, int mapHeight, int mapWidth)
{   
    srand((unsigned int)time(NULL));


    //Creating a 2D for game array
    for (int i = 0; i < mapHeight; i++)
    {
        map[i] = new pokemon [mapWidth];
    }

    int timesRandom = 2;

    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            if (i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1)
                map[i][j].isValid = 0;
        }
    }

    for (int i = 1; i < mapHeight - 1; i++)
    {
        for (int j = 1; j < mapWidth - 1; j++)
        {
            map[i][j].x = j;
            map[i][j].y = i;
        }
    }


    int totalCell = ((mapWidth - 2) * (mapHeight - 2)) / 2;

    while (totalCell > 0)
    {
        char randomCharacter = 65 + rand() % 26;
        while (timesRandom > 0)
        {
            int index = rand() % (mapWidth * mapHeight);
            if (map[index / mapWidth][index % mapWidth].chr == ' ')
            {
                if (index / mapWidth != 0 && index / mapWidth != (mapHeight - 1) && index % mapWidth != 0 && index % mapWidth != (mapWidth - 1))
                {
                    map[index / mapWidth][index % mapWidth].chr = randomCharacter;
                    timesRandom--;
                }
            }
        }
        timesRandom = 2;
        totalCell--;
    }
}



void deleteBoard(pokemon** map, int mapHeight, int mapWidth)
{
    for (int i = 1; i < mapHeight - 1; i++) 
    {
        for (int j = 1; j < mapWidth - 1; j++) 
        {
            if (map[i][j].isValid) 
            {
                map[i][j].deleteBox();
                //if (j < 4) displayBackground(bg, j, i);
                Sleep(5);
            }
        }
    }

    for (int i = 0; i < mapHeight; i++) {
        delete[]map[i];
    }
    delete[]map;
}





void pokemon::drawPlayingBox(int color)
{   
    if (!isValid)
        return;

    for (int i = 0; i < 5; i++) {
        gotoxy(x * 10, y * 4 + i);
        cout << box[i];
    }

    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (chr % 6 + 1)); // white background
        for (int i = 1; i < 4; i++) {
            gotoxy(x * 10 + 1, y * 4 + i);
            cout << "         ";
        }

        gotoxy(x * 10 + 5, y * 4 + 2);
        cout << chr;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        gotoxy(x * 10 + 5, y * 4 + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), chr % 6 + 1);
        cout << chr;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void pokemon::deleteBox() {
    int xCurrent = x + 1, yCurrent = y + 1;

    for (int i = 0; i < 5; i++) {
        gotoxy(x * 10, y * 4 + i);
        cout << "           ";
    }
}

void pokemon::drawSuggestedBox(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (chr % 6 + 1)); // white background
    for (int i = 1; i < 4; i++) {
        gotoxy(x * 10 + 1, y * 4 + i);
        cout << "         ";
    }

    gotoxy(x * 10 + 5, y * 4 + 2);
    cout << chr;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}


void renderBoard(pokemon** map, int mapHeight, int mapWidth)
{
    for (int i = 1; i < mapHeight - 1; i++) {
        for (int j = 1; j < mapWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
}