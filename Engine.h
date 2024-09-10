#pragma once
#include <vector>

class AActor;


class Engine
{
private:
	Engine()
	{
		KeyCode = 0;
		bIsRunning = true;
		bWillStop = false;
	}

public:
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

};

#define GEngine			Engine::GetInstance()

