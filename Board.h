#pragma once
#include <iostream>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h" 
#include "Queen.h"
#include <vector>
using namespace std;

class Piece;

class Board
{
private:
	int Dim;
	Piece***Ps;
	int NOP;
	Colour CC;
	string A;
	string B;
	char** FileBoard;
	vector<MoveMade>Moves;
public:
	Board();
	Board(string);
	void Init();
	void InitFile(string);
	void SaveGame();
	void FileDraw(int ri, int ci, char c);
	void FileUnDraw(int ri, int ci);
	void AddMove(Position, Position, char k, char pro);
	void UndoMove();
	void Replay();
	void ReplayPieceCreate(int i, int, int);
	void OriginalLocation();
	void ReturnNewPiece(char, int , int );
	void Draw();
	void Play();
	void Move();
	void DrawBoard();
	void TurnChange();
	bool PieceOnPiece(int ri, int ci);
	bool DimensionsCheck(Position S, Position E);
	void HighlightPath(int Row, int Col);
	void UnHighlightPath(int Row, int Col);
	void FindKing(int& , int&);
	Piece* GetPiece(int ri, int ci);
	void PawnPromotion(int ri, int ci, char& dum);
	bool InCheck();
	void Move2(Position S, Position E);
	void Undo2();
	bool CheckMate();
	bool AnyLegalMove();
	bool StaleMate();
	void DisplayWinMsg();
	void DisplayDrawMsg();
	bool SelfCheck(Position, Position);
	~Board();
};

