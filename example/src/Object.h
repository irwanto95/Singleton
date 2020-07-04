#pragma once

#include "source/Singleton.h"
#include <iostream>

class Object : public Singleton<Object>
{
public:
	Object(const char * name);
	~Object() = default;

private:
	std::string m_name;
};