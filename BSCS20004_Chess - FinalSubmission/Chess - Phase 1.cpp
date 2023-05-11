#include <iostream>
#include "Board.h"
#include <string>
using namespace std;

int main()
{
	/*int d;
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();
			cout << d << endl;
		}
	}*/
	int k;
	do
	{
		system("cls");
		cout << "You want to open a save file or start a new game?\nPress 1 to start a new game.\nPress 2 to enter save file name." << endl;
		cout << "\nYou choose : ";
		cin >> k;
	} while (!(k == 1 or k == 2) /*k != 1 and k != 2*/);
	if (k == 1)
	{
		cin.ignore();
		Board B;
		B.Play();
	}
	else if (k == 2)
	{
		cin.ignore();
		string Name;
		cout << "Enter Save File Name: ";
		getline(cin, Name);
		Board B2(Name);
		B2.Play();
	}
    /*for (int i = 0; i < 256; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << "Text Color" << i << endl;
    }
    return 0;*/
}