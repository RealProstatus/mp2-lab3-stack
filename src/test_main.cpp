#include"TStack.h"
#include"Calc.h"
#include<string>
#include<iostream>

using namespace std;

int main() {
	Calc calc;
	calc.setInfix("1.5+cos(exp(0))");
	cout<<cos(exp(0))<<endl<<calc.calc();
}