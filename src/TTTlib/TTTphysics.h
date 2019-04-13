#ifndef _TTT_PHYSICS_H_
#define _TTT_PHYSICS_H_

#define GRAVITY 1.0

#include <cmath>
#include <SDL2/SDL.h>
#include <iostream>

class TTTphysics
{
public:
	TTTphysics(int x, int y, int w, int h, float weight, float Cd, float density, float Cf, float friction, int jumpCount);

	void TestCollision(SDL_Rect *rect);
	void handle();
	void UpdatePosition();
	float GetMY()
	{
		return m_MomentumY;
	}
	float GetMX()
	{
		return m_MomentumX;
	}
	void SetMY(float MY)
	{
		m_MomentumY = MY;
	}
	void SetMX(float MX)
	{
		m_MomentumX = MX;
	}
	int GetPosX()
	{
		return m_PosX;
	}
	int GetPosY()
	{
		return m_PosY;
	}
	void SetPosX(int x)
	{
		m_PosX = x;
	}
	void SetPosY(int y)
	{
		m_PosY = y;
	}
	bool CanJump()
	{
		return (m_JumpCounter > 0);
	}
	void Jump()
	{
		m_JumpCounter--;
		m_Grounded = false;
	}
	bool Grounded()
	{
		return m_Grounded;
	}
	void UpdateRect(SDL_Rect rect)
	{
		m_Width = rect.w;
		m_Height = rect.h;
	}

	virtual ~TTTphysics();
private:
	int m_PosX;
	int m_PosY;
	int m_Width;
	int m_Height;

	float m_MomentumX;
	float m_MomentumY;
	float m_Weight;
	float m_Cd; //Drag coefficient
	float m_Density;
	float m_Cf; //Coeffiient of friction
	int m_FallingTimeStamp;
	int m_JumpCount;
	int m_JumpCounter;
	bool m_Grounded;
	float m_Friction;
};

#endif
