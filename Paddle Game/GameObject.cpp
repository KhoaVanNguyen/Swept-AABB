#include "GameObject.h"
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
	movex = newX;
	movey = newY;
}
void GameObject::SetSize(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
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
	return movex;
}
int GameObject::VelY() {
	return movey;
}
int GameObject::Width() {
	return width;
}
int GameObject::Height() {
	return height;
}


RECT GameObject::GetRect()
{
	RECT rResult;
	rResult.top = y;
	rResult.left = x;
	rResult.bottom = y + height;
	rResult.right = x + width;
	return rResult;
}

int CheckCollision(GameObject obj1, GameObject obj2)
{
	int centerx, centery;
	centerx = obj1.x + obj1.width / 2;
	centery = obj1.y + obj1.height / 2;
	if (obj1.x < obj2.x + obj2.width &&
		obj1.x + obj1.width > obj2.x &&
		obj1.y < obj2.y + obj2.height &&
		obj1.height + obj1.y > obj2.y)
	{
		if ((centery <= obj2.y) || (centery >= obj2.y + obj2.height))
			return 1;
		else if ((centerx <= obj2.x) || (centerx <= obj2.x + obj2.width))
			return 2;
	}
	return 0;
}