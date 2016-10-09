#include "Ball.h"

Ball::Ball() {

}
Ball::~Ball() {

}
void Ball::InitPosition() {
	width = FrameWidth;
	height = FrameHeight;
	x = G_ScreenWidth / 2;
	y = G_ScreenHeight / 2;
	movex = BALL_SPEED;
	movey = BALL_SPEED;
}
void Ball::Move() {
	//move the ball sprite
	x += movex;
	y += movey;

	//bounce the ball at screen edges

	if (y > G_ScreenHeight - height)
	{
		y -= height;
		movey *= -1;
	}
	else if (y < 0)
	{
		y += height;
		movey *= -1;
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
	else if (x >= (G_ScreenWidth - width))
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
	movex *= -1;
}