#include "gameController.h"

char bg[20][41]; //ADD

void renderBoard(pokemon** map, int mapHeight, int mapWidth)
{
    for (int i = 1; i < mapHeight - 1; i++) {
        for (int j = 1; j < mapWidth - 1; j++) {
            map[i][j].drawPlayingBox(112);
        }
    }
}

void generateMap(pokemon**& map, int mapHeight, int mapWidth)
{
    srand((unsigned int)time(NULL));

    //Creating a 2D for game array
    for (int i = 0; i < mapHeight; i++)
    {
        map[i] = new pokemon[mapWidth];
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

    //Random character in the cell, with the number of cells is even
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
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            if (map[i][j].isValid)
            {
                map[i][j].deleteBox();
                if (j < 4) displayBackground(bg, j, i); //ADD
                Sleep(5);
            }
        }
    }

    for (int i = 0; i < mapHeight; i++) {
        delete[]map[i];
    }
    delete[]map;
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

void moveSuggestion(pokemon** map, position guidePos[], int height, int width)
{   
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            if (!map[i][j].isValid)
                continue;
            
            for (int k = 1; k < height - 1; k++)
            {
                for (int l = 1; l < width - 1; l++)
                {
                    if (i == k && l == j)
                        continue;
                    if (map[k][l].isValid == false)
                        continue;
                    if (map[i][j].chr == map[k][l].chr)
                    {
                        if (allCheck(map, i, j, k, l, height, width) == true)
                        {
                            guidePos[0].x = j;
                            guidePos[0].y = i;
                            guidePos[1].x = l;
                            guidePos[1].y = k;
                            return;
                        }
                    }
                }
            }
        }
    }
    
}

void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple, int height, int width) {
    int temp, key;
    temp = _getch();


    if (temp == 72 || temp == 104) 
    {
        if (p.hint == 0)
        {
            return;
        }

        position guidePos[2] = {{0,0},{0,0}};
        moveSuggestion(map, guidePos, height , width);

        map[guidePos[0].y][guidePos[0].x].isSelected = 1;
        map[guidePos[1].y][guidePos[1].x].isSelected = 1;

        map[guidePos[0].y][guidePos[0].x].drawPlayingBox(100);
        map[guidePos[1].y][guidePos[1].x].drawPlayingBox(100);

        Sleep(500);

        map[guidePos[0].y][guidePos[0].x].isSelected = 0;
        map[guidePos[1].y][guidePos[1].x].isSelected = 0;

        //renderBoard(map, height, width);

        p.hint--;
        p.point -= 2;
        gotoxy(103, 9);
        cout << "           ";
        gotoxy(103, 9);
        cout << "POINTS: " << p.point;
        gotoxy(100, 12);
        cout << "HINT(S) LEFT: " << p.hint;

    }
    if (temp && temp != 224) 
    { // neu ko phai la dau mui ten
        if (temp == ESC_KEY) // neu la ESC
        {
            status = 2;
        }
        else if (temp == ENTER_KEY || temp == SPACE_KEY) { // neu la Enter
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                Sleep(500);

                map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };

                p.life--;

                gotoxy(104, 6);
                cout << "         ";
                gotoxy(104, 6);
                cout << "LIFE: " << p.life;

            } // kiem tra lap lai
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                map[pos.y][pos.x].isSelected = 1;
                couple--;



                if (couple == 0) { // neu da chon 1 cap
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr) {  // neu cap nay hop nhau
                        if (allCheck(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, height, width)) {
                            p.point += 3;

                            gotoxy(103, 9);
                            cout << "          ";
                            gotoxy(103, 9);
                            cout << "POINTS: " << p.point;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].isValid = 0;
                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            displayBackground(bg, selectedPos[0].x, selectedPos[0].y); //ADD

                            map[selectedPos[1].y][selectedPos[1].x].isValid = 0;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            displayBackground(bg, selectedPos[1].x, selectedPos[1].y); //ADD

                        }
                        else {
                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                            Sleep(500);

                            p.point -= 3;
                            gotoxy(103, 9);
                            cout << "          ";
                            gotoxy(103, 9);
                            cout << "POINTS: " << p.point;


                            p.life--;
                            gotoxy(104, 6);
                            cout << "LIFE: " << p.life;
                        }
                    }
                    else {
                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                        Sleep(500);
                        //Point
                        p.point -= 3;
                        gotoxy(103, 9);
                        cout << "          ";
                        gotoxy(103, 9);
                        cout << "POINTS: " << p.point;

                        p.life--;
                        gotoxy(104, 6);
                        cout << "LIFE: " << p.life;
                    }

                    // Set ve gia tri null ban dau
                    map[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < height - 1; i++) {
                        for (int j = pos.x; j < width - 1; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    for (int i = 1; i <= pos.y; i++) { // chuyen den CELL_1 o tren
                        for (int j = 1; j <= pos.x; j++) {
                            if (map[i][j].isValid) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else //Dau mui ten
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            map[pos.y][pos.x].isSelected = 0;
        switch (key = _getch())
        {
        case KEY_UP:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i > 0; i--) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y + 1; j < height - 1; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width - 1; i++) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = width - 1; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = width - 2; j > pos.x; j--) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i > 0; i--) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

        default:
            break;
        }
    }
}

void playGame(player& p, int height, int width) 
{

    getBackground(bg); //ADD

    DrawInfoBox(8, 10);

    pokemon** map = new pokemon * [height];
    generateMap(map, height, width);

    gotoxy(97, 3);
    cout << "PLAYER NAME: " << p.name;

    gotoxy(104, 6);
    cout << "LIFE: " << p.life;

    gotoxy(103, 9);
    cout << "POINTS: " << p.point;

    gotoxy(100, 12);
    cout << "HINT(S) LEFT: " << p.hint;

    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 1, 1 };
    int status = 0; // 0. dang choi game 
                    // 1. het game 
                    // 2. nguoi choi chon thoat

    while (!status && p.life)
    {


        map[curPosition.y][curPosition.x].isSelected = 1;

        renderBoard(map, height, width);

        move(map, curPosition, status, p, selectedPos, couple, height, width);

        if (checkValidPairs(map, height, width) == false)
        {
            status = 1;
        }

    }

    deleteBoard(map, height, width);
    Sleep(500);
    system("cls");
}

void getPlayerInfo(player& p) {
    gotoxy(50, 10);
    cout << "Enter player name: ";
    getline(cin, p.name);
    p.life = 4;
    p.point = 0;
    p.hint = 30;
}

void getBackground(char bg[][41]) { //ADD
    ifstream fin("pukachi.txt");
    if (fin) {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                bg[i][j] = fin.get();
            }
            fin.ignore();
        }
        fin.close();
    }
    else {
        memset(bg, ' ', sizeof(bg));
    }
}

void displayBackground(char bg[][41], int x, int y) { //ADD
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            gotoxy(x * 10 + j, y * 4 + i);
            cout << bg[y  + i][x * 6 + j];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}