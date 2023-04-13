#include "struct.h"
#include "console_settings.h"
#include "gameController.h"

#include <chrono>
#include <thread>

using namespace std;



int main()
{   
    initConsole(18, 11);





    player p;
    getPlayerInfo(p);

   
    playGame(p, 8, 8);




    return 0;
}