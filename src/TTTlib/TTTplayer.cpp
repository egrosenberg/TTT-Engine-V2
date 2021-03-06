#include "TTTplayer.h"

TTTplayer::TTTplayer(TTTsprite *animations [], TTTphysics *physics, TTTcontroller *controller, TTTsprite *terrain [])
{
	for (int currentState = 0; currentState < TTT_PlayerState::STATE_COUNT; currentState++)
	{
		m_Animations [currentState] = animations [currentState];
	}
	m_Physics = physics;
	m_Controller = controller;
	m_CurrentState = TTT_PlayerState::IDLE;
	for (int n = 0; n  < 10; n++)
	{
		m_Terrain [n] = terrain [n]->GetRectPointer();
	}
	m_Direction = 'L';
	m_TurnTime = 0;
}

int velocity = 7;
void TTTplayer::handle()
{
	const char *input = m_Controller->GetInput();
        if (input != 0)
        {
                std::cout << input << '\n';
                if (strcmp(input, "Up") == 0)
                {
	                if (m_Physics->CanJump())
                        {
                                m_Physics->SetMY(-5);
                                m_Physics->Jump();
                        }
                        std::cout << "Up\n";
                }
                if (m_Controller->GetKeyState(SDL_SCANCODE_DOWN))
                {
                //      physics->SetMY(velocity);
                        std::cout << "Down\n";
                }
                //if (controller->GetKeyState(SDL_SCANCODE_LEFT))
                //{
        	//      physics->SetMX(-velocity);
                //      std::cout << "Left\n";
                //}
                //if (controller->GetKeyState(SDL_SCANCODE_RIGHT))
                //{
                //      physics->SetMX(velocity);
                //      std::cout << "Right\n";
                //}
        }

	if (m_Controller->GetKeyState(SDL_SCANCODE_LEFT))
        {
                m_Physics->SetMX(-velocity);
                //if (m_Physics->Grounded())
                //{
                        m_Animations [m_CurrentState]->SetDirection(SDL_FLIP_NONE);
                //}
		m_CurrentState = TTT_PlayerState::RUN;
                std::cout << "Left\n";
		if (m_Direction == 'R')
                {
			m_TurnTime = (float)clock()/CLOCKS_PER_SEC;
                }
		m_Direction = 'L';
        }
	else if (m_Controller->GetKeyState(SDL_SCANCODE_RIGHT))
        {
                m_Physics->SetMX(velocity);
                //if (m_Physics->Grounded())
                //{
                      m_Animations [m_CurrentState]->SetDirection(SDL_FLIP_HORIZONTAL);
                
		//}
		m_CurrentState = TTT_PlayerState::RUN;
                std::cout << "Right\n";
		if (m_Direction == 'L')
		{
			m_TurnTime = (float)clock()/CLOCKS_PER_SEC;
		}
		m_Direction = 'R';
        }
	else
	{
		m_CurrentState = TTT_PlayerState::IDLE;
	}
	if ((float)clock()/CLOCKS_PER_SEC - m_TurnTime < 0.5)
        {
//                m_CurrentState = TTT_PlayerState::TURNING;
        }
	m_Physics->UpdateRect(m_Animations [m_CurrentState]->GetRect());
	m_Physics->handle();
	for (int n = 0; n < 10; n++)
        {
                m_Physics->TestCollision(m_Terrain [n]);
        }
	if (!m_Physics->Grounded())
	{
		m_CurrentState = TTT_PlayerState::JUMP;
	}
	m_Physics->UpdatePosition();

        m_Animations [m_CurrentState]->SetCoordinates(m_Physics->GetPosX(), m_Physics->GetPosY());
        //m_Animations [m_CurrentState]->SetCoordinates(NULL, m_Animations [m_CurrentState]->GetPosY() + m_Physics->GetMY());
        //std::cout << physics->GetMY() << '\n';
	m_Animations [m_CurrentState]->handle();
}

TTTplayer::~TTTplayer()
{

}
