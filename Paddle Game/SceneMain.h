#ifndef _SCENEMAIN_H_
#define _SCENEMAIN_H_

#include "Game.h"
#include "Utils.h"
#include "GTexture.h"
#include "Global.h"
#include "Paddle.h"
#include "Ball.h"
#include "GUI.h"
class SceneMain: public CGame
{
public: 	
	SceneMain(int _nCmdShow);
	~SceneMain();	

	Ball ball;
	Paddle leftPaddle, rightPaddle;
	int score1, score2, totalTime;
	GUI gui;
	RECT rScore1;
	RECT rScore2;
	RECT rTimer;
	void InitLabels();
	void CountTime();
protected:	

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);
};

#endif