#ifndef _MF_INPUT_MANAGER_H
#define _MF_INPUT_MANAGER_H

#include "mfutils/Singleton/Singleton.h"
#include "InputKey.h"
#include "InputObserver.h"

namespace mufise
{
	namespace utils
	{
		class InputManager : public Singleton<InputManager>
		{
		public:
			LISTV(InputKey)			Keys;
			LISTV(InputObserverPtr)	Observers;

			InputManager();
			~InputManager();

			void Capture(const Input& input);
			void Update();

			void AttachObserver(InputObserverPtr pObserver);
			void DetachObserver(InputObserverPtr pObserver);

		private:
			void DispatchKey(const InputKey& key);

		private:
			sbit m_keys;
			Keys m_keysQueue;

			Observers m_observers;
		};
	}
}

#endif // !_MF_INPUT_MANAGER_H
