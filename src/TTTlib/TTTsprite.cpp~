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
	//strncpy (currentPath, "1.bmp", 10);
	
	//Get size of both strings and make a memory block large enough to store both
	size_t currentPathSize = strlen(currentPath);
	size_t appendPathSize = strlen(tempAppend);
	//size of both strings combined
	size_t pathSize = sizeof(char) * (currentPathSize + appendPathSize + 1); //+1 is for a null terminator at the end

	std::cout << "currPathSize: " << currentPathSize << '\n';
	std::cout << "appendPathSize: " << appendPathSize << '\n';

	//allocate memory for our new path string
	char *tempPath = (char*)malloc(pathSize);
	//copy data from currentpath into the first half of tempPath
	memcpy (tempPath, currentPath, currentPathSize);
	//do the same for the append
	//we add currentPathSize so we dont just overwrite what we just did
	memcpy (tempPath + currentPathSize, tempAppend, appendPathSize);
	//Set the last char to a null terminator
	tempPath [currentPathSize + appendPathSize] = '\0';

	currentPath = tempPath;
	std::cout << currentPath;

	//free the memory from our temp string
	free (tempPath);
	

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
	char *currentPath = m_Path;
        char *tempAppend = ".bmp";
	char *tempNum = (char*)std::to_string(m_CurrentFrame).c_str();
        //Get size of both strings and make a memory block large enough to store both
        size_t currentPathSize = strlen(currentPath);
        size_t numSize = strlen(tempNum);
	size_t appendPathSize = strlen(tempAppend);
        //size of both strings combined
        size_t pathSize = sizeof(char) * (currentPathSize + appendPathSize + numSize + 1); //+1 is for a null terminator at the end
        //allocate memory for our new path string
        char *tempPath = (char*)malloc(pathSize);
        //copy data from currentpath into the first half of tempPath
        memcpy (tempPath, currentPath, currentPathSize);
	//do the same for the number
        memcpy (tempPath + currentPathSize, tempNum, numSize);
        //do the same for the append
        memcpy (tempPath + currentPathSize + numSize, tempAppend, appendPathSize); 
        //Set the last char to a null terminator
        tempPath [currentPathSize + appendPathSize + numSize + 1] = '\0';
        std::cout << tempPath;
	
	m_Surface = SDL_LoadBMP(tempPath);
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);

	SDL_RenderCopy (m_Renderer, m_Texture, NULL, &m_Rect);

	m_CurrentFrame++;

        if (m_CurrentFrame > m_FrameCount)
        {                                                                                                           
                m_CurrentFrame = 1;                                                                                   
        }

        //free the memory from our temp string
	free (tempPath);
}

TTTsprite::~TTTsprite()
{
	SDL_DestroyTexture(m_Texture);
	SDL_FreeSurface(m_Surface);
}
