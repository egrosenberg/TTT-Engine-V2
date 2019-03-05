#include "TTTprogram.h"

TTTprogram::TTTprogram(const char *title, int w, int h, Uint32 flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	}
	else
	{
		std::cout << "ERROR NO INIT\n";
	}
}

void TTTprogram::ClearToColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
        /* Select the color for drawing. It is set to red here. */
        SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);

        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(m_Renderer);	
}

bool TTTprogram::TestWindow()
{
	//If the window doesn't exist, then it doesn't exist
	if (m_Window == NULL)
	{
		std::cerr << "Failed to init window: error " << SDL_GetError() << '\n';
		return false;
	}
	else
	{
		return true;
	}
}

void TTTprogram::handle()
{
	//Render the current screen
	SDL_RenderPresent(m_Renderer);
}

TTTprogram::~TTTprogram()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
}
