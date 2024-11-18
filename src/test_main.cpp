#include"TStack.h"
#include"Calc.h"
#include<string>
#include<iostream>

using namespace std;

int main() {
	/*TStack<int> stack(5);
	cout << stack.isEmpty();
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	cout << stack.isFull() << endl;
	cout << stack.top() << endl;
	stack.pop();
	cout << stack.top() << endl;
	stack.clr();
	cout << stack.top();*/

	Calc calc;
	calc.setInfix("2+(-5*2)");
	cout << calc.calc();
}