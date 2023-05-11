#include "King.h"

King::King(Position _Pos, Colour _Col, Board* _Bor) :Piece(_Pos, _Col, _Bor)
{
	if (_Col == BLACK)
	{
		Sym = 'K';
	}
	else
	{
		Sym = 'k';
	}
}
bool King::AllowedMove(Position P1, Position P2)
{
	if (abs(P1.ri - P2.ri) > 1)
	{
		return false;
	}
	else if (abs(P1.ci - P2.ci) > 1)
	{
		return false;
	}
	if (isVertical(P1, P2) and isVerticalPathClear(P1, P2))
	{
		return true;
	}
	else if (isHorizontal(P1, P2) and isHorizontalPathClear(P1, P2))
	{
		return true;
	}
	else if (isDiagonal(P1, P2) and isDiagonalPathClear(P1, P2))
	{
		return true;
	}
	return false;
}
void King::Draw(int ri, int ci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	ri = P.ri * 10;
	ci = P.ci * 10;
	if (C == WHITE)
	{
		SetConsoleTextAttribute(H, 7);
	}
	else
	{
		SetConsoleTextAttribute(H, 0);
	}
	gotoRowCol(ri + 1, ci + 4);
	cout << char(-37);
	gotoRowCol(ri + 2, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 3, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 4, ci + 4);
	cout << char(-37) ;
	gotoRowCol(ri + 5, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 6, ci + 4);
	cout << char(-37);
	gotoRowCol(ri + 7, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 8, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
King::~King()
{

}