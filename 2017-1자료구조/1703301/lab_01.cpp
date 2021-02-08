/*
 * lab_01.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: tjddl
 */
#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;
bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, char openSymbol);

int main() {
	char symbol;
	Stack stack;
	bool balanced = true;
	char openSymbol;
	ifstream fin;

	fin.open("lab_01.cpp");

	while (fin.get(symbol) && balanced)
	{
		if (isOpen(symbol))
			stack.push(symbol);
		else if (isClosed(symbol))
		{
			if (stack.isEmpty())
				balanced = false;
			else
			{
				openSymbol = stack.pop();
				balanced = matches(symbol, openSymbol);
			}
		}
	}
    if (!balanced)
    	cout << "-1" << endl;
    else if (stack.isEmpty())
    	cout << "1" << endl;
    else
    	cout << "-1" << endl;

    return 0;
}

bool isOpen(char symbol)
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}
