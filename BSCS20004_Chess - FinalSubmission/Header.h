#pragma once
#include<iostream>
#include<windows.h>
using namespace std;
#include<conio.h>
#include<math.h>
#include<Windows.h>
struct Position
{
	int ri, ci;
};
enum Colour
{
	BLACK,
	WHITE
};
struct MoveMade
{
	Position Sor;
	Position Des;
	char K;
	char ifPro;
};
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);


