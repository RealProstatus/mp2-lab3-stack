#pragma once

#include<iostream>

class Exception {
public:
	virtual void show() = 0;
};

//Stack exceptions----------------------------------------------
class EPushInFullStack: public Exception {
public:
	void show() {
		std::cout << "Pushing in full stack!";
	}
};

class EPopFromEmptyStack : public Exception {
public:
	void show() {
		std::cout << "Pop from empty stack!";
	}
};

class EStackWithNegativeOrZeroSize : public Exception {
public:
	void show() {
		std::cout << "Attempt to create stack with negative or zero size!";
	}
};

class ETopFromEmptyStack : public Exception {
public:
	void show() {
		std::cout << "Attempt to top from empty stack!";
	}
};

//Calc exceptions-----------------------------------------------
class EWrongExpression : public Exception {
public:
	void show() {
		std::cout << "Wrong math expression!";
	}
};

class EDivizionByZero : public Exception {
public:
	void show() {
		std::cout << "Divizion by zero!";
	}
};