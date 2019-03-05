#include "TTTsprite.h"
#include <iostream>

TTTsprite::TTTsprite(SDL_Renderer *renderer, char *path, int frameCount, int x, int y, int w, int h)
{
	m_CurrentFrame = 1;
	m_FrameCount = frameCount;

	m_Path = path;
	m_Renderer = renderer;
	
	char *currentPath = m_Path;
	std::cout << currentPath << '\n';
	char *tempAppend = "1.bmp";
	std::cout<< tempAppend << '\n';
	strncpy (currentPath, tempAppend, 10);
	
	std::cout << currentPath;

	m_Surface = SDL_LoadBMP(currentPath);
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

void TTTsprite::handle()
{

	//char array to hold temp number
	//char *buffer;
	//itoa (m_CurrentFrame, buffer, 10);
	char *currentPath = m_Path;
	//strncpy (currentPath, buffer, 10);
	//strncpy (currentPath, ".bmp", 10);
	
	m_Surface = SDL_LoadBMP(currentPath);
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);

	SDL_RenderCopy (m_Renderer, m_Texture, NULL, &m_Rect);

	m_CurrentFrame++;

        if (m_CurrentFrame > m_FrameCount)
        {                                                                                                           
                m_CurrentFrame = 1;                                                                                   
        }
}

TTTsprite::~TTTsprite()
{
	SDL_DestroyTexture(m_Texture);
	SDL_FreeSurface(m_Surface);
}
