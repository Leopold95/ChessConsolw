#include "CommandRemouter.h"

void CommandRemouter::onNewCommandArgs(vecstr& args)
{
	if (boost::algorithm::iequals(args[0], "move"))
	{
		//move 1-1 2-4
		string firstPos = args[1];
		string secondPos = args[2];

		vecstr coords1;
		vecstr coords2;

		split(coords1, firstPos, boost::is_any_of("-"));
		split(coords2, secondPos, boost::is_any_of("-"));


		int p1 = atoi(coords1[0].c_str());
		int p2 = atoi(coords1[1].c_str());

		int p3 = atoi(coords2[0].c_str());
		int p4 = atoi(coords2[1].c_str());

		_gameLogic.tryMovePiece(Location(p2, p1), Location(p4, p3));		
	}
}
