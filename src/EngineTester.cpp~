#include "EngineTester.h"

int main(int argc,  char *argv[])
{
	//Create our main program
	TTTprogram *program = new TTTprogram("TestWindow", WINDOW_W, WINDOW_H, 0);
	TTTcontroller *controller = new TTTcontroller(program);
	TTTsprite *animations [5];
	animations [TTTplayer::TTT_PlayerState::RUN] = new TTTsprite(program->GetRenderer(), "marioSpriteSheet.bmp", 3, 0, 1000, 51, 84, 17, 28, 5, 81, 12);
	animations [TTTplayer::TTT_PlayerState::IDLE] = new TTTsprite(program->GetRenderer(), "marioSpriteSheet.bmp", 1, 0, 1000, 51, 84, 17, 28, 5, 81, 12);
	animations [TTTplayer::TTT_PlayerState::JUMP] = new TTTsprite(program->GetRenderer(), "marioSpriteSheet.bmp", 1, 0, 1000, 51, 84, 17, 28, 5 + ((17+12)*3) + 2, 81, 12);
	animations [TTTplayer::TTT_PlayerState::TURNING] = new TTTsprite(program->GetRenderer(), "marioSpriteSheet.bmp", 1, 0, 1000, 51, 84, 17, 28, 158-5, 81, 12);;
	animations [TTTplayer::TTT_PlayerState::STATE_COUNT] = NULL;

	TTTphysics *physics = new TTTphysics(0, 0, animations [0]->GetRect().w, animations [0]->GetRect().h, 20, 0.47, 0.6, 5, 3, 1);

	int rockCount = 10;
	TTTsprite *rocks [rockCount];
	bool dragging = false;

	physics->SetMX(0);
	physics->SetMY(0);

	//Declare and initialize two variables to store our cursor offset from our selected sprite
	int offsetX = 0;
	int offsetY = 0;
	//an int to declare our speed when we use the arrow keys
	int velocity = 7;

	for (int n = 0; n < 9; n++)
	{
		rocks [n] = new TTTsprite(program->GetRenderer(), "rock.bmp", 1, 10 + (n*300), 500 - (n*100), 128, 86, 640, 426, 0, 0, 0);
	}

	rocks [9] = new TTTsprite(program->GetRenderer(), "rock.bmp", 1, 0, 600, 128 * 10, 400/*86*/, 640, 426, 0, 0, 0);

	TTTplayer *player = new TTTplayer(animations, physics, controller, rocks);
	
	//As long as the window is there run this loop
	while (program->TestWindow() && controller->GetOpen())
	{
		//Temporary variables to store cursor location
		int cursorX = controller->GetCursorX();
                int cursorY = controller->GetCursorY();
		
		//physics->handle();
		//physics->UpdatePosition();
		//image->SetCoordinates(physics->GetPosX(), physics->GetPosY());
		//image->SetCoordinates(NULL, image->GetPosY() + physics->GetMY());
		//std::cout << physics->GetMY() << '\n';
		//Clean the screen
		program->ClearToColor(255, 255, 255, 255);
		for (int n = 0; n < rockCount; n++)
                {
                        rocks [n]->handle();
                };
		player->handle();
		//image->handle();
		program->handle();
		
		//if (physics->GetPosY() > 900)
		//{
		//	physics->SetPosY(10);
		//	physics->SetPosX(10);
		//}

		SDL_Delay(1000/120);
	}

	delete physics;
	for (int n = 0; n < 5; n++)
	{
		delete animations [n];
	}
	delete program;
	delete controller;

	return 0;
}
