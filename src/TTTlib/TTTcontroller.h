#ifndef _TTT_CONTROLLER_
#define _TTT_CONTROLLER_

#include <SDL2/SDL.h>
#include "TTTprogram.h"

class TTTcontroller
{
public:
	TTTcontroller(TTTprogram *program);
	bool GetOpen();
	const char *GetInput();
	int GetCursorX();
	int GetCursorY();
	virtual ~TTTcontroller();
private:
	bool m_IsOpen;
	SDL_Event m_Event;
	TTTprogram *m_Program;
};

#endif
