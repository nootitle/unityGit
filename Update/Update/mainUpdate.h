#pragma once

class Scene;
class mainUpdate
{
private:
	Scene* _scene;

public:
	//virtual void Init() = 0; //���������Լ� ���
	void Init();
	void Update();
	void LateUpdate();
	void FixedUpdate();
	void render();
	void Destroy();
public:
	mainUpdate();
	~mainUpdate();
};

