#include "Paddle.h"

Paddle::Paddle() {
	
}
Paddle::~Paddle()
{

}

void Paddle::InitPosition() {
	if (this->isLeft) {
		x = 40;
	}
	else {
		// right paddle
		x = G_ScreenWidth - 66;
	}
	y = G_ScreenHeight / 2;
	this->h = FrameHeight;
	this->w = FrameWidth;
}
void Paddle::ConstrainPosition() {
	if (y <= 0) {
		y = 0;
	}
	if (y + h >= G_ScreenHeight) {
		y = G_ScreenHeight - h;
	}
}
void Paddle::MoveDown() {
	y += PADDLE_SPEED;
}
void Paddle::MoveUp() {
	y -= PADDLE_SPEED;
}
void Paddle::Move() {

}