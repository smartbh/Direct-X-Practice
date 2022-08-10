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

	Sonic* sonic;

	F2::FLOOR		floor[FMAX];
	ObImage* rock[RMAX];

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

