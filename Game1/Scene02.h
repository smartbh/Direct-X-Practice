#pragma once
#define FMAX 8
#define RMAX 3
namespace F2
{
	struct FLOOR
	{
		ObImage* img;
		ObRect* col;
		bool	isVisible;
	};
};

class Scene02 : public Scene
{
private:
	ObImage* test;
	float		testScale;

	

	F2::FLOOR		floor[FMAX];
	ObImage* rock[RMAX];

	ObImage* bg; //배경
	ObImage* bg2; //불

	ObRect* ui;

	float bgmScale;
	float gunScale;

	bool fadeOut;
	float fadeIn;

public:
	Sonic* sonic;

	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

