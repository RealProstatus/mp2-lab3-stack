#pragma once

#include<string>
#include"TStack.h"

using namespace std;

enum Operations
{
	Sin,Cos=0,Exp=0,Bracket=0, Add, Sub=1, Mult, Div=2,Pow
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
	void setPostfix(char* str); //потом убрать, это не интерфейс
	void setPostfix(string str);//потом убрать, это не интерфейс
	string getPostfix();		//потом убрать, это не интерфейс

	double calcUsingPostfix();
	double calc();

	void convertToPostfix();//потом скрыть этот метод в private
};