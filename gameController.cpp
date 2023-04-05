#include "gameController.h"

int width = 10, height = 8;

void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple) {
    int temp, key;
    temp = _getch();
    if (temp && temp != 224) { // neu ko phai la dau mui ten
        if (temp == ESC_KEY) { // neu la ESC
            status = 2;
        }
        else if (temp == ENTER_KEY) { // neu la Enter
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                Sleep(500);

                map[selectedPos[0].y][selectedPos[0].x].selected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;
                gotoxy(70, 0);
                cout << "Life: " << p.life;
            } // kiem tra lap lai
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                map[pos.y][pos.x].selected = 1;
                couple--;

                if (couple == 0) { // neu da chon 1 cap
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr) {  // neu cap nay hop nhau
                        if (allCheck(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                            p.point += 20;
                            gotoxy(40, 0);
                            cout << "Point: " << p.point;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].matched = 1;
                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            map[selectedPos[1].y][selectedPos[1].x].matched = 1;
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
                        }
                        else {
                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                            Sleep(500);

                            p.life--;
                            gotoxy(70, 0);
                            cout << "Life: " << p.life;
                        }
                    }
                    else {
                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);
                        Sleep(500);

                        p.life--;
                        gotoxy(70, 0);
                        cout << "Life: " << p.life;
                    }
                    // tra ve noi san xuat
                    map[selectedPos[0].y][selectedPos[0].x].selected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].selected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < height; i++) {
                        for (int j = pos.x; j < width; j++) {
                            if (map[i][j].matched == 0) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    for (int i = 0; i <= pos.y; i++) { // chuyen den CELL_1 o tren
                        for (int j = 0; j <= pos.x; j++) {
                            if (map[i][j].matched == 0) {
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
    else //neu la dau mui ten
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            map[pos.y][pos.x].selected = 0;
        switch (key = _getch())
        {
        case KEY_UP:
            for (int i = pos.x; i < width; i++) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width; i++) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < width; i++) {
                for (int j = pos.y + 1; j < height; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y + 1; j < height; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width; i++) {
                for (int j = 0; j < pos.y; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = 0; j < pos.y; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height; i++) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = width - 1; j > pos.x; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height; i++) {
                for (int j = width - 1; j > pos.x; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x + 1; j < width; j++) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height; i++) {
                for (int j = pos.x + 1; j < width; j++) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = 0; j < pos.x; j++) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height; i++) {
                for (int j = 0; j < pos.x; j++) {
                    if (map[i][j].matched == 0) {
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

void playGame(player& p) {
    srand(time(0));
    //getBackground(bg);

    pokemon** map = new pokemon * [height];
    generateMap(map);

    gotoxy(10, 0);
    cout << "Name: " << p.name;
    gotoxy(40, 0);
    cout << "Point: " << p.point;
    gotoxy(70, 0);
    cout << "Life: " << p.life;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    //gotoxy(100, 12);
    //cout << "Press arrow key to move";
    //gotoxy(100, 13);
    //cout << "Press Enter to delete";
    //gotoxy(100, 14);
    //cout << "Press ESC to quit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 0, 0 };
    int status = 0; //0. dang choi game
    //1. het game
    //2. nguoi choi chon thoat

    while (!status && p.life) {
        map[curPosition.y][curPosition.x].selected = 1;

        renderBoard(map);

        move(map, curPosition, status, p, selectedPos, couple);

        //if ((!checkValidPairs(board))) status = 1;
    }

    renderBoard(map);
    deleteMap(map);
    Sleep(500);
    system("cls");

    //if (p.life && status == 1) {
    //    if (status == 1)
    //    gotoxy(50, 17);
    //    char c;
    //    cout << "Do you want to continue next game? (Y/N): ";
    //    cin >> c;
    //    cin.ignore();
    //    system("cls");
    //    if (c == 'y' || c == 'Y') normalMode(p);
    //    else writeLeaderBoard(p);
    //}
    //else if (p.life == 0) {
    //    displayStatus(0);
    //    writeLeaderBoard(p);
    //    Sleep(2000);
    //}
    system("cls");
}

void getPlayerInfo(player& p) {
    gotoxy(50, 12);
    cout << "Enter player name: ";
    getline(cin, p.name);
    cin.ignore();
    p.life = 3;
    p.point = 0;
}