#include "TTTsprite.h"
#include <iostream>

TTTsprite::TTTsprite(SDL_Renderer *renderer, char *path, int frameCount, int x, int y, int w, int h, int srcW, int srcH, int offsetX, int offsetY, int spacing)
{
	m_CurrentFrame = 1;
	m_FrameCount = frameCount;

	m_Path = path;
	m_Renderer = renderer;

	m_srcW = srcW;
	m_srcH = srcH;
	
	m_Surface = SDL_LoadBMP(m_Path);
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);
	m_Rect.x = x; 
	m_Rect.y = y; 
	m_Rect.w = w; 
	m_Rect.h = h;

	m_OffsetX = offsetX;
	m_OffsetY = offsetY;
	m_Spacing = spacing;
	m_Direction = SDL_FLIP_HORIZONTAL;
}

int TTTsprite::GetPosX()
{
	return m_Rect.x;
}

int TTTsprite::GetPosY()
{
	return m_Rect.y;
}



void TTTsprite::SetCoordinates(int x, int y)
{
	if (x != NULL)
	{
		m_Rect.x = x;
	}
	if (y != NULL)
	{
		m_Rect.y = y;
	}
}

clock_t previousClock = clock();

void TTTsprite::handle()
{
	m_CurrentFrame = (SDL_GetTicks() / 166) % m_FrameCount;


	SDL_Rect tempSrcRect;
	tempSrcRect.w = m_srcW;
	tempSrcRect.h = m_srcH;
	tempSrcRect.x = (m_CurrentFrame * m_srcW) + m_OffsetX + (m_CurrentFrame * m_Spacing);
	tempSrcRect.y = m_OffsetY;

	SDL_RenderCopyEx (m_Renderer, m_Texture, &tempSrcRect, &m_Rect, 0, NULL, m_Direction);
}

TTTsprite::~TTTsprite()
{
	SDL_DestroyTexture(m_Texture);
	SDL_FreeSurface(m_Surface);
}
