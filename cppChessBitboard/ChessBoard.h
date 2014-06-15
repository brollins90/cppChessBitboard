#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <stdio.h>
#include "bitMath.h"
#include "BitBoard.h"

struct ChessBoard
{
	/* The white piece positions */
	BitBoard whitePawns;
	BitBoard whiteRooks;
	BitBoard whiteKnights;
	BitBoard whiteBishops;
	BitBoard whiteQueens;
	BitBoard whiteKing;

	/* The black piece positions */
	BitBoard blackPawns;
	BitBoard blackRooks;
	BitBoard blackKnights;
	BitBoard blackBishops;
	BitBoard blackQueens;
	BitBoard blackKing;

	/* Commonly derived positions */
	BitBoard allWhitePieces;
	BitBoard allBlackPieces;
	BitBoard allPieces;

	ChessBoard()
	{
		whitePawns =   B64(00000000,00000000,00000000,00000000,00000000,00000000,11111111,00000000);
		whiteRooks =   B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,10000001);
		whiteKnights = B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,01000010);
		whiteBishops = B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00100100);
		whiteQueens =  B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00001000);
		whiteKing =    B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00010000);
		blackPawns =   B64(00000000,11111111,00000000,00000000,00000000,00000000,00000000,00000000);
		blackRooks =   B64(10000001,00000000,00000000,00000000,00000000,00000000,00000000,00000000);
		blackKnights = B64(01000010,00000000,00000000,00000000,00000000,00000000,00000000,00000000);
		blackBishops = B64(00100100,00000000,00000000,00000000,00000000,00000000,00000000,00000000);
		blackQueens =  B64(00001000,00000000,00000000,00000000,00000000,00000000,00000000,00000000);
		blackKing =    B64(00010000,00000000,00000000,00000000,00000000,00000000,00000000,00000000);

		allWhitePieces = whitePawns | whiteRooks | whiteKnights | whiteBishops | whiteQueens | whiteKing;
		allBlackPieces = blackPawns | blackRooks | blackKnights | blackBishops | blackQueens | blackKing;
		allPieces = allWhitePieces | allBlackPieces;
	}

	

};

#endif
