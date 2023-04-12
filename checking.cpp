#include "checking.h"

bool linecheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int y, x, dem = 0;
        x = min(y1, y2);
        y = max(y1, y2);
        for (int i = x; i <= y; i++) {
            if (map[x1][i].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!map[x1][y1].isValid && map[x2][y2].isValid) || (map[x1][y1].isValid && !map[x2][y2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    if (y1 == y2) {
        int x, y, dem = 0;
        x = min(x1, x2);
        y = max(x1, x2);
        for (int i = x; i <= y; i++) {
            if (map[i][y1].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!map[x1][y1].isValid && map[x2][y2].isValid) || (map[x1][y1].isValid && !map[x2][y2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    return false;
}

bool Icheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int y, x, dem = 0;
        if (y1 > y2) {
            x = y2;
            y = y1;
        }
        else {
            x = y1;
            y = y2;
        }
        for (int i = x + 1; i < y; i++) {
            if (map[x1][i].isValid) {
                return false;
            }
        }
        return true;
    }
    if (y1 == y2) {
        int x, y, dem = 0;
        if (x1 > x2) {
            x = x2;
            y = x1;
        }
        else {
            x = x1;
            y = x2;
        }
        for (int i = x + 1; i < y; i++) {
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
    bool c1, c2;
    if (!map[x1][y2].isValid) {
        c1 = linecheck(map, x1, y1, x1, y2);
        c2 = linecheck(map, x2, y2, x1, y2);
        if (c1 && c2) {
            return true;
        }
    }
    if (!map[x2][y1].isValid) {
        c1 = linecheck(map, x1, y1, x2, y1);
        c2 = linecheck(map, x2, y2, x2, y1);
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}

bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return false;
    }
    bool c1, c2, c3;
    int x, y;
    if (y2 < y1) {
        x = y2;
        y = y1;
    }
    else {
        x = y1;
        y = y2;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(map, x1, i, x2, i);
        if (c3) {
            c1 = linecheck(map, x1, y1, x1, i);
            c2 = linecheck(map, x2, y2, x2, i);
            if (c1 && c2)
                return true;
        }
    }
    if (x2 < x1) {
        x = x2;
        y = x1;
    }
    else {
        x = x1;
        y = x2;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(map, i, y1, i, y2);
        if (c3) {
            c1 = linecheck(map, x1, y1, i, y1);
            c2 = linecheck(map, x2, y2, i, y2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}


bool Ucheck(pokemon** map, int x1, int y1, int x2, int y2, int height, int width) 
{
    if (((x1 == x2) && (x1 == 1 || x1 == height - 2) || ((y1 == y2) && (y1 == 1 || y2 == width - 2)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;

    x = min(y2, y1);
    y = max(y2, y1);
    for (int i = 1; i < width - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, x1, i, x2, i);
            if (c3) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (width - 2)) {
                c1 = linecheck(map, x1, y1, x1, i);
                c2 = linecheck(map, x2, y2, x2, i);
                if ((c1 && c2) || (c1 && y2 == i) || (y1 == i && c2)) {
                    return true;
                }
            }
        }
    }


    for (int i = 1; i < height - 1; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(map, i, y1, i, y2);
            if (c3) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 1 || i == (height - 2)) {
                c1 = linecheck(map, x1, y1, i, y1);
                c2 = linecheck(map, x2, y2, i, y2);
                if ((c1 && c2) || (c1 && x2 == i) || (x1 == i && c2)) {
                    return true;
                }
            }
        }
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


// Allcheck function for medium level

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

bool gameOver(pokemon** map, int height, int width)
{
    int dem = 0;
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            if (map[i][j].isValid == 1)
                return false;
        }
    }

    return true;
}
