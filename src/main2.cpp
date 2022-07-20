#include <SDL2/SDL.h>
#include <stdlib.h>

SDL_Window* g_pWindow = 0;
//-윈도우 관련 정보를 저장하는 구조제
//- SDL_CreateWindow 함수를 이용하여 생성

SDL_Renderer* g_pRenderer = 0;
//-랜더링 상태를 포함하는 구조체
//- SDL_CreateRenderer 함수를 이용하여 생성

bool g_bRunning = false; // while문 제어용 변수

bool init(const char* title, int x, int y, int w, int h, Uint32 flags);
void render();
bool update();

int main(int argc, char* args[])
{

    if (init("Setting up SDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1;
    }
      
    while (g_bRunning)
    {
        render();
        update();
    }

   
    SDL_Quit();

    return 0;
}

bool init(const char* title, int x, int y, int w, int h, Uint32 flags) {

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) // SDL 라이브러리 초기화
    {

        g_pWindow = SDL_CreateWindow(title, x, y, w, h, flags); //이름 위치 크기 및 flag로 윈도우 생성


        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0); //랜더러 생성
        }
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
        return true;
    }
    else
    {
        return false;
    }
}

void render() {

    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);

}

bool update() {
    SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);

    return true;
}