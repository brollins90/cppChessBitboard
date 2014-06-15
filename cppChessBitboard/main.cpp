#include <iostream>
#include "bitMath.h"
#include "BitBoard.h"
#include "LookupTables.h"
#include "ChessBoard.h"

using std::cout;
using std::endl;


// King
// 1  2  3
// 8  K  4
// 7  6  5
BitBoard compute_king_incomplete(BitBoard king_loc, BitBoard own_side)
{
	/* we can ignore the rank clipping since the overflow/underflow with
		respect to rank simply vanishes. We only care about the file
		overflow/underflow. */ 

	BitBoard king_clip_file_h = king_loc & LookupTables::ClearFile[LookupTables::FILE_H]; 
	BitBoard king_clip_file_a = king_loc & LookupTables::ClearFile[LookupTables::FILE_A]; 

	/* remember the representation of the board in relation to the bitindex 
		when looking at these shifts.... */
	BitBoard spot_1 = king_clip_file_h << 7; 
	BitBoard spot_2 = king_loc << 8; 
	BitBoard spot_3 = king_clip_file_h << 9; 
	BitBoard spot_4 = king_clip_file_h << 1; 

	BitBoard spot_5 = king_clip_file_a >> 7; 
	BitBoard spot_6 = king_loc >> 8; 
	BitBoard spot_7 = king_clip_file_a >> 9; 
	BitBoard spot_8 = king_clip_file_a >> 1; 

	BitBoard king_moves = spot_1 | spot_2 | spot_3 | spot_4 | spot_5 | spot_6 | spot_7 | spot_8; 

	BitBoard KingValid = king_moves & ~own_side; 

	/* compute only the places where the king can move and attack. The caller
		will interpret this as a white or black king. */
	return KingValid;	
}

// Knight
//  - - - - - - - -
//  - - 2 - 3 - - - 
//  - 1 - - - 4 - - 
//  - - - N - - - - 
//  - 8 - - - 5 - - 
//  - - 7 - 6 - - - 
//  - - - - - - - - 
BitBoard compute_knight(BitBoard knight_loc, BitBoard own_side)
{
	/* we can ignore the rank clipping since the overflow/underflow with
		respect to rank simply vanishes. We only care about the file
		overflow/underflow which is much more work for a knight. */ 
	
	BitBoard spot_1_clip = LookupTables::ClearFile[LookupTables::FILE_A] & LookupTables::ClearFile[LookupTables::FILE_B];
	BitBoard spot_2_clip = LookupTables::ClearFile[LookupTables::FILE_A];
	BitBoard spot_3_clip = LookupTables::ClearFile[LookupTables::FILE_H];
	BitBoard spot_4_clip = LookupTables::ClearFile[LookupTables::FILE_H] & LookupTables::ClearFile[LookupTables::FILE_G];

	BitBoard spot_5_clip = LookupTables::ClearFile[LookupTables::FILE_H] & LookupTables::ClearFile[LookupTables::FILE_G];
	BitBoard spot_6_clip = LookupTables::ClearFile[LookupTables::FILE_H];
	BitBoard spot_7_clip = LookupTables::ClearFile[LookupTables::FILE_A];
	BitBoard spot_8_clip = LookupTables::ClearFile[LookupTables::FILE_A] & LookupTables::ClearFile[LookupTables::FILE_B];

	/* The clipping masks we just created will be used to ensure that no
		under or overflow positions are computed when calculating the
		possible moves of the knight in certain files. */

	BitBoard spot_1 = (knight_loc & spot_1_clip) << 6;
	BitBoard spot_2 = (knight_loc & spot_2_clip) << 15;
	BitBoard spot_3 = (knight_loc & spot_3_clip) << 17;
	BitBoard spot_4 = (knight_loc & spot_4_clip) << 10;

	BitBoard spot_5 = (knight_loc & spot_5_clip) >> 6;
	BitBoard spot_6 = (knight_loc & spot_6_clip) >> 15;
	BitBoard spot_7 = (knight_loc & spot_7_clip) >> 17;
	BitBoard spot_8 = (knight_loc & spot_8_clip) >> 10;

	BitBoard KnightValid = spot_1 | spot_2 | spot_3 | spot_4 | spot_5 | spot_6 | spot_7 | spot_8;

	/* compute only the places where the knight can move and attack. The
		caller will determine if this is a white or black night. */
	return KnightValid & ~own_side;
}

/* unlike the king and knight algorithms, pawns move in fundamentally
	different ways for each color, so we need to seperate functions to
	deal with the change in shifting and the opponents color. This is
	the one for computing a white pawn movement. */
BitBoard compute_white_pawns(BitBoard white_pawn_loc, BitBoard all_pieces, BitBoard all_black_pieces, LookupTables *lbts)
{
	/* check the single space infront of the white pawn */
	BitBoard white_pawn_one_step = (white_pawn_loc << 8) & ~all_pieces; 

	/* for all moves that came from rank 2 (home row) and passed the above 
		filter, thereby being on rank 3, check and see if I can move forward 
		one more */
	BitBoard white_pawn_two_steps = ((white_pawn_one_step & LookupTables::MaskRank[LookupTables::RANK_3]) << 8) & ~all_pieces; 

	/* the union of the movements dictate the possible moves forward 
		available */
	BitBoard white_pawn_valid_moves = white_pawn_one_step | white_pawn_two_steps;

	/* next we calculate the pawn attacks */

	/* check the left side of the pawn, minding the underflow File A */
	BitBoard white_pawn_left_attack = (white_pawn_loc & LookupTables::ClearFile[LookupTables::FILE_A]) << 7;

	/* then check the right side of the pawn, minding the overflow File H */
	BitBoard white_pawn_right_attack = (white_pawn_loc & LookupTables::ClearFile[LookupTables::FILE_H]) << 9;

	/* the union of the left and right attacks together make up all the 
		possible attacks */
	BitBoard white_pawn_attacks = white_pawn_left_attack | white_pawn_right_attack;

	/* Calculate where I can _actually_ attack something */
	BitBoard white_pawn_valid_attacks = white_pawn_attacks & all_black_pieces;

	/* then we combine the two situations in which a white pawn can legally 
		attack/move. */
	BitBoard WhitePawnValid = white_pawn_valid_moves | white_pawn_valid_attacks;

	return WhitePawnValid;
}


BitBoard getPositiveRayAttacks(LookupTables::Locations checkLocation, LookupTables::RayDirection dir, BitBoard occupied)
{
	BitBoard attacks = LookupTables::rayAttacks[dir][checkLocation];
	BitBoard blockers = attacks & occupied;

	if (blockers)
	{
		//checkLocation = bitScanForward(blockers);
		//attacks ^= LookupTables::rayAttacks[dir][checkLocation];
	}
	return attacks;
}

int main()
{
	
//	LookupTables* lookup_tables = new LookupTables();
	ChessBoard* board1 = new ChessBoard();

	//cout << B8(01010101) << endl; // 85
	//cout << B16(10101010,01010101) << endl; // 43,605
	//cout << B32(10000000,11111111,10101010,01010101) << endl; // 2,164,238,933
	//Bitboard b1 = (B64(10000000,00000000,00000000,00000000,10000000,11111111,10101010,01010101)); // ??????
	//cout << b1 << endl;
	//cout << B64(01111111,11111111,11111111,11111111,11111111,11111111,11111111,11111111) << endl; // ??????
	//cout << B64(11111111,11111111,11111111,11111111,11111111,11111111,11111111,11111111) << endl; // ??????

	//cout << ( (B8(010) << 5) | (B8(11) << 3) | (B8(101) << 0) ) << endl;
	////*p_reg = ( (B8(010) << 5) | (B8(11) << 3) | (B8(101) << 0) )
	
	
	
	cout << board1->whitePawns << endl;
	cout << board1->whiteRooks << endl;
	cout << board1->whiteKnights << endl;
	cout << board1->whiteBishops << endl;
	cout << board1->whiteQueens << endl;
	cout << board1->whiteKing << endl;
	cout << board1->blackPawns << endl;
	cout << board1->blackRooks << endl;
	cout << board1->blackKnights << endl;
	cout << board1->blackBishops << endl;
	cout << board1->blackQueens << endl;
	cout << board1->blackKing << endl;
	cout << board1->allWhitePieces << endl;
	cout << board1->allBlackPieces << endl;
	cout << board1->allPieces << endl;
	
	cout << (board1->whitePawns & LookupTables::MaskRank[LookupTables::RANK_3]) << endl;
	cout << (board1->whitePawns & LookupTables::MaskRank[LookupTables::RANK_2]) << endl;
	
	cout << sizeof(unsigned long long) << endl;
	cout << "lookup_tables size: " << sizeof(LookupTables) << endl;
	cout << "ChessBoard size: " << sizeof(*board1) << endl;

	BitBoard whiteKingValid = compute_king_incomplete(LookupTables::Piece[LookupTables::E1], board1->allWhitePieces);
	BitBoard whiteKnightValid = compute_knight(LookupTables::Piece[LookupTables::B4], board1->allWhitePieces);
	BitBoard blackKnightValid = compute_knight(LookupTables::Piece[LookupTables::B4], board1->allBlackPieces);
	
	cout << "whiteKingValid: " << whiteKingValid << endl;
	cout << "whiteKnightValid: " << whiteKnightValid << endl;
	cout << "blackKnightValid: " << blackKnightValid << endl;


	
	cout << "allPieces boardPrint: " << endl;
	printBitBoard(board1->allPieces);
	cout << endl;

	cout << "north of e4: " << endl;
	printBitBoard(LookupTables::rayAttacks[LookupTables::NORTH][LookupTables::E4]);
	cout << endl;


	std::cin.ignore();
	return 0;
}




