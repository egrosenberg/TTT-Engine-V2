#include "TTTphysics.h"

TTTphysics::TTTphysics(int x, int y, int w, int h, float weight, float Cd, float density, float Cf, float friction, int jumpCount)
{
	m_PosX = x;
	m_PosY = y;
	m_Width = w;
	m_Height = h;

	m_MomentumX = 0;
	m_MomentumY = 0;
	m_Weight = weight;
	m_Cd = Cd;
	m_Density = density;
	m_Cf = Cf;

	m_Friction = friction;
	m_JumpCount = jumpCount;
	m_JumpCounter = m_JumpCount;
	m_Grounded = false;
}

void TTTphysics::TestCollision(SDL_Rect *rect)
{
	bool over = false;
	if ((m_PosX < rect->x + rect->w) && (m_PosX + m_Width > rect->x))
	{
		over = true;
	}
	bool inLine = false;
	if ((m_PosY + m_Height > rect->y) && (m_PosY < rect->y + rect->h))
	{
		inLine = true;
	}
	//Test for hitting on Y
	if ((((m_PosY + m_MomentumY + m_Height > rect->y) && (m_PosY < rect->y)) || ((m_PosY + m_MomentumY < rect->y + rect->h) && m_PosY > rect->y)) && over)
	{
		m_Grounded = false;
		//If we are in here it means we are hitting on the x axis
		//Check which side we are on
		if (m_PosY < rect->y) // we are on the Top
		{
			//Set the position to right on top of
			m_MomentumY = rect->y - (m_PosY + m_Height);
			m_JumpCounter = m_JumpCount;
			m_Grounded = true;
		}
		else
		{
			//Set the position Right below
			m_MomentumY = m_PosY - (rect->y + rect->h);
		}
		std::cout << "Y\n";
	}
	//we are hitting from the left
	if ((m_PosX + m_Width + m_MomentumX > rect->x) && (m_PosX < rect->x) && inLine)
	{
		m_MomentumX = rect->x - (m_PosX + m_Width);
		std::cout << "LEFT\n";
		m_JumpCounter = 1;
	}
	//we are hitting from the right
	else if ((m_PosX + m_MomentumX < rect->x + rect->w) && (m_PosX > rect->x) && inLine)
	{
		m_MomentumX = m_PosX - (rect->x + rect->w);
		std::cout << "RIGHT\n";
		m_JumpCounter = 1;
	}
}

void TTTphysics::handle()
{
	float weight = m_Weight * GRAVITY;
	float drag = m_Cd * m_Density * ((pow(m_MomentumY, 2) * pow(m_Width * 0.0254, 2)) / 2);
	if (drag > weight)
	{
		//drag = weight;
	}
	
	if (m_MomentumY < 0)
	{
		drag *= -1;
	}

	float acceleration = (weight - drag) / m_Weight;

	m_MomentumY = m_MomentumY + (acceleration * 0.12);

	if (m_MomentumX > 0)
	{
		if (m_Friction > m_MomentumX)
			m_MomentumX = 0;
		else
			m_MomentumX -= m_Friction;
	}
	if (m_MomentumX < 0)
        {
                if (m_Friction > fabs(m_MomentumX))
                        m_MomentumX = 0;
                else
                        m_MomentumX += m_Friction;
        }
}

void TTTphysics::UpdatePosition()
{
	m_PosX += m_MomentumX;
	m_PosY += m_MomentumY;
}

TTTphysics::~TTTphysics()
{

}
