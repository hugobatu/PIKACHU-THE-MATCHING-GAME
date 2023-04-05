#include "gameView.h"
#include "checkGame.h"
#include "console_settings.h"
#include "gameController.h"

using namespace std;

int main()
{   
    initConsole(1200, 1100);
    pokemon** map;

    //generateForTesting(map);
    generateMap(map);
    
    //Assign to a specific value (to avoid receiving -1 for variables)
    /*int x1 = -2, y1 = -2, x2 = -2, y2 = -2; 


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j].matched == 0)
                cout << map[i][j].chr << " ";
            else
                cout << " " << " ";
        }
        cout << endl;
    }
    while (x1 != -1 || y1 != -1 || x2 != -1 || y2 != -1)
    {

        cout << "Nhap toa do x1: ";
        cin >> x1;
        cout << "Nhap toa do y1: ";
        cin >> y1;
        cout << "Nhap toa do x2: ";
        cin >> x2;
        cout << "Nhap toa do y2: ";
        cin >> y2;
        
        selectedCell(map, x1, y1, x2, y2);

        if (allCheck(map, x1, y1, x2, y2) == true)
        {
            cout << endl;
            cout << "Successful move" << endl;
            matchedCell(map, x1, y1, x2, y2);
        }

        else
        {
            cout << endl;
            cout << "Invalid move" << endl;
            unselectedCell(map, x1, y1, x2, y2);
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (map[i][j].matched == 0)
                    cout << map[i][j].chr << " ";
                else
                    cout << " " << " ";
            }
         
        cout << endl;
        }
    }   */

    player p;
    getPlayerInfo(p);
    playGame(p);

    deleteMap(map);
    return 0;
}