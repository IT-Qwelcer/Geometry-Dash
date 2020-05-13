#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SDL.h>
#include "map.h"

struct GameManager
{
	GameManager();
	~GameManager();

	bool init(const char* title, int width, int height);
	void destroy();

	static Vector2d getWindowSize();

	void setPlayerPosition(int x, int y);
	void createBlock(int iType, int x, int y);

	void eventHandle();
	void update();
	void draw();

	bool isRunning();

private:
	SDL_Window* m_pWin = NULL;
	SDL_Renderer* m_pRenderer = NULL;

	static int m_winWidth;
	static int m_winHeight;

	SDL_Event m_event;

	bool m_bRunning = false;

	Map m_map;
	EPlayer m_player;
	std::vector<EBlock> m_vcBlocks;
};

#endif