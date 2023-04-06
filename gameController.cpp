#include "gameController.h"

int width = 10, height = 8;

/*void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple) {
    int temp, key;
    temp = _getch();
    if (temp && temp != 224 && temp != 'w' && temp != 'W' && temp != 'a' && temp != 'A' && temp != 's' && temp != 'S' && temp != 'd' && temp != 'D') { // neu ko phai la dau mui ten
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
            for (int i = pos.x; i < width - 1; i++) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y - 1; j > 0; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width-1; i++) {
                for (int j = height - 1; j > pos.y; j--) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i > 0; i--) {
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
            for (int i = pos.x; i < width-1; i++) {
                for (int j = pos.y + 1; j < height-1; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = pos.y + 1; j < height-1; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < width-1; i++) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].matched == 0) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i > 0; i--) {
                for (int j = 1; j < pos.y; j++) {
                    if (map[j][i].matched == 0) {
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
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x - 1; j > 0; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = width - 2; j > pos.x; j--) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = width - 2; j > pos.x; j--) {
                    if (map[i][j].matched == 0) {
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
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = pos.x + 1; j < width - 1; j++) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i > 0; i--) {
                for (int j = 1; j < pos.x; j++) {
                    if (map[i][j].matched == 0) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < height - 1; i++) {
                for (int j = 1; j < pos.x; j++) {
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
} */


void move(pokemon** map, position& pos, int& status, player& p, position selectedPos[], int& couple)
{
    int key1, key2;
    key1 = _getch();
    if (key1 && key1 != 224 &&
        key1 != A_LEFT && key1 != D_RIGHT &&
        key1 != S_DOWN && key1 != W_UP &&
        key1 != a_left && key1 != d_right &&
        key1 != s_down && key1 != w_up)
    {
        if (key1 == ESC_KEY)
            status = 2;
        else if (key1 == ENTER_KEY)
        {
            if (map[pos.y][pos.x].matched == 1)
                return;
            else if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) 
            {   
                map[pos.y][pos.x].selected = 0;

                Sleep(50);

                map[selectedPos[0].y][selectedPos[0].x].selected = 0;
                couple = 2;
                selectedPos[0] = { -1,-1 };
            }
            else
            {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                couple--;
                map[pos.y][pos.x].selected = 1;

                if (couple == 0)
                {   
                    if (map[selectedPos[0].y][selectedPos[0].x].chr == map[selectedPos[1].y][selectedPos[1].x].chr)
                    {
                        if (allCheck(map, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x))
                        {
                            p.point += 30;
                            gotoxy(40, 0);
                            cout << "Point" << p.point;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(40);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(40);
                            Sleep(500);

                            map[selectedPos[0].y][selectedPos[0].x].matched = 1;
                            map[selectedPos[1].y][selectedPos[1].x].matched = 1;

                            map[selectedPos[0].y][selectedPos[0].x].deleteBox();
                            map[selectedPos[1].y][selectedPos[1].x].deleteBox();
                        }
                        else
                        {
                            p.point -= 30;
                            gotoxy(40, 0);
                            cout << "Point: " << p.point;

                            p.life -= 1;
                            gotoxy(70, 0);
                            cout << "Life: " << p.life;

                            map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                            map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);

                        }
                    }

                    else
                    {
                        p.point -= 30;
                        gotoxy(40, 0);
                        cout << "Point: " << p.point;

                        p.life -= 1;
                        gotoxy(70, 0);
                        cout << "Life: " << p.life;

                        map[selectedPos[0].y][selectedPos[0].x].drawPlayingBox(70);
                        map[selectedPos[1].y][selectedPos[1].x].drawPlayingBox(70);

                    }
                    couple = 2;
                    map[selectedPos[0].y][selectedPos[0].x].selected = 0;
                    map[selectedPos[1].y][selectedPos[1].x].selected = 0;
                    selectedPos[0] = { -1,-1 };
                    selectedPos[1] = { -1,-1 };
                }

            }
        }

    }
    else // PHIM MUI TEN DI CHUYEN
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x))
        {
            map[pos.y][pos.x].selected = 0;
        }

        switch (key2 = _getch())
        {
        case KEY_UP:
            if (pos.y == 1)
            {
                pos.y = height - 2;
                return;
            }
            for(int j = pos.y - 1; j > 0; j--)
            {
                pos.y = j;
                return;
            }
            break;
        case KEY_DOWN:
            if (pos.y == height - 2)
            {
                pos.y = 1;
                return;
            }

            for (int j = pos.y + 1; j < height - 1; j++)
            {
                pos.y = j;
                return;
            }
            break;
        case KEY_LEFT:
            if (pos.x == 1)
            {
                pos.x = width - 2;
                return;
            }
            for(int j = pos.x - 1; j > 0; j--)
            {
                pos.x = j;
                return;
            }
            break;
        case KEY_RIGHT:
            if (pos.x == width - 2)
            {
                pos.x = 1;
                return;
            }
            else
            {
                for (int j = pos.x + 1; j < width - 1; j++)
                {
                    pos.x = j;
                    return;
                }
            }
        default:
            break;
        }
    }
}

void playGame(player& p) {
    //srand(time(0));
    //getBackground(bg);

    pokemon** map = new pokemon * [height];
    generateMap(map);

    gotoxy(10, 0);
    cout << "Name: " << p.name;
    gotoxy(40, 0);
    cout << "Point: ";
    gotoxy(70, 0);
    cout << "Life: " << p.life;

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    //gotoxy(100, 12);
    //cout << "Press arrow key to move";
    //gotoxy(100, 13);
    //cout << "Press Enter to delete";
    //gotoxy(100, 14);
    //cout << "Press ESC to quit";
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition{ 1, 1 };
    int status = 0; //0. dang choi game //1. het game //2. nguoi choi chon thoat

    //    while (status == 0 && p.life != 0) {
    //
    //        int curX = curPosition.x, curY = curPosition.y;
    //        map[curPosition.y][curPosition.x].selected = 1;
    //
    //        renderBoard(map);
    //
    //        if (map[curPosition.y][curPosition.x].matched == 1) {
    //            int x = curPosition.x, y = curPosition.y;
    //            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); // white background
    //            for (int i = 1; i < 4; i++) {
    //                gotoxy(x * 10 + 1, y * 4 + i);
    //                cout << "         ";
    //            }
    //            map[curPosition.y][curPosition.x].selected = 0;
    //        }
    //
    //        move(map, curPosition, status, p, selectedPos, couple);
    //
    //        if (map[curY][curX].matched == 1) {
    //            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    //            int x = curX, y = curY;
    //            for (int i = 1; i < 4; i++) {
    //                gotoxy(x * 10 + 1, y * 4 + i);
    //                cout << "         ";
    //            }
    //            //            if(curX < 5)
    //            //              displayBackground(bg, curX, curY);
    //        }
    //        renderBoard(map);
    //    //}
    //
    //    deleteMap(map);
    //    Sleep(500);
    //    system("cls");
    //
    //    /*if (p.life && status == 1) {
    //        if (status == 1)
    //        gotoxy(50, 17);
    //        char c;
    //        cout << "Do you want to continue next game? (Y/N): ";
    //        cin >> c;
    //        cin.ignore();
    //        system("cls");
    //        if (c == 'y' || c == 'Y') normalMode(p);
    //        else writeLeaderBoard(p);
    //    }
    //    else if (p.life == 0) {
    //        displayStatus(0);
    //        writeLeaderBoard(p);
    //        Sleep(2000);
    //    }*/

    while (status == 0 && p.life != 0) {
        map[curPosition.y][curPosition.x].selected = 1;

        renderBoard(map);

        move(map, curPosition, status, p, selectedPos, couple);

        clearConsole();
        //if ((!checkValidPairs(board))) status = 1;
    }

    renderBoard(map);
    deleteMap(map);
    Sleep(500);
    system("cls");

}

void getPlayerInfo(player& p) {
    gotoxy(50, 12);
    cout << "Enter player name: ";
    getline(cin, p.name);
    p.life = 1000;
    p.point = 0;
}