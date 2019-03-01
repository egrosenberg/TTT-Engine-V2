#ifndef _TTTPROGRAM_H_
#define  _TTTPROGRAM_H_

#include <iostream>
#include <SDL2\SDL.h>

class TTTprogram
{
private:
	char *m_Title;
	SDL_Window *m_Window;
	SDL_Renderer *m_Renderer;
public:
	TTTprogram (const char *title, int w, int h, Uint32 flags);

	SDL_Renderer* getRenderer()
		{return m_Renderer;}

	bool TestWindow();

	virtual  ~TTTprogram();
};

#endif
