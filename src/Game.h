#ifndef __GAME_H__
#define __GAME_H__

class Game
{
private:
	//-������ ���� ������ �����ϴ� ������
	//- SDL_CreateWindow �Լ��� �̿��Ͽ� ����
	class SDL_Window* m_pWindow;
	
	//-������ ���¸� �����ϴ� ����ü
	//- SDL_CreateRenderer �Լ��� �̿��Ͽ� ����
	class SDL_Renderer* m_pRenderer;
	
	// while�� ����� ����
	bool m_bRunning; 

	



public:
	Game();
	~Game();
	/// <summary>
	/// �ʱ�ȭ�� �ϴ� �Լ�
	/// </summary>
	/// <param name="title"> exe�̸� </param>
	/// <param name="x"> : x��ǥ </param>
	/// <param name="y"> : y��ǥ </param>
	/// <param name="w"> : ���� </param>
	/// <param name="h"> : ���� </param>
	/// <returns> </returns>
	bool init(const char* title, int x, int y, int w, int h, unsigned __int32 flags);
	void render();
	bool update();
	bool is_Running();
	void clean();
};
		



#endif