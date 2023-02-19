#include <iostream>
#include <tuple>

#include "engine/gameManager/GameManager.hpp"
#include "engine/gameManager/GameData.hpp"
#include "engine/utils/window.hpp"

int main(int argc, char *argv[])
{
    // int* curr_res = Gengine::getCurrentResolution();
    
    struct GameData gameData = {DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "GEingine"};

    Gengine::GameManager* gameManager = new Gengine::GameManager(gameData);
 
    gameManager->init();

    return EXIT_SUCCESS;
}