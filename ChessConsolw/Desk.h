#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "Piece.hpp"
#include "SystemVariables.h"
#include "PieceManager.h"
#include "Console.h"


using std::string;
using ConsolePromoute::Console;

class Desk
{
public:
    static Desk& GetInstanse();
    Desk(const Desk&) = delete;

    void print(string desk[9][9]);

    std::unordered_map<std::string, Piece*> Pieces;
    std::string PritebleDesk[9][9];
    std::string PiecesOnPritebleDesk_mask[8][8];

private:
    static Desk instanse;
    Desk();
    
    PieceManager _pieceManager;

public:
    const std::unordered_map<std::string, Piece*> DefaultPieces = _pieceManager.placeStarterPieceOnDesk();

    const std::string _fullyCrearPritrbleDesk[9][9]
    {
    {" ", "1", "2", "3", "4", "5", "6", "7", "8"},
    { "A", "", "", "", "", "", "", "", "" },
    { "B", "", "", "", "", "", "", "", "" },
    { "C", "", "", "", "", "", "", "", "" },
    { "D", "", "", "", "", "", "", "", "" },
    { "E", "", "", "", "", "", "", "", "" },
    { "F", "", "", "", "", "", "", "", "" },
    { "G", "", "", "", "", "", "", "", "" },
    { "H", "", "", "", "", "", "", "", "" },
    };

    const std::string _blackWhitePritebleDesk[9][9] =
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

    const std::string deskWithdDfaultPieces[9][9] =
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

