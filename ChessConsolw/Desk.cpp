#include "Desk.h"

Desk::Desk()
{
    //заполнение доски для вывода из стандартного шаблона
    for (size_t i = 0; i < 9; i++)
        for (size_t j = 0; j < 9; j++)
            PritebleDesk[i][j] = _fullyCrearPritrbleDesk[i][j];
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

