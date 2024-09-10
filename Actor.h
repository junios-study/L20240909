#pragma once
enum class EDepth
{
	Background = 0,
	Floor = 5,
	Actor = 10,
	UI = 20,
	Max
};

enum class ECollisionType
{
	NoCollision = 0,
	Collision = 1,
	Overlap = 2,
	Max
};

class AActor
{
public:
	AActor()
	{
		X = 10;
		Y = 10;
		Depth = EDepth::Background;
		CollisionType = ECollisionType::NoCollision;
	}

	virtual ~AActor()
	{

	}

	virtual void Tick(int KeyCode);
	void Render();

	//acessor
	inline int GetX()
	{
		return X;
	}

	void SetX(int NewX)
	{
		X = NewX;
	}

	inline int GetY()
	{
		return Y;
	}

	void SetY(int NewY)
	{
		Y = NewY;
	}

	inline char GetStaticMesh()
	{
		return StaticMesh;
	}

	void SetStaticMesh(char	NewStaticMesh)
	{
		StaticMesh = NewStaticMesh;
	}

	EDepth GetDepth()
	{
		return Depth;
	}

	static bool Compare(AActor* A, AActor* B)
	{
		return (int)A->GetDepth() < (int)B->GetDepth();
	}

	ECollisionType CollisionType;

	bool PredictCollision(int NewX, int NewY);



protected:
	int X;
	int Y;
	char StaticMesh;
	EDepth Depth;
};


