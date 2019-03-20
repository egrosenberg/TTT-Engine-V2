#include "TTTsprite.h"
#include <iostream>

TTTsprite::TTTsprite(SDL_Renderer *renderer, char *path, int frameCount, int x, int y, int w, int h)
{
	m_CurrentFrame = 1;
	m_FrameCount = frameCount;

	m_Path = path;
	m_Renderer = renderer;
	
	m_Surface = SDL_LoadBMP(m_Path);
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);
	m_Rect.x = x; 
	m_Rect.y = y; 
	m_Rect.w = w; 
	m_Rect.h = h;
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
	m_CurrentFrame = (SDL_GetTicks() / 100) % m_FrameCount;

	std::cout << "Current Frame " << m_CurrentFrame << '\n';

	SDL_Rect tempSrcRect = m_Rect;
	tempSrcRect.x = m_CurrentFrame * m_Rect.w;
	tempSrcRect.y = 0;

	SDL_RenderCopy (m_Renderer, m_Texture, &tempSrcRect, &m_Rect);
}

TTTsprite::~TTTsprite()
{
	SDL_DestroyTexture(m_Texture);
	SDL_FreeSurface(m_Surface);
}
