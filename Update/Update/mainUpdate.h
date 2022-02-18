#pragma once

class Scene;
class mainUpdate
{
private:
	Scene* _scene;

public:
	//virtual void Init() = 0; //순수가상함수 용법
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

