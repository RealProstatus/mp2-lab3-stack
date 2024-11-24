#pragma once

#include<string>
#include"TStack.h"
#include"Exception.h"

using namespace std;

enum Operations : char
{
	Sin = 's', Cos = 'c', Exp = 'e', Bracket = '('
};

class Calc {
	string infix;				//выражение в инфиксной форме
	string postfix;				//выражение в постфиксной форме
	TStack<double> NumStack;	//стек для вычисления результата
	TStack<char> CharStack;		//стек для перевода из инфиксной в постфиксную

	int OpPriority(char op) const;
public:
	Calc();

	void setInfix(char* str);
	void setInfix(string str);
	string getInfix();
	void setPostfix(char* str);
	void setPostfix(string str);
	string getPostfix();

	void convertToPostfix();

	double calcUsingPostfix();
	double calc();
	double calc(string inp);
};