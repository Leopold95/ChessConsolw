#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "Piece.hpp"
#include "SystemVariables.h"

using std::string;

enum class DeskType
{
    Empty,
    WithDefaultPieces,
    Default
};

class Desk
{
public:
    void print(DeskType);
    void print(DeskType, std::unordered_map<std::string, Piece*>&);
    void initilisePieces(std::unordered_map<std::string, Piece*>&);
    void create();
    void setPieces();


    void tryMovePiece(string firstPos, string secondPos, PieceList& piece);

private:
    const static short SIZE = 8;

    //SystemVariables& sv = SystemVariables::GetInstanse();

    bool checkValidPiecePosition(string position);

    std::string desktemplatee[9][9] =
    {
    {" ", "À", "Á", "Â", "Ã", "Ä", "E", "¨", "Æ"},
    {"1", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"2", "·", " ", "·", " ", "·", " ", "·", " "},
    {"3", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"4", "·", " ", "·", " ", "·", " ", "·", " "},
    {"5", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"6", "·", " ", "·", " ", "·", " ", "·", " "},
    {"7", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"8", "·", " ", "·", " ", "·", " ", "·", " "},
    };

    std::string deskWithdDfaultPieces[9][9] =
    {
    {" ", "À", "Á", "Â", "Ã", "Ä", "E", "¨", "Æ"},
    {"1", "r", "k", "b", "K", "Q", "b", "k", "r"},
    {"2", "p", "p", "p", "p", "p", "p", "p", "p"},
    {"3", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"4", "·", " ", "·", " ", "·", " ", "·", " "},
    {"5", " ", "·", " ", "·", " ", "·", " ", "·"},
    {"6", "·", " ", "·", " ", "·", " ", "·", " "},
    {"7", "p", "p", "p", "p", "p", "p", "p", "p"},
    {"8", "r", "k", "b", "Q", "K", "b", "k", "r"},
    };

    std::string tempdesk[SIZE][SIZE];
};

