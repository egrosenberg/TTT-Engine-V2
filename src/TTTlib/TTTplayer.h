#ifndef _TTT_PLAYER_H_
#define _TTT_PLAYER_H_

#include <ctime>
#include <chrono>
#include <SDL2\SDL.h>
#include "TTTsprite.h"
#include "TTTphysics.h"
#include "TTTcontroller.h"

class TTTplayer
{
public:
	enum TTT_PlayerState
	{
		IDLE = 0,
		RUN,
		JUMP,
		TURNING,
		STATE_COUNT
	};
	void handle();
	void TestCollision (SDL_Rect *rect)
	{
		m_Physics->TestCollision(rect);
	}

	TTTplayer(TTTsprite *animations [], TTTphysics *physics, TTTcontroller *controller, TTTsprite *terrain []);
	virtual ~TTTplayer();
private:
	TTTsprite *m_Animations [TTT_PlayerState::STATE_COUNT];
	TTTphysics *m_Physics;
	TTTcontroller *m_Controller;

	SDL_Rect *m_Terrain [10];

	TTT_PlayerState m_CurrentState;
	float m_TurnTime;
	char m_Direction;
};

#endif
