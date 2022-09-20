#include "CommandRemouter.h"

CommandRemouter::CommandRemouter()
{
	//genering list of valid pieses' poses
	for (auto item : VALID_LETTERS)
		for (auto item1 : VALID_NUMS)
			valid_poses.push_back(item + "-" + item1);
}

CommandRemouter::~CommandRemouter()
{
}

void CommandRemouter::handleNewCommand()
{
	std::vector<std::string> args = ConsolePromoute::Console::getConsoleArgs();

	if (iequals(args[0], "move"))
	{
		//move A-1 B-2
		const string& command = args[0];

		vecstr splittedFirstPos = boost::split(splittedFirstPos, args[1], boost::is_any_of("-"));
		vecstr splittedSecondPos = boost::split(splittedSecondPos, args[2], boost::is_any_of("-"));

		if (isValidCommandSyntax(command, {args[1], args[2]}) == false)
			incorrectCommand();

		try 
		{
			short p1 = std::stoi(splittedFirstPos.at(0));
			short p2 = std::stoi(splittedFirstPos.at(1));

			short p3 = std::stoi(splittedSecondPos.at(0));
			short p4 = std::stoi(splittedSecondPos.at(1));

			_gameLogic.tryMovePiece(Location(p2, p1), Location(p4, p3));
		}
		catch (std::exception&)
		{
			_logger.WriteFile("Error with converting command. Class: CommandRemouter. Error is: bad list index");
		}
	}
}

void CommandRemouter::incorrectCommand()
{
	_logger.Write("This command is not correct.");
	handleNewCommand();
}

bool CommandRemouter::isValidCommandSyntax(const string& command, vecstr args)
{
	if (iequals(command, "move"))
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
