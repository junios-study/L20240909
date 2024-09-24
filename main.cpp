#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int agrc, char* agrv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	//SDL_Renderer* MyRenderer =  SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	bool bIsRunning = true;
	SDL_Event MyEvent;
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		}

		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(MyRenderer);

		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0, 0, 0xff);
		SDL_RenderDrawPoint(MyRenderer, 100, 100);

		SDL_Rect MyRect = { 100, 100, 100, 100 };
		SDL_RenderFillRect(MyRenderer, &MyRect);

		double PI = 3.1415926;
	
		for (int i = 0; i <= 360; i += 10)
		{
			int X1 = SDL_cos(i * PI / 180.0f) * 100;
			int Y1 = SDL_sin(i * PI / 180.0f) * 100;
			int X2 = SDL_cos( (i+10)  * PI / 180.0f) * 100;
			int Y2 = SDL_sin( (i+10) * PI / 180.0f) * 100;
			SDL_RenderDrawLine(MyRenderer, 400 + X1, 400 + Y1, 400 + X2, 400 + Y2);
		}



		SDL_RenderPresent(MyRenderer);
	}


	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}


//#include "Engine.h"
//
//int main()
//{
//	GEngine->LoadLevel("Level01.Map");
//
//	GEngine->Run();//
//	return 0;
//}