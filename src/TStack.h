#pragma once

#include"Exception.h"

template<class T>
class TStack {
	T* pMem;
	int maxSize;
	int index;
public:
	TStack(int maxSize = 32) {
		if (maxSize > 0) {
			pMem = new T[maxSize];
			this->maxSize = maxSize;
			index = -1;
		}
		else { throw EStackWithNegativeOrZeroSize(); }
	}
	TStack(const TStack<T>& s) {
		pMem = new T[s.maxSize];
		maxSize = s.maxSize;
		index = s.index;
	}
	~TStack() { delete[] pMem; }


	TStack<T>& operator=(const TStack<T>& s) {
		if (this == &s) return *this;
		if (maxSize != s.maxSize) {
			T* tmp = new T[s.maxSize];
			delete[] pMem;
			pMem = tmp;
			maxSize = s.maxSize;
		}
		index = s.index;
		for (int i = 0; i < index; i++) pMem[i] = s.pMem[i];
		return *this;
	}
	bool operator==(const TStack<T>& s) {
		if (this == &s) return true;
		if ((maxSize != s.maxSize) || (index != s.index)) return false;
		for (int i = 0; i < index; i++) {
			if (pMem[i] != s.pMem[i]) return false;
		}
		return true;
	}
	bool operator!=(const TStack<T>& s) {
		return !(this->operator==(s));
	}


	bool isEmpty() const { return index == -1; }
	bool isFull() const { return index == (maxSize - 1); }
	T pop() {
		if (this->isEmpty()) throw EPopFromEmptyStack();
		return pMem[index--];
	}
	void push(T val) {
		if (this->isFull()) throw EPushInFullStack();
		pMem[++index] = val;
	}
	T top() { 
		if (index != -1) return pMem[index];
		throw ETopFromEmptyStack();
	}
	void clr() { index = -1; }
};