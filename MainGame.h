#pragma once
class MainGame : public Scene
{
public:
	Vector2 pos;

public:
	~MainGame();

	//æ¿ √ ±‚»≠
	virtual void Init() override;
	//æ¿ ∞ªΩ≈
	virtual void Update() override;
	//æ¿ √‚∑¬
	virtual void Render() override;
};

