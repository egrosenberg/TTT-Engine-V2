#include "Engine-Tester.h"

int main()
{
	TTTprogram program = new TTTprogram("TestWindow", WINDOW_W, WINDOW_H, 0);
	
	while (program->TestWindow())
	{
		SDL_RenderClear(program->getRenderer());		

		SDL_RenderPresent (program->getRenderer());

		SDL_Delay(1000/60);
	}
	
	return 0;
}
