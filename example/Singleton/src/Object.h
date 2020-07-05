#pragma once

#include "Singleton/Singleton.h"
#include <iostream>

class Object : public Singleton<Object>
{
public:
	Object(const char * name);
	~Object() = default;

private:
	std::string m_name;
};

class Object1 : public Singleton<Object1>
{
public:
	Object1();
	~Object1() = default;

private:
	bool m_bInitialized;
};

class Object2 : public Singleton<Object2>
{
public:
	Object2(const char* name, int index);
	~Object2() = default;

private:
	std::string m_name;
	int			m_index;
};