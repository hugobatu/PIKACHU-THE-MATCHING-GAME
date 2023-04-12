#include "gameView.h"

// 6X8 EASY
// 8X10 NORMAL


//char box[5][12] = {
//            {" --------- "},
//            {"|         |"},
//            {"|         |"},
//            {"|         |"},
//            {" --------- "}
//};

char box[5][12] = {
    {char(218), char(196), char(196), char(196),char(196), char(196), char(196), char(196), char(196), char(196), char(191)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(192), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(217)}
};

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
        gotoxy(x * 10 + 5, y * 4 + 2);
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



void renderBoard(pokemon** map, int mapHeight, int mapWidth)
{
    for (int i = 1; i < mapHeight - 1; i++) {
        for (int j = 1; j < mapWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
}


void DrawInfoBox(int height, int width)
{
    int infoBoxWidth = 26, infoBoxHeight = 25;
    int xStar = width * width - 5;

    // Top Border
    gotoxy(xStar, 4);
    cout << char(218);
    for (int x = 1; x < infoBoxWidth - 1; x++)
    {
        cout << char(196);
    }
    cout << char(191);


    //Mid line
    gotoxy(xStar, 14);
    cout << char(218);
    for (int x = 1; x < infoBoxWidth - 1; x++)
    {
        cout << char(196);
    }
    cout << char(191);




    // Bottom
    gotoxy(xStar, infoBoxHeight - 1);
    cout << char(192);
    for (int x = 1; x < infoBoxWidth - 1; x++)
    {
        cout << char(196);
    }
    cout << char(217);
    // Left and Right Border
    for (int y = 5; y < infoBoxHeight - 1; y++)
    {
        gotoxy(xStar, y);
        cout << char(179);
        gotoxy(xStar + infoBoxWidth - 1, y);
        cout << char(179);
    }


    gotoxy(xStar + 1, 15);
    cout << "Press ARROW key to move";
    gotoxy(xStar + 4, 18);
    cout << "Press ENTER or SPACE";
    gotoxy(xStar + 8, 19);
    cout << "to choose";

    gotoxy(xStar + 2, 22);
    cout << "Press H for suggestion";



}