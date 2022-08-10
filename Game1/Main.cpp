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
}

void Main::Release()
{
	SafeDelete(pl);
}

void Main::Update()
{
	if (ImGui::Button("1"))
	{


		SCENE->ChangeScene("Scene01");
		cout << "Scene change" << endl;

		LIGHT->light.radius = 4000.0f;
	}
	if (ImGui::Button("2"))
	{

		SCENE->ChangeScene("Scene02");

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