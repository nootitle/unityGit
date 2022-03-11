#pragma once

template <typename T>
inline void Safe_Delete(T& _Obj)
{
	if (_Obj)
	{
		delete _Obj;
		_Obj = nullptr;
	}
}

#define DECLARE_SINGLETON(type)\
	static type** GetInstance(void)\
		{\
			static type* pInstance = new type;\
			if(pInstance == NULL)\
			{\
				pInstance = new type;\
			}\
			return &pInstance;\
		}\
		static void DestroySingleton(void)\
		{\
			static type** ppInstance = GetInstance();\
			if(*ppInstance != NULL)\
			{\
				delete *ppInstance;\
				*ppInstance = NULL;\
			}\
		}

#define GETSINGLE(type) (*type::GetInstance())
#define DESTROY_SINGLETON(type) (*type::GetInstance())->DestroySingleton()