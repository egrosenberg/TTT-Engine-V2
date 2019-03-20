#include "EngineTester.h"

int main(int argc,  char *argv[])
{
	//Create our main program
	TTTprogram *program = new TTTprogram("TestWindow", WINDOW_W, WINDOW_H, 0);
	TTTcontroller *controller = new TTTcontroller(program);
	TTTsprite *image = new TTTsprite(program->GetRenderer(), "testSpriteSheet.bmp", 10, 10, 10, 231, 253);

	bool dragging = false;

	//Declare and initialize two variables to store our cursor offset from our selected sprite
	int offsetX = 0;
	int offsetY = 0;

	//As long as the window is there run this loop
	while (program->TestWindow() && controller->GetOpen())
	{
		//Temporary variables to store cursor location
		int cursorX = controller->GetCursorX();
                int cursorY = controller->GetCursorY();
		
		const char *input = controller->GetInput();
		if (input != 0)
		{
			std::cout << input << std::endl;
			//Check if input is a mouse up or down
			//If left click down, then make it so we are in dragging mode
			if (input [0] == 'L' && input [1] == 'M' && input [2] == 'D')
			{
				dragging = true;
				offsetX = image->GetPosX() - cursorX;
				offsetY = image->GetPosY() - cursorY; 
			}
			//Once the button is let go, release dragging mode
			else if (input [0] == 'L' && input [1] == 'M' && input [2] == 'U')
			{
				dragging  = false;
			}
		}
		//Clean the screen
		program->ClearToColor(255, 200, 255, 255);
		image->handle();
		program->handle();
		
		//If we are dragging, make it so that the sprite follows with the cursor
		if (dragging)
		{
			image->SetCoordinates(cursorX + offsetX, cursorY + offsetY);
		}
		SDL_Delay(1000/120);
	}
	
	delete program;
	delete controller;

	return 0;
}
