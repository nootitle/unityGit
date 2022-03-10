#pragma once
#include "Object.h"

class Bullet : public Object
{
	public:
		virtual void Start()override;
		virtual void Update()override;
		virtual void Render()override;
		virtual void Release()override;
	public:
		int GetNumber() { return iNumber; }
		void SetNumber(int v) { iNumber = v; }
		string GetKey() { return strKey; }

		Bullet();
		Bullet(int value);
		virtual ~Bullet();
};

