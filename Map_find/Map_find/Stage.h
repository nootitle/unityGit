#pragma once
#include "Scene.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

class Stage : public Scene
{
private:
	Object* m_pPlayer;
	vector<Object*> m_enemyObject;
	vector<Object*> m_pBulletsObject;
	list<Object*> *Enemys;
	list<Object*> *Bullets;

protected:
	string strKey;
	int iNumber;
public:
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:
	void SetNumber(int _num) { iNumber = _num; }
	int GetNumber() { return iNumber; }
	string GetKey() { return strKey; }

	Stage();
	virtual ~Stage();
};
