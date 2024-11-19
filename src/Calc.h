#pragma once

#include<string>
#include"TStack.h"

using namespace std;

enum Operations : char
{
	Sin = 's', Cos = 'c', Exp = 'e', Bracket = '('
};

class Calc {
	string infix;				//��������� � ��������� �����
	string postfix;				//��������� � ����������� �����
	TStack<double> NumStack;	//���� ��� ���������� ����������
	TStack<char> CharStack;		//���� ��� �������� �� ��������� � �����������

	void convertToPostfix();
	int OpPriority(char op) const;
public:
	Calc();

	void setInfix(char* str);
	void setInfix(string str);
	string getInfix();
	void setPostfix(char* str);
	void setPostfix(string str);

	double calcUsingPostfix();
	double calc();
	double calc(string inp);
};