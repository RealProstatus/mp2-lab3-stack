#pragma once

#include<string>
#include"../sln/LLStack.h"
#include"Exception.h"

enum Operations : char
{
	Sin = 's', Cos = 'c', Exp = 'e', Bracket = '('
};

class Calc {
	std::string infix;			//выражение в инфиксной форме
	std::string postfix;		//выражение в постфиксной форме
	LLStack<double> NumStack;	//стек для вычисления результата
	LLStack<char> CharStack;		//стек для перевода из инфиксной в постфиксную

	int OpPriority(char op) const;
public:
	Calc();

	void setInfix(char* str);
	void setInfix(std::string str);
	std::string getInfix();
	void setPostfix(char* str);
	void setPostfix(std::string str);
	std::string getPostfix();

	void convertToPostfix();

	double calcUsingPostfix();
	double calc();
	double calc(std::string inp);
};