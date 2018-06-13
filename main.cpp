#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include "BigInt.h"
using namespace std;

int main(int argc, char *argv[])
{
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);
	string command;
	string a, b, op;
	init();
	while (getline(cin, command))
	{
		int p1, p2 = 0;
		a.clear(); b.clear(); op.clear();
		parse(command, p1, p2, a, b, op);
		execute(p1, p2, a, b, op);
		command.clear();
	}
	return 0;
}