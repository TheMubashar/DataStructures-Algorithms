// LinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
public:
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int d) {
		data = d;
		next = NULL;
	}
	void display() {
		cout << data << " ";
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node* n) {
		next = n;
	}
	void setData(int d) {
		data = d;
	}

private:
	int data;
	Node * next;
};

class List {

public:
	List() {
		head = NULL;
		size = 0;
	}
	void insertAtRandom(int d) {
		Node *n = new Node(d);
		if (head == NULL) {
			head = n;
		}
		else {
			Node *temp = head;
			while (temp->getNext() != NULL) {
				temp = temp->getNext();
			}
			temp->setNext(n);
		}
		size++;
	}
	void deletiondupllication() {
		Node * next = head->getNext();
		Node * previous = head;
		Node * prev = head;
		while (previous!=NULL)
		{
			while (next != NULL)
			{
				if (previous->getData() == next->getData()) {
					Node * current = next;
					if (next->getNext() != NULL) {
						next = next->getNext();
						delete current;
						size--;
						prev->setNext(next);
					}
					else {
						delete current;
						size--;
						prev->setNext(NULL);
						break;
					}
				}
				else {
					prev = prev->getNext();
					next = next->getNext();
				}
			}
			if (previous->getNext()!=NULL) {
				previous = previous->getNext();
				next = previous->getNext();
				prev = previous;
			}
			else {
				break;
			}
		}
	}
	void insertAtStart(int d) {
		Node *n = new Node(d);
		if (head == NULL) {
			head = n;
		}
		else {
			n->setNext(head);
			head = n;
		}
		size++;
	}
	void insertAtMiddle(int d) {
		Node *n = new Node(d);
		if (head == NULL) {
			head = n;
		}
		else {
			Node * temp = head;
			Node * Previous = NULL;
			if (temp->getData() < d) {
				Previous = temp;
				temp = temp->getNext();
				while (temp->getData() <= d && temp->getNext() != NULL) {
					Previous = temp;
					temp = temp->getNext();
				}
				if (temp->getNext() != NULL) {
					n->setNext(temp);
					Previous->setNext(n);
				}
				else if (temp->getData() <= d) {
					temp->setNext(n);
				}
				else {
					n->setNext(temp);
					Previous->setNext(n);
				}

			}
			else {
				head = n;
				n->setNext(temp);
			}

		}
		size++;
	}
	void Deletion(int d) {
		Node * temp = head;
		Node * previous = NULL;
		bool flag = false;
		while (temp != NULL || !flag) {
			if (d == temp->getData()) {
				flag = true;
				if (temp->getNext() == NULL) {
					previous->setNext(NULL);
					delete temp;
				}
				else if (previous == NULL) {
					head = temp->getNext();
					temp->setNext(NULL);
					delete temp;

				}
				else {
					previous->setNext(temp->getNext());
					delete temp;
				}
				cout << "Node deleted" << endl;
				cout << endl;
				size--;
				break;
			}
			previous = temp;
			temp = temp->getNext();
			if (temp == NULL) {
				cout << "This data does not eixts " << endl;
				cout << endl;
				break;
			}
		}
	}
	void insertAtEnd(int d) {
		Node *n = new Node(d);

		if (head == NULL) {
			head = n;
		}
		else {
			Node * temp = head;

			while (temp->getNext() != NULL) {
				temp = temp->getNext();
			}
			temp->setNext(n);
		}
		size++;
	}
	void display() {
		Node * temp = head;

		while (temp != NULL) {
			temp->display();
			temp = temp->getNext();
		}
		cout << endl << "Size of List = " << size << endl;
	}
	bool search(int d) {
		Node * temp = head;
		bool flag = false;
		while (temp != NULL) {
			if (d == temp->getData()) {
				flag = true;
			}
			temp = temp->getNext();
		}
		return flag;
	}
	int getSize() {
		return size;
	}
private:

	Node * head;
	int size;
};

int main() {

	List list;
	list.insertAtRandom(2);
	list.insertAtRandom(2);
	list.insertAtRandom(3);
	list.insertAtRandom(3);
	list.insertAtRandom(4);
	list.insertAtRandom(5);
	list.insertAtRandom(6);
	list.insertAtRandom(7);
	list.insertAtRandom(4);
	list.insertAtRandom(5);
	list.insertAtRandom(6);
	list.insertAtRandom(7);
	list.display();
	cout << endl;
	list.deletiondupllication();
	list.display();
	cout << endl;

	
	return 0;
}

