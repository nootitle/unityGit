#pragma once
#include "Object.h"

class CollisionManager
{
public:
	static bool Collision(Object* _origin, Object* _target)
	{
		Vector3 Playerpos = _origin->GetPosition();
		Vector3 Enemypos = _target->GetPosition();
		Vector3 PlayerScale = _origin->GetScale();
		Vector3 EnemyScale = _target->GetScale();

		if ((Playerpos.x + PlayerScale.x) > Enemypos.x &&
			(Enemypos.x + EnemyScale.x) > Playerpos.x &&
			Enemypos.y == Playerpos.y)
			return true;
		return false;
	}
};