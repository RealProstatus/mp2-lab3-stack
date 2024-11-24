#include"TStack.h"
#include"Calc.h"
#include<string>
#include<iostream>


int main() {
	Calc calc;
	calc.setInfix("1.5+cos(exp(0))");
	std::cout<<cos(exp(0))<<std::endl<<calc.calc();
}