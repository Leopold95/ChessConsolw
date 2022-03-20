#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class SystemVariables
{
public:
	static SystemVariables& GetInstanse();
	SystemVariables(const SystemVariables&) = delete;


private:
	SystemVariables();
	static SystemVariables instanse;
};