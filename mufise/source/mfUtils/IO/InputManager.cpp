#include "mfpch.h"
#include "mufise/mfUtils/IO/InputManager.h"

namespace mufise
{
	InputManager::InputManager()
		:  m_keys(NULL)
	{
	}

	InputManager::~InputManager()
	{
		m_observers.clear();
	}

	void InputManager::Capture(const Input& input)
	{
		switch (input.GetType())
		{
		case Input::KEY:
			m_keysQueue.push_back(*static_cast<const InputKey*>(&input));
			break;
		case Input::MOUSE:
			break;
		}
	}

	void InputManager::Update()
	{
		DECL_IT(Keys, m_keysQueue, key);
		while (keyIt != m_keysQueue.end())
		{
			switch (keyIt->GetState())
			{
			case InputKey::KEY_PRESSED:
			{
				m_keys |= keyIt->GetValue();
				DispatchKey(InputKey(m_keys, InputKey::KEY_PRESSED));
					
				break;
			}
			case InputKey::KEY_RELEASED:
			{
				m_keys -= keyIt->GetValue();

				// dispatch only last released input
				if (m_keys == NULL)
				{
					DispatchKey(InputKey(keyIt->GetValue(), InputKey::KEY_RELEASED));
				}

				break;
			}
			}

			keyIt = m_keysQueue.erase(keyIt);
		}
	}

	void InputManager::AttachObserver(InputObserverSPtr pObserver)
	{
		Observers::iterator it = FIND_IT(m_observers, pObserver);

		if (it == m_observers.end())
		{
			m_observers.push_back(pObserver);
		}
		else
		{
			MF_ASSERT_MSG(0, "Observer already attached, please detach it first !");
		}
	}

	void InputManager::DetachObserver(InputObserverSPtr pObserver)
	{
		Observers::iterator it = FIND_IT(m_observers, pObserver);

		if (it != m_observers.end())
		{
			m_observers.erase(it);
		}
		else
		{
			MF_ASSERT_MSG(0, "Observer not found, detatch failed !");
		}
	}

	void InputManager::DispatchKey(const InputKey& key)
	{
		for (auto obs : m_observers)
		{
			if (key.GetState() == InputKey::KEY_PRESSED)
			{
				obs->OnKeyPressed(key);
			}
			else if (key.GetState() == InputKey::KEY_RELEASED)
			{
				// to do
			}
		}
	}
} // mufise