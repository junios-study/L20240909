#include "Player.h"
#include "Engine.h"


void APlayer::Tick(int KeyCode)
{
	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		SDL_Keycode MyKeyCode = GEngine->MyEvent.key.keysym.sym;

		if (MyKeyCode == SDLK_w || MyKeyCode == SDLK_UP)
		{
			if (PredictCollision(X, Y - 1))
			{
				Y--;
			}
		}
		if (MyKeyCode == SDLK_a || MyKeyCode == SDLK_LEFT)
		{
			if (PredictCollision(X - 1, Y))
			{
				X--;
			}
		}
		if (MyKeyCode == SDLK_s || MyKeyCode == SDLK_DOWN)
		{
			if (PredictCollision(X, Y + 1))
			{
				Y++;
			}
		}
		if (MyKeyCode == SDLK_d || MyKeyCode == SDLK_RIGHT)
		{
			if (PredictCollision(X + 1, Y))
			{
				X++;
			}
		}
	}
}

void APlayer::Render()
{
	//AActor::Render();
	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	SDL_Rect PositionRect = { X * SizeX, Y * SizeY, SizeX, SizeY };
	if (Texture == nullptr)
	{
		SDL_RenderFillRect(GEngine->MyRenderer, &PositionRect);
	}
	else
	{
		int Width = Surface->w;
		int Height = Surface->h;

		SDL_Rect SourceRect = { 0, 0, Width / 5, Height / 5 };
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &PositionRect);
	}
}
