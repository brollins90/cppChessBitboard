#ifndef LOOKUP_TABLES_H
#define LOOKUP_TABLES_H

#include "BitBoard.h"

struct LookupTables
{
	
	static enum RayDirection
	{
		NORTH_WEST = 0, NORTH = 1, NORTH_EAST = 2, EAST = 3, SOUTH_EAST = 4, SOUTH = 5, SOUTH_WEST = 6, WEST = 7
	};
	static enum RankID
	{
		RANK_1 = 0, RANK_2 = 1, RANK_3 = 2, RANK_4 = 3,
		RANK_5 = 4, RANK_6 = 5, RANK_7 = 6, RANK_8 = 7
	};
	static enum FileID
	{
		FILE_A = 0, FILE_B = 1, FILE_C = 2, FILE_D = 3,
		FILE_E = 4, FILE_F = 5, FILE_G = 6, FILE_H = 7
	};
	static enum Locations
	{
		A1 =  0, B1 =  1, C1 =  2, D1 =  3, E1 =  4, F1 =  5, G1 =  6, H1 =  7,
		A2 =  8, B2 =  9, C2 = 10, D2 = 11, E2 = 12, F2 = 13, G2 = 14, H2 = 15,
		A3 = 16, B3 = 17, C3 = 18, D3 = 19, E3 = 20, F3 = 21, G3 = 22, H3 = 23,
		A4 = 24, B4 = 25, C4 = 26, D4 = 27, E4 = 28, F4 = 29, G4 = 30, H4 = 31,
		A5 = 32, B5 = 33, C5 = 34, D5 = 35, E5 = 36, F5 = 37, G5 = 38, H5 = 39,
		A6 = 40, B6 = 41, C6 = 42, D6 = 43, E6 = 44, F6 = 45, G6 = 46, H6 = 47,
		A7 = 48, B7 = 49, C7 = 50, D7 = 51, E7 = 52, F7 = 53, G7 = 54, H7 = 55,
		A8 = 56, B8 = 57, C8 = 58, D8 = 59, E8 = 60, F8 = 61, G8 = 62, H8 = 63
	};

	static BitBoard rayAttacks[8][64];
	static BitBoard ClearRank[8];
	static BitBoard MaskRank[8];
	static BitBoard ClearFile[8];
	static BitBoard MaskFile[8];
	static BitBoard Piece[64];

};

BitBoard LookupTables::ClearRank[] =
{
	B64(11111111,11111111,11111111,11111111,11111111,11111111,11111111,00000000),
	B64(11111111,11111111,11111111,11111111,11111111,11111111,00000000,11111111),
	B64(11111111,11111111,11111111,11111111,11111111,00000000,11111111,11111111),
	B64(11111111,11111111,11111111,11111111,00000000,11111111,11111111,11111111),
	B64(11111111,11111111,11111111,00000000,11111111,11111111,11111111,11111111),
	B64(11111111,11111111,00000000,11111111,11111111,11111111,11111111,11111111),
	B64(11111111,00000000,11111111,11111111,11111111,11111111,11111111,11111111),
	B64(00000000,11111111,11111111,11111111,11111111,11111111,11111111,11111111)
};

BitBoard LookupTables::MaskRank[] =
{
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,11111111),
	B64(00000000,00000000,00000000,00000000,00000000,00000000,11111111,00000000),
	B64(00000000,00000000,00000000,00000000,00000000,11111111,00000000,00000000),
	B64(00000000,00000000,00000000,00000000,11111111,00000000,00000000,00000000),
	B64(00000000,00000000,00000000,11111111,00000000,00000000,00000000,00000000),
	B64(00000000,00000000,11111111,00000000,00000000,00000000,00000000,00000000),
	B64(00000000,11111111,00000000,00000000,00000000,00000000,00000000,00000000),
	B64(11111111,00000000,00000000,00000000,00000000,00000000,00000000,00000000)
};

BitBoard LookupTables::ClearFile[] =
{	
	B64(11111110,11111110,11111110,11111110,11111110,11111110,11111110,11111110),	// FILE_A
	B64(11111101,11111101,11111101,11111101,11111101,11111101,11111101,11111101),	// FILE_B
	B64(11111011,11111011,11111011,11111011,11111011,11111011,11111011,11111011),	// FILE_C
	B64(11110111,11110111,11110111,11110111,11110111,11110111,11110111,11110111),	// FILE_D
	B64(11101111,11101111,11101111,11101111,11101111,11101111,11101111,11101111),	// FILE_E
	B64(11011111,11011111,11011111,11011111,11011111,11011111,11011111,11011111),	// FILE_F
	B64(10111111,10111111,10111111,10111111,10111111,10111111,10111111,10111111),	// FILE_G
	B64(01111111,01111111,01111111,01111111,01111111,01111111,01111111,01111111)	// FILE_H
};	

BitBoard LookupTables::MaskFile[] =
{	
	B64(00000001,00000001,00000001,00000001,00000001,00000001,00000001,00000001),	// FILE_A
	B64(00000010,00000010,00000010,00000010,00000010,00000010,00000010,00000010),	// FILE_B
	B64(00000100,00000100,00000100,00000100,00000100,00000100,00000100,00000100),	// FILE_C
	B64(00001000,00001000,00001000,00001000,00001000,00001000,00001000,00001000),	// FILE_D
	B64(00010000,00010000,00010000,00010000,00010000,00010000,00010000,00010000),	// FILE_E
	B64(00100000,00100000,00100000,00100000,00100000,00100000,00100000,00100000),	// FILE_F
	B64(01000000,01000000,01000000,01000000,01000000,01000000,01000000,01000000),	// FILE_G
	B64(10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000)	// FILE_H
};

BitBoard LookupTables::Piece[] =
{
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001),  // A1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000010),  // B1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000100),  // C1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00001000),  // D1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00010000),  // E1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,00100000),  // F1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,01000000),  // G1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000000,10000000),  // H1
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000001,00000000),  // A2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000010,00000000),  // B2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00000100,00000000),  // C2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00001000,00000000),  // D2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00010000,00000000),  // E2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,00100000,00000000),  // F2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,01000000,00000000),  // G2
	B64(00000000,00000000,00000000,00000000,00000000,00000000,10000000,00000000),  // H2
	B64(00000000,00000000,00000000,00000000,00000000,00000001,00000000,00000000),  // A3
	B64(00000000,00000000,00000000,00000000,00000000,00000010,00000000,00000000),  // B3
	B64(00000000,00000000,00000000,00000000,00000000,00000100,00000000,00000000),  // C3
	B64(00000000,00000000,00000000,00000000,00000000,00001000,00000000,00000000),  // D3
	B64(00000000,00000000,00000000,00000000,00000000,00010000,00000000,00000000),  // E3
	B64(00000000,00000000,00000000,00000000,00000000,00100000,00000000,00000000),  // F3
	B64(00000000,00000000,00000000,00000000,00000000,01000000,00000000,00000000),  // G3
	B64(00000000,00000000,00000000,00000000,00000000,10000000,00000000,00000000),  // H3
	B64(00000000,00000000,00000000,00000000,00000001,00000000,00000000,00000000),  // A4
	B64(00000000,00000000,00000000,00000000,00000010,00000000,00000000,00000000),  // B4
	B64(00000000,00000000,00000000,00000000,00000100,00000000,00000000,00000000),  // C4
	B64(00000000,00000000,00000000,00000000,00001000,00000000,00000000,00000000),  // D4
	B64(00000000,00000000,00000000,00000000,00010000,00000000,00000000,00000000),  // E4
	B64(00000000,00000000,00000000,00000000,00100000,00000000,00000000,00000000),  // F4
	B64(00000000,00000000,00000000,00000000,01000000,00000000,00000000,00000000),  // G4
	B64(00000000,00000000,00000000,00000000,10000000,00000000,00000000,00000000),  // H4
	B64(00000000,00000000,00000000,00000001,00000000,00000000,00000000,00000000),  // A5
	B64(00000000,00000000,00000000,00000010,00000000,00000000,00000000,00000000),  // B5
	B64(00000000,00000000,00000000,00000100,00000000,00000000,00000000,00000000),  // C5
	B64(00000000,00000000,00000000,00001000,00000000,00000000,00000000,00000000),  // D5
	B64(00000000,00000000,00000000,00010000,00000000,00000000,00000000,00000000),  // E5
	B64(00000000,00000000,00000000,00100000,00000000,00000000,00000000,00000000),  // F5
	B64(00000000,00000000,00000000,01000000,00000000,00000000,00000000,00000000),  // G5
	B64(00000000,00000000,00000000,10000000,00000000,00000000,00000000,00000000),  // H5
	B64(00000000,00000000,00000001,00000000,00000000,00000000,00000000,00000000),  // A6
	B64(00000000,00000000,00000010,00000000,00000000,00000000,00000000,00000000),  // B6
	B64(00000000,00000000,00000100,00000000,00000000,00000000,00000000,00000000),  // C6
	B64(00000000,00000000,00001000,00000000,00000000,00000000,00000000,00000000),  // D6
	B64(00000000,00000000,00010000,00000000,00000000,00000000,00000000,00000000),  // E6
	B64(00000000,00000000,00100000,00000000,00000000,00000000,00000000,00000000),  // F6
	B64(00000000,00000000,01000000,00000000,00000000,00000000,00000000,00000000),  // G6
	B64(00000000,00000000,10000000,00000000,00000000,00000000,00000000,00000000),  // H6
	B64(00000000,00000001,00000000,00000000,00000000,00000000,00000000,00000000),  // A7
	B64(00000000,00000010,00000000,00000000,00000000,00000000,00000000,00000000),  // B7
	B64(00000000,00000100,00000000,00000000,00000000,00000000,00000000,00000000),  // C7
	B64(00000000,00001000,00000000,00000000,00000000,00000000,00000000,00000000),  // D7
	B64(00000000,00010000,00000000,00000000,00000000,00000000,00000000,00000000),  // E7
	B64(00000000,00100000,00000000,00000000,00000000,00000000,00000000,00000000),  // F7
	B64(00000000,01000000,00000000,00000000,00000000,00000000,00000000,00000000),  // G7
	B64(00000000,10000000,00000000,00000000,00000000,00000000,00000000,00000000),  // H7
	B64(00000001,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // A8
	B64(00000010,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // B8
	B64(00000100,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // C8
	B64(00001000,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // D8
	B64(00010000,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // E8
	B64(00100000,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // F8
	B64(01000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000),  // G8
	B64(10000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000)   // H8
};


BitBoard LookupTables::rayAttacks[8][64] =
{
	{// NORTH_WEST (0)
		/* A1 */ 0,
		/* B1 */ Piece[A2],
		/* C1 */ Piece[B2] | Piece[A3],
		/* D1 */ Piece[C2] | Piece[B3] | Piece[A4],
		/* E1 */ Piece[D2] | Piece[C3] | Piece[B4] | Piece[A5],
		/* F1 */ Piece[E2] | Piece[D3] | Piece[C4] | Piece[B5] | Piece[A6],
		/* G1 */ Piece[F2] | Piece[E3] | Piece[D4] | Piece[C5] | Piece[B6] | Piece[A7],
		/* H1 */ Piece[G2] | Piece[F3] | Piece[E4] | Piece[D5] | Piece[C6] | Piece[B7] | Piece[A8],
		/* A2 */ 0,
		/* B2 */ Piece[A3],
		/* C2 */ Piece[B3] | Piece[A4],
		/* D2 */ Piece[C3] | Piece[B4] | Piece[A5],
		/* E2 */ Piece[D3] | Piece[C4] | Piece[B5] | Piece[A6],
		/* F2 */ Piece[E3] | Piece[D4] | Piece[C5] | Piece[B6] | Piece[A7],
		/* G2 */ Piece[F3] | Piece[E4] | Piece[D5] | Piece[C6] | Piece[B7] | Piece[A8],
		/* H2 */ Piece[G3] | Piece[F4] | Piece[E5] | Piece[D6] | Piece[C7] | Piece[B8],
		/* A3 */  0,
		/* B3 */  Piece[A4],
		/* C3 */  Piece[B4] | Piece[A5],
		/* D3 */  Piece[C4] | Piece[B5] | Piece[A6],
		/* E3 */  Piece[D4] | Piece[C5] | Piece[B6] | Piece[A7],
		/* F3 */  Piece[E4] | Piece[D5] | Piece[C6] | Piece[B7] | Piece[A8],
		/* G3 */  Piece[F4] | Piece[E5] | Piece[D6] | Piece[C7] | Piece[B8],
		/* H3 */  Piece[G4] | Piece[F5] | Piece[E6] | Piece[D7] | Piece[C8],
		/* A4 */  0,
		/* B4 */  Piece[A5],
		/* C4 */  Piece[B5] | Piece[A6],
		/* D4 */  Piece[C5] | Piece[B6] | Piece[A7],
		/* E4 */  Piece[D5] | Piece[C6] | Piece[B7] | Piece[A8],
		/* F4 */  Piece[E5] | Piece[D6] | Piece[C7] | Piece[B8],
		/* G4 */  Piece[F5] | Piece[E6] | Piece[D7] | Piece[C8],
		/* H4 */  Piece[G5] | Piece[F6] | Piece[E7] | Piece[D8],
		/* A5 */  0,
		/* B5 */  Piece[A6],
		/* C5 */  Piece[B6] | Piece[A7],
		/* D5 */  Piece[C6] | Piece[B7] | Piece[A8],
		/* E5 */  Piece[D6] | Piece[C7] | Piece[B8],
		/* F5 */  Piece[E6] | Piece[D7] | Piece[C8],
		/* G5 */  Piece[F6] | Piece[E7] | Piece[D8],
		/* H5 */  Piece[G6] | Piece[F7] | Piece[E8],
		/* A6 */  0,
		/* B6 */  Piece[A7],
		/* C6 */  Piece[B7] | Piece[A8],
		/* D6 */  Piece[C7] | Piece[B8],
		/* E6 */  Piece[D7] | Piece[C8],
		/* F6 */  Piece[E7] | Piece[D8],
		/* G6 */  Piece[F7] | Piece[E8],
		/* H6 */  Piece[G7] | Piece[F8],
		/* A7 */  0,
		/* B7 */  Piece[A8],
		/* C7 */  Piece[B8],
		/* D7 */  Piece[C8],
		/* E7 */  Piece[D8],
		/* F7 */  Piece[E8],
		/* G7 */  Piece[F8],
		/* H7 */  Piece[G8],
		/* A8 */  0,
		/* B8 */  0,
		/* C8 */  0,
		/* D8 */  0,
		/* E8 */  0,
		/* F8 */  0,
		/* G8 */  0,
		/* H8 */  0
	},
	{// NORTH (1)
		/* A1 */  Piece[A2] | Piece[A3] | Piece[A4] | Piece[A5] | Piece[A6] | Piece[A7] | Piece[A8],
		/* B1 */  Piece[B2] | Piece[B3] | Piece[B4] | Piece[B5] | Piece[B6] | Piece[B7] | Piece[B8],
		/* C1 */  Piece[C2] | Piece[C3] | Piece[C4] | Piece[C5] | Piece[C6] | Piece[C7] | Piece[C8],
		/* D1 */  Piece[D2] | Piece[D3] | Piece[D4] | Piece[D5] | Piece[D6] | Piece[D7] | Piece[D8],
		/* E1 */  Piece[E2] | Piece[E3] | Piece[E4] | Piece[E5] | Piece[E6] | Piece[E7] | Piece[E8],
		/* F1 */  Piece[F2] | Piece[F3] | Piece[F4] | Piece[F5] | Piece[F6] | Piece[F7] | Piece[F8],
		/* G1 */  Piece[G2] | Piece[G3] | Piece[G4] | Piece[G5] | Piece[G6] | Piece[G7] | Piece[G8],
		/* H1 */  Piece[H2] | Piece[H3] | Piece[H4] | Piece[H5] | Piece[H6] | Piece[H7] | Piece[H8],
		/* A2 */  Piece[A3] | Piece[A4] | Piece[A5] | Piece[A6] | Piece[A7] | Piece[A8],
		/* B2 */  Piece[B3] | Piece[B4] | Piece[B5] | Piece[B6] | Piece[B7] | Piece[B8],
		/* C2 */  Piece[C3] | Piece[C4] | Piece[C5] | Piece[C6] | Piece[C7] | Piece[C8],
		/* D2 */  Piece[D3] | Piece[D4] | Piece[D5] | Piece[D6] | Piece[D7] | Piece[D8],
		/* E2 */  Piece[E3] | Piece[E4] | Piece[E5] | Piece[E6] | Piece[E7] | Piece[E8],
		/* F2 */  Piece[F3] | Piece[F4] | Piece[F5] | Piece[F6] | Piece[F7] | Piece[F8],
		/* G2 */  Piece[G3] | Piece[G4] | Piece[G5] | Piece[G6] | Piece[G7] | Piece[G8],
		/* H2 */  Piece[H3] | Piece[H4] | Piece[H5] | Piece[H6] | Piece[H7] | Piece[H8],
		/* A3 */  Piece[A4] | Piece[A5] | Piece[A6] | Piece[A7] | Piece[A8],
		/* B3 */  Piece[B4] | Piece[B5] | Piece[B6] | Piece[B7] | Piece[B8],
		/* C3 */  Piece[C4] | Piece[C5] | Piece[C6] | Piece[C7] | Piece[C8],
		/* D3 */  Piece[D4] | Piece[D5] | Piece[D6] | Piece[D7] | Piece[D8],
		/* E3 */  Piece[E4] | Piece[E5] | Piece[E6] | Piece[E7] | Piece[E8],
		/* F3 */  Piece[F4] | Piece[F5] | Piece[F6] | Piece[F7] | Piece[F8],
		/* G3 */  Piece[G4] | Piece[G5] | Piece[G6] | Piece[G7] | Piece[G8],
		/* H3 */  Piece[H4] | Piece[H5] | Piece[H6] | Piece[H7] | Piece[H8],
		/* A4 */  Piece[A5] | Piece[A6] | Piece[A7] | Piece[A8],
		/* B4 */  Piece[B5] | Piece[B6] | Piece[B7] | Piece[B8],
		/* C4 */  Piece[C5] | Piece[C6] | Piece[C7] | Piece[C8],
		/* D4 */  Piece[D5] | Piece[D6] | Piece[D7] | Piece[D8],
		/* E4 */  Piece[E5] | Piece[E6] | Piece[E7] | Piece[E8],
		/* F4 */  Piece[F5] | Piece[F6] | Piece[F7] | Piece[F8],
		/* G4 */  Piece[G5] | Piece[G6] | Piece[G7] | Piece[G8],
		/* H4 */  Piece[H5] | Piece[H6] | Piece[H7] | Piece[H8],
		/* A5 */  Piece[A6] | Piece[A7] | Piece[A8],
		/* B5 */  Piece[B6] | Piece[B7] | Piece[B8],
		/* C5 */  Piece[C6] | Piece[C7] | Piece[C8],
		/* D5 */  Piece[D6] | Piece[D7] | Piece[D8],
		/* E5 */  Piece[E6] | Piece[E7] | Piece[E8],
		/* F5 */  Piece[F6] | Piece[F7] | Piece[F8],
		/* G5 */  Piece[G6] | Piece[G7] | Piece[G8],
		/* H5 */  Piece[H6] | Piece[H7] | Piece[H8],
		/* A6 */  Piece[A7] | Piece[A8],
		/* B6 */  Piece[B7] | Piece[B8],
		/* C6 */  Piece[C7] | Piece[C8],
		/* D6 */  Piece[D7] | Piece[D8],
		/* E6 */  Piece[E7] | Piece[E8],
		/* F6 */  Piece[F7] | Piece[F8],
		/* G6 */  Piece[G7] | Piece[G8],
		/* H6 */  Piece[H7] | Piece[H8],
		/* A7 */  Piece[A8],
		/* B7 */  Piece[B8],
		/* C7 */  Piece[C8],
		/* D7 */  Piece[D8],
		/* E7 */  Piece[E8],
		/* F7 */  Piece[F8],
		/* G7 */  Piece[G8],
		/* H7 */  Piece[H8],
		/* A8 */  0,
		/* B8 */  0,
		/* C8 */  0,
		/* D8 */  0,
		/* E8 */  0,
		/* F8 */  0,
		/* G8 */  0,
		/* H8 */  0
	},
	{// NORTH_EAST (2)
		/* A1 */  Piece[B2] | Piece[C3] | Piece[D4] | Piece[E5] | Piece[F6] | Piece[G7] | Piece[H8],
		/* B1 */  Piece[C2] | Piece[D3] | Piece[E4] | Piece[F5] | Piece[G6] | Piece[H7],
		/* C1 */  Piece[D2] | Piece[E3] | Piece[F4] | Piece[G5] | Piece[H6],
		/* D1 */  Piece[E2] | Piece[F3] | Piece[G4] | Piece[H5],
		/* E1 */  Piece[F2] | Piece[G3] | Piece[H4],
		/* F1 */  Piece[G2] | Piece[H3],
		/* G1 */  Piece[H2],
		/* H1 */  0,
		/* A2 */  Piece[B3] | Piece[C4] | Piece[D5] | Piece[E6] | Piece[F7] | Piece[G8],
		/* B2 */  Piece[C3] | Piece[D4] | Piece[E5] | Piece[F6] | Piece[G7] | Piece[H8],
		/* C2 */  Piece[D3] | Piece[E4] | Piece[F5] | Piece[G6] | Piece[H7],
		/* D2 */  Piece[E3] | Piece[F4] | Piece[G5] | Piece[H6],
		/* E2 */  Piece[F3] | Piece[G4] | Piece[H5],
		/* F2 */  Piece[G3] | Piece[H4],
		/* G2 */  Piece[H3],
		/* H2 */  0,
		/* A3 */  Piece[B4] | Piece[C5] | Piece[D6] | Piece[E7] | Piece[F8],
		/* B3 */  Piece[C4] | Piece[D5] | Piece[E6] | Piece[F7] | Piece[G8],
		/* C3 */  Piece[D4] | Piece[E5] | Piece[F6] | Piece[G7] | Piece[H8],
		/* D3 */  Piece[E4] | Piece[F5] | Piece[G6] | Piece[H7],
		/* E3 */  Piece[F4] | Piece[G5] | Piece[H6],
		/* F3 */  Piece[G4] | Piece[H5],
		/* G3 */  Piece[H4],
		/* H3 */  0,
		/* A4 */  Piece[B5] | Piece[C6] | Piece[D7] | Piece[E8],
		/* B4 */  Piece[C5] | Piece[D6] | Piece[E7] | Piece[F8],
		/* C4 */  Piece[D5] | Piece[E6] | Piece[F7] | Piece[G8],
		/* D4 */  Piece[E5] | Piece[F6] | Piece[G7] | Piece[H8],
		/* E4 */  Piece[F5] | Piece[G6] | Piece[H7],
		/* F4 */  Piece[G5] | Piece[H6],
		/* G4 */  Piece[H5],
		/* H4 */  0,
		/* A5 */  Piece[B6] | Piece[C7] | Piece[D8],
		/* B5 */  Piece[C6] | Piece[D7] | Piece[E8],
		/* C5 */  Piece[D6] | Piece[E7] | Piece[F8],
		/* D5 */  Piece[E6] | Piece[F7] | Piece[G8],
		/* E5 */  Piece[F6] | Piece[G7] | Piece[H8],
		/* F5 */  Piece[G6] | Piece[H7],
		/* G5 */  Piece[H6],
		/* H5 */  0,
		/* A6 */  Piece[B7] | Piece[C8],
		/* B6 */  Piece[C7] | Piece[D8],
		/* C6 */  Piece[D7] | Piece[E8],
		/* D6 */  Piece[E7] | Piece[F8],
		/* E6 */  Piece[F7] | Piece[G8],
		/* F6 */  Piece[G7] | Piece[H8],
		/* G6 */  Piece[H7],
		/* H6 */  0,
		/* A7 */  Piece[B8],
		/* B7 */  Piece[C8],
		/* C7 */  Piece[D8],
		/* D7 */  Piece[E8],
		/* E7 */  Piece[F8],
		/* F7 */  Piece[G8],
		/* G7 */  Piece[H8],
		/* H7 */  0,
		/* A8 */  0,
		/* B8 */  0,
		/* C8 */  0,
		/* D8 */  0,
		/* E8 */  0,
		/* F8 */  0,
		/* G8 */  0,
		/* H8 */  0
	},
	{// EAST (3)
		/* A1 */  Piece[B1] | Piece[C1] | Piece[D1] | Piece[E1] | Piece[F1] | Piece[G1] | Piece[H1],
		/* B1 */  Piece[C1] | Piece[D1] | Piece[E1] | Piece[F1] | Piece[G1] | Piece[H1],
		/* C1 */  Piece[D1] | Piece[E1] | Piece[F1] | Piece[G1] | Piece[H1],
		/* D1 */  Piece[E1] | Piece[F1] | Piece[G1] | Piece[H1],
		/* E1 */  Piece[F1] | Piece[G1] | Piece[H1],
		/* F1 */  Piece[G1] | Piece[H1],
		/* G1 */  Piece[H1],
		/* H1 */  0,
		/* A2 */  Piece[B2] | Piece[C2] | Piece[D2] | Piece[E2] | Piece[F2] | Piece[G2] | Piece[H2],
		/* B2 */  Piece[C2] | Piece[D2] | Piece[E2] | Piece[F2] | Piece[G2] | Piece[H2],
		/* C2 */  Piece[D2] | Piece[E2] | Piece[F2] | Piece[G2] | Piece[H2],
		/* D2 */  Piece[E2] | Piece[F2] | Piece[G2] | Piece[H2],
		/* E2 */  Piece[F2] | Piece[G2] | Piece[H2],
		/* F2 */  Piece[G2] | Piece[H2],
		/* G2 */  Piece[H2],
		/* H2 */  0,
		/* A3 */  Piece[B3] | Piece[C3] | Piece[D3] | Piece[E3] | Piece[F3] | Piece[G3] | Piece[H3],
		/* B3 */  Piece[C3] | Piece[D3] | Piece[E3] | Piece[F3] | Piece[G3] | Piece[H3],
		/* C3 */  Piece[D3] | Piece[E3] | Piece[F3] | Piece[G3] | Piece[H3],
		/* D3 */  Piece[E3] | Piece[F3] | Piece[G3] | Piece[H3],
		/* E3 */  Piece[F3] | Piece[G3] | Piece[H3],
		/* F3 */  Piece[G3] | Piece[H3],
		/* G3 */  Piece[H3],
		/* H3 */  0,
		/* A4 */  Piece[B4] | Piece[C4] | Piece[D4] | Piece[E4] | Piece[F4] | Piece[G4] | Piece[H4],
		/* B4 */  Piece[C4] | Piece[D4] | Piece[E4] | Piece[F4] | Piece[G4] | Piece[H4],
		/* C4 */  Piece[D4] | Piece[E4] | Piece[F4] | Piece[G4] | Piece[H4],
		/* D4 */  Piece[E4] | Piece[F4] | Piece[G4] | Piece[H4],
		/* E4 */  Piece[F4] | Piece[G4] | Piece[H4],
		/* F4 */  Piece[G4] | Piece[H4],
		/* G4 */  Piece[H4],
		/* H4 */  0,
		/* A5 */  Piece[B5] | Piece[C5] | Piece[D5] | Piece[E5] | Piece[F5] | Piece[G5] | Piece[H5],
		/* B5 */  Piece[C5] | Piece[D5] | Piece[E5] | Piece[F5] | Piece[G5] | Piece[H5],
		/* C5 */  Piece[D5] | Piece[E5] | Piece[F5] | Piece[G5] | Piece[H5],
		/* D5 */  Piece[E5] | Piece[F5] | Piece[G5] | Piece[H5],
		/* E5 */  Piece[F5] | Piece[G5] | Piece[H5],
		/* F5 */  Piece[G5] | Piece[H5],
		/* G5 */  Piece[H5],
		/* H5 */  0,
		/* A6 */  Piece[B6] | Piece[C6] | Piece[D6] | Piece[E6] | Piece[F6] | Piece[G6] | Piece[H6],
		/* B6 */  Piece[C6] | Piece[D6] | Piece[E6] | Piece[F6] | Piece[G6] | Piece[H6],
		/* C6 */  Piece[D6] | Piece[E6] | Piece[F6] | Piece[G6] | Piece[H6],
		/* D6 */  Piece[E6] | Piece[F6] | Piece[G6] | Piece[H6],
		/* E6 */  Piece[F6] | Piece[G6] | Piece[H6],
		/* F6 */  Piece[G6] | Piece[H6],
		/* G6 */  Piece[H6],
		/* H6 */  0,
		/* A7 */  Piece[B7] | Piece[C7] | Piece[D7] | Piece[E7] | Piece[F7] | Piece[G7] | Piece[H7],
		/* B7 */  Piece[C7] | Piece[D7] | Piece[E7] | Piece[F7] | Piece[G7] | Piece[H7],
		/* C7 */  Piece[D7] | Piece[E7] | Piece[F7] | Piece[G7] | Piece[H7],
		/* D7 */  Piece[E7] | Piece[F7] | Piece[G7] | Piece[H7],
		/* E7 */  Piece[F7] | Piece[G7] | Piece[H7],
		/* F7 */  Piece[G7] | Piece[H7],
		/* G7 */  Piece[H7],
		/* H7 */  0,
		/* A8 */  Piece[B8] | Piece[C8] | Piece[D8] | Piece[E8] | Piece[F8] | Piece[G8] | Piece[H8],
		/* B8 */  Piece[C8] | Piece[D8] | Piece[E8] | Piece[F8] | Piece[G8] | Piece[H8],
		/* C8 */  Piece[D8] | Piece[E8] | Piece[F8] | Piece[G8] | Piece[H8],
		/* D8 */  Piece[E8] | Piece[F8] | Piece[G8] | Piece[H8],
		/* E8 */  Piece[F8] | Piece[G8] | Piece[H8],
		/* F8 */  Piece[G8] | Piece[H8],
		/* G8 */  Piece[H8],
		/* H8 */  0,
	},
	{// SOUTH_EAST (4)
		/* A1 */  0,
		/* B1 */  0,
		/* C1 */  0,
		/* D1 */  0,
		/* E1 */  0,
		/* F1 */  0,
		/* G1 */  0,
		/* H1 */  0,
		/* A2 */  Piece[B1],
		/* B2 */  Piece[C1],
		/* C2 */  Piece[D1],
		/* D2 */  Piece[E1],
		/* E2 */  Piece[F1],
		/* F2 */  Piece[G1],
		/* G2 */  Piece[H1],
		/* H2 */  0,
		/* A3 */  Piece[B2] | Piece[C1],
		/* B3 */  Piece[C2] | Piece[D1],
		/* C3 */  Piece[D2] | Piece[E1],
		/* D3 */  Piece[E2] | Piece[F1],
		/* E3 */  Piece[F2] | Piece[G1],
		/* F3 */  Piece[G2] | Piece[H1],
		/* G3 */  Piece[H2],
		/* H3 */  0,
		/* A4 */  Piece[B3] | Piece[C2] | Piece[D1],
		/* B4 */  Piece[C3] | Piece[D2] | Piece[E1],
		/* C4 */  Piece[D3] | Piece[E2] | Piece[F1],
		/* D4 */  Piece[E3] | Piece[F2] | Piece[G1],
		/* E4 */  Piece[F3] | Piece[G2] | Piece[H1],
		/* F4 */  Piece[G3] | Piece[H2],
		/* G4 */  Piece[H3],
		/* H4 */  0,
		/* A5 */  Piece[B4] | Piece[C3] | Piece[D2] | Piece[E1],
		/* B5 */  Piece[C4] | Piece[D3] | Piece[E2] | Piece[F1],
		/* C5 */  Piece[D4] | Piece[E3] | Piece[F2] | Piece[G1],
		/* D5 */  Piece[E4] | Piece[F3] | Piece[G2] | Piece[H1],
		/* E5 */  Piece[F4] | Piece[G3] | Piece[H2],
		/* F5 */  Piece[G4] | Piece[H3],
		/* G5 */  Piece[H4],
		/* H5 */  0,
		/* A6 */  Piece[B5] | Piece[C4] | Piece[D3] | Piece[E2] | Piece[F1],
		/* B6 */  Piece[C5] | Piece[D4] | Piece[E3] | Piece[F2] | Piece[G1],
		/* C6 */  Piece[D5] | Piece[E4] | Piece[F3] | Piece[G2] | Piece[H1],
		/* D6 */  Piece[E5] | Piece[F4] | Piece[G3] | Piece[H2],
		/* E6 */  Piece[F5] | Piece[G4] | Piece[H3],
		/* F6 */  Piece[G5] | Piece[H4],
		/* G6 */  Piece[H5],
		/* H6 */  0,
		/* A7 */  Piece[B6] | Piece[C5] | Piece[D4] | Piece[E3] | Piece[F2] | Piece[G1],
		/* B7 */  Piece[C6] | Piece[D5] | Piece[E4] | Piece[F3] | Piece[G2] | Piece[H1],
		/* C7 */  Piece[D6] | Piece[E5] | Piece[F4] | Piece[G3] | Piece[H2],
		/* D7 */  Piece[E6] | Piece[F5] | Piece[G4] | Piece[H3],
		/* E7 */  Piece[F6] | Piece[G5] | Piece[H4],
		/* F7 */  Piece[G6] | Piece[H5],
		/* G7 */  Piece[H6],
		/* H7 */  0,
		/* A8 */  Piece[B7] | Piece[C6] | Piece[D5] | Piece[E4] | Piece[F3] | Piece[G2] | Piece[H1],
		/* B8 */  Piece[C7] | Piece[D6] | Piece[E5] | Piece[F4] | Piece[G3] | Piece[H2],
		/* C8 */  Piece[D7] | Piece[E6] | Piece[F5] | Piece[G4] | Piece[H3],
		/* D8 */  Piece[E7] | Piece[F6] | Piece[G5] | Piece[H4],
		/* E8 */  Piece[F7] | Piece[G6] | Piece[H5],
		/* F8 */  Piece[G7] | Piece[H6],
		/* G8 */  Piece[H7],
		/* H8 */  0,
	}, // SOUTH (5)
	{
		/* A1 */  0,
		/* B1 */  0,
		/* C1 */  0,
		/* D1 */  0,
		/* E1 */  0,
		/* F1 */  0,
		/* G1 */  0,
		/* H1 */  0,
		/* A2 */  Piece[A1],
		/* B2 */  Piece[B1],
		/* C2 */  Piece[C1],
		/* D2 */  Piece[D1],
		/* E2 */  Piece[E1],
		/* F2 */  Piece[F1],
		/* G2 */  Piece[G1],
		/* H2 */  Piece[H1],
		/* A3 */  Piece[A2] | Piece[A1],
		/* B3 */  Piece[B2] | Piece[B1],
		/* C3 */  Piece[C2] | Piece[C1],
		/* D3 */  Piece[D2] | Piece[D1],
		/* E3 */  Piece[E2] | Piece[E1],
		/* F3 */  Piece[F2] | Piece[F1],
		/* G3 */  Piece[G2] | Piece[G1],
		/* H3 */  Piece[H2] | Piece[H1],
		/* A4 */  Piece[A3] | Piece[A2] | Piece[A1],
		/* B4 */  Piece[B3] | Piece[B2] | Piece[B1],
		/* C4 */  Piece[C3] | Piece[C2] | Piece[C1],
		/* D4 */  Piece[D3] | Piece[D2] | Piece[D1],
		/* E4 */  Piece[E3] | Piece[E2] | Piece[E1],
		/* F4 */  Piece[F3] | Piece[F2] | Piece[F1],
		/* G4 */  Piece[G3] | Piece[G2] | Piece[G1],
		/* H4 */  Piece[H3] | Piece[H2] | Piece[H1],
		/* A5 */  Piece[A4] | Piece[A3] | Piece[A2] | Piece[A1],
		/* B5 */  Piece[B4] | Piece[B3] | Piece[B2] | Piece[B1],
		/* C5 */  Piece[C4] | Piece[C3] | Piece[C2] | Piece[C1],
		/* D5 */  Piece[D4] | Piece[D3] | Piece[D2] | Piece[D1],
		/* E5 */  Piece[E4] | Piece[E3] | Piece[E2] | Piece[E1],
		/* F5 */  Piece[F4] | Piece[F3] | Piece[F2] | Piece[F1],
		/* G5 */  Piece[G4] | Piece[G3] | Piece[G2] | Piece[G1],
		/* H5 */  Piece[H4] | Piece[H3] | Piece[H2] | Piece[H1],
		/* A6 */  Piece[A5] | Piece[A4] | Piece[A3] | Piece[A2] | Piece[A1],
		/* B6 */  Piece[B5] | Piece[B4] | Piece[B3] | Piece[B2] | Piece[B1],
		/* C6 */  Piece[C5] | Piece[C4] | Piece[C3] | Piece[C2] | Piece[C1],
		/* D6 */  Piece[D5] | Piece[D4] | Piece[D3] | Piece[D2] | Piece[D1],
		/* E6 */  Piece[E5] | Piece[E4] | Piece[E3] | Piece[E2] | Piece[E1],
		/* F6 */  Piece[F5] | Piece[F4] | Piece[F3] | Piece[F2] | Piece[F1],
		/* G6 */  Piece[G5] | Piece[G4] | Piece[G3] | Piece[G2] | Piece[G1],
		/* H6 */  Piece[H5] | Piece[H4] | Piece[H3] | Piece[H2] | Piece[H1],
		/* A7 */  Piece[A6] | Piece[A5] | Piece[A4] | Piece[A3] | Piece[A2] | Piece[A1],
		/* B7 */  Piece[B6] | Piece[B5] | Piece[B4] | Piece[B3] | Piece[B2] | Piece[B1],
		/* C7 */  Piece[C6] | Piece[C5] | Piece[C4] | Piece[C3] | Piece[C2] | Piece[C1],
		/* D7 */  Piece[D6] | Piece[D5] | Piece[D4] | Piece[D3] | Piece[D2] | Piece[D1],
		/* E7 */  Piece[E6] | Piece[E5] | Piece[E4] | Piece[E3] | Piece[E2] | Piece[E1],
		/* F7 */  Piece[F6] | Piece[F5] | Piece[F4] | Piece[F3] | Piece[F2] | Piece[F1],
		/* G7 */  Piece[G6] | Piece[G5] | Piece[G4] | Piece[G3] | Piece[G2] | Piece[G1],
		/* H7 */  Piece[H6] | Piece[H5] | Piece[H4] | Piece[H3] | Piece[H2] | Piece[H1],
		/* A8 */  Piece[A7] | Piece[A6] | Piece[A5] | Piece[A4] | Piece[A3] | Piece[A2] | Piece[A1],
		/* B8 */  Piece[B7] | Piece[B6] | Piece[B5] | Piece[B4] | Piece[B3] | Piece[B2] | Piece[B1],
		/* C8 */  Piece[C7] | Piece[C6] | Piece[C5] | Piece[C4] | Piece[C3] | Piece[C2] | Piece[C1],
		/* D8 */  Piece[D7] | Piece[D6] | Piece[D5] | Piece[D4] | Piece[D3] | Piece[D2] | Piece[D1],
		/* E8 */  Piece[E7] | Piece[E6] | Piece[E5] | Piece[E4] | Piece[E3] | Piece[E2] | Piece[E1],
		/* F8 */  Piece[F7] | Piece[F6] | Piece[F5] | Piece[F4] | Piece[F3] | Piece[F2] | Piece[F1],
		/* G8 */  Piece[G7] | Piece[G6] | Piece[G5] | Piece[G4] | Piece[G3] | Piece[G2] | Piece[G1],
		/* H8 */  Piece[H7] | Piece[H6] | Piece[H5] | Piece[H4] | Piece[H3] | Piece[H2] | Piece[H1]
	}, // SOUTH_WEST (6)
	{
		/* A1 */  0,
		/* B1 */  0,
		/* C1 */  0,
		/* D1 */  0,
		/* E1 */  0,
		/* F1 */  0,
		/* G1 */  0,
		/* H1 */  0,
		/* A2 */  0,
		/* B2 */  Piece[A1],
		/* C2 */  Piece[B1],
		/* D2 */  Piece[C1],
		/* E2 */  Piece[D1],
		/* F2 */  Piece[E1],
		/* G2 */  Piece[F1],
		/* H2 */  Piece[G1],
		/* A3 */  0,
		/* B3 */  Piece[A2],
		/* C3 */  Piece[B2] | Piece[A1],
		/* D3 */  Piece[C2] | Piece[B1],
		/* E3 */  Piece[D2] | Piece[C1],
		/* F3 */  Piece[E2] | Piece[D1],
		/* G3 */  Piece[F2] | Piece[E1],
		/* H3 */  Piece[G2] | Piece[F1],
		/* A4 */  0,
		/* B4 */  Piece[A3],
		/* C4 */  Piece[B3] | Piece[A2],
		/* D4 */  Piece[C3] | Piece[B2] | Piece[A1],
		/* E4 */  Piece[D3] | Piece[C2] | Piece[B1],
		/* F4 */  Piece[E3] | Piece[D2] | Piece[C1],
		/* G4 */  Piece[F3] | Piece[E2] | Piece[D1],
		/* H4 */  Piece[G3] | Piece[F2] | Piece[E1],
		/* A5 */  0,
		/* B5 */  Piece[A4],
		/* C5 */  Piece[B4] | Piece[A3],
		/* D5 */  Piece[C4] | Piece[B3] | Piece[A2],
		/* E5 */  Piece[D4] | Piece[C3] | Piece[B2] | Piece[A1],
		/* F5 */  Piece[E4] | Piece[D3] | Piece[C2] | Piece[B1],
		/* G5 */  Piece[F4] | Piece[E3] | Piece[D2] | Piece[C1],
		/* H5 */  Piece[G4] | Piece[F3] | Piece[E2] | Piece[D1],
		/* A6 */  0,
		/* B6 */  Piece[A5],
		/* C6 */  Piece[B5] | Piece[A4],
		/* D6 */  Piece[C5] | Piece[B4] | Piece[A3],
		/* E6 */  Piece[D5] | Piece[C4] | Piece[B3] | Piece[A2],
		/* F6 */  Piece[E5] | Piece[D4] | Piece[C3] | Piece[B2] | Piece[A1],
		/* G6 */  Piece[F5] | Piece[E4] | Piece[D3] | Piece[C2] | Piece[B1],
		/* H6 */  Piece[G5] | Piece[F4] | Piece[E3] | Piece[D2] | Piece[C1],
		/* A7 */  0,
		/* B7 */  Piece[A6],
		/* C7 */  Piece[B6] | Piece[A5],
		/* D7 */  Piece[C6] | Piece[B5] | Piece[A4],
		/* E7 */  Piece[D6] | Piece[C5] | Piece[B4] | Piece[A3],
		/* F7 */  Piece[E6] | Piece[D5] | Piece[C4] | Piece[B3] | Piece[A2],
		/* G7 */  Piece[F6] | Piece[E5] | Piece[D4] | Piece[C3] | Piece[B2] | Piece[A1],
		/* H7 */  Piece[G6] | Piece[F5] | Piece[E4] | Piece[D3] | Piece[C2] | Piece[B1],
		/* A8 */  0,
		/* B8 */  Piece[A7],
		/* C8 */  Piece[B7] | Piece[A6],
		/* D8 */  Piece[C7] | Piece[B6] | Piece[A5],
		/* E8 */  Piece[D7] | Piece[C6] | Piece[B5] | Piece[A4],
		/* F8 */  Piece[E7] | Piece[D6] | Piece[C5] | Piece[B4] | Piece[A3],
		/* G8 */  Piece[F7] | Piece[E6] | Piece[D5] | Piece[C4] | Piece[B3] | Piece[A2],
		/* H8 */  Piece[G7] | Piece[F6] | Piece[E5] | Piece[D4] | Piece[C3] | Piece[B2] | Piece[A1],
	}, // WEST (7)
	{
		/* A1 */  0,
		/* B1 */  Piece[A1],
		/* C1 */  Piece[B1] | Piece[A1],
		/* D1 */  Piece[C1] | Piece[B1] | Piece[A1],
		/* E1 */  Piece[D1] | Piece[C1] | Piece[B1] | Piece[A1],
		/* F1 */  Piece[E1] | Piece[D1] | Piece[C1] | Piece[B1] | Piece[A1],
		/* G1 */  Piece[F1] | Piece[E1] | Piece[D1] | Piece[C1] | Piece[B1] | Piece[A1],
		/* H1 */  Piece[G1] | Piece[F1] | Piece[E1] | Piece[D1] | Piece[C1] | Piece[B1] | Piece[A1],
		/* A2 */  0,
		/* B2 */  Piece[A2],
		/* C2 */  Piece[B2] | Piece[A2],
		/* D2 */  Piece[C2] | Piece[B2] | Piece[A2],
		/* E2 */  Piece[D2] | Piece[C2] | Piece[B2] | Piece[A2],
		/* F2 */  Piece[E2] | Piece[D2] | Piece[C2] | Piece[B2] | Piece[A2],
		/* G2 */  Piece[F2] | Piece[E2] | Piece[D2] | Piece[C2] | Piece[B2] | Piece[A2],
		/* H2 */  Piece[G2] | Piece[F2] | Piece[E2] | Piece[D2] | Piece[C2] | Piece[B2] | Piece[A2],
		/* A3 */  0,
		/* B3 */  Piece[A3],
		/* C3 */  Piece[B3] | Piece[A3],
		/* D3 */  Piece[C3] | Piece[B3] | Piece[A3],
		/* E3 */  Piece[D3] | Piece[C3] | Piece[B3] | Piece[A3],
		/* F3 */  Piece[E3] | Piece[D3] | Piece[C3] | Piece[B3] | Piece[A3],
		/* G3 */  Piece[F3] | Piece[E3] | Piece[D3] | Piece[C3] | Piece[B3] | Piece[A3],
		/* H3 */  Piece[G3] | Piece[F3] | Piece[E3] | Piece[D3] | Piece[C3] | Piece[B3] | Piece[A3],
		/* A4 */  0,
		/* B4 */  Piece[A4],
		/* C4 */  Piece[B4] | Piece[A4],
		/* D4 */  Piece[C4] | Piece[B4] | Piece[A4],
		/* E4 */  Piece[D4] | Piece[C4] | Piece[B4] | Piece[A4],
		/* F4 */  Piece[E4] | Piece[D4] | Piece[C4] | Piece[B4] | Piece[A4],
		/* G4 */  Piece[F4] | Piece[E4] | Piece[D4] | Piece[C4] | Piece[B4] | Piece[A4],
		/* H4 */  Piece[G4] | Piece[F4] | Piece[E4] | Piece[D4] | Piece[C4] | Piece[B4] | Piece[A4],
		/* A5 */  0,
		/* B5 */  Piece[A5],
		/* C5 */  Piece[B5] | Piece[A5],
		/* D5 */  Piece[C5] | Piece[B5] | Piece[A5],
		/* E5 */  Piece[D5] | Piece[C5] | Piece[B5] | Piece[A5],
		/* F5 */  Piece[E5] | Piece[D5] | Piece[C5] | Piece[B5] | Piece[A5],
		/* G5 */  Piece[F5] | Piece[E5] | Piece[D5] | Piece[C5] | Piece[B5] | Piece[A5],
		/* H5 */  Piece[G5] | Piece[F5] | Piece[E5] | Piece[D5] | Piece[C5] | Piece[B5] | Piece[A5],
		/* A6 */  0,
		/* B6 */  Piece[A6],
		/* C6 */  Piece[B6] | Piece[A6],
		/* D6 */  Piece[C6] | Piece[B6] | Piece[A6],
		/* E6 */  Piece[D6] | Piece[C6] | Piece[B6] | Piece[A6],
		/* F6 */  Piece[E6] | Piece[D6] | Piece[C6] | Piece[B6] | Piece[A6],
		/* G6 */  Piece[F6] | Piece[E6] | Piece[D6] | Piece[C6] | Piece[B6] | Piece[A6],
		/* H6 */  Piece[G6] | Piece[F6] | Piece[E6] | Piece[D6] | Piece[C6] | Piece[B6] | Piece[A6],
		/* A7 */  0,
		/* B7 */  Piece[A7],
		/* C7 */  Piece[B7] | Piece[A7],
		/* D7 */  Piece[C7] | Piece[B7] | Piece[A7],
		/* E7 */  Piece[D7] | Piece[C7] | Piece[B7] | Piece[A7],
		/* F7 */  Piece[E7] | Piece[D7] | Piece[C7] | Piece[B7] | Piece[A7],
		/* G7 */  Piece[F7] | Piece[E7] | Piece[D7] | Piece[C7] | Piece[B7] | Piece[A7],
		/* H7 */  Piece[G7] | Piece[F7] | Piece[E7] | Piece[D7] | Piece[C7] | Piece[B7] | Piece[A7],
		/* A8 */  0,
		/* B8 */  Piece[A8],
		/* C8 */  Piece[B8] | Piece[A8],
		/* D8 */  Piece[C8] | Piece[B8] | Piece[A8],
		/* E8 */  Piece[D8] | Piece[C8] | Piece[B8] | Piece[A8],
		/* F8 */  Piece[E8] | Piece[D8] | Piece[C8] | Piece[B8] | Piece[A8],
		/* G8 */  Piece[F8] | Piece[E8] | Piece[D8] | Piece[C8] | Piece[B8] | Piece[A8],
		/* H8 */  Piece[G8] | Piece[F8] | Piece[E8] | Piece[D8] | Piece[C8] | Piece[B8] | Piece[A8],
	}

};

static void printBitBoard(BitBoard b)
{
	for (int i = 63; i >= 0; i--)
	{
		std::cout << (((b & LookupTables::Piece[i]) == 0) ? 0 : 1);
		if (((i) % 8) == 0)
		{
			std::cout << std::endl;
		}
	}
}
#endif
