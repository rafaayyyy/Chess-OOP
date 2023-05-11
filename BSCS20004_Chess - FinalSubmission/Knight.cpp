#include "Knight.h"

Knight::Knight(Position _Pos, Colour _Col, Board* _Bor) :Piece(_Pos, _Col, _Bor)
{
	if (_Col == BLACK)
	{
		Sym = 'H';
	}
	else
	{
		Sym = 'h';
	}
}
bool Knight::AllowedMove(Position P1, Position P2)
{
	if (abs(P1.ri - P2.ri) == 2 and abs(P1.ci - P2.ci) == 1)
	{
		return true;
	}
	else if (abs(P1.ri - P2.ri) == 1 and abs(P1.ci - P2.ci) == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Knight::Draw(int ri, int ci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	if (C == WHITE)
	{
		SetConsoleTextAttribute(H, 7);
	}
	else
	{
		SetConsoleTextAttribute(H, 0);
	}
	ri = P.ri * 10;
	ci = P.ci * 10;
	gotoRowCol(ri + 1, ci + 4);
	cout << char(-37) ;
	gotoRowCol(ri + 2, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 3, ci + 2);
	cout << char(-37) << char(-37);
	gotoRowCol(ri + 3, ci + 5);
	cout << char(-37) << char(-37);
	gotoRowCol(ri + 4, ci + 5);
	cout << char(-37) << char(-37);
	gotoRowCol(ri + 5, ci + 5);
	cout << char(-37) << char(-37);
	gotoRowCol(ri + 6, ci + 4);
	cout << char(-37) << char(-37);
	gotoRowCol(ri + 7, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 8, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
Knight::~Knight()
{

}