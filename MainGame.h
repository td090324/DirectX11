#pragma once
class MainGame : public Scene
{
public:
	Vector2 pos;

public:
	~MainGame();

	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

