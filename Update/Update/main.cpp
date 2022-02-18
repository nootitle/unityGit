#include <iostream>
#include "headers.h"

using namespace std;

int main()
{	
	mainUpdate Uscene;
	Uscene.Init();

	ULONGLONG Time = GetTickCount64();
	float DeltaTime = 0.0;
	float DeltaTime_S = 0.0;
	float DeltaTime_E = 0.0;

	while (true)
	{
		//system("cls");
		DeltaTime_S = (GetTickCount64() % 1000) * 0.001;
		if (Time + DeltaTime < GetTickCount64())
		{
			Time = GetTickCount64();			
			Uscene.FixedUpdate();
			cout << "**********************************************************************************************" << endl;
		}
		else
		{
			Uscene.Update();
			Uscene.LateUpdate();
			Uscene.render();
		}
		DeltaTime_E = (GetTickCount64() % 1000) * 0.001;
		DeltaTime = DeltaTime_E - DeltaTime_S;
		cout << DeltaTime << endl;
	}

	Uscene.Destroy();
	

	return 0;
}

//Main -> MainUpdate -> Obejct(PlayerController µî)