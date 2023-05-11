#pragma once
#include "Header.h"
class Board;
class Piece
{
protected:
	Position P;
	Colour C;
	char Sym;
	Board* B;
public:
	Piece(Position Pos, Colour Col, Board* Bor);
	virtual void Draw(int ri, int ci);
	void Remove();
	void NewPos(Position _P);
	Colour GetColour();
	virtual bool AmIAking();
	virtual bool AllowedMove(Position OriPos, Position NewPos);
	bool isHorizontal(Position OriPos, Position NewPos);
	bool isVertical(Position OriPos, Position NewPos);
	bool isDiagonal(Position OriPos, Position NewPos);
	bool isHorizontalPathClear(Position OriPos, Position NewPos);
	bool isVerticalPathClear(Position OriPos, Position NewPos);
	bool isDiagonalPathClear(Position OriPos, Position NewPos);
	void HighlightBox(int ri, int ci);
	void UnHighlightBox(int ri, int ci);
	~Piece();
};

