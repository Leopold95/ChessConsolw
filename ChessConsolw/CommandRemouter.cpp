#include "CommandRemouter.h"

CommandRemouter::CommandRemouter()
{
	for (auto item : valid_words)
		for (auto item1 : valid_nums)
			valid_poses.push_back(item + item1);
}

void CommandRemouter::onNewCommandArgs(vecstr& args)
{
	if (boost::algorithm::iequals(args[0], "move"))
	{
		string moveString = args[1];
		vecstr coords = split(coords, moveString, boost::is_any_of("-"));
		//D4-D7
		short is = 0;
		for (const auto& item : valid_poses)
		{
			if (coords[0] == item) is++;
		}



		//move 1-1 2-4
		string firstPos = args[1];
		string secondPos = args[2];

		vecstr coords1 = split(coords1, firstPos, boost::is_any_of("-"));
		vecstr coords2 = split(coords2, secondPos, boost::is_any_of("-"));

		
		


		int p1 = atoi(coords1[0].c_str());
		int p2 = atoi(coords1[1].c_str());

		int p3 = atoi(coords2[0].c_str());
		int p4 = atoi(coords2[1].c_str());

		_gameLogic.tryMovePiece(Location(p2, p1), Location(p4, p3));		
	}
}
