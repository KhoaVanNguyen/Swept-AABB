#pragma once
#include "GTexture.h"
class GameObject : public GTexture
{
protected:

	virtual void Move();
	virtual void InitPosition();
public:
	int x, y;
	int width, height;
	int movex, movey;

	void SetPosition(int, int);
	void SetVelocity(int, int);
	void SetSize(int, int);
	
	// getter - setter
	int X();
	int Y();
	int VelX();
	int VelY();
	int Width();
	int Height();
	RECT GetRect();
	void Draw();
	GameObject();
	//void Init(char* _fileName, int cols = 1, int rows = 1, int count = 1);
	//GameObject(char*);
	~GameObject();

	friend int CheckCollision(GameObject, GameObject);
};

