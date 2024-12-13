#pragma once

#include"../src/Exception.h";

template<class T>
struct Node {
	T val;
	Node<T>* pNext;
};

template<class T>
class LLStack {
	Node<T>* pFirst;
public:
	LLStack() { pFirst = nullptr; }

	LLStack(const LLStack<T>& s) {
		Node<T>* stmp = s.pFirst;
		if (stmp != nullptr) {
			pFirst = new Node<T>;
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;
			
			stmp = stmp->pNext;

			Node<T>* prev = pFirst;
			while (stmp != nullptr) {
				Node<T>* newnode = new Node<T>;
				newnode->val = stmp->val;
				newnode->pNext = nullptr;
				
				prev->pNext = newnode;

				stmp = stmp->pNext;
				prev = prev->pNext;
			}
		}
		else {
			pFirst = nullptr;
		}
	}

	~LLStack() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
//--------------------interface------------------------------
	bool isEmpty() const { return pFirst == nullptr; }

	bool isFull() const {
		try {
			Node<T>* tmp = new Node<T>;
			delete tmp;
			return true;
		}
		catch (std::bad_alloc e) {
			return false;
		}
	}

	void push(T val) {
		try {
			Node<T>* tmp = new Node<t>;
			tmp->val = val;
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		catch (std::bad_alloc e) {
			throw EPushInFullStack();
		}
	}

	T pop() {
		T res;
		if (pFirst != nullptr) {
			T res = pFirst->val;
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			return res;
		}
		else {
			throw EPopFromEmptyStack();
		}
	}

	T top() {
		if (pFirst != nullptr)
			return pFirst->val;
		else
			throw ETopFromEmptyStack();
	}

	void clear() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	bool operator==(const LLStack<T>& s) const {
		Node<T>* tmp = pFirst;
		Node<T>* stmp = s.pFirst;

		while (stmp != nullptr && tmp != nullptr) {
			if (tmp->val != stmp->val)
				return false;
			tmp = tmp->pNext;
			stmp = stmp->pNext;
		}

		return tmp == stmp;
		/*
		* if(tmp != stmp) - разные размеры стеков
		*	return false;
		* return true;
		*/
	}

	LLStack<T>& operator=(const LLStack<T>& s) {
		if (this == &s) return *this;
		//удаляем все звенья
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		//переносим значения из правого стека
		Node<T>* stmp = s.pFirst;
		if (stmp != nullptr) {
			pFirst = new Node<T>;
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;

			stmp = stmp->pNext;

			Node<T>* prev = pFirst;
			while (stmp != nullptr) {
				Node<T>* newnode = new Node<T>;
				newnode->val = stmp->val;
				newnode->pNext = nullptr;

				prev->pNext = newnode;

				stmp = stmp->pNext;
				prev = prev->pNext;
			}
		}
		else {
			pFirst = nullptr;
		}
	}
};