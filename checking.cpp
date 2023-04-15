#include "checking.h"



bool Icheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {

    for (int i = min(y1, y2) + 1; i < max(y1, y2); i++) {
        if (map[x1][i].isValid) {
            return false;
        }
    }
    return true;
    }
    else if (y1 == y2) {

    for (int i = min(x1, x2) + 1; i < max(x1,x2); i++) {
        if (map[i][y1].isValid) {
            return false;
        }
    }
    return true;
    }
    return false;
}

bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return false;
    }
    bool check1, check2;
    if (!map[x1][y2].isValid) {
        check1 = Icheck(map, x1, y1, x1, y2);
        check2 = Icheck(map, x2, y2, x1, y2);
        if (check1 && check2) {
            return true;
        }
    }
    if (!map[x2][y1].isValid) {
        check1 = Icheck(map, x1, y1, x2, y1);
        check2 = Icheck(map, x2, y2, x2, y1);
        if (check1 && check2) {
            return true;
        }
    }
    return false;
}



bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2)
        return false;
    bool check1, check2, check3;
    for (int i = min(y1, y2) + 1; i < max(y1, y2); i++)
    {
        check1 = Icheck(map, x1, y1, x1, i);
        check2 = Icheck(map, x1, i, x2, i);
        check3 = Icheck(map, x2, y2, x2, i);
        if (check1 && check2 && check3 && !map[x1][i].isValid && !map[x2][i].isValid)
            return true;
    }
    for (int i = min(x1, x2) + 1; i < max(x1, x2); i++)
    {
        check1 = Icheck(map, x1, y1, i, y1);
        check2 = Icheck(map, i, y1, i, y2);
        check3 = Icheck(map, x2, y2, i, y2);
        if (check1 && check2 && check3 && !map[i][y1].isValid && !map[i][y2].isValid)
            return true;
    }
    return false;
}

bool Ucheck(pokemon** map, int x1, int y1, int x2, int y2, int height, int width)
{
    for (int i = 0; i < width; i++)
    {
        if (Icheck(map, x1, i, x1, y1) && Lcheck(map, x1, i, x2, y2) && !map[x1][i].isValid)
            return true;
    }
    for (int i = 0; i < height; i++)
    {
        if (Icheck(map, i, y1, x1, y1) && Lcheck(map, i, y1, x2, y2) && !map[i][y1].isValid)
            return true;
    }
    return false;
}



bool allCheck(pokemon** map, int x1, int y1, int x2, int y2, int height, int width)
{
    if (Icheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Lcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Zcheck(map, x1, y1, x2, y2)) {
        return true;
    }
    else if (Ucheck(map, x1, y1, x2, y2, height, width)) {
        return true;
    }
    return false;
}



bool checkValidPairs(pokemon** map, int height, int width) 
{
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[height * width];
        for (int i = 1; i < height - 1; i++) {
            for (int j = 1; j < width - 1; j++) {
                if (map[i][j].chr == check && map[i][j].isValid) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allCheck(map, pos[i], pos[i + 1], pos[j], pos[j + 1], height, width)) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}

