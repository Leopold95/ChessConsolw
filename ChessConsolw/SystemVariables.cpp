#include "SystemVariables.h"

SystemVariables* SystemVariables::instanse;

SystemVariables* SystemVariables::GetInstanse()
{
	if (instanse == nullptr)
		instanse = new SystemVariables();

	return instanse;
}




short SystemVariables::randomShort(int min = 0, int max = 10)
{
	std::time_t t;
	std::srand((unsigned int)std::time(&t));


	return std::rand() % max + min;
}

SystemVariables::SystemVariables()
{ 
}