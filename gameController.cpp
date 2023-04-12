#include "gameController.h"



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

    if (temp == 82 || temp == 114)
    {
        map[pos.y][pos.x].isSelected = 0;
        shuffleBoard(map, height, width, pos);
        renderBoard(map, height, width);
        map[pos.y][pos.x].isSelected = 1;
        return;
    }

    else if (temp == 72 || temp == 104) 
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
        //gotoxy(100, 1);
        //cout << "suggest y1: " << guidePos[1].y;
        //gotoxy(100, 2);
        //cout << "suggest x1: " << guidePos[1].x;
        //gotoxy(100, 3);
        //cout << "suggest y2: " << guidePos[0].y;
        //gotoxy(100, 4);
        //cout << "suggest x2: " << guidePos[0].x;
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

                gotoxy(10, 1);
                cout << "xCurSelected[0]: " << selectedPos[0].x;
                gotoxy(10, 2);
                cout << "yCurSelected[0]: " << selectedPos[0].y;

                gotoxy(30, 1);
                cout << "xCurSelected[1]: " << selectedPos[1].x;
                gotoxy(30, 2);
                cout << "yCurSelected[1]: " << selectedPos[1].y;

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
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            map[selectedPos[1].y][selectedPos[1].x].isValid = 0;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
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
            //gotoxy(10, 1);
            //cout << "xCur: " << pos.x;
            //gotoxy(10, 1);
            //cout << "yCur: " << pos.y;
        default:
            break;
        }
    }
}

void playGame(player& p, int height, int width) 
{
    //srand(time(0));
    //getBackground(bg);


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
        //gotoxy(50, 1);
        //cout << "xCur: " << curPosition.x;
        //gotoxy(50, 2);
        //cout << "yCur: " << curPosition.y;

        gotoxy(10, 1);
        cout << "                    ";
        gotoxy(10, 2);
        cout << "                    ";
        gotoxy(30, 1);
        cout << "                    ";
        gotoxy(30, 2);
        cout << "                    ";



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

void shuffleBoard(pokemon** map, int height, int width, position &pos)
{
    // Calculate the number of valid pokemon in the map
    int numValid = 0;
    int check = 0;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if (map[i][j].isValid) {
                numValid++;
            }
        }
    }

    // Copy valid pokemon to a flat array
    pokemon* validPokemon = new pokemon[numValid];
    int k = 0;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if (map[i][j].isValid) {
                validPokemon[k] = map[i][j];
                k++;
            }
        }
    }

    // Shuffle the valid pokemon array using Fisher-Yates shuffle
    srand(time(NULL));
    for (int i = numValid - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(validPokemon[i], validPokemon[j]);
    }

    // Copy shuffled pokemon back to the map
    k = 0;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if (check == 0) {
                pos.y = i;
                pos.x = j;
                check++;
            }
            if (map[i][j].isValid) {
                map[i][j] = validPokemon[k];
                k++;
            }
        }
    }

    // Free memory
    delete[] validPokemon;
}
