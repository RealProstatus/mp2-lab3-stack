#pragma once

#include<string>
#include"TStack.h"
#include"Exception.h"

enum Operations : char
{
	Sin = 's', Cos = 'c', Exp = 'e', Bracket = '('
};

class Calc {
	std::string infix;				//��������� � ��������� �����
	std::string postfix;				//��������� � ����������� �����
	TStack<double> NumStack;	//���� ��� ���������� ����������
	TStack<char> CharStack;		//���� ��� �������� �� ��������� � �����������

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