#include "struct.h"




char bground[22][61];

char box[5][12] = {
    {char(218), char(196), char(196), char(196),char(196), char(196), char(196), char(196), char(196), char(196), char(191)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(179), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(32), char(179)},
    {char(192), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(196), char(217)}
};




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





