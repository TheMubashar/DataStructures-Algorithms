// PostFix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


class Node {
public:
	Node() {
		data = 0;
		next = NULL;
	}
	char getData() {
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
	void display() {
		cout << data << " ";
	}
private:
	char data;
	Node * next;
};

class Stack {
public:
	Stack() {
		size = 0;
		top = NULL;
	}
	void push(char d) {
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
	void SortSymbol() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
		}
		else {
			Node * ptemp = top;
			Node * ntemp = top;
			while (ptemp != NULL) {
				while (ntemp->getNext() != NULL){
					if (ptemp->getData() >ntemp->getNext()->getData()) {
						char prevchardata = ptemp->getData();
						char nextchardata = ntemp->getNext()->getData();
						char tempchardata = ntemp->getNext()->getData();
						ntemp->setData(prevchardata);
						ptemp->setData(tempchardata);
					}
					ntemp = ntemp->getNext();
				}
				ptemp=ptemp->getNext();
			}
		}
		size++;
	}
	char pop() {
		if (top != NULL) {
			Node * temp = top;
			char tempchar = top->getData();
			top = top->getNext();
			temp->setNext(NULL);
			delete temp;
			temp = NULL;
			return tempchar;
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

int main(){
	Stack temp;
	Stack PostfixExpression;
	string Expression="(A+(B/C*(D+E*G)))";
	int count = 0, Scount = 0, Acount = 0;
	Stack symbol;
	int openongbracket=1, closingbracket;
	while (openongbracket!=-1){
		openongbracket = -1;
		while (count<Expression.length()) {
			if (Expression[count] == '(') {
				openongbracket = count;
			}
			else {
				if (Expression[count] == ')') {
					closingbracket = count;
					Expression[count] = NULL;
					break;
				}
			}
			count++;
		}
		count = 0;
		if (openongbracket != -1){
			for (int i = openongbracket; i < closingbracket; i++) {
				if (Expression[i] == '+') {
					symbol.push('+');
					Expression[i] = NULL;
					Scount++;
				}
				else if (Expression[i] == '-') {
					symbol.push('-');
					Expression[i] = NULL;
					Scount++;
				}
				else if (Expression[i] == '*') {
					if (Expression[i+1]==NULL) {
						temp.push('*');
						Expression[i] = NULL;
						Acount++;
					}
					else {
						temp.push(Expression[i + 1]);
						temp.push('*');
						Expression[i] = NULL;
						Expression[i + 1] = NULL;
						Acount += 2;
					}
				}
				else if (Expression[i] == '/') {
					if (Expression[i + 1] == NULL) {
						temp.push('/');
						Expression[i] = NULL;
						Acount++;
					}
					else {
						temp.push(Expression[i + 1]);
						temp.push('/');
						Expression[i] = NULL;
						Expression[i + 1] = NULL;
						Acount += 2;
					}
				}
				else if (Expression[i] == '^') {
					if (Expression[i + 1] == NULL) {
						temp.push('^');
						Expression[i] = NULL;
						Acount++;
					}
					else {
						temp.push(Expression[i + 1]);
						temp.push('^');
						Expression[i] = NULL;
						Expression[i + 1] = NULL;
						Acount += 2;
					}
				}
				else if (Expression[i] == '(') {
					Expression[i] = NULL;
				}
				else if (Expression[i] == '\0') {
					Expression[i] = NULL;
				}
				else {
					temp.push(Expression[i]);
					Acount++;
					Expression[i] = NULL;
				}
			}
		}
		symbol.SortSymbol();
		count = Scount;
		while (count>0) {
			temp.push(symbol.pop());
			count--;
		}
		count = Acount + Scount;
		while (count>0) {
			PostfixExpression.push(temp.pop());
			count--;
		}
		PostfixExpression.display();
		cout << endl << endl;
		Scount = 0;
		Acount = 0;
	}
    return 0;
}