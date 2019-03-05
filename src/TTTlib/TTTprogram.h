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

	SDL_Window *GetWindow()
		{return m_Window;}
	SDL_Renderer *GetRenderer()
		{return m_Renderer;}
	void ClearToColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	bool TestWindow();
	void handle();

	virtual  ~TTTprogram();
};

#endif
