#pragma once

class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr) Instance = new SceneManager;
		return Instance;
	}
public:
	SceneManager();
	~SceneManager();
};

