#include "Pawn.h"
#include "Board.h"
Pawn::Pawn(Position _Pos, Colour _Col, Board* _Bor) :Piece(_Pos, _Col, _Bor)
{
	if (_Col == BLACK)
	{
		Sym = 'P';
	}
	else
	{
		Sym = 'p';
	}
}
bool Pawn::AllowedMove(Position P1, Position P2)
{
	Piece* Pi = B->GetPiece(P1.ri, P1.ci);
	bool check1;
	bool check2;
	if (Pi->GetColour() == WHITE)
	{
		if (P1.ri == 6)
		{
			if ((P1.ri - P2.ri == 1) and (abs(P2.ci - P1.ci) == 1))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return true;
				}
			}
			if ((P1.ri - P2.ri == 1) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P1.ri - P2.ri == 2) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri + 1 , P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P1.ri - P2.ri) == 2 and B->GetPiece(P2.ri, P2.ci) != nullptr)
			{
				return false;
			}
			if (((P1.ri - P2.ri == 2) or (P1.ri - P2.ri == 1)) and (P2.ci == P1.ci))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ((P1.ri - P2.ri == 1) and (abs(P2.ci - P1.ci) == 1))
			{
				if (B->GetPiece(P2.ri , P2.ci) != nullptr)
				{
					return true;
				}
			}
			if ((P1.ri - P2.ri == 1) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P1.ri - P2.ri == 1) and (P2.ci == P1.ci))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if(Pi->GetColour() == BLACK)
	{
		if (P1.ri == 1)
		{
			if ((P2.ri - P1.ri == 1) and (abs(P2.ci - P1.ci) == 1))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return true;
				}
			}
			if ((P2.ri - P1.ri == 1) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P2.ri - P1.ri == 2) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri - 1, P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P2.ri - P1.ri) == 2 and B->GetPiece(P2.ri, P2.ci) != nullptr)
			{
				return false;
			}
			if (((P2.ri - P1.ri == 2) or (P2.ri - P1.ri == 1)) and (P2.ci == P1.ci))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ((P2.ri - P1.ri == 1) and (abs(P2.ci - P1.ci) == 1))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return true;
				}
			}
			if ((P2.ri - P1.ri == 1) and (P2.ci == P1.ci))
			{
				if (B->GetPiece(P2.ri, P2.ci) != nullptr)
				{
					return false;
				}
			}
			if ((P2.ri - P1.ri == 1) and (P2.ci == P1.ci))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
void Pawn::Draw(int ri, int ci)
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
	gotoRowCol(ri + 3, ci + 4);
	cout << char(-37);
	gotoRowCol(ri + 4, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 5, ci + 4);
	cout << char(-37);
	gotoRowCol(ri + 6, ci + 3);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(ri + 7, ci + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
Pawn::~Pawn()
{

}