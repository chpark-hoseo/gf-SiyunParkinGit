#include <SDL2/SDL.h>
#include <stdlib.h>

SDL_Window* g_pWindow = 0;
//-������ ���� ������ �����ϴ� ������
//- SDL_CreateWindow �Լ��� �̿��Ͽ� ����

SDL_Renderer* g_pRenderer = 0;
//-������ ���¸� �����ϴ� ����ü
//- SDL_CreateRenderer �Լ��� �̿��Ͽ� ����

bool g_bRunning = false; // while�� ����� ����

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

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) // SDL ���̺귯�� �ʱ�ȭ
    {

        g_pWindow = SDL_CreateWindow(title, x, y, w, h, flags); //�̸� ��ġ ũ�� �� flag�� ������ ����


        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0); //������ ����
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