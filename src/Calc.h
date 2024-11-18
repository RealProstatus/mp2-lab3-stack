#pragma once

#include<string>
#include"TStack.h"

using namespace std;

enum Operations
{
	Sin,Cos=0,Exp=0,Bracket=0, Add, Sub=1, Mult, Div=2,Pow
};

class Calc {
	string infix;				//��������� � ��������� �����
	string postfix;				//��������� � ����������� �����
	TStack<double> NumStack;	//���� ��� ���������� ����������
	TStack<char> CharStack;		//���� ��� �������� �� ��������� � �����������

	int OpPriority(char op) const;
public:
	Calc();

	void setInfix(char* str);
	void setInfix(string str);
	string getInfix();
	void setPostfix(char* str); //����� ������, ��� �� ���������
	void setPostfix(string str);//����� ������, ��� �� ���������
	string getPostfix();		//����� ������, ��� �� ���������

	double calcUsingPostfix();
	double calc();

	void convertToPostfix();//����� ������ ���� ����� � private
};