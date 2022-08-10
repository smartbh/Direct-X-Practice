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

	ObImage* bg; //���
	ObImage* bg2; //��

	ObRect* ui;

	float bgmScale;
	float gunScale;


public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

