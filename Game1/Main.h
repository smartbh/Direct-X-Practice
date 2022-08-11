#pragma once


class Main : public Scene
{
private:
	//Sonic* pl;

	//float trailTimer = 0.0f;
	//bool	sceneChange = false;
	//bool	trigger;
	//bool    fadeOut;
	//float	getTickTime;
	//float	getTickTime2;

	ObImage*	player;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
