#include "Bishop.h"

Bishop::Bishop(Position _Pos, Colour _Col, Board* _Bor) :Piece(_Pos, _Col, _Bor)
{
	if (_Col == BLACK)
	{
		Sym = 'B';
	}
	else
	{
		Sym = 'b';
	}
}
bool Bishop::AllowedMove(Position P1, Position P2)
{
	if (isDiagonal(P1, P2) && isDiagonalPathClear(P1, P2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Bishop::Draw(int ri, int ci)
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
	gotoRowCol(ri + 2, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 3, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 4, ci + 4);
	cout << char(-37);
	gotoRowCol(ri + 5, ci + 4);
	cout << char(-37) ;
	gotoRowCol(ri + 6, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 7, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
Bishop::~Bishop()
{

}