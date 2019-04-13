#ifndef _TTT_SPRITE_H_
#define _TTT_SPRITE_H_

#include <SDL2\SDL.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

class TTTsprite
{
public:
	TTTsprite(SDL_Renderer *renderer, char *path, int frameCount, int x, int y, int w, int h, int srcW, int srcH, int offsetX, int offsetY, int spacing);
	
	void handle();
	void SetCoordinates(int x, int y);

	int GetPosX();
	int GetPosY();

	SDL_Rect GetRect()
	{
		return m_Rect;
	}
	SDL_Rect *GetRectPointer()
	{
		return &m_Rect;
	}
	void SetDirection(SDL_RendererFlip direction)
	{
		m_Direction = direction;
	}
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

	int m_OffsetX;
	int m_OffsetY;
	int m_Spacing;
	SDL_RendererFlip m_Direction;
};

#endif
