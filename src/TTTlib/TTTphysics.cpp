#include "TTTphysics.h"

TTTphysics::TTTphysics(int x, int y, int w, int h, float weight, float Cd, float density, float Cf)
{
	m_PosX = x;
	m_PosY = y;
	m_Width = w;
	m_Height = h;

	m_MomentumX = 0;
	m_MomentumY = 9.8;
	m_Weight = weight;
	m_Cd = Cd;
	m_Density = density;
	m_Cf = Cf;
	
	m_Falling = false;
	m_Rising = false;
}

void TTTphysics::handle()
{
	if (m_MomentumY == 0)
	{
		if (!m_Falling)
		{
			m_FallingTimeStamp = SDL_GetTicks();
		}
		else
		{
			m_Falling = true;
		}
	}
	float weight = m_Weight * 9.8;
	float drag = m_Cd * ((m_Density * pow(((weight / m_Weight) + 1) * m_MomentumY, 2))/2) * (m_Width * 0.1) * (m_Width * 0.1);
	if (drag > weight)
	{
		drag = weight;
	}
	float acceleration = (weight - drag) / m_Weight;

	m_MomentumY = m_MomentumY + (acceleration * 0.12);
}

TTTphysics::~TTTphysics()
{

}
