#include"Calc.h"
#include<math.h>

Calc::Calc(): NumStack(64), CharStack(64) { }

void Calc::setInfix(char* str) { std::string tmp(str); infix = tmp; }
void Calc::setInfix(std::string str) { infix = str; }
std::string Calc::getInfix() { return infix; }
void Calc::setPostfix(char* str) { std::string tmp(str); postfix = tmp; }	
void Calc::setPostfix(std::string str) { postfix = str; }
std::string Calc::getPostfix() { return postfix; }
int Calc::OpPriority(char op) const{
	switch (op) {
	case 's':
	case 'c':
	case 'e':
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
			double tmp = std::stod(&postfix[i], &idx);
			NumStack.push(tmp);
			i += idx - 1;
		}
		else {
			if (postfix[i] == '+' || postfix[i] == '/' || postfix[i] == '*' 
				|| postfix[i] == '-' || postfix[i] == '^' ||
				postfix[i] == 'c' || postfix[i]=='s'|| postfix[i]=='e') {
				try {
					double scnd = NumStack.pop();
					switch (postfix[i]) {
					case 'c':
						NumStack.push(cos(scnd)); break;
					case 's':
						NumStack.push(sin(scnd)); break;
					case 'e':
						NumStack.push(exp(scnd)); break;
					case '+':
						NumStack.push(NumStack.pop() + scnd); break;
					case '-':
						NumStack.push(NumStack.pop() - scnd); break;
					case '/':
						NumStack.push(NumStack.pop() / scnd); break;
					case '*':
						NumStack.push(NumStack.pop() * scnd); break;
					case '^':
						NumStack.push(pow(NumStack.pop(), scnd)); break;
					default:
						break;
					}
				}
				catch (const int i) {
					throw EWrongExpression();
				}
			}
		}
		i++;
	}
	double res = NumStack.pop();
	if (NumStack.isEmpty()) return res;
	else throw EWrongExpression();
}

void Calc::convertToPostfix() {
	postfix = ""; CharStack.clr();
	std::string str = "(" + infix + ")";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') CharStack.push(str[i]);
		else {
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				size_t idx;
				double tmp = std::stod(&str[i], &idx);
				postfix += str.substr(i, idx); postfix += " ";
				i += idx - 1;
			}
			else {
				if (str[i] == ')') {
					try {
						char a = CharStack.pop();
						while (a != '(') {
							postfix += a; postfix += " ";
							a = CharStack.pop();
						}
					}
					catch (const int i) { throw EWrongExpression(); }
				}
				else {
					if (str[i] == '+' || str[i] == '^' || str[i] == '/' || str[i] == '*' || str[i] == '-') {
						while (OpPriority(str[i]) <= OpPriority(CharStack.top())) {
							postfix += CharStack.pop(); postfix += " ";
						}
						CharStack.push(str[i]);
					}
					else {
						if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(') {
							CharStack.push(Operations::Bracket);
							CharStack.push(Operations::Cos);
							i += 3;
						}
						else {
							if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
								CharStack.push(Operations::Bracket);
								CharStack.push(Operations::Sin);
								i += 3;
							}
							else {
								if (str[i] == 'e' && str[i + 1] == 'x' && str[i + 2] == 'p' && str[i + 3] == '(') {
									CharStack.push(Operations::Bracket);
									CharStack.push(Operations::Exp);
									i += 3;
								}
							}
						}
					}
				}
			}
		}
	}
}

double Calc::calc() {
	std::string str = "(" + infix + ")";
	CharStack.clr(); NumStack.clr();
	for (int i = 0; i < str.size(); i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			size_t idx;
			NumStack.push(std::stod(&str[i], &idx));
			i += idx - 1;
		}
		else {
			if (str[i] == '+' || str[i] == '^' || str[i] == '/' || str[i] == '*' || str[i] == '-') {
				while (OpPriority(CharStack.top()) >= OpPriority(str[i])) {
					double scnd = NumStack.pop();
					double fst = NumStack.pop();
					switch (CharStack.pop()) {
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
				CharStack.push(str[i]);
			}
			else {
				if (str[i] == ')') {
					char op = CharStack.pop();
					while (op != '(') {
						double scnd = NumStack.pop();
						switch (op) {
						case 'c':
							NumStack.push(cos(scnd)); break;
						case 's':
							NumStack.push(sin(scnd)); break;
						case 'e':
							NumStack.push(exp(scnd)); break;
						case '+':
							NumStack.push(NumStack.pop() + scnd); break;
						case '-':
							NumStack.push(NumStack.pop() - scnd); break;
						case '/':
							NumStack.push(NumStack.pop() / scnd); break;
						case '*':
							NumStack.push(NumStack.pop() * scnd); break;
						case '^':
							NumStack.push(pow(NumStack.pop(), scnd)); break;
						default:
							break;
						}
						op = CharStack.pop();
					}
				}
				else {
					if (str[i] == '(') {
							CharStack.push(str[i]);
						if (str[i + 1] == '-') {
							size_t idx;
							NumStack.push(-1.0*std::stod(&str[i+2], &idx));
							i += idx + 1;
						}
					}
					else {
						if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(') {
							CharStack.push(Operations::Bracket);
							CharStack.push(Operations::Cos);
							i += 3;
						}
						else {
							if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
								CharStack.push(Operations::Bracket);
								CharStack.push(Operations::Sin);
								i += 3;
							}
							else {
								if (str[i] == 'e' && str[i + 1] == 'x' && str[i + 2] == 'p' && str[i + 3] == '(') {
									CharStack.push(Operations::Bracket);
									CharStack.push(Operations::Exp);
									i += 3;
								}
							}
						}
					}
						
				}
			}
		}
	}//закончилась обработка строки

	double result = NumStack.pop();
	if (CharStack.isEmpty() && NumStack.isEmpty()) {
		return result;
	}
	else {
		throw EWrongExpression();
	}
}

double Calc::calc(std::string inp) {
	infix = inp;
	return calc();
}
