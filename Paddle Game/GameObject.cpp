#include "GameObject.h"
#include <limits>
#include <algorithm>
GameObject::GameObject() {

}
//GameObject::GameObject(char *filename) {
//
//	GTexture::GTexture(filename, 1, 1, 1);
//}
//void GameObject::Init(char* _fileName, int cols, int rows, int count)
//{
//	GTexture::Init(_fileName, 1, 1, 1);
//}
void GameObject::SetPosition(int newX, int newY) {
	x = newX;
	y = newY;
}
void GameObject::SetVelocity(int newX, int newY) {
	vx = newX;
	vy = newY;
}
void GameObject::SetSize(int newWidth, int newHeight) {
	w = newWidth;
	h = newHeight;
}


void GameObject::Draw() {
		D3DXVECTOR3 position(0, 0, 0);
		position.x = this->x;
		position.y = this->y;
		G_SpriteHandler->Draw(this->Texture,
			NULL,
			NULL,
			&position,
			D3DCOLOR_XRGB(255, 255, 255));
}

GameObject::~GameObject()
{
}
void GameObject::Move() {

}
void GameObject::InitPosition() {

}

int GameObject::X() {
	return x;
}
int GameObject::Y() {
	return y;
}
int GameObject::VelX() {
	return vx;
}
int GameObject::VelY() {
	return vy;
}
int GameObject::Width() {
	return w;
}
int GameObject::Height() {
	return h;
}


RECT GameObject::GetRect()
{
	RECT rResult;
	rResult.top = y;
	rResult.left = x;
	rResult.bottom = y + h;
	rResult.right = x + w;
	return rResult;
}

int CheckCollision(GameObject obj1, GameObject obj2)
{
	int centerx, centery;
	centerx = obj1.x + obj1.w / 2;
	centery = obj1.y + obj1.h / 2;
	if (obj1.x < obj2.x + obj2.w &&
		obj1.x + obj1.w > obj2.x &&
		obj1.y < obj2.y + obj2.h &&
		obj1.h + obj1.y > obj2.y)
	{
		if ((centery <= obj2.y) || (centery >= obj2.y + obj2.h))
			return 1;
		else if ((centerx <= obj2.x) || (centerx <= obj2.x + obj2.w))
			return 2;
	}
	return 0;
}
float GameObject::SweptAABB(GameObject b1, GameObject b2, float &normalx, float&normaly) {
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1.vx > 0.0f)
	{
		xInvEntry = b2.x - (b1.x + b1.w);
		xInvExit = (b2.x + b2.w) - b1.x;
	}
	else
	{
		xInvEntry = (b2.x + b2.w) - b1.x;
		xInvExit = b2.x - (b1.x + b1.w);
	}

	if (b1.vy > 0.0f)
	{
		yInvEntry = b2.y - (b1.y + b1.h);
		yInvExit = (b2.y + b2.h) - b1.y;
	}
	else
	{
		yInvEntry = (b2.y + b2.h) - b1.y;
		yInvExit = b2.y - (b1.y + b1.h);
	}
	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1.vx;
		xExit = xInvExit / b1.vx;
	}

	if (b1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1.vy;
		yExit = yInvExit / b1.vy;
	}
	// find the earliest/latest times of collision
	float entryTime = max(xEntry, yEntry); 
	float exitTime = min(xExit, yExit);

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	else // if there was a collision
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
				direction = NORMAL_DIRECTION::RIGHT;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
				direction = NORMAL_DIRECTION::LEFT;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
				direction = NORMAL_DIRECTION::TOP;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
				direction = NORMAL_DIRECTION::BOTTOM;
			}
		}
		OnCollision(direction);
		// return the time of collision
		return entryTime;
	}

}
void GameObject::OnCollision(NORMAL_DIRECTION normalDirection) {
	switch (normalDirection)
	{
	case NORMAL_DIRECTION::LEFT:
		this->vx *= -1;
		break;
	case NORMAL_DIRECTION::RIGHT:
		this->vx *= -1;
		break;
	case NORMAL_DIRECTION::TOP:
		this->vy *= -1;
		break;
	case NORMAL_DIRECTION::BOTTOM:
		this->vy *= -1;
		break;
	default:
		break;
	}
}