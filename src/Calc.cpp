#include"Calc.h"
#include<math.h>

Calc::Calc(): NumStack(100), CharStack(100) { }

void Calc::setInfix(char* str) { string tmp(str); infix = tmp; }
void Calc::setInfix(string str) { infix = str; }
string Calc::getInfix() { return infix; }
void Calc::setPostfix(char* str) { string tmp(str); postfix = tmp; }	//потом убрать, это не интерфейс
void Calc::setPostfix(string str) { postfix = str; }					//потом убрать, это не интерфейс
string Calc::getPostfix() { return postfix; }							//потом убрать, это не интерфейс
int Calc::OpPriority(char op) const{
	switch (op) {
	case '(':
		return 0; break;
	case '+':
	case '-':
		return 1; break;
	case '*':
	case '/':
		return 2; break;
	case '^':
		return 3; break;
	default: 
		break;
	}
}

double Calc::calcUsingPostfix() {
	NumStack.clr();
	size_t i = 0;
	while (i != postfix.size()) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			NumStack.push(tmp);
			i += idx - 1;
		}
		else {
			if (postfix[i] == '+' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '^') {
				try {
					double scnd = NumStack.pop();
					double fst = NumStack.pop();
					switch (postfix[i]) {
					case '+':
						NumStack.push(fst + scnd); break;
					case '-':
						NumStack.push(fst - scnd); break;
					case '/':
						NumStack.push(fst / scnd); break;
					case '*':
						NumStack.push(fst * scnd); break;
					case '^':
						NumStack.push(pow(fst, scnd)); break;
					default:
						break;
					}
				}
				catch (const int i) {
					throw 2351;
				}
			}
		}
		i++;
	}
	double res = NumStack.pop();
	if (NumStack.isEmpty()) return res;
	else throw 2531;
}

void Calc::convertToPostfix() {
	postfix = ""; CharStack.clr();
	string str = "(" + infix + ")";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') CharStack.push(str[i]);
		else {
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') postfix += str[i];
			else {
				if (str[i] == ')') {
					try {
						char a = CharStack.pop();
						while (a != '(') {
							postfix += a; postfix += ' ';
							a = CharStack.pop();
						}
					}
					catch (const int i) { throw 2351; }
				}
				else {
					if (str[i] == '+' || str[i] == '^' || str[i] == '/' || str[i] == '*' || str[i] == '-') {
						while (OpPriority(str[i]) <= OpPriority(CharStack.top())) {
							postfix += CharStack.pop(); postfix += ' ';
						}
						CharStack.push(str[i]);
					}
				}
			}
		}
	}
}
