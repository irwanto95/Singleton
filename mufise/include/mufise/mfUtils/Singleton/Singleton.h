#ifndef MFU_SINGLETON_H
#define MFU_SINGLETON_H

#include <iostream>

namespace mufise
{
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
		static inline bool	HasInstance();
		static inline void	DeleteInstance();
	};


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
	inline T* Singleton<T>::GetInstance()
	{
		return s_instance;
	}

	template<class T>
	inline bool Singleton<T>::HasInstance()
	{
		return s_instance != nullptr;
	}

	template<class T>
	inline void Singleton<T>::DeleteInstance()
	{
		if (s_instance)
		{
			delete s_instance;
			s_instance = nullptr;
		}
	}
} // mufise

#endif // !MFU_SINGLETON_H