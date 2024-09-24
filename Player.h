#pragma once
#include "Actor.h"
#include "Engine.h"

class APlayer : public AActor
{
public:
	APlayer()
	{
		Depth = EDepth::Actor;
		CollisionType = ECollisionType::Overlap;

		Color = { 0, 255, 0, 0 };

		Surface = SDL_LoadBMP("Data/player.bmp");
		Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, Surface);
	}
	virtual ~APlayer()
	{

	}

	virtual void Tick(int KeyCode) override;
};

