
#include "SceneMain.h"
#include <fstream>
int start = 0;
#include <fstream>
ofstream myfile("trace.txt");


void KeepTrack(float value1, float value2) {

	if (myfile.is_open())
	{
		myfile << "normalx = " << value1 << "\n";
		myfile << "normaly = " << value2 << "\n";
		//myfile.close();
	}
	else {
		//MessageBox(hwnd, "Error initializing the mouse", "Error", MB_OK);
	}
}
void KeepTrack(float value1) {

	if (myfile.is_open())
	{
		myfile << "collisiontime = " << value1 << "\n";
		//myfile.close();
	}
	else {
		//MessageBox(hwnd, "Error initializing the mouse", "Error", MB_OK);
	}
}
void SceneMain::CountTime() {
		if (GetTickCount() - start > 1000) {
			totalTime++;
			start = GetTickCount();
		}
}
void DrawBackground(LPDIRECT3DDEVICE9 d3ddv) {
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}
void SceneMain::InitLabels() {
	totalTime = 0;
	gui.Init();

	SetRect(&rScore1, 0, 0, 200, 400);
	SetRect(&rScore2, G_ScreenWidth - 50, 0, G_ScreenWidth, 50);
	SetRect(&rTimer, (G_ScreenWidth / 2 ) - 100, 0, ( G_ScreenWidth / 2 ) + 100, 50);
	gui.DrawLabel("0", rScore1, DT_LEFT);
	gui.DrawLabel("0", rScore2, DT_RIGHT);
	gui.DrawLabel(to_string(totalTime) + " s", rTimer, DT_CENTER);
}
SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}
void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	CountTime();
	//DrawBackground(d3ddv);
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 12));
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	//Draw score
	if (gui.font != NULL) {
		gui.DrawLabel(to_string(score1), rScore1, DT_LEFT);
		gui.DrawLabel(to_string(score2), rScore2, DT_RIGHT);
		gui.DrawLabel(to_string(totalTime) + " s", rTimer, DT_CENTER);
	}
	ball.Draw();
	leftPaddle.Draw();
	rightPaddle.Draw();
	//rightPaddle.y += Mouse_Y();
	G_SpriteHandler->End();
}
void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	ball.Move(); 
	int isScore = ball.IsScore();
	if (isScore == 2) {
		score2++;
	}
	else if (isScore == 1) {
		score1++;
	}
	if (IsKeyDown(DIK_UPARROW)) {
		leftPaddle.MoveUp();
	}
	if (IsKeyDown(DIK_DOWNARROW)) {

		leftPaddle.MoveDown();
	}

	rightPaddle.y += Mouse_Y();

	//  constraint the paddle to the screen's edges
	leftPaddle.ConstrainPosition();
	rightPaddle.ConstrainPosition();
	
	
	float normalx, normaly;
	float collisiontimeL, collisiontimeR;
	
	collisiontimeL = ball.SweptAABB(ball, leftPaddle, normalx, normaly);
	collisiontimeR = ball.SweptAABB(ball, rightPaddle, normalx, normaly);
	if (normalx != 0 || normaly != 0) {
		KeepTrack(normalx, normaly);
		KeepTrack(collisiontimeL);
	}

}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand(time(NULL));
	//DrawBackground(d3ddv);
	
	
	InitLabels();

	ball.Init("ball.bmp", 1, 1, 1);
	ball.InitPosition();
	leftPaddle.Init("paddle.bmp", 1, 1, 1);
	leftPaddle.isLeft = true;
	rightPaddle.Init("paddle.bmp", 1, 1, 1);

	leftPaddle.InitPosition();
	rightPaddle.InitPosition();
}
void SceneMain::OnKeyDown(int KeyCode)
{
}
SceneMain::~SceneMain(void)
{
}
