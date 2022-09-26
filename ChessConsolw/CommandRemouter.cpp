#include "CommandRemouter.h"

CommandRemouter::CommandRemouter()
{
	//genering list of valid pieses' poses
	for (auto item : VALID_LETTERS)
		for (auto item1 : VALID_NUMS)
			valid_poses.push_back(item + "-" + item1);
}

void CommandRemouter::handleNewCommand()
{
	std::vector<std::string> args = ConsolePromoute::Console::getConsoleArgs();

	if (iequals(args[0], "move"))
	{
		//move A-1 B-2
		const string& command = args[0];

		//need 3 argumets for "move" command
		if (args.size() != 3)
			incorrectCommand();

		vecstr splittedFirstPos; 
		vecstr splittedSecondPos;

		boost::split(splittedFirstPos, args[1], boost::is_any_of("-"));
		boost::split(splittedSecondPos, args[2], boost::is_any_of("-"));

		if (isValidCommandSyntax(command, {args[1], args[2]}) == false)
			incorrectCommand();

		try 
		{
			int p1 = _gameLogic.letterToInt(splittedFirstPos.at(0));
			int p2 = std::stoi(splittedFirstPos.at(1));

			int p3 = _gameLogic.letterToInt(splittedSecondPos.at(0));
			int p4 = std::stoi(splittedSecondPos.at(1));

			_gameLogic.tryMovePiece(Location(p2, p1), Location(p4, p3));
		}
		catch (...)
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
