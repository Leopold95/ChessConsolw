#include "CommandRemouter.h"

CommandRemouter::CommandRemouter()
{
	//genering list of valid pieses' poses
	for (auto item : VALID_NUMS)
		for (auto item1 : VALID_LETTERS)
			valid_poses.push_back(item + "-" + item1);
}

void CommandRemouter::handleNewCommand()
{
	std::vector<std::string> args = ConsolePromoute::Console::getConsoleArgs();

	if (iequals(args[0], "move"))
	{
		//move A-1 B-2

		string firstPos = args[1];
		string secondPos = args[2];

		_logger->Write(firstPos + " " + secondPos);

		vecstr splittedFirstPos = boost::split(splittedFirstPos, firstPos, boost::is_any_of("-"));
		vecstr splittedSecondPos = boost::split(splittedSecondPos, secondPos, boost::is_any_of("-"));

		

		if (isValidCommandSyntax(args[0], {args[1], args[2]}) == false)
		{
			incorrectCommand();
		}

		try 
		{
			int p1 = std::stoi(splittedFirstPos.at(0));
			int p2 = std::stoi(splittedFirstPos.at(1));

			int p3 = std::stoi(splittedSecondPos.at(0));
			int p4 = std::stoi(splittedSecondPos.at(1));


			_gameLogic.tryMovePiece(Location(p2, p1), Location(p4, p3));
		}
		catch (std::exception& ex)
		{
			_logger->WriteFile("Error with converting command. Class: CommandRemouter. Error is: bad list index");
		}

			

		//if(!isValid("move", args[1]))	
	}
}

void CommandRemouter::incorrectCommand()
{
	_logger->Write("This command is not correct.");
	handleNewCommand();
}

bool CommandRemouter::isValidCommandSyntax(const string& command, vecstr args)
{
	if (iequals("move", command) == false)
	{
		auto fistValid = std::find(valid_poses.begin(), valid_poses.end(), args[0]);
		auto secondValid = std::find(valid_poses.begin(), valid_poses.end(), args[1]);

		if (fistValid != valid_poses.end() && secondValid != valid_poses.end())
			return true;
		else
			return false;
	}
	

	return false;
}
