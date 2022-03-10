#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "collision.h"

Stage::Stage() : m_pPlayer(nullptr), Enemys(nullptr)
{
}

Stage::~Stage()
{
	Release();
}
/*
template <typename T>
Object* CreateObject(int _num)
{
	Object* pObj = new T;
	pObj->SetNumber(_num);
	return pObj;
}
*/
void Stage::Start()
{
	Time = GetTickCount64();

	m_pPlayer = ObjectManager::GetInstance()->FindPlayer();
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = ObjectFactory::CreateObject<Player>(10, 10);
		ObjectManager::GetInstance()->AddObject(m_pPlayer);
	} 
	//ObjectManager::GetInstance()->setActive("Player", 0, false); //Objects에 등록된 개체들은 key와 index만 알면 출력 여부를 결정할 수 있음
	Enemys = ObjectManager::GetInstance()->FindList("Enemy");
	if (Enemys == nullptr)
	{
		for (int i = 0; i < 10; ++i)
		{
			srand(GetTickCount64() * (i + 1));
			Object* te = ObjectFactory::CreateObject<Enemy>(rand() % 99, rand() % 27);
			ObjectManager::GetInstance()->AddObject(te);
		}
		Enemys = ObjectManager::GetInstance()->FindList("Enemy");
	}

	/*
	Bullets = ObjectManager::GetInstance()->FindList("Bullet");
	if (Bullets == nullptr)
	{
		for (int i = 0; i < 10; ++i)
		{
			srand(GetTickCount64() * (i + 2));
			Object* te = ObjectFactory::CreateObject<Bullet>(rand() % 99, rand() % 27);
			ObjectManager::GetInstance()->AddObject(te);
		}
		Bullets = ObjectManager::GetInstance()->FindList("Bullet");
	}
	*/
	/*
	for (int i = 0; i < 3; ++i)
	{
		m_enemyObject.push_back(ObjectFactory::CreateObject<Enemy>(i + 1));
		m_pBulletsObject.push_back(ObjectFactory::CreateObject<Bullet>(i + 1));
	}
	*/
	/*
	for (auto i : m_enemyObject)
		i->Start();
	for (auto i : m_pBulletsObject)
		i->Start();
*/
}

void Stage::Update()
{

	if (Time + 984 < GetTickCount64())
	{
		Time = GetTickCount64();
		iNumber++;
	}

	for (auto itr = Enemys->begin(); itr != Enemys->end(); ++itr)
		if (CollisionManager::Collision(m_pPlayer, (*itr)))
		{
			CursorManager::SetCursorPosition(44, 2);
			cout << "좆됨*****************************" << endl;
		}


	m_pPlayer->Update();
	for (auto i = Enemys->begin(); i != Enemys->end(); ++i)
		(*i)->Update();
	//for (auto i = Bullets->begin(); i != Bullets->end(); ++i)
		//(*i)->Update();


	if (GetAsyncKeyState('D'))
	{
		SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
	}
	/*
	for (auto i : m_enemyObject)
		i->Update();
	for (auto i : m_pBulletsObject)
		i->Update();
	*/
}

void Stage::Render()
{
	for (auto i = Enemys->begin(); i != Enemys->end(); ++i)
		(*i)->Render();
	//for (auto i = Bullets->begin(); i != Bullets->end(); ++i)
		//(*i)->Render();
	m_pPlayer->Render();
	CursorManager::SetCursorPosition(49, 1);
	cout << iNumber;
	/*
	for (auto i : m_enemyObject)
		i->Render();
	for (auto i : m_pBulletsObject)
		i->Render();
	*/
}

void Stage::Release()
{
}

