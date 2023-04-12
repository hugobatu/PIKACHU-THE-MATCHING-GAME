#include "gameView.h"
#include "console_settings.h"
#include "gameController.h"

#include <chrono>
#include <thread>

using namespace chrono;
using namespace std;

void gameTimer(int seconds) {
    auto start = high_resolution_clock::now(); // start timer
    auto end = start + seconds * duration_cast<std::chrono::seconds>(1s); // calculate end time

    while (high_resolution_clock::now() < end) { // loop until end time is reached
        auto remaining_time = duration_cast<std::chrono::seconds>(end - high_resolution_clock::now());
        cout << "Time remaining: " << remaining_time.count() << " seconds" << endl;
        this_thread::sleep_for(1s); // wait for 1 second
        system("cls");
    }

    cout << "Time's up!" << endl; // output when timer is finished
}

int main()
{   
    //SetConsoleOutputCP(65001);
    initConsole(18, 11);

    //generateForTesting(map);
    
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

    // Start the game function in the main thread
    playGame(p, 8, 10);

    // Wait for the timer thread to finish


    return 0;
}