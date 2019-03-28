#ifndef _TTT_SPRITE_H_
#define _TTT_SPRITE_H_

#include <SDL2\SDL.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

class TTTsprite
{
public:
	TTTsprite(SDL_Renderer *renderer, char *path, int frameCount, int x, int y, int w, int h, int srcW, int srcH);
	
	void handle();
	void SetCoordinates(int x, int y);

	int GetPosX();
	int GetPosY();

	virtual ~TTTsprite();

private:
	SDL_Renderer *m_Renderer;
	SDL_Surface *m_Surface;
	SDL_Texture *m_Texture;
	SDL_Rect m_Rect;
	int m_srcW;
	int m_srcH;
	
	int m_FrameCount;
	int m_CurrentFrame;
	char *m_Path;
};

#endif
