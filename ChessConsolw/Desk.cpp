#include "Desk.h"

void Desk::print(DeskType dt)
{
    switch (dt)
    {
    case DeskType::Empty:
        for (short s = 0; s < SIZE; s++)
        {
            for (short i = 0; i < SIZE; i++)
            {
                std::cout << desktemplatee[s][i] << " ";
            }
            std::cout << "\n";
        }
        break;

    case DeskType::WithDefaultPieces:
        for (short s = 0; s < SIZE; s++)
        {
            for (short i = 0; i < SIZE; i++)
            {
                std::cout << deskWithdDfaultPieces[s][i] << " ";
            }
            std::cout << "\n";
        }
        break;
    }
}

void Desk::print(DeskType dt, std::unordered_map<std::string, Piece*>& mp)
{

}

void Desk::initilisePieces(std::unordered_map<std::string, Piece*>& mp)
{

}

void Desk::create()
{

}

void Desk::setPieces()
{

}

void Desk::tryMovePiece(string firstPos, string secondPos, PieceList& piece)
{
    if (checkValidPiecePosition(firstPos) == false) throw new std::exception("first posistion in not valid");
    if (checkValidPiecePosition(secondPos) == false) throw new std::exception("second position in not valid");


    //switch (piece)
    //{
    //}
}

bool Desk::checkValidPiecePosition(string position)
{
    for (const auto& i :)
    {

    }
    //for (const auto& item : sv.getAllPositionList())
    //{
    //    if (position == item)
    //    {
    //        return true;
    //    }
    //    else
    //    {
    //        continue;
    //    }
    //}

    return false;
}


