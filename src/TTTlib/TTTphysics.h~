#ifndef _SRC_TTTLIB_H_
#define _SRC_TTTLIB_H_

#include <cmath>
#include <SDL2/SDL.h>

class TTTphysics
{
public:
	TTTphysics(int x, int y, int w, int h, float weight, float Cd, float density, float Cf);

	void handle();

	float GetMY()
	{
		return m_MomentumY;
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
	bool m_Falling;
	bool m_Rising;
};

#endif
