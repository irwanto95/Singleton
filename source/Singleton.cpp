#include "Singleton.h"


template <class T>
T* Singleton<T>::s_instance = nullptr;

template <class T>
template <typename... Args>
static T* Singleton<T>::CreateInstance(Args&&...args)
{
	if (!s_instance)
	{
		s_instance = new T(std::forward<Args>(args)...);
	}

	return s_instance;
}

template <class T>
static T* Singleton<T>::GetInstance()
{
	return s_instance;
}

template<class T>
inline void Singleton<T>::DestroyInstance()
{
	if (s_instance)
	{
		delete s_instance;
		s_instance = nullptr;
	}
}
