#ifndef MFU_INPUT_MANAGER_H
#define MFU_INPUT_MANAGER_H

#include "mufise/mfUtils/Singleton/Singleton.h"
#include "InputKey.h"
#include "InputObserver.h"

namespace mufise
{
	class InputManager : public Singleton<InputManager>
	{
	public:
		LISTV(InputKey)				Keys;
		LISTV(InputObserverSPtr)	Observers;

		InputManager();
		~InputManager();

		void Capture(const Input& input);
		void Update();

		void AttachObserver(InputObserverSPtr pObserver);
		void DetachObserver(InputObserverSPtr pObserver);

	private:
		void DispatchKey(const InputKey& key);

	private:
		sbit m_keys;
		Keys m_keysQueue;

		Observers m_observers;
	};
} // mufise

#endif // !MFU_INPUT_MANAGER_H
