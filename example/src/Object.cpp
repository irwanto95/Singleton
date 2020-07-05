#include "Object.h"

Object::Object(const char* name)
{
	m_name = name;
}

Object1::Object1()
{
	m_bInitialized = true;
}

Object2::Object2(const char* name, int index)
{
	m_name = name;
	m_index = index;
}
