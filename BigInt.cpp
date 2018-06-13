#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BigInt.h"
using namespace std;

QInt Power_2[128];

/* Phan tich cau lenh doc vao va chuyen gia tri vao cac tham so lenh tuong ung*/
void parse(string command, int &p1, int &p2, string &a, string &b, string &op)
{
	int length = command.size();
	int space = 0;
	for (int i = 0; i < length; i++)
		if (command[i] == ' ')
			space++;

	int pos = 2;
	p1 = command[0] - '0';
	if (p1 == 1)
	{
		p1 = p1 * 10 + (command[1] - '0');
		pos = 3;
	}
	switch (space)
	{
		case 2: {
			if (command[pos] == '~')
			{
				op = "~";
				pos++;
			}
			else
			{
				while (command[pos] != ' ')
					p2 = p2 * 10 + (command[pos++] - '0');
			}
			for (unsigned char i = pos + 1; i < command.size(); i++)
				a = a + command[i];
			break;
		}
		case 3: {
			while (command[pos] != ' ')
				a = a + command[pos++];
			pos++;

			while (command[pos] != ' ')
				op = op + command[pos++];

			for (unsigned char i = pos + 1; i < command.size(); i++)
				b = b + command[i];
			break;
		}
		case 4: {
			while (command[pos] != ' ')
				p2 = p2 * 10 + (command[pos++] - '0');
			pos++;

			while (command[pos] != ' ')
				a = a + command[pos++];
			pos++;

			while (command[pos] != ' ')
				op = op + command[pos++];

			for (unsigned char i = pos + 1; i < command.size(); i++)
				b = b + command[i];
			break;
		}
	}
	return;
}
/**********************************************************************/

/* Thuc hien lenh dua tren cac tham so lenh :
	p1 : Thuc hien o che do Binary(2) / Decimal(10) / Hexadecimal(16)
	p2 : Chuyen tu che do p1 sang che do p2 tuong ung (neu co)
	a : Toan hang thu nhat
	b : Toan hang thu hai (neu co)
	op : Toan tu (neu co)
*/
void execute(int p1, int p2, string a, string b, string op)
{
	switch (p1)
	{
		case 2:
		{
			Binary A = StringToBinary(a), B;
			if (!b.empty())
				B = StringToBinary(b);
			switch (p2)
			{
				case 0:
				{
					if (op.compare("+") == 0)
						PrintBinary(A + B);
					else if (op.compare("-") == 0)
						PrintBinary(A - B);
					else if (op.compare("&") == 0)
						PrintBinary(A & B);
					else if (op.compare("|") == 0)
						PrintBinary(A | B);
					else if (op.compare("^") == 0)
						PrintBinary(A ^ B);
					else if (op.compare("~") == 0)
						PrintBinary(~A);
					else
					{
						QInt sh = BinToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintBinary(A << shift);
						else
							PrintBinary(A >> shift);
					}
					break;
				}

				case 10:
				{
					if (op.empty())
						PrintQInt(BinToDec(A));
					else if (op.compare("+") == 0)
						PrintQInt(BinToDec(A) + BinToDec(B));
					else if (op.compare("-") == 0)
						PrintQInt(BinToDec(A) - BinToDec(B));
					else if (op.compare("&") == 0)
						PrintQInt(BinToDec(A) & BinToDec(B));
					else if (op.compare("|") == 0)
						PrintQInt(BinToDec(A) | BinToDec(B));
					else if (op.compare("^") == 0)
						PrintQInt(BinToDec(A) ^ BinToDec(B));
					else if (op.compare("~") == 0)
						PrintQInt(~BinToDec(A));
					else
					{
						QInt sh = BinToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintQInt(BinToDec(A) << shift);
						else
							PrintQInt(BinToDec(A) >> shift);
					}
					break;
				}

				case 16:
				{
					if (op.empty())
						PrintHexa(BinToHex(A));
					else if (op.compare("+") == 0)
						PrintHexa(BinToHex(A) + BinToHex(B));
					else if (op.compare("-") == 0)
						PrintHexa(BinToHex(A) - BinToHex(B));
					else if (op.compare("&") == 0)
						PrintHexa(BinToHex(A) & BinToHex(B));
					else if (op.compare("|") == 0)
						PrintHexa(BinToHex(A) | BinToHex(B));
					else if (op.compare("^") == 0)
						PrintHexa(BinToHex(A) ^ BinToHex(B));
					else if (op.compare("~") == 0)
						PrintHexa(~BinToHex(A));
					else
					{
						QInt sh = BinToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintHexa(BinToHex(A) << shift);
						else
							PrintHexa(BinToHex(A) >> shift);
					}
					break;
				}
			}
			break;
		}
		case 10:
		{
			QInt A = StringToQInt(a), B;
			if (!b.empty())
				B = StringToQInt(b);
			switch (p2)
			{
				case 0:
				{
					if (op.compare("+") == 0)
						PrintQInt(A + B);
					else if (op.compare("-") == 0)
						PrintQInt(A - B);
					else if (op.compare("&") == 0)
						PrintQInt(A & B);
					else if (op.compare("|") == 0)
						PrintQInt(A | B);
					else if (op.compare("^") == 0)
						PrintQInt(A ^ B);
					else if (op.compare("~") == 0)
						PrintQInt(~A);
					else
					{
						int shift = 0;
						for (unsigned char i = 0; i < b.size(); i++)
							shift = shift * 10 + (b[i] - '0');
						if (op.compare("<<") == 0)
							PrintQInt(A << shift);
						else
							PrintQInt(A >> shift);
					}
					break;
				}
				case 2:
				{
					if (op.empty())
						PrintBinary(DecToBin(A));
					else if (op.compare("+") == 0)
						PrintBinary(DecToBin(A) + DecToBin(B));
					else if (op.compare("-") == 0)
						PrintBinary(DecToBin(A) - DecToBin(B));
					else if (op.compare("&") == 0)
						PrintBinary(DecToBin(A) & DecToBin(B));
					else if (op.compare("|") == 0)
						PrintBinary(DecToBin(A) | DecToBin(B));
					else if (op.compare("^") == 0)
						PrintBinary(DecToBin(A) ^ DecToBin(B));
					else if (op.compare("~") == 0)
						PrintBinary(~DecToBin(A));
					else
					{
						int shift = 0;
						for (unsigned char i = 0; i < b.size(); i++)
							shift = shift * 10 + (b[i] - '0');
						if (op.compare("<<") == 0)
							PrintBinary(DecToBin(A) << shift);
						else
							PrintBinary(DecToBin(A) >> shift);
					}
					break;
				}
				case 16:
				{
					if (op.empty())
						PrintHexa(DecToHex(A));
					else if (op.compare("+") == 0)
						PrintHexa(DecToHex(A) + DecToHex(B));
					else if (op.compare("-") == 0)
						PrintHexa(DecToHex(A) - DecToHex(B));
					else if (op.compare("&") == 0)
						PrintHexa(DecToHex(A) & DecToHex(B));
					else if (op.compare("|") == 0)
						PrintHexa(DecToHex(A) | DecToHex(B));
					else if (op.compare("^") == 0)
						PrintHexa(DecToHex(A) ^ DecToHex(B));
					else if (op.compare("~") == 0)
						PrintHexa(~DecToHex(A));
					else
					{
						int shift = 0;
						for (unsigned char i = 0; i < b.size(); i++)
							shift = shift * 10 + (b[i] - '0');
						if (op.compare("<<") == 0)
							PrintHexa(DecToHex(A) << shift);
						else
							PrintHexa(DecToHex(A) >> shift);
					}
					break;
				}
			}
			break;
	}
		case 16:
		{
			Hexa A = StringToHex(a), B;
			if (!b.empty())
				B = StringToHex(b);
			switch (p2)
			{
				case 0:
				{
					if (op.compare("+") == 0)
						PrintHexa(A + B);
					else if (op.compare("-") == 0)
						PrintHexa(A - B);
					else if (op.compare("&") == 0)
						PrintHexa(A & B);
					else if (op.compare("|") == 0)
						PrintHexa(A | B);
					else if (op.compare("^") == 0)
						PrintHexa(A ^ B);
					else if (op.compare("~") == 0)
						PrintHexa(~A);
					else
					{
						QInt sh = HexToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintHexa(A << shift);
						else
							PrintHexa(A >> shift);
					}
					break;
				}

				case 2:
				{
					if (op.empty())
						PrintBinary(HexToBin(A));
					else if (op.compare("+") == 0)
						PrintBinary(HexToBin(A) + HexToBin(B));
					else if (op.compare("-") == 0)
						PrintBinary(HexToBin(A) - HexToBin(B));
					else if (op.compare("&") == 0)
						PrintBinary(HexToBin(A) & HexToBin(B));
					else if (op.compare("|") == 0)
						PrintBinary(HexToBin(A) | HexToBin(B));
					else if (op.compare("^") == 0)
						PrintBinary(HexToBin(A) ^ HexToBin(B));
					else if (op.compare("~") == 0)
						PrintBinary(~HexToBin(A));
					else
					{
						QInt sh = HexToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintBinary(HexToBin(A) << shift);
						else
							PrintBinary(HexToBin(A) >> shift);
					}
					break;
				}

				case 10:
				{
					if (op.empty())
						PrintQInt(HexToDec(A));
					else if (op.compare("+") == 0)
						PrintQInt(HexToDec(A) + HexToDec(B));
					else if (op.compare("-") == 0)
						PrintQInt(HexToDec(A) - HexToDec(B));
					else if (op.compare("&") == 0)
						PrintQInt(HexToDec(A) & HexToDec(B));
					else if (op.compare("|") == 0)
						PrintQInt(HexToDec(A) | HexToDec(B));
					else if (op.compare("^") == 0)
						PrintQInt(HexToDec(A) ^ HexToDec(B));
					else if (op.compare("~") == 0)
						PrintQInt(~HexToDec(A));
					else
					{
						QInt sh = HexToDec(B);
						int shift = 0;
						for (int i = sh.digit.size() - 1; i >= 0; i--)
							shift = shift * 10 + (sh.digit[i] - '0');
						if (op.compare("<<") == 0)
							PrintQInt(HexToDec(A) << shift);
						else
							PrintQInt(HexToDec(A) >> shift);
					}
					break;
				}
			}
			break;
		}
	}
	return;
}
/*******************************************************/

/* Khoi tao bang gia tri luy thua cua 2 : Power_2[i] = 2^i (0 <= i < 128)*/
void init()
{
	Power_2[0].digit.push_back('1');
	Power_2[0].sign = 0;
	for (int i = 1; i < 128; i++)
	{
		Power_2[i] = Power_2[i - 1] + Power_2[i - 1];
	}
	return;
}
/*----------------------------------------------------------------------*/

/* Ham chuyen tu chuoi String sang dang thap phan QInt */
QInt StringToQInt(string x)
{
	QInt decimal;
	if (x.empty())
	{
		decimal.digit.push_back('0');
		decimal.sign = 0;
	}
	else
	{
		int first = 0;
		if (x[0] == '-')
		{
			first = 1;
			decimal.sign = 1;
		}
		for (int i = x.size() - 1; i >= 0; i--)
		{
			decimal.digit.push_back(x[i]);
		}
	}
	return decimal;
}
/*------------------------------------------------------*/

/* Ham chuyen tu chuoi String sang dang nhi phan Binary */
Binary StringToBinary(string x)
{
	Binary binary;
	for (int i = x.size() - 1; i >= 0; i--)
		binary.digit.push_back((x[i] == '1'));
	return binary;
}
/*------------------------------------------------------*/

/* Ham chuyen tu chuoi String sang dang nhi phan Binary */
Hexa StringToHex(string x)
{
	Hexa hexa;
	for (int i = x.size() - 1; i >= 0; i--)
		hexa.digit.push_back(x[i]);
	return hexa;
}
/*------------------------------------------------------*/

/* Tim gia tri lon nhat cua 2 so nguyen */
int max(int a, int b)
{
	return (a > b) ? a : b;
}
/*--------------------------------------*/

/* Tim gia tri nho nhat cua 2 so nguyen */
int min(int a, int b)
{
	return (a < b) ? a : b;
}
/*--------------------------------------*/

/* Chuyen doi tu gia tri thap luc phan sang gia tri thap phan tuong ung */
int HexToDecimal(char hex)
{
	switch (hex) {
	case '0': { return 0; break;}
	case '1': { return 1; break;}
	case '2': { return 2; break;}
	case '3': { return 3; break;}
	case '4': { return 4; break;}
	case '5': { return 5; break;}
	case '6': { return 6; break;}
	case '7': { return 7; break;}
	case '8': { return 8; break;}
	case '9': { return 9; break;}
	case 'A': { return 10; break;}
	case 'B': { return 11; break;}
	case 'C': { return 12; break;}
	case 'D': { return 13; break;}
	case 'E': { return 14; break;}
	default: { return 15; break;}
	}
}
/***********************************************************************/

/* Chuyen doi tu gia tri thap phan sang gia tri thap luc phan tuong ung*/
char DecimalToHex(int hex)
{
	switch (hex) {
	case 0: { return '0'; break;}
	case 1: { return '1'; break;}
	case 2: { return '2'; break;}
	case 3: { return '3'; break;}
	case 4: { return '4'; break;}
	case 5: { return '5'; break;}
	case 6: { return '6'; break;}
	case 7: { return '7'; break;}
	case 8: { return '8'; break;}
	case 9: { return '9'; break;}
	case 10: { return 'A'; break;}
	case 11: { return 'B'; break;}
	case 12: { return 'C'; break;}
	case 13: { return 'D'; break;}
	case 14: { return 'E'; break;}
	default: { return 'F'; break;}
	}
}
/***********************************************************************/

/* Chuyen do tu 4 bit nhi phan sang gia tri thap luc phan tuong ung */
char BinaryToHex(string hex)
{
		 if (hex.compare("0000") == 0) return '0';
	else if (hex.compare("0001") == 0) return '1';
	else if (hex.compare("0010") == 0) return '2';
	else if (hex.compare("0011") == 0) return '3';
	else if (hex.compare("0100") == 0) return '4';
	else if (hex.compare("0101") == 0) return '5';
	else if (hex.compare("0110") == 0) return '6';
	else if (hex.compare("0111") == 0) return '7';
	else if (hex.compare("1000") == 0) return '8';
	else if (hex.compare("1001") == 0) return '9';
	else if (hex.compare("1010") == 0) return 'A';
	else if (hex.compare("1011") == 0) return 'B';
	else if (hex.compare("1100") == 0) return 'C';
	else if (hex.compare("1101") == 0) return 'D';
	else if (hex.compare("1110") == 0) return 'E';
	else return 'F';
}
/********************************************************************/

/* Chuyen doi tu gia tri thap luc phan sang 4 bit nhi phan tuong ung*/
string HexToBinary(char hex)
{
	switch (hex)
	{
		case '0': { return "0000"; break;}
		case '1': { return "0001"; break;}
		case '2': { return "0010"; break;}
		case '3': { return "0011"; break;}
		case '4': { return "0100"; break;}
		case '5': { return "0101"; break;}
		case '6': { return "0110"; break;}
		case '7': { return "0111"; break;}
		case '8': { return "1000"; break;}
		case '9': { return "1001"; break;}
		case 'A': { return "1010"; break;}
		case 'B': { return "1011"; break;}
		case 'C': { return "1100"; break;}
		case 'D': { return "1101"; break;}
		case 'E': { return "1110"; break;}
		default:  { return "1111"; break;}
	}
}
/********************************************************************/

/* Nhap so kieu QInt */
void ScanQInt(QInt &x)
{
	char number[40];
	scanf("%[^\n]s", &number);
	int size = strlen(number);
	int last = 0;
	if (number[0] == '-')
	{
		x.sign = 1;
		last = 1;
	}
	for (int i = size - 1; i >= last; i--)
		x.digit[size - i - 1] = number[i];
}
/*********************/

/* Xuat so thap phan kieu QInt */
void PrintQInt(QInt x)
{
	if (x.digit.size() == 0) printf("0");
	else
	{ 
		if (x.sign == 1)
			printf("-");
		for (int i = x.digit.size() - 1; i >= 0; i--)
			printf("%c", x.digit[i]);
	}
	printf("\n");
}
/*******************************/

/* Xuat so nhi phan kieu Binary*/
void PrintBinary(Binary bit)
{
	for (int i = bit.digit.size() - 1; i >= 0; i--)
		printf("%d", (bit.digit[i] == 1));
	printf("\n");
}
/*****************************/

/* Xuat so thap luc phan kieu Hexa*/
void PrintHexa(Hexa hexa)
{
	for (int i = hexa.digit.size() - 1; i >= 0; i--)
		printf("%c", hexa.digit[i]);
	printf("\n");
}
/*******************************/

/* Chuyen doi tu kieu thap phan QInt sang kieu nhi phan Binary*/
Binary DecToBin(QInt x)
{
	Binary ans;
	while (x.digit.size() > 0)
	{
		ans.digit.push_back((x.digit[0] - '0') % 2);
		x = Div2(x);
		if (x.digit.size() == 1 && x.digit[0] == '1')
		{
			ans.digit.push_back(1);
			break;
		}
	}
	if (x.sign == 1)
	{
		int pos = 0;
		while (ans.digit[pos] == 0) pos++;
		int size = ans.digit.size();
		for (int i = pos + 1; i < size; i++)
			ans.digit[i] = !ans.digit[i];
		while (ans.digit.size() < 128) ans.digit.push_back(1);
	}
	return ans;
}
/**************************************************************/

/* Chuyen doi tu kieu nhi phan Binary sang kieu thap phan QInt*/
QInt BinToDec(Binary bit)
{
	QInt ans;
	int pos = 0;
	while (bit.digit[pos] == 0) pos++;
	ans = Power_2[pos];
	int size = bit.digit.size();
	for (int i = pos + 1; i < size; i++)
		if (bit.digit[i] == 1)
		{
			if (i < 127)
				ans = ans + Power_2[i];
			else
			{
				ans.sign = 1;
				ans = Power_2[i] - ans;
			}
		}
	return ans;
}
/**************************************************************/

/* Chuyen doi tu kieu nhi phan Binary sang kieu thap luc phan Hexa */
Hexa BinToHex(Binary bit)
{
	while (bit.digit.size() % 4 != 0) bit.digit.push_back(0);
	Hexa ans;
	int i = 0;
	int size = bit.digit.size();
	string hex;
	while (i < size)
	{
		hex.clear();
		for (int cnt = 3; cnt >= 0; cnt--)
			hex += (bit.digit[i + cnt] == 1) + '0';
		ans.digit.push_back(BinaryToHex(hex));
		i += 4;
	}
	return ans;
}
/*******************************************************************/

/* Chuyen doi tu kieu thap luc phan Hexa sang kieu nhi phan Binary */
Binary HexToBin(Hexa hex)
{
	Binary ans;
	for (unsigned char i = 0; i < hex.digit.size(); i++)
	{
		string bin = HexToBinary(hex.digit[i]);
		for (int j = bin.size() - 1; j >= 0; j--)
			ans.digit.push_back((bin[j] - '0') == 1);
	}
	return ans;
}
/*******************************************************************/

/* Chuyen doi tu kieu thap phan QInt sang kieu thap luc phan Hexa*/
Hexa DecToHex(QInt x)
{
	Binary ans = DecToBin(x);
	return BinToHex(ans);
}
/*****************************************************************/

/* Chuyen doi tu kieu thap luc phan Hexa sang kieu thap phan Hexa*/
QInt HexToDec(Hexa hex)
{
	Binary ans = HexToBin(hex);
	return BinToDec(ans);
}
/*****************************************************************/

/* Operator cong 2 so nhi phan kieu Binary */
Binary operator + (Binary a, Binary b)
{
	Binary ans;
	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back(0);
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back(0);
	}

	int carry = 0;

	for (unsigned char i = 0; i < a.digit.size(); i++) {
		int a_i = (a.digit[i]), b_i = (b.digit[i]);
		carry += a_i + b_i;
		ans.digit.push_back(carry % 2);
		carry /= 2;
	}
	if (carry > 0)
		ans.digit.push_back(1);
	while (ans.digit.size() > 1 && ans.digit.back() == 0)
		ans.digit.pop_back();
	return ans;
}
/*******************************************/

/* Operator tru 2 so nhi phan kieu Binary */
Binary operator - (Binary a, Binary b)
{
	Binary ans;
	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back(0);
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back(0);
	}

	int borrow = 0;

	for (unsigned char i = 0; i < a.digit.size(); i++) {
		int a_i = (a.digit[i]), b_i = (b.digit[i]);
		borrow = (a_i - b_i) - borrow;
		if (borrow >= 0)
		{
			ans.digit.push_back(borrow == 1);
			borrow = 0;
		}
		else
		{
			ans.digit.push_back(borrow + 2 == 1);
			borrow = 1;
		}

	}
	if (borrow > 0)
	{
		while (ans.digit.size() < 128)
			ans.digit.push_back(1);
	}
	while (ans.digit.size() > 1 && ans.digit.back() == 0)
		ans.digit.pop_back();
	return ans;
}
/******************************************/

/* Operator AND 2 so nhi phan kieu Binary */
Binary operator & (Binary a, Binary b)
{
	Binary ans;
	for (unsigned char i = 0; i < min(a.digit.size(), b.digit.size()); i++)
	{
		ans.digit.push_back(a.digit[i] && b.digit[i]);
	}

	while (ans.digit.size() > 1 && ans.digit.back() == 0)
		ans.digit.pop_back();

	return ans;
}
/******************************************/

/* Operator OR 2 so nhi phan kieu Binary */
Binary operator | (Binary a, Binary b)
{
	Binary ans;

	for (unsigned char i = 0; i < max(a.digit.size(), b.digit.size()); i++)
	{
		if (i >= a.digit.size() || i >= b.digit.size())
			ans.digit.push_back(1);
		else
			ans.digit.push_back((int)a.digit[i] | (int)b.digit[i]);
	}

	while (ans.digit.size() > 1 && ans.digit.back() == 0)
		ans.digit.pop_back();

	return ans;
}
/*****************************************/

/* Operator XOR 2 so nhi phan kieu Binary */
Binary operator ^ (Binary a, Binary b)
{
	Binary ans;
	for (unsigned char i = 0; i < max(a.digit.size(), b.digit.size()); i++)
	{
		if (i >= a.digit.size() || i >= b.digit.size())
			ans.digit.push_back(1);
		else
			ans.digit.push_back((int)a.digit[i] ^ (int)b.digit[i]);
	}

	while (ans.digit.size() > 1 && ans.digit.back() == 0)
		ans.digit.pop_back();

	return ans;
}
/******************************************/

/* Operator NOT so nhi phan kieu Binary */
Binary operator ~ (Binary a)
{
	Binary ans;
	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		ans.digit.push_back(!a.digit[i]);
	}

	if (ans.digit.size() < 128)
		while (ans.digit.size() < 128)
			ans.digit.push_back(1);
	else
		while (ans.digit.size() > 1 && ans.digit.back() == 0)
			ans.digit.pop_back();

	return ans;
}
/**************************************/

/* Operator dich trai b bit so nhi phan kieu Binary*/
Binary operator << (Binary a, int b)
{
	for (int i = 0; i < min(b, 128 - a.digit.size()); i++)
		a.digit.push_back(0);

	for (int i = a.digit.size() - 1; i >= 0; i--)
	{
		a.digit[i] = (i - b >= 0) ? a.digit[i - b] : 0;
	}

	while (a.digit.size() > 1 && a.digit.back() == 0)
		a.digit.pop_back();

	return a;
}
/***************************************************/

/* Operator dich phai b bit so nhi phan kieu Binary*/
Binary operator >> (Binary a, int b)
{
	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		a.digit[i] = (i + b < min(a.digit.size(), 128)) ? (a.digit[i + b] == 1) : 0;
	}

	while (a.digit.size() > 1 && a.digit.back() == 0) 
		a.digit.pop_back();
	return a;
}
/***************************************************/

/* Operator cong 2 so thap phan kieu QInt*/
QInt operator + (QInt a, QInt b)
{
	int size_a = a.digit.size(), size_b = b.digit.size();
	QInt sum;
	int carry = 0;
	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back('0');
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back('0');
	}
	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		carry += (a.digit[i] - '0') + (b.digit[i] - '0');
		sum.digit.push_back((carry % 10) + '0');
		carry /= 10;
	}
	if (carry > 0)
		sum.digit.push_back('1');
	while (sum.digit.size() > 1 && sum.digit.back() == '0')
		sum.digit.pop_back();
	return sum;
}
/*****************************************/

/* Operator tru so thap phan kieu QInt*/
QInt operator - (QInt a, QInt b)
{
	QInt difference;
	int borrow = 0;

	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back('0');
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back('0');
	}

	if (a > b)
	{
		for (unsigned char i = 0; i < a.digit.size(); i++)
		{
			borrow = (a.digit[i] - '0') - (b.digit[i] - '0') - borrow;
			if (borrow < 0)
			{
				difference.digit.push_back(borrow + 10 + '0');
				borrow = 1;
			}
			else
			{
				difference.digit.push_back(borrow + '0');
				borrow = 0;
			}
		}
		difference.sign = 0;
	}
	else {
		for (unsigned char i = 0; i < b.digit.size(); i++)
		{
			borrow = (b.digit[i] - '0') - (a.digit[i] - '0') - borrow;

			if (borrow < 0)
			{
				difference.digit.push_back(borrow + 10 + '0');
				borrow = 1;
			}
			else
			{
				difference.digit.push_back(borrow + '0');
				borrow = 0;
			}
		}
		difference.sign = 1;
	}
	while (difference.digit.size() > 1 && difference.digit.back() == '0')
		difference.digit.pop_back();
	return difference;
}
/*****************************************/

/* Operator AND 2 so thap phan kieu QInt*/
QInt operator & (QInt a, QInt b)
{
	Binary A = DecToBin(a), B = DecToBin(b);
	Binary ans = A & B;
	return BinToDec(ans);
}
/*****************************************/

/* Operator OR 2 so thap phan kieu QInt*/
QInt operator | (QInt a, QInt b)
{
	Binary A = DecToBin(a), B = DecToBin(b);
	Binary ans = A | B;
	return BinToDec(ans);
}
/***************************************/

/* Operator XOR 2 so thap phan kieu QInt*/
QInt operator ^ (QInt a, QInt b)
{
	Binary A = DecToBin(a), B = DecToBin(b);
	Binary ans = A ^ B;
	return BinToDec(ans);
}
/***************************************/

/* Operator NOT so thap phan kieu QInt*/
QInt operator ~ (QInt a)
{
	Binary A = DecToBin(a);
	Binary ans = ~A;
	return BinToDec(ans);
}
/**************************************/

/* Operator dich trai b bit so thap phan kieu QInt*/
QInt operator << (QInt a, int b)
{
	Binary A = DecToBin(a);
	return BinToDec(A << b);
}
/**************************************************/

/* Operator dich phai b bit so thap phan kieu QInt*/
QInt operator >> (QInt a, int b)
{
	Binary A = DecToBin(a);
	return BinToDec(A >> b);
}
/**************************************************/

/* Operator so sanh lon hon giua 2 so nguyen lon kieu QInt */
bool operator > (QInt a, QInt b)
{
	if (a.sign < b.sign)
		return 1;
	else if (a.sign > b.sign)
		return 0;

	if (a.digit.size() != b.digit.size())
		return (a.digit.size() > b.digit.size());
	for (int i = a.digit.size() - 1; i >= 0; i--)
		if (a.digit[i] > b.digit[i])
			return (a.sign == 0);
		else if (a.digit[i] < b.digit[i])
			return (a.sign == 1);
}
/**********************************************************/

/* Tinh ket qua phep tinh x div 2 voi x la so nguyen lon kieu QInt */
QInt Div2(QInt x)
{
	string ans = "";
	int current = 0;
	for (int i = x.digit.size() - 1; i >= 0; i--)
	{
		current = current * 10 + (x.digit[i] - '0');
		ans.push_back((current / 2) + '0');
		current %= 2;
	}
	if (!ans.empty())
		while (!ans.empty() && ans.at(0) == '0')
			ans.erase(0, 1);
	return (StringToQInt(ans));
}
/*******************************************************************/

/* Operator cong 2 so thap luc phan kieu Hexa */
Hexa operator + (Hexa a, Hexa b)
{
	Hexa ans;
	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back('0');
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back('0');
	}

	int carry = 0;

	for (unsigned char i = 0; i < a.digit.size(); i++) {
		int a_i = HexToDecimal(a.digit[i]), b_i = HexToDecimal(b.digit[i]);
		carry += a_i + b_i;
		ans.digit.push_back(DecimalToHex(carry % 16));
		carry /= 16;
	}
	if (carry > 0)
		ans.digit.push_back('1');
	while (ans.digit.size() > 1 && ans.digit.back() == '0')
		ans.digit.pop_back();
	return ans;
}
/**********************************************/

/* Operator tru 2 so thap luc phan kieu Hexa */
Hexa operator - (Hexa a, Hexa b)
{
	Hexa ans;
	while (a.digit.size() < b.digit.size()) {
		a.digit.push_back('0');
	}
	while (b.digit.size() < a.digit.size()) {
		b.digit.push_back('0');
	}

	int borrow = 0;

	for (unsigned char i = 0; i < a.digit.size(); i++) {
		int a_i = HexToDecimal(a.digit[i]), b_i = HexToDecimal(b.digit[i]);
		borrow = (a_i - b_i) - borrow;
		if (borrow >= 0)
		{
			ans.digit.push_back(DecimalToHex(borrow));
			borrow = 0;
		}
		else
		{
			ans.digit.push_back(DecimalToHex(borrow + 16));
			borrow = 1;
		}
	}
	if (borrow > 0)
	{
		while (ans.digit.size() < 32)
			ans.digit.push_back('F');
	}
	while (ans.digit.size() > 1 && ans.digit.back() == '0')
		ans.digit.pop_back();
	return ans;
}
/*********************************************/

/* Operator AND 2 so thap luc phan kieu Hexa */
Hexa operator & (Hexa a, Hexa b)
{
	Hexa ans;
	for (unsigned char i = 0; i < min(a.digit.size(), b.digit.size()); i++)
	{	
		int a_i = HexToDecimal(a.digit[i]), b_i = HexToDecimal(b.digit[i]);
		ans.digit.push_back(DecimalToHex(a_i & b_i));
	}
	while (ans.digit.size() > 1 && ans.digit.back() == '0')
		ans.digit.pop_back();
	return ans;
}
/**********************************************/

/* Operator OR 2 so thap luc phan kieu Hexa */
Hexa operator | (Hexa a, Hexa b)
{
	Hexa ans;
	while (a.digit.size() < b.digit.size())
		a.digit.push_back('0');
	while (b.digit.size() < a.digit.size())
		b.digit.push_back('0');

	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		int a_i = HexToDecimal(a.digit[i]), b_i = HexToDecimal(b.digit[i]);
		ans.digit.push_back(DecimalToHex(a_i | b_i));

	}
	while (ans.digit.size() > 1 && ans.digit.back() == '0')
		ans.digit.pop_back();
	return ans;
}
/**********************************************/

/* Operator XOR 2 so thap luc phan kieu Hexa */
Hexa operator ^ (Hexa a, Hexa b)
{
	Hexa ans;
	while (a.digit.size() < b.digit.size())
		a.digit.push_back('0');
	while (b.digit.size() < a.digit.size())
		b.digit.push_back('0');

	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		int a_i = HexToDecimal(a.digit[i]), b_i = HexToDecimal(b.digit[i]);
		ans.digit.push_back(DecimalToHex(a_i ^ b_i));
	}
	while (ans.digit.size() > 1 && ans.digit.back() == '0')
		ans.digit.pop_back();
	return ans;
}
/**********************************************/

/* Operator NOT so thap luc phan kieu Hexa */
Hexa operator ~ (Hexa a)
{
	Hexa ans;
	for (unsigned char i = 0; i < a.digit.size(); i++)
	{
		int a_i = HexToDecimal(a.digit[i]);
		ans.digit.push_back(DecimalToHex(15 - a_i));
	}

	if (ans.digit.size() < 32)
		while (ans.digit.size() < 32)
			ans.digit.push_back('F');
	else
		while (ans.digit.size() > 1 && ans.digit.back() == '0')
			ans.digit.pop_back();
	return ans;
}
/*********************************************/

/* Operator dich trai b bit so thap luc phan kieu Hexa */
Hexa operator << (Hexa a, int b)
{
	Binary ans = HexToBin(a);
	return BinToHex(ans << b);
}
/*******************************************************/

/* Operator dich phai b bit so thap luc phan kieu Hexa */
Hexa operator >> (Hexa a, int b)
{
	Binary ans = HexToBin(a);
	return BinToHex(ans >> b);
}
/*******************************************************/