#pragma once
#include <utility>

template <class T>
class Singleton
{
	Singleton() = default;
	virtual ~Singleton() = default;
	
	static T* s_instance;

public:
	template <typename... Args>
	static inline T*	CreateInstance(Args&&...args);
	static inline T*	GetInstance();
	static inline void	DestroyInstance();
};