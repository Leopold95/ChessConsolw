#include "Desk.h"

Desk Desk::instanse;

Desk::Desk() { }

void Desk::setCursorPos(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

Desk& Desk::GetInstanse()
{
    return instanse;
}

void Desk::print(std::string desk[9][9])
{
    system("CLS");
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            std::cout << " " << desk[i][j];
        }

        std::cout << std::endl;
    }
}

void Desk::printNew()
{
    system("CLS");
    for (const auto& [id, piece] : Pieces)
    {
        setCursorPos(piece->CurrentLocation().x, piece->CurrentLocation().y);

        if (piece->CurrentColor() == Color::White)
            std::cout << "\033[38;5;" << 15 << "m" << (char)piece->CurrentPiece() << "\033[m";
        else if (piece->CurrentColor() == Color::Black)
            std::cout << "\033[38;5;" << 27 << "m" << (char)piece->CurrentPiece() << "\033[m";
    }

    setCursorPos(0, 9);
}
