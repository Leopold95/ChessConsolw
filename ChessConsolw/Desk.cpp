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

void Desk::print(std::string desk[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            std::cout << desk[i][j];
        }

        std::cout << std::endl;
    }
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

