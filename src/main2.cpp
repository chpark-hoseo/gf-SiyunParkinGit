#include <SDL2/SDL.h>
#include <stdlib.h>
#include "Game.h"



int main(int argc, char* args[])
{

    Game* game = new Game();


    if (game->init("Setting up SDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
    {    }
    else
    {
        return 1;
    }
      
    while (game->is_Running())
    {
        game->render();
        game->update();
    }

    delete game;

    SDL_Quit();

    return 0;
}

