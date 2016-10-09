#pragma once
#include "GameObject.h"
class Paddle : public GameObject
{

	
public:
	bool isLeft;
	
	void ConstrainPosition();
	void MoveDown();
	void MoveUp();


	virtual void Move();
	virtual void InitPosition();
	Paddle();
	~Paddle();
	friend class Ball;
};

