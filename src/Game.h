#ifndef __GAME_H__
#define __GAME_H__

class Game
{
private:
	//-윈도우 관련 정보를 저장하는 구조제
	//- SDL_CreateWindow 함수를 이용하여 생성
	class SDL_Window* m_pWindow;
	
	//-랜더링 상태를 포함하는 구조체
	//- SDL_CreateRenderer 함수를 이용하여 생성
	class SDL_Renderer* m_pRenderer;
	
	// while문 제어용 변수
	bool m_bRunning; 

	



public:
	Game();
	~Game();
	/// <summary>
	/// 초기화를 하는 함수
	/// </summary>
	/// <param name="title"> exe이름 </param>
	/// <param name="x"> : x좌표 </param>
	/// <param name="y"> : y좌표 </param>
	/// <param name="w"> : 넓이 </param>
	/// <param name="h"> : 높이 </param>
	/// <returns> </returns>
	bool init(const char* title, int x, int y, int w, int h, unsigned __int32 flags);
	void render();
	bool update();
	bool is_Running();
	void clean();
};
		



#endif