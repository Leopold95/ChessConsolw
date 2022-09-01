#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

class Logger
{
public:
	void Write(std::string info) 
	{
		auto time = std::chrono::system_clock::now();

		std::cout << "[" << time << "] " << info << "\n";
	}

	void WriteFile(std::string info)
	{
		std::cout << info << "\n";

		try
		{
			std::ofstream file;
			file.open("logs.txt", std::ios_base::app);

			auto time = std::chrono::system_clock::now();

			file << "[" << time << "] " << info << "\n";
			file.close();
		}
		catch (std::ofstream::failure& exception)
		{
			std::cout << "Error trying open logs file. Exception: " << exception.what() << "Code: " << exception.code() << std::endl;
		}
	}
};
