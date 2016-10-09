#include "Ball.h"

Ball::Ball() {

}
Ball::~Ball() {

}
void Ball::InitPosition() {
	w = FrameWidth;
	h = FrameHeight;
	x = G_ScreenWidth / 2;
	y = G_ScreenHeight / 2;
	vx = BALL_SPEED;
	vy = -BALL_SPEED;
}
void Ball::Move() {
	//move the ball sprite
	x += vx;
	y += vy;

	//bounce the ball at screen edges

	if (y > G_ScreenHeight - h)
	{
		y -= h;
		vy *= -1;
	}
	else if (y < 0)
	{
		y += h;
		vy *= -1;
	}


}


int Ball::IsScore()
{

	//vertical boundary
	if (x <= 0)
	{
		ResetPosition();
		return 2;
	}
	else if (x >= (G_ScreenWidth - w))
	{
		ResetPosition();
		return 1;
	}
	return 0;
}


void Ball::ResetPosition()
{
	x = G_ScreenWidth / 2;
	y = G_ScreenHeight / 2;
	vy *= 1;
}