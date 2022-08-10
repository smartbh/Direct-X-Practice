#pragma once
#define FMAX 8
#define RMAX 3

namespace F1
{
	struct FLOOR
	{
		ObImage* img;
		ObRect* col;
		bool	isVisible;
	};
};

class Scene01 : public Scene
{
private:
	ObImage* test;
	float		testScale;

	Sonic* sonic;

	F1::FLOOR		floor[FMAX];
	ObImage*	rock[RMAX];

	ObImage* bg; //배경
	ObImage* bg2; //불

	ObRect* ui;

	float bgmScale;
	float gunScale;


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

