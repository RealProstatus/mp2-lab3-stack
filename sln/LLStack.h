#pragma once

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
//-----------------------------------------------------------
// TODO
	bool isEmpty();
	bool isFull();
	void push(T val);
	void pop();
	T top();
	void clear();//...

};