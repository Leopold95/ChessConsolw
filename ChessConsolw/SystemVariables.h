#pragma once

#include "Structs.hpp"
#include <ctime>
#include <random>
#include "random.hpp"

using Random = effolkronium::random_static;

class SystemVariables
{
public:
	static SystemVariables* GetInstanse();

	const Structs::SoundOptions SoundOptions;

	short randomShort(int, int);

private:
	SystemVariables();
	SystemVariables(const SystemVariables&) = delete;
	SystemVariables(SystemVariables&) = delete;
	void operator=(const SystemVariables&) = delete;
	SystemVariables& operator=(SystemVariables&) = delete;
	static SystemVariables* instanse;


};