#pragma once
#include <vector>
#include "SDL.h"

class AActor;


class Engine
{
private:
	Engine();




public:
	void Init();
	void Term();

	static Engine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new Engine();
		}

		return Instance;
	}


	virtual ~Engine();

protected:
	void Input();
	void Tick();
	void Render();
	void BeginPlay();


	std::vector<AActor*> Actors;
	int KeyCode;
	bool bIsRunning;

	bool bWillStop;

	static Engine* Instance;

public:
	void Run();

	void SpawnActor(AActor* SpawnedActor);

	void LoadLevel(const char* MapName);

	const std::vector<class AActor*>& GetActors()
	{
		return Actors;
	}

	void Stop()
	{
		bWillStop = true;
	}

	struct SDL_Window* MyWindow;
	struct SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	Uint64 DeltaSeconds;

	inline const Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; }

};

#define GEngine			Engine::GetInstance()

