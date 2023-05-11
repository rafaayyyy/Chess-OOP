#include "Rook.h"
#include "Board.h"
Rook::Rook(Position _Pos, Colour _Col, Board* _Bor) :Piece(_Pos, _Col, _Bor)
{
	if (_Col == BLACK)
	{
		Sym = 'R';
	}
	else
	{
		Sym = 'r';
	}  
}
bool Rook::AllowedMove(Position P1, Position P2)
{
	if (isHorizontal(P1, P2) && isHorizontalPathClear(P1, P2))
	{
		return true;
	}
	else if (isVertical(P1, P2) && isVerticalPathClear(P1, P2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Rook::Draw(int ri, int ci)
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
	for (int c = ci + 2; c <= ci + 6; c += 2)
	{
		gotoRowCol(ri + 3, c);
		cout << char(-37);
	}
	gotoRowCol(ri + 4, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 5, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 6, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 7, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
Rook::~Rook()
{

}