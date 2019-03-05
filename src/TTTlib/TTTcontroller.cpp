#include "TTTcontroller.h"
#include <iostream>

TTTcontroller::TTTcontroller(TTTprogram *program)
{
	m_Program = program;
	m_IsOpen = true;
}

bool TTTcontroller::GetOpen()
{
	return m_IsOpen;
}

int TTTcontroller::GetCursorX()
{
	int temp = 0;
	SDL_GetMouseState(&temp, NULL);
	return temp;
}

int TTTcontroller::GetCursorY()
{
	int temp = 0;
        SDL_GetMouseState(NULL, &temp);
        return temp;
}

const char* TTTcontroller::GetInput()
{
	if (SDL_PollEvent(&m_Event))
	{
		if (m_Event.type == SDL_KEYDOWN)
			return SDL_GetKeyName(m_Event.key.keysym.sym);
		if (m_Event.type == SDL_MOUSEBUTTONDOWN)
		{
			switch (m_Event.button.button)
			{
				case SDL_BUTTON_LEFT:
					return "LMD";
					break;
				case SDL_BUTTON_RIGHT:
					return "RMD";
					break;
			}
		}
		else if (m_Event.type == SDL_MOUSEBUTTONUP)
                {
                        switch (m_Event.button.button)
                        {
                                case SDL_BUTTON_LEFT:
                                        return "LMU";
                                        break;
                                case SDL_BUTTON_RIGHT:
                                        return "RMU";
                                        break;
                        }
                }
		else if (m_Event.type == SDL_QUIT)
		{
			SDL_DestroyWindow(m_Program->GetWindow());
			m_IsOpen = false;
			return 0;
		}
		else
			return 0;
	}
	else
		return 0;	
}

TTTcontroller::~TTTcontroller()
{

}
