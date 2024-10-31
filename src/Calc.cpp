#include"Calc.h"

Calc::Calc(): NumStack(100), CharStack(100) { }

void Calc::setInfix(char* str) { string tmp(str); infix = tmp; }
void Calc::setInfix(string str) { infix = str; }
string Calc::getInfix() { return infix; }
void Calc::setPostfix(char* str) { string tmp(str); postfix = tmp; } //����� ������, ��� �� ���������
void Calc::setPostfix(string str) { postfix = str; }//����� ������, ��� �� ���������
string Calc::getPostfix() { return postfix; }//����� ������, ��� �� ���������

double Calc::calcUsingPostfix() {
	NumStack.clr();
	size_t i = 0;
	while (i != postfix.size()) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			NumStack.push(stod((postfix.c_str() + i), &i));
		}
	}
}
