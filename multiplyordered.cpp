// multiplyordered.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class Node
{
public:
	Node() {
		Name = "";
		Age = 0;
		nextone = NULL;
		nexttwo = NULL;
	}
	Node(string d1,int d2) {
		Name = d1;
		Age = d2;
		nextone = NULL;
		nexttwo = NULL;
	}
	void display() {
		cout << Name<< " "<< Age <<" ";
	}
	//Get Data
	string getName() {
		return Name;
	}
	int getAge() {
		return Age;
	}
	//Get Pointer
	Node* getNextOne() {
		return nextone;
	}
	Node* getNextTwo() {
		return nexttwo;
	}
	//Set Pointer
	void setNextOne(Node* n1) {
		nextone = n1;
	}
	void setNextTwo(Node* n2) {
		nexttwo = n2;
	}
	//Set Data
	void setDataOne(string d1) {
		Name = d1;
	}
	void setDataOne(int d2) {
		Age = d2;
	}
private:
	string Name;
	int Age;
	Node * nextone;
	Node * nexttwo;
};

class List {

public:
	List() {
		first1 = NULL;
		first2 = NULL;
		size = 0;
	}
	void insert(string d1,int d2) {
		Node * n = new Node(d1, d2);
		if (first1 == NULL) {
			first1 = n;
			first2 = n;
		}
		else{
			Node * temp = first2;
			Node * Previous = NULL;
			if (temp->getAge() < d2) {
				while (temp->getAge() <= d2 && temp->getNextTwo() != NULL) {
					Previous = temp;
					temp = temp->getNextTwo();
				}
				if (temp->getNextTwo() != NULL) {
					n->setNextTwo(temp);
					Previous->setNextTwo(n);
				}
				else if (temp->getAge() <= d2) {
					temp->setNextTwo(n);
				}
				else {
					n->setNextTwo(temp);
					Previous->setNextTwo(n);
				}
			}
			else {
				first2 = n;
				n->setNextTwo(temp);
			}

			//String comparison
			temp = first1;
			Previous = NULL;
			if (temp->getName() < d1) {
				while (temp->getName() <= d1 && temp->getNextOne() != NULL) {
					Previous = temp;
					temp = temp->getNextOne();
				}
				if (temp->getNextOne() != NULL) {
					n->setNextOne(temp);
					Previous->setNextOne(n);
				}
				else if (temp->getName() <= d1) {
					temp->setNextOne(n);
				}
				else {
					n->setNextOne(temp);
					Previous->setNextOne(n);
				}
			}
		}
		size++;			
	}
	void displayName() {
		Node *temp = first1;
		while (temp != NULL) {
			temp->display();
			temp = temp->getNextOne();
		}
	}
	void displayAge() {
		Node *temp = first2;
		while (temp != NULL) {
			temp->display();
			temp = temp->getNextTwo();
		}
	}
private:
	Node * first1;
	Node * first2;
	int size;
};


int main()
{	
	List l1;
	l1.insert("Adams", 1932);
	l1.insert("Doe", 1197);
	l1.insert("Jones", 2570);
	l1.insert("Smith", 1537);
	l1.displayName();
	cout << endl << endl;
	l1.displayAge();
    return 0;
}

