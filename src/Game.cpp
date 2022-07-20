
#include "Game.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

Game::Game()
{
	m_pWindow = 0;
	m_pRenderer = 0;
	m_bRunning = false;
}

Game::~Game()
{
    clean();
}

bool Game::init(const char* title, int x, int y, int w, int h, unsigned __int32 flags)
{
  

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) // SDL 라이브러리 초기화
    {

        m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags); //이름 위치 크기 및 flag로 윈도우 생성


        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); //랜더러 생성
        }
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
        m_bRunning = true;
        return true;
    }
    else
    {
        m_bRunning = false;
        return false;
    }

}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

bool Game::update()
{
    SDL_SetRenderDrawColor(m_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);

    return true;
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}


bool Game::is_Running()
{
    return m_bRunning;
}
