#pragma once
#include "GTexture.h"
#include "Global.h"


class GameObject : public GTexture
{
protected:

	virtual void Move();
	virtual void InitPosition();
public:
	NORMAL_DIRECTION direction;
	int x, y;
	int w, h;
	int vx, vy;
	void SetPosition(int, int);
	void SetVelocity(int, int);
	void SetSize(int, int);
	
	void OnCollision(NORMAL_DIRECTION);
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
	float SweptAABB(GameObject b1, GameObject b2, float &normalx, float &normaly);
};

