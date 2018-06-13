#pragma once
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct QInt
{
	int sign = 0;
	vector<char> digit;
};

struct Binary
{
	vector<bool> digit;
};

struct Hexa
{
	vector<char> digit;
};

void init();
void parse(string command, int &p1, int &p2, string &a, string &b, string &op);
void execute(int p1, int p2, string a, string b, string op);

QInt StringToQInt(string x);
Binary StringToBinary(string x);
Hexa StringToHex(string x);

void ScanQInt(QInt &x);
void PrintQInt(QInt x);
void PrintHexa(Hexa hex);
void PrintBinary(Binary x);

Binary DecToBin(QInt x);
QInt BinToDec(Binary bit);

Hexa BinToHex(Binary bit);
Binary HexToBin(Hexa hex);

Hexa DecToHex(QInt x);
QInt HexToDec(Hexa x);

QInt operator + (QInt a, QInt b);
QInt operator - (QInt a, QInt b);
QInt operator & (QInt a, QInt b);
QInt operator | (QInt a, QInt b);
QInt operator ^ (QInt a, QInt b);
QInt operator ~ (QInt a);
QInt operator << (QInt a, int b);
QInt operator >> (QInt a, int b);
bool operator > (QInt a, QInt b);
QInt Div2(QInt x);

Binary operator + (Binary a, Binary b);
Binary operator - (Binary a, Binary b);
Binary operator & (Binary a, Binary b);
Binary operator | (Binary a, Binary b);
Binary operator ^ (Binary a, Binary b);
Binary operator ~ (Binary a);
Binary operator << (Binary a, int b);
Binary operator >> (Binary a, int b);

Hexa operator + (Hexa a, Hexa b);
Hexa operator - (Hexa a, Hexa b);
Hexa operator & (Hexa a, Hexa b);
Hexa operator | (Hexa a, Hexa b);
Hexa operator ^ (Hexa a, Hexa b);
Hexa operator ~ (Hexa a);
Hexa operator << (Hexa a, int b);
Hexa operator >> (Hexa a, int b);