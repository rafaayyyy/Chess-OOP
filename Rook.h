#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(Position _Pos, Colour _Col, Board* _Bor);
    void Draw(int ri, int ci) override;
    bool AllowedMove(Position P1, Position P2) override;
    bool AmIAking() { return false; }
    ~Rook();
};

