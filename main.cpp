#include <SDL.h>

#include "game_manager.h"

int main(int argc, char** argv)
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	GameManager gm;

	if (gm.init("(SDL) Geometry Dash", 1024, 720))
	{
		Uint32 frameStart;
		int frameTime;

		while (gm.isRunning())
		{
			frameStart = SDL_GetTicks();

			gm.eventHandle();
			gm.update();
			gm.draw();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}

		gm.destroy();
	}

	system("pause");

	return 0;
}