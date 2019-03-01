#include "TTTprogram.h"

TTTprogram::TTTprogram(const char *title, int width, int height, Uint32 flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	}
	else
	{
		std::cout << "ERROR NO INIT\n";
	}
}

bool TTTprogram::TestWindow()
{
	if (m_Window == NULL)
	{
		std::cerr << "Failed to init window!\n";
		return false;
	}
	else
		return true;
}

TTTprogram::~TTTprogram()
{

}
