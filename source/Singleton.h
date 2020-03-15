#pragma once
#include <utility>

template <class T>
class Singleton
{	
	static T* s_instance;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

public:
	template <typename... Args>
	static inline T*	CreateInstance(Args&&...args);
	static inline T*	GetInstance();
	static inline void	DestroyInstance();
};