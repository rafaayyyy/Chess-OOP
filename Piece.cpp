#include "Piece.h"
#include "Header.h"
#include "Board.h"
#include "Windows.h"
Piece::Piece(Position Pos, Colour Col, Board* Bor)
{
	P = Pos;
	C = Col;
	B = Bor;
}
void Piece::Draw(int ri, int ci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	if (C == WHITE)
	{
		SetConsoleTextAttribute(H, 3);
	}
	else
	{
		SetConsoleTextAttribute(H, 6);
	}
	ri = P.ri * 10 + 5;
	ci = P.ci * 10 + 5;
	gotoRowCol(ri, ci);
	cout << Sym;
}
void Piece::Remove()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int C;
	if ((P.ri % 2 != 0 && P.ci % 2 != 0) || (P.ri % 2 == 0 && P.ci % 2 == 0))
	{
		C = 14;
	}
	if ((P.ri % 2 != 0 && P.ci % 2 == 0) || (P.ri % 2 == 0 && P.ci % 2 != 0))
	{
		C = 6;
	}
	for (int r = P.ri * 10; r < (P.ri * 10) + 10; r++)
	{
		for (int c = P.ci * 10; c < (P.ci * 10) + 10; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(H, C);
			cout << char(-37);
		}
	}
}
void Piece::NewPos(Position _P)
{
	P = _P;
}
Colour Piece::GetColour()
{
	P.ri; P.ci;
	return C;
}
bool Piece::isHorizontal(Position OriPos, Position NewPos)
{
	if (OriPos.ri == NewPos.ri)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::isVertical(Position OriPos, Position NewPos)
{
	if (OriPos.ci == NewPos.ci)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::isDiagonal(Position OriPos, Position NewPos)
{
	if (abs(OriPos.ri- NewPos.ri) == abs(OriPos.ci - NewPos.ci))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::isHorizontalPathClear(Position OriPos, Position NewPos)
{
	if (OriPos.ci < NewPos.ci)
	{
		for (int C = OriPos.ci + 1;C < NewPos.ci;C++)
		{
			if (B->GetPiece(OriPos.ri, C) != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int C = OriPos.ci - 1;C > NewPos.ci;C--)
		{
			if (B->GetPiece(OriPos.ri, C) != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
bool Piece::isVerticalPathClear(Position OriPos, Position NewPos)
{
	if (OriPos.ri < NewPos.ri)
	{
		for (int R = OriPos.ri + 1;R < NewPos.ri;R++)
		{
			if (B->GetPiece(R, OriPos.ci) != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int R = OriPos.ri - 1;R > NewPos.ri;R--)
		{
			if (B->GetPiece(R, OriPos.ci) != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
bool Piece::isDiagonalPathClear(Position OriPos, Position NewPos)
{
	int row = OriPos.ri;
	int col = OriPos.ci;
	if (NewPos.ri - OriPos.ri < -1 && NewPos.ci - OriPos.ci < -1) 
	{
		while (row - 1 != NewPos.ri)
		{
			if (B->GetPiece(row - 1, col - 1) != nullptr)
				return false;
			row--;
			col--;
		}
	}
	else if (NewPos.ri - OriPos.ri < -1 && NewPos.ci - OriPos.ci > 1)
	{
		while (row - 1 != NewPos.ri) 
		{
			if (B->GetPiece(row - 1, col + 1) != nullptr)
				return false;
			row--;
			col++;
		}
	}
	else if (NewPos.ri - OriPos.ri > 1 && NewPos.ci - OriPos.ci < -1)
	{
		while (row + 1 != NewPos.ri)
		{
			if (B->GetPiece(row + 1, col - 1) != nullptr)
				return false;
			row++;
			col--;
		}
	}
	else if (NewPos.ri - OriPos.ri > 1 && NewPos.ci - OriPos.ci > 1) 
	{
		while (row + 1 != NewPos.ri) 
		{
			if (B->GetPiece(row + 1, col + 1) != nullptr)
				return false;
			row++;
			col++;
		}
	}
	return true;
}
bool Piece::AllowedMove(Position P1, Position P2)
{
	return true;
}
bool Piece::AmIAking()
{
	return false;
}
void Piece::HighlightBox(int ri, int ci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 12);
	for (int r = ri * 10; r < (ri * 10) + 10; r++)
	{
		for (int c = ci * 10; c < (ci * 10) + 10; c++)
		{
			if ((r > (ri * 10)) and (r < (ri * 10) + 9) && (c > (ci * 10)) and (c < (ci * 10) + 9))
			{
				continue;
			}
			gotoRowCol(r, c);
			cout << char(-37);
		}
	}
}
void Piece::UnHighlightBox(int ri, int ci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int C;
	if ((ri % 2 != 0 && ci % 2 != 0) || (ri % 2 == 0 && ci % 2 == 0))
	{
		C = 14;
	}
	if ((ri % 2 != 0 && ci % 2 == 0) || (ri % 2 == 0 && ci % 2 != 0))
	{
		C = 6;
	}
	for (int r = ri * 10; r < (ri * 10) + 10; r++)
	{
		for (int c = ci * 10; c < (ci * 10) + 10; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(H, C);
			cout << char(-37);
		}
	}
}
Piece::~Piece()
{

}