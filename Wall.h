#pragma once
#include "Actor.h"
#include "Engine.h"

class AWall : public AActor
{
public:
	AWall()
	{
		Depth = EDepth::Actor;
		CollisionType = ECollisionType::Collision;
		Color = { 128, 128, 128, 0 };

		Surface = SDL_LoadBMP("Data/wall.bmp");
		Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, Surface);
	}

	virtual ~AWall()
	{

	}
};

