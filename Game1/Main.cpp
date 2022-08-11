#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	player = new ObImage(L"Walk.png");
	player->maxFrame.y = 8;
	player->maxFrame.x = 6;
	player->visible = false;
	player->scale = Vector2(96.0f, 128.0f);
	player->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	rolling = new ObImage(L"Roll.png");
	rolling->SetParentRT(*player);
	rolling->maxFrame.y = 8;
	rolling->maxFrame.x = 6;
	rolling->visible = true;
	rolling->scale = Vector2(96.0f, 128.0f);
	rolling->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//pl = new Sonic();

	////익명 스코프
	//{
	//	Scene01* temp = new Scene01();
	//	temp->sonic = pl;
	//	SCENE->AddScene("Scene01", temp);
	//}

	//{
	//	Scene02* temp = new Scene02();
	//	temp->sonic = pl;
	//	SCENE->AddScene("Scene02", temp);
	//}

	//SCENE->ChangeScene("Scene01");
	//LIGHT->light.radius = 4000.0f;

	//getTickTime = 5.0f;
	//sceneChange = false;
	//trigger = false;
}

void Main::Release()
{

}

void Main::Update()
{
	Vector2 dir = INPUT->GetMouseWorldPos() - player->GetWorldPos();
	//player->rotation = Utility::DirToRadian(dir);

	dir.Normalize();

	cout << "dir x : " << dir.x << endl;
	cout << "dir y : " << dir.y << endl;
	cout << player->frame.y << endl;

	if (dir.x > 0)
	{
		if (dir.y >= 0.0f && dir.y <= 0.2f) //우측
		{
			player->frame.y = 0;
			rolling->frame.y = 0;
		}
		else if (dir.y <= 0.0f && dir.y >= -0.2f) 
		{
			player->frame.y = 0;
			rolling->frame.y = 0;
		}
		else if (dir.y >= 0.2f && dir.y <= 0.8f)//우 대각선 위
		{
			player->frame.y = 7;
			rolling->frame.y = 7;
		}
		else if (dir.y >= 0.8f && dir.y <= 1.0f)// 위
		{
			player->frame.y = 1;
			rolling->frame.y = 1;
		}
		else if (dir.y <= -0.2f && dir.y >= -0.8f)//우 대각선 아래
		{
			player->frame.y = 4;
			rolling->frame.y = 4;
		}
		else if (dir.y <= -0.8f && dir.y >= -1.0f)//아래
		{
			player->frame.y = 3;
			rolling->frame.y = 3;
		}
	}
	else
	{
		if (dir.y >= 0.0f && dir.y <= 0.2f) //좌측
		{
			player->frame.y = 2;
			rolling->frame.y = 2;
		}
		else if (dir.y <= 0.0f && dir.y >= -0.2f)
		{
			player->frame.y = 2;
			rolling->frame.y = 2;
		}
		else if (dir.y >= 0.2f && dir.y <= 0.8f)//좌 대각선 위
		{
			player->frame.y = 6;
			rolling->frame.y = 6;
		}
		else if (dir.y >= 0.8f && dir.y <= 1.0f)// 위
		{
			player->frame.y = 1;
			rolling->frame.y = 1;
		}
		else if (dir.y <= -0.2f && dir.y >= -0.8f)//좌 대각선 아래
		{
			player->frame.y = 5;
			rolling->frame.y = 5;
		}
		else if (dir.y <= -0.8f && dir.y >= -1.0f)//아래
		{
			player->frame.y = 3;
			rolling->frame.y = 3;
		}
	}

	if (INPUT->KeyPress('W'))
	{
		player->MoveWorldPos(UP * 100.0f * DELTA);
		if (INPUT->KeyDown(VK_SPACE))
		{
			player->visible = false;
			rolling->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			rolling->visible = true;
			getTickTime = 0.5f;
			rollDir = UP;
		}
	}
	if (INPUT->KeyPress('S'))
	{
		player->MoveWorldPos(DOWN * 100.0f * DELTA);
		if (INPUT->KeyDown(VK_SPACE))
		{
			player->visible = false;
			rolling->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			rolling->visible = true;
			getTickTime = 0.5f;
			rollDir = DOWN;
		}
		rolling->visible = false;
	}
	if (INPUT->KeyPress('A'))
	{
		player->MoveWorldPos(LEFT * 100.0f * DELTA);
		if (INPUT->KeyDown(VK_SPACE))
		{
			player->visible = false;
			rolling->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			rolling->visible = true;
			getTickTime = 0.5f;
			rollDir = LEFT;
		}
	}
	if (INPUT->KeyPress('D'))
	{
		player->MoveWorldPos(RIGHT * 100.0f * DELTA);
		if (INPUT->KeyDown(VK_SPACE))
		{
			player->visible = false;
			rolling->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			rolling->visible = true;
			getTickTime = 0.5f;
			rollDir = RIGHT;
		}
	}

	getTickTime -= DELTA;
	if (getTickTime > 0.0f)
	{
		player->MoveWorldPos(dir * 100.0f * DELTA);

	}
	else
	{
		player->visible = true;
		rolling->visible = false;
	}



	//SCENE->Update();

	player->Update();
	rolling->Update();
}

void Main::LateUpdate()
{
	//SCENE->LateUpdate();
}

void Main::Render()
{
	//SCENE->Render();
	player->Render();
	rolling->Render();
}

void Main::ResizeScreen()
{

}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400,800.0f);
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	WIN->DeleteSingleton();
	SafeDelete(main);
	return wParam;
}