#pragma once

#include<string>
#include"TStack.h"

using namespace std;


class Calc {
	string infix;				//��������� � ��������� �����
	string postfix;				//��������� � ����������� �����
	TStack<double> NumStack;	//���� ��� ���������� ����������
	TStack<char> CharStack;		//���� ��� �������� �� ��������� � �����������

	void convertToPostfix();
public:
	Calc();

	void setInfix(char* str);
	void setInfix(string str);
	string getInfix();
	void setPostfix(char* str); //����� ������, ��� �� ���������
	void setPostfix(string str);//����� ������, ��� �� ���������
	string getPostfix();//����� ������, ��� �� ���������

	double calcUsingPostfix();
	double calc();


};