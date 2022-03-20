#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "Piece.hpp"
#include "SystemVariables.h"
#include "PieceManager.h"

using std::string;

class Desk
{
public:
    Desk();

    void print(string desk[9][9]);

    std::unordered_map<std::string, Piece*> Pieces = _pieceManager.placeStarterPieceOnDesk();
    std::string PritebleDesk[9][9];

private:
    const static short SIZE = 8;
    PieceManager _pieceManager;


    std::string _fullyCrearPritrbleDesk[9][9]
    {
    {" ", "1", "2", "3", "4", "5", "6", "7", "8"},
    { "1", "", "", "", "", "", "", "", "" },
    { "2", "", "", "", "", "", "", "", "" },
    { "3", "", "", "", "", "", "", "", "" },
    { "4", "", "", "", "", "", "", "", "" },
    { "5", "", "", "", "", "", "", "", "" },
    { "6", "", "", "", "", "", "", "", "" },
    { "7", "", "", "", "", "", "", "", "" },
    { "8", "", "", "", "", "", "", "", "" },
    };

    std::string _blackWhitePritebleDesk[9][9] =
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
};

