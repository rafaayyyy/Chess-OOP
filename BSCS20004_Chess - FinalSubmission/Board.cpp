#include "Board.h"
#include <string>
#include <Windows.h>
#include <fstream>
bool gameend = false;
HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
Board::Board()
{
	Dim = 8;
	NOP = 2;
	Init();
	CC = WHITE;
}
Board::Board(string name)
{
	InitFile(name);
}
void Board::Init()
{
	Ps = new Piece **[Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		Ps[i] = new Piece * [Dim] {};
	}
	FileBoard = new char* [Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		FileBoard[i] = new char[Dim] {};
	}
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (ri == 1)
			{
				Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ BLACK }, this);
				FileBoard[ri][ci] = 'P';
			}
			else if (ri == 6)
			{
				Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ WHITE }, this);
				FileBoard[ri][ci] = 'p';
			}
			else if (ri == 0)
			{
				if (ci == 0 or ci == 7)
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'R';
				}
				else if(ci == 1 or ci == 6)
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'H';
				}
				else if (ci == 2 or ci == 5)
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'B';
				}
				else if (ci == 3)
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'Q';
				}
				else if (ci == 4)
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'K';
				}
			}
			else if (ri == 7)
			{
				if (ci == 0 or ci == 7)
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'r';
				}
				else if (ci == 1 or ci == 6)
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'h';
				}
				else if (ci == 2 or ci == 5)
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'b';
				}
				else if (ci == 4)
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'k';
				}
				else if (ci == 3)
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'q';
				}
			}
			else
			{
				FileBoard[ri][ci] = '-';
			}
		}
	}
	cout << "Enter Name of Player 1: ";
	getline(cin, A);
	cout << "Enter Name of Player 2: ";
	getline(cin, B);
}
void Board::InitFile(string name)
{
	ifstream read(name);
	int K;
	char RC;
	if (!read)
	{
		cout << "No Such File Exists.";
		return;
	}
	read >> Dim >> A >> B >> K;
	if (K == 1)
		CC = WHITE;
	else if (K == 0)
		CC = BLACK;
	Ps = new Piece * *[Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		Ps[i] = new Piece * [Dim] {};
	}
	FileBoard = new char* [Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		FileBoard[i] = new char[Dim] {};
	}
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			read >> RC;
			if (RC >= 'A' and RC <= 'Z')
			{
				if (RC == 'P')
				{
					Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'P';
				}
				else if (RC == 'R')
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'R';
				}
				else if (RC == 'H')
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'H';
				}
				else if (RC == 'B')
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'B';
				}
				else if (RC == 'Q')
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'Q';
				}
				else if (RC == 'K')
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'K';
				}
			}
			else if (RC >= 'a' and RC <= 'z')
			{
				if (RC == 'p')
				{
					Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'p';
				}
				else if (RC == 'r')
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'r';
				}
				else if (RC == 'h')
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'h';
				}
				else if (RC == 'b')
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'b';
				}
				else if (RC == 'k')
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'k';
				}
				else if (RC == 'q')
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'q';
				}
			}
			else if (RC == '-')
			{
				FileBoard[ri][ci] = '-';
			}
		}
	}
	int size;
	read >> size;
	MoveMade M;
	for (int i = 0; i < size; i++)
	{
		read >> M.Sor.ri >> M.Sor.ci >> M.Des.ri >> M.Des.ci >> M.K >> M.ifPro;
		Moves.push_back(M);
	}
}
void Board::SaveGame()
{
	system("cls");
	string N;
	cout << "Enter the name of your save file: ";
	getline(cin, N);
	ofstream write(N);
	write << Dim << endl;
	write << A << endl;
	write << B << endl;
	if (CC == WHITE)
		write << 1 << endl;
	if (CC == BLACK)
		write << 0 << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			write << FileBoard[i][j];
		}
		write << endl;
	}
	write << Moves.size() << endl;
	for (int i = 0; i < Moves.size(); i++)
	{
		write << Moves[i].Sor.ri << "  " << Moves[i].Sor.ci << "  ";
		write << Moves[i].Des.ri << "  " << Moves[i].Des.ci;
		write << "  " << Moves[i].K << "  " << Moves[i].ifPro << endl;
	}
	DrawBoard();
}
void Board::Draw()
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr)
			{
				Ps[ri][ci]->Draw(ri, ci);
			}
		}
	}
}
Piece* Board::GetPiece(int ri, int ci)
{
	return Ps[ri][ci];
}
void Board::TurnChange()
{
	if (CC == WHITE)
	{
		CC = BLACK;
	}
	else
	{
		CC = WHITE;
	}
}
void Board::AddMove(Position P1, Position P2 , char k, char pro)
{
	MoveMade S{ P1, P2 , k, pro};
	Moves.push_back(S);
}
void Board::Play()
{
	DrawBoard();
	while (true)
	{
		Move();
		TurnChange();
		if (gameend == true)
		{
			return;
		}
	}
}
bool Board::DimensionsCheck(Position S, Position E)
{
	if (((S.ri >= 0 and S.ri <= 7) and (S.ci >= 0 and S.ci <= 7)) && ((E.ri >= 0 and E.ri <= 7) and (E.ci >= 0 and E.ci <= 7)))
	{
		return true;
	}
	return false;
}
void Board::FileDraw(int ri, int ci, char c)
{
	FileBoard[ri][ci] = c;
}
void Board::FileUnDraw(int ri, int ci)
{
	FileBoard[ri][ci] = '-';
}
void Board::DisplayWinMsg()
{
	system("cls");
	if (CC == 1)
		cout << "Player 1 ( " << A << " ) with colour WHITE wins!!!";
	else
		cout << "Player 2 ( " << B << " ) with colour BLACK wins!!!";
}
void Board::DisplayDrawMsg()
{
	system("cls");
	cout << "Match has been DRAWN!!!";
}
bool Board::SelfCheck(Position S, Position E)
{
	bool selfcheck;
	int kr, kc;
	TurnChange();
	selfcheck = InCheck();
	TurnChange();
	return selfcheck;
}
void Board::Move()
{
	int kr, kc;
	int kr2 = 0, kc2 = 0;
	Position S, E;
	while (true)
	{
		char pd;
		char KillChar;
		Draw();
		SetConsoleTextAttribute(H, 15);
		gotoRowCol(9, 120);
		cout << ((CC == 1) ? "(White Move)" : "(Black Move)");
		gotoRowCol(10, 120);
		cout << "Make your move.";
		if (StaleMate() == true)
		{
			DisplayDrawMsg();
			gameend = true;
		}	
		getRowColbyLeftClick(S.ri, S.ci);
		if ((S.ri >= 1 and S.ri < 10) and (S.ci >= 100 and S.ci < 110))
		{
			SaveGame();
			TurnChange();
			return;
		}
		if ((S.ri >= 16 and S.ri < 25) and (S.ci >= 100 and S.ci < 110))
		{
			Replay();
			TurnChange();
			return;
		}
		if ((S.ri >= 31 and S.ri < 40) and (S.ci >= 100 and S.ci < 110))
		{
			UndoMove();
			TurnChange();
			return;
		}
		S.ri = S.ri / 10;
		S.ci = S.ci / 10;
		if (Ps[S.ri][S.ci] == nullptr)
		{
			gotoRowCol(10, 120);
			cout << "INVALID MOVE!!!";
			system("pause");
			DrawBoard();
		}
		else if (CC == 1)
		{
			if (Ps[S.ri][S.ci]->GetColour() == WHITE)
			{
				HighlightPath(S.ri, S.ci);
				getRowColbyLeftClick(E.ri, E.ci);
				if ((E.ri >= 1 and E.ri < 10) and (E.ci >= 100 and E.ci < 110))
				{
					SaveGame();
					TurnChange();
					return;
				}
				if ((S.ri >= 16 and S.ri < 25) and (S.ci >= 100 and S.ci < 110))
				{
					Replay();
					TurnChange();
					return;
				}
				if ((S.ri >= 31 and S.ri < 40) and (S.ci >= 100 and S.ci < 110))
				{
					UndoMove();
					TurnChange();
					return;
				}
				E.ri = E.ri / 10;
				E.ci = E.ci / 10;
				UnHighlightPath(S.ri, S.ci);
				if (DimensionsCheck(S,E) == true)
				{
					if (PieceOnPiece(E.ri, E.ci) == true)
					{
						if (Ps[S.ri][S.ci]->AllowedMove(S, E))
						{
							KillChar = FileBoard[E.ri][E.ci];
							if (Ps[E.ri][E.ci] != nullptr)
							{
								Ps[E.ri][E.ci]->Remove();
								FileUnDraw(E.ri, E.ci);
							}
							Ps[S.ri][S.ci]->Remove();
							FileDraw(E.ri, E.ci, FileBoard[S.ri][S.ci]);
							FileUnDraw(S.ri, S.ci);
							Ps[E.ri][E.ci] = Ps[S.ri][S.ci];
							Ps[S.ri][S.ci] = nullptr;
							Ps[E.ri][E.ci]->NewPos(Position{ E.ri, E.ci });
							Ps[E.ri][E.ci]->Draw(E.ri, E.ci);
							PawnPromotion(E.ri, E.ci, pd);
							AddMove(S, E, KillChar, pd);
							if (SelfCheck(S, E) == true)
							{
								system("cls");
								SetConsoleTextAttribute(H, 15);
								cout << "You put your king in danger...INVALID MOVE!!!";
								Sleep(1000);
								DrawBoard();
								UndoMove();
								//TurnChange();
								return;
							}
							if (InCheck() == true)
							{
								HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
								SetConsoleTextAttribute(H, 12);
								TurnChange();
								FindKing(kr, kc);
								kr2 = kr; kc2 = kc;
								Ps[kr][kc]->HighlightBox(kr, kc);
								TurnChange();
								if (CheckMate() == true)
								{
									system("cls");
									SetConsoleTextAttribute(H, 15);
									DisplayWinMsg();
									gameend = true;
								}
							}
							else
							{
								Ps[kr2][kc2]->UnHighlightBox(kr2, kc2);
							}
							break;
						}
						else
						{
							gotoRowCol(10, 120);
							cout << "INVALID MOVE!!!";
							system("pause");
							DrawBoard();
						}
					}
					else
					{
						gotoRowCol(10, 120);
						cout << "INVALID MOVE!!!";
						system("pause");
						DrawBoard();
					}
				}
				else
				{
					gotoRowCol(10, 120);
					cout << "INVALID MOVE!!!";
					system("pause");
					DrawBoard();
				}
			}
			else
			{
				gotoRowCol(10, 120);
				cout << "INVALID MOVE!!!";
				system("pause");
				DrawBoard();
			}
		}
		else
		{
			if (Ps[S.ri][S.ci]->GetColour() == BLACK)
			{
				HighlightPath(S.ri, S.ci);
				getRowColbyLeftClick(E.ri, E.ci);
				if ((E.ri >= 1 and E.ri < 10) and (E.ci >= 100 and E.ci < 110))
				{
					SaveGame();
					TurnChange();
					return;
				}
				if ((S.ri >= 16 and S.ri < 25) and (S.ci >= 100 and S.ci < 110))
				{
					Replay();
					TurnChange();
					return;
				}
				if ((S.ri >= 31 and S.ri < 40) and (S.ci >= 100 and S.ci < 110))
				{
					UndoMove();
					TurnChange();
					return;
				}
				E.ri = E.ri / 10;
				E.ci = E.ci / 10;
				UnHighlightPath(S.ri, S.ci);
				if (DimensionsCheck(S, E) == true)
				{
					if (PieceOnPiece(E.ri, E.ci) == true)
					{
						if (Ps[S.ri][S.ci]->AllowedMove(S, E))
						{
							KillChar = FileBoard[E.ri][E.ci];
							if (Ps[E.ri][E.ci] != nullptr)
							{
								Ps[E.ri][E.ci]->Remove();
								FileUnDraw(E.ri, E.ci);
							}
							Ps[S.ri][S.ci]->Remove();
							FileDraw(E.ri, E.ci, FileBoard[S.ri][S.ci]);
							FileUnDraw(S.ri, S.ci);
							Ps[E.ri][E.ci] = Ps[S.ri][S.ci];
							Ps[S.ri][S.ci] = nullptr;
							Ps[E.ri][E.ci]->NewPos(Position{ E.ri, E.ci });
							Ps[E.ri][E.ci]->Draw(E.ri, E.ci);
							PawnPromotion(E.ri, E.ci, pd);
							AddMove(S, E, KillChar, pd);
							if (SelfCheck(S, E) == true)
							{
								system("cls");
								SetConsoleTextAttribute(H, 15);
								cout << "You put your king in danger...INVALID MOVE!!!";
								Sleep(1000);
								DrawBoard();
								UndoMove();
								//TurnChange();
								return;
							}
							if (InCheck() == true)
							{
								HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
								SetConsoleTextAttribute(H, 12);
								TurnChange();
								FindKing(kr, kc);
								kr2 = kr; kc2 = kc;
								Ps[kr][kc]->HighlightBox(kr, kc);
								TurnChange();
								if (CheckMate() == true)
								{
									system("cls");
									SetConsoleTextAttribute(H, 15);
									DisplayWinMsg();
									gameend = true;
								}
							}
							else
							{
								Ps[kr2][kc2]->UnHighlightBox(kr2, kc2);
							}
							break;
						}
						else
						{
							gotoRowCol(10, 120);
							cout << "INVALID MOVE!!!";
							system("pause");
							DrawBoard();
						}
					}
					else
					{
						gotoRowCol(10, 120);
						cout << "INVALID MOVE!!!";
						system("pause");
						DrawBoard();
					}
				}
				else
				{
					gotoRowCol(10, 120);
					cout << "INVALID MOVE!!!";
					system("pause");
					DrawBoard();
				}
			}
			else
			{
				gotoRowCol(10, 120);
				cout << "INVALID MOVE!!!";
				system("pause");
				DrawBoard();
			}
		}
	}
}
void Board::ReturnNewPiece(char k, int ri, int ci)
{
	if (k >= 'A' and k <= 'Z')
	{
		if (k == 'P')
		{
			Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'P';
		}
		else if (k == 'R')
		{
			Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'R';
		}
		else if (k == 'H')
		{
			Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'H';
		}
		else if (k == 'B')
		{
			Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'B';
		}
		else if (k == 'Q')
		{
			Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'Q';
		}
		else if (k == 'K')
		{
			Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ BLACK }, this);
			FileBoard[ri][ci] = 'K';
		}
	}
	else if (k >= 'a' and k <= 'z')
	{
		if (k == 'p')
		{
			Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'p';
		}
		else if (k == 'r')
		{
			Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'r';
		}
		else if (k == 'h')
		{
			Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'h';
		}
		else if (k == 'b')
		{
			Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'b';
		}
		else if (k == 'k')
		{
			Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'k';
		}
		else if (k == 'q')
		{
			Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
			FileBoard[ri][ci] = 'q';
		}
	}
	else if (k == '-')
	{
		FileBoard[ri][ci] = '-';
	}
}
void Board::UndoMove()
{
	int i = Moves.size() - 1;
	if (i >= 0)
	{
		Position NewS;
		Position NewD;
		NewS = Moves[i].Des;
		NewD = Moves[i].Sor;
		Ps[NewS.ri][NewS.ci]->Remove();
		FileDraw(NewD.ri, NewD.ci, FileBoard[NewS.ri][NewS.ci]);
		FileUnDraw(NewS.ri, NewS.ci);
		Ps[NewD.ri][NewD.ci] = Ps[NewS.ri][NewS.ci];
		if (Moves[i].K != '-')
		{
			ReturnNewPiece(Moves[i].K, NewS.ri, NewS.ci);
		}
		else
		{
			Ps[NewS.ri][NewS.ci] = nullptr;
		}
		if (Moves[i].ifPro >='a' and Moves[i].ifPro <= 'z')
		{
			Ps[Moves[i].Sor.ri][Moves[i].Sor.ci] = nullptr;
			Ps[Moves[i].Sor.ri][Moves[i].Sor.ci] = new Pawn(Position{ Moves[i].Sor.ri, Moves[i].Sor.ci }, Colour{ WHITE }, this);
			FileBoard[Moves[i].Sor.ri][Moves[i].Sor.ci] = 'p';
		}
		else if (Moves[i].ifPro >= 'A' and Moves[i].ifPro <= 'Z')
		{
			Ps[Moves[i].Sor.ri][Moves[i].Sor.ci] = nullptr;
			Ps[Moves[i].Sor.ri][Moves[i].Sor.ci] = new Pawn(Position{ Moves[i].Sor.ri, Moves[i].Sor.ci }, Colour{ BLACK }, this);
			FileBoard[Moves[i].Sor.ri][Moves[i].Sor.ci] = 'P';
		}
		Ps[NewD.ri][NewD.ci]->NewPos(Position{ NewD.ri, NewD.ci });
		Ps[NewD.ri][NewD.ci]->Draw(NewD.ri, NewD.ci);
		Moves.pop_back();
		TurnChange();
	}
}
void Board::OriginalLocation()
{
	Ps = new Piece * *[Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		Ps[i] = new Piece * [Dim] {};
	}
	FileBoard = new char* [Dim] {};
	for (int i = 0; i < Dim; i++)
	{
		FileBoard[i] = new char[Dim] {};
	}
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (ri == 1)
			{
				Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ BLACK }, this);
				FileBoard[ri][ci] = 'P';
			}
			else if (ri == 6)
			{
				Ps[ri][ci] = new Pawn(Position{ ri, ci }, Colour{ WHITE }, this);
				FileBoard[ri][ci] = 'p';
			}
			else if (ri == 0)
			{
				if (ci == 0 or ci == 7)
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'R';
				}
				else if (ci == 1 or ci == 6)
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'H';
				}
				else if (ci == 2 or ci == 5)
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'B';
				}
				else if (ci == 3)
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'Q';
				}
				else if (ci == 4)
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ BLACK }, this);
					FileBoard[ri][ci] = 'K';
				}
			}
			else if (ri == 7)
			{
				if (ci == 0 or ci == 7)
				{
					Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'r';
				}
				else if (ci == 1 or ci == 6)
				{
					Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'h';
				}
				else if (ci == 2 or ci == 5)
				{
					Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'b';
				}
				else if (ci == 4)
				{
					Ps[ri][ci] = new King(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'k';
				}
				else if (ci == 3)
				{
					Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
					FileBoard[ri][ci] = 'q';
				}
			}
			else
			{
				FileBoard[ri][ci] = '-';
			}
		}
	}
}
void Board::ReplayPieceCreate(int i, int ri , int ci)
{
	char cp = Moves[i].ifPro;
	if (cp >= 'a' and cp <= 'z')
	{
		if (cp == 'q')
		{
			FileBoard[ri][ci] = 'q';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
		}
		else if (cp == 'r')
		{
			FileBoard[ri][ci] = 'r';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
		}
		else if (cp == 'b')
		{
			FileBoard[ri][ci] = 'b';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
		}
		else if (cp == 'h')
		{
			FileBoard[ri][ci] = 'h';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
		}
	}
	else if ((Moves[i].ifPro >= 'A' and Moves[i].ifPro <= 'Z'))
	{
		if (cp == 'Q')
		{
			FileBoard[ri][ci] = 'Q';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
		}
		else if (cp == 'R')
		{
			FileBoard[ri][ci] = 'R';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
		}
		else if (cp == 'B')
		{
			FileBoard[ri][ci] = 'B';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
		}
		else if (cp == 'H')
		{
			FileBoard[ri][ci] = 'H';
			Ps[ri][ci] = nullptr;
			Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
		}
	}
}
void Board::Replay()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	OriginalLocation();
	DrawBoard();
	CC = WHITE;
	char kc;
	if (Moves.size() != 0)
	{
		do
		{
			Draw();
			Position S = Moves[i].Sor;
			Position E = Moves[i].Des;
			if (Ps[E.ri][E.ci] != nullptr)
			{
				Ps[E.ri][E.ci]->Remove();
				FileUnDraw(E.ri, E.ci);
			}
			Ps[S.ri][S.ci]->Remove();
			FileDraw(E.ri, E.ci, FileBoard[S.ri][S.ci]);
			FileUnDraw(S.ri, S.ci);
			Ps[E.ri][E.ci] = Ps[S.ri][S.ci];
			Ps[S.ri][S.ci] = nullptr;
			Ps[E.ri][E.ci]->NewPos(Position{ E.ri, E.ci });
			ReplayPieceCreate(i, E.ri, E.ci);
			Ps[E.ri][E.ci]->Draw(E.ri, E.ci);
			i++;
			SetConsoleTextAttribute(H, 15);
			gotoRowCol(9, 120);
			cout << ((CC == 0) ? "(White Move)" : "(Black Move)");
			Sleep(1000);
			TurnChange();
		} while (i < Moves.size());
	}
}
void Board::DrawBoard()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int flag = 0;
	for (int R = 1; R <= 8; R++)
	{
		for (int ri = 1; ri <= 10; ri++)
		{
			for (int C = 1; C <= 8; C++)
			{
				for (int ci = 1; ci <= 10; ci++)
				{
					if (flag == 0)
					{
						if (C % 2 == 0)
						{
							SetConsoleTextAttribute(H, 6);
							cout << char(-37);
						}
						else
						{
							SetConsoleTextAttribute(H, 14);
							cout << char(-37);
						}
					}
					else
					{
						if (C % 2 == 0)
						{
							SetConsoleTextAttribute(H, 14);
							cout << char(-37);
						}
						else
						{
							SetConsoleTextAttribute(H, 6);
							cout << char(-37);
						}
					}
				}
			}
			cout << endl;
		}
		if (flag == 0)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	for (int r = 1; r < 10; r++)
	{
		for (int c = 100; c < 110; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(H, 12);
			cout << char(-37);
		}
	}
	SetConsoleTextAttribute(H, 15);
	gotoRowCol(5, 103);
	cout << "SAVE";
	for (int r = 31; r < 40; r++)
	{
		for (int c = 100; c < 110; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(H, 12);
			cout << char(-37);
		}
	}
	SetConsoleTextAttribute(H, 15);
	gotoRowCol(35, 103);
	cout << "Undo";
	for (int r = 16; r < 25; r++)
	{
		for (int c = 100; c < 110; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(H, 12);
			cout << char(-37);
		}
	}
	SetConsoleTextAttribute(H, 15);
	gotoRowCol(20, 103);
	cout << "Replay";
	gotoRowCol(1, 120);
	cout << "Player 1 : " << A << " ( White)";
	gotoRowCol(2, 120);
	cout << "Player 2 : " << B << " ( Black)";
}
bool Board::PieceOnPiece(int ri, int ci)
{
	if (Ps[ri][ci] == nullptr)
	{
		return true;
	}
	else if(Ps[ri][ci]->GetColour() == CC)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Board::HighlightPath(int Row, int Col)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int C;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (Ps[ri][ci] != nullptr)
			{
				SetConsoleTextAttribute(H, 12);
			}
			else
			{
				SetConsoleTextAttribute(H, 2);
			}
			if (Ps[Row][Col]->AllowedMove({ Row, Col }, { ri, ci }) and PieceOnPiece(ri, ci) == true)
			{
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
		}
	}
}
void Board::UnHighlightPath(int Row, int Col)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int C;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if ((ri % 2 != 0 && ci % 2 != 0) || (ri % 2 == 0 && ci % 2 == 0))
			{
				C = 14;
			}
			if ((ri % 2 != 0 && ci % 2 == 0) || (ri % 2 == 0 && ci % 2 != 0))
			{
				C = 6;
			}
			SetConsoleTextAttribute(H, C);
			if (Ps[Row][Col]->AllowedMove({ Row, Col }, { ri, ci }) and PieceOnPiece(ri, ci) == true)
			{
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
		}
	}
}
void PawnMenu()
{
	system("cls");
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 15);
	cout << "Promote the pawn to" << endl;
	cout << "1) QUEEN" << endl;
	cout << "2) ROOK" << endl;
	cout << "3) BISHOP" << endl;
	cout << "4) KNIGHT" << endl;
	cout << endl << endl << "You choose : ";
}
void Board::PawnPromotion(int ri, int ci, char& dum)
{
	int pc;
	dum = '-';
	if (CC == WHITE)
	{
		if (ri == 0 && FileBoard[ri][ci] == 'p')
		{
			do
			{
				PawnMenu();
				cin >> pc;
			} while (!(pc > 0 and pc < 5));
			if (pc == 1)
			{
				FileBoard[ri][ci] = 'q';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ WHITE }, this);
				dum = 'q';
			}
			else if (pc == 2)
			{
				FileBoard[ri][ci] = 'r';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ WHITE }, this);
				dum = 'r';
			}
			else if (pc == 3)
			{
				FileBoard[ri][ci] = 'b';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ WHITE }, this);
				dum = 'b';
			}
			else if (pc == 4)
			{
				FileBoard[ri][ci] = 'h';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ WHITE }, this);
				dum = 'h';
			}
			DrawBoard();
			Draw();
		}
	}
	else if (CC == BLACK)
	{
		if (ri == 7 && FileBoard[ri][ci] == 'P')
		{
			do
			{
				PawnMenu();
				cin >> pc;
			} while (!(pc > 0 and pc < 5));
			if (pc == 1)
			{
				FileBoard[ri][ci] = 'Q';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Queen(Position{ ri, ci }, Colour{ BLACK }, this);
				dum = 'Q';
			}
			else if (pc == 2)
			{
				FileBoard[ri][ci] = 'R';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Rook(Position{ ri, ci }, Colour{ BLACK }, this);
				dum = 'R';
			}
			else if (pc == 3)
			{
				FileBoard[ri][ci] = 'B';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Bishop(Position{ ri, ci }, Colour{ BLACK }, this);
				dum = 'B';
			}
			else if (pc == 4)
			{
				FileBoard[ri][ci] = 'H';
				Ps[ri][ci] = nullptr;
				Ps[ri][ci] = new Knight(Position{ ri, ci }, Colour{ BLACK }, this);
				dum = 'H';
			}
			DrawBoard();
			Draw();
		}
	}
}
void Board::FindKing(int& row, int& col)
{
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->AmIAking())
			{
				if (Ps[ri][ci]->GetColour() == CC)
				{
					row = ri;
					col = ci;
				}
			}
		}
	}
}
bool Board::InCheck()
{
	int ri, ci;
	TurnChange();
	FindKing(ri, ci);
	for (int R = 0; R < 8; R++)
	{
		for (int C = 0; C < 8; C++)
		{
			if (Ps[R][C] != nullptr && Ps[R][C]->GetColour() != CC)
			{
				if (Ps[R][C]->AllowedMove({ R,C }, { ri,ci }))
				{
					TurnChange();
					return true;
				}
			}
		}
	}
	TurnChange();
	return false;
}
void Board::Move2(Position S, Position E)
{
	char killchar = FileBoard[E.ri][E.ci];
	if (Ps[E.ri][E.ci] != nullptr)
	{
		FileUnDraw(E.ri, E.ci);
	}
	FileDraw(E.ri, E.ci, FileBoard[S.ri][S.ci]);
	FileUnDraw(S.ri, S.ci);
	Ps[E.ri][E.ci] = Ps[S.ri][S.ci];
	Ps[S.ri][S.ci] = nullptr;
	Ps[E.ri][E.ci]->NewPos(Position{ E.ri, E.ci });
	AddMove(S, E, killchar, '-');
}
void Board::Undo2()
{
	int i = Moves.size() - 1;
	if (i >= 0)
	{
		Position NewS;
		Position NewD;
		NewS = Moves[i].Des;
		NewD = Moves[i].Sor;
		FileDraw(NewD.ri, NewD.ci, FileBoard[NewS.ri][NewS.ci]);
		FileUnDraw(NewS.ri, NewS.ci);
		Ps[NewD.ri][NewD.ci] = Ps[NewS.ri][NewS.ci];
		if (Moves[i].K != '-')
		{
			ReturnNewPiece(Moves[i].K, NewS.ri, NewS.ci);
		}
		else
		{
			Ps[NewS.ri][NewS.ci] = nullptr;
		}
		Ps[NewD.ri][NewD.ci]->NewPos(Position{ NewD.ri, NewD.ci });
		Moves.pop_back();
		TurnChange();
	}
}
bool Board::CheckMate()
{
	TurnChange();
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->GetColour() == CC)
			{
				for (int R = 0; R < 8; R++)
				{
					for (int C = 0; C < 8; C++)
					{
						if ((Ps[ri][ci]->AllowedMove({ ri,ci }, { R,C }) == true) /*&& PieceOnPiece(R,C)*/ && !(Ps[R][C] != nullptr && Ps[R][C]->GetColour() == CC) /*&& Ps[ri][ci]->AmIAking() == false*/ /*&& Ps[R][C] != nullptr*/ /* && !(Ps[R][C]!=nullptr && Ps[R][C]->AmIAking())*/)
						{				
							Move2({ ri,ci }, { R,C });
							TurnChange();
							if (InCheck() == false)
							{
								Undo2();
								TurnChange();
								return false;
							}
							else
							{
								Undo2();
							}
							
						}
					}
				}
			}
		}
	}
	TurnChange();
	return true;
}
bool Board::AnyLegalMove()
{
	TurnChange();
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->GetColour() == CC)
			{
				for (int R = 0; R < 8; R++)
				{
					for (int C = 0; C < 8; C++)
					{
						if (Ps[ri][ci]->AllowedMove({ ri,ci }, { R,C }) == true && PieceOnPiece(R,C)/* && (ri != R && ci != C)*/)
						{
							Move2({ ri,ci }, { R,C });
							TurnChange();
							if (!InCheck())
							{
								Undo2();
								TurnChange();
								return true;
							}
							else
							{
								Undo2();
							}
						}
					}
				}
			}
		}
	}
	TurnChange();
	return false;
}
bool Board::StaleMate()
{
	TurnChange();
	if (InCheck() == false && AnyLegalMove() == false)
	{
		return true;
	}
	else
	{
		TurnChange();
		return false;
	}
}
Board::~Board()
{

} 