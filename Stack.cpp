// S.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class Node {
public:
	Node() {
		data = 0;
		next = NULL;
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node * n) {
		next = n;
	}
	void setData(int data) {
		Node::data = data;
	}

	Node(int data) : data(data) {
		next = NULL;
	}

	friend std::ostream &operator<<(std::ostream &os, const Node &node) {
		os << "data: " << node.data;
		return os;
	}
	void display() {
		cout << data << " ";
	}
private:
	int data;
	Node * next;

};

class Stack {

public:
	Stack() {
		size = 0;
		top = NULL;
	}
	void push(int d) {
		Node * n = new Node(d);

		if (top == NULL) {
			top = n;
		}
		else {
			n->setNext(top);
			top = n;
		}
		size++;
	}
	void pop() {
		if (top != NULL) {
			Node * temp = top;
			top = top->getNext();
			temp->setNext(NULL);
			delete temp;
			temp = NULL;
		}
		else {
			cout << "Stack is already empty !!!" << endl;
		}

	}
	void display() {
		Node * temp = top;
		while (temp != NULL) {
			temp->display();
			temp = temp->getNext();
		}
	}


private:
	Node * top;
	int size;
};
int main() {
	Stack stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.display();
	stack.pop();
	cout << endl << endl;
	stack.display();
	cout << endl << endl;


	return 0;
}