#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	pl = new Sonic();

	//익명 스코프
	{
		Scene01* temp = new Scene01();
		temp->sonic = pl;
		SCENE->AddScene("Scene01", temp);
	}

	{
		Scene02* temp = new Scene02();
		temp->sonic = pl;
		SCENE->AddScene("Scene02", temp);
	}

	SCENE->ChangeScene("Scene01");
	LIGHT->light.radius = 4000.0f;

	getTickTime = 5.0f;
	sceneChange = false;
	trigger = false;
}

void Main::Release()
{
	SafeDelete(pl);
}

void Main::Update()
{
	if (INPUT->KeyDown('Z'))
	{
		sceneChange = true;
		getTickTime = 2.0f;
		trigger = true;
	}

	if (trigger)
	{
		if (sceneChange)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (fadeOut == false)
				{
					if(LIGHT->light.radius > 0)
						LIGHT->light.radius -= 2200.0f * DELTA;

				}
				else
				{
					if (LIGHT->light.radius < 4000)
						LIGHT->light.radius += 2200.0f * DELTA;
				}
			}
			else
			{
				cout << LIGHT->light.radius << endl;
				SCENE->ChangeScene("Scene02");
				trigger = false;
				sceneChange = false;
				if(LIGHT->light.radius > 0)
					fadeOut = false;
				else
					fadeOut = true;
			}
		}
		else
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (fadeOut == false)
				{
					if (LIGHT->light.radius > 0)
						LIGHT->light.radius -= 2000.0f * DELTA;

				}
				else
				{
					if (LIGHT->light.radius < 4000)
						LIGHT->light.radius += 2000.0f * DELTA;
				}
			}
			else
			{
				cout << LIGHT->light.radius << endl;
				SCENE->ChangeScene("Scene01");
				trigger = false;
				sceneChange = true;
				if (LIGHT->light.radius > 0)
					fadeOut = false;
				else
					fadeOut = true;
			}
		}
	}
	

	LIGHT->SetLightPos(pl->col->GetWorldPivot());

	SCENE->Update();
}

void Main::LateUpdate()
{
	SCENE->LateUpdate();
}

void Main::Render()
{
	SCENE->Render();
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