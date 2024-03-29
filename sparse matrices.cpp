// orthog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Matrix {
public:
	Matrix(int c = 0, int r = 0, int d = 0) {
		Cvalue = c;
		Rvalue = r;
		Dvalue = d;
	}
	void SetData(int d) {
		Dvalue = d;
	}
	void SetRow(int r) {
		Rvalue = r;
	}
	void SetCol(int c) {
		Cvalue = c;
	}
	int GetData() {
		return Dvalue;
	}
	int GetRow() {
		return Rvalue;
	}
	int GetCol() {
		return Cvalue;
	}
private:
	int Cvalue;
	int Rvalue;
	int Dvalue;
};

template <class TNode>
class Node{
public:
	Node(TNode d):data(d.GetCol(),d.GetRow(),d.GetData()){
		rowlink = collink = NULL;
	}
	TNode getData() {
		return data;
	}
	Node<TNode>* getRowLink() {
		return rowlink;
	}
	Node<TNode>* getColLink() {
		return collink;
	}
	void setRowLink(Node<TNode> * n) {
		rowlink = n;
	}
	void setColLink(Node<TNode> * n) {
		collink = n;
	}
	void setData(TNode data) {
		Node::data = data;
	}
	void display() {

	}
private:
	TNode data;
	Node<TNode> * rowlink;
	Node<TNode> * collink;
};

template <class DList>
class DLinkList{
public:
	DLinkList(DList c) {
		head = new Node<DList>(c);
		Node<DList> * temp = head;
		int columnValue = c.GetCol();
		int rowValue = c.GetRow();

		//Rows
		for (int i = 1; i <= rowValue; i++){
			Matrix M(i, 0, 0);
			Node<DList> * n = new Node<DList>(M);
			n->setRowLink(n);
			temp->setColLink(n);
			temp = temp->getColLink();
		}
		temp->setColLink(head);

		//Column
		temp = head;
		for (int i = 1; i <= columnValue; i++){
			Matrix M(0, i, 0);
			Node<DList> * n = new Node<DList>(M);
			n->setColLink(n);
			temp->setRowLink(n);
			temp = temp->getRowLink();
		}
		temp->setRowLink(head);
	}
	/*void DeleteMatrix(DList d) {
		Node<DList> * temp = head->getColLink();
		Node<DList> * Ptemp = head->getColLink();
		DList value = temp->getData();
		while ((temp != head)) {
			if (value.GetCol() == d.GetCol()) {
				Node<DList> * Ctemp = temp;
				temp = temp->getRowLink();
				value = temp->getData();
				Ptemp = temp;
				while (temp != Ctemp) {
					if (value.GetRow() == d.GetRow()) {
						value = temp->getData();
						if (value.GetData() == d.GetData()) {
							Ptemp->setRowLink(temp->getRowLink());
							temp->setColLink(NULL);
							temp->setRowLink(NULL);
							delete temp;
							cout << "Node Delete Successfull" << endl;
						}
						else {
							cout << "You have enter wrong data value that does not exits in this matrix" << endl;
							break;
						}
						break;
					}
					else {
						Ptemp = temp;
						temp = temp->getRowLink();
						value = temp->getData();
					}
				}
				if (temp == Ctemp) {
					cout << "You have enter wrong row value that does not exits in this matrix" << endl;
				}
				break;
			}
			else {
				temp = temp->getColLink();
				value = temp->getData();
			}
		}
		if (temp == head) {
			cout << "You have enter wrong column value that does not exits in this matrix" << endl;
		}
	}*/
	void insert(DList d) {
		Node<DList> * n = new Node<DList>(d);
		Node<DList> * Rtemp = head->getRowLink();
		DList TempRData = Rtemp->getData();
		DList nData = n->getData();
		Node<DList> * ptemp = Rtemp;
		Node<DList> * temp = Rtemp;
		//Finding Row
		while (TempRData.GetRow() != nData.GetRow()) {
			Rtemp = Rtemp->getRowLink();
			TempRData = Rtemp->getData();
		}
		if (Rtemp->getColLink() == Rtemp) {
			n->setColLink(Rtemp);
			Rtemp->setColLink(n);
		}
		else {
			temp = Rtemp->getColLink();
			ptemp = Rtemp;
			nData = n->getData();
			TempRData = temp->getData();
			while (TempRData.GetCol() < nData.GetCol() && temp->getColLink() != Rtemp) {
				ptemp = temp;
				temp = temp->getColLink();
				TempRData = temp->getData();
			}
			if (TempRData.GetCol() > nData.GetCol()) {
				n->setColLink(temp);
				ptemp->setColLink(n);
			}
			else {
				n->setColLink(temp->getColLink());
				temp->setColLink(n);
			}
		}
		//column selection
		Node<DList> * Ctemp = head->getColLink();
		DList TempCData = Ctemp->getData();
		ptemp = Rtemp;
		while (TempCData.GetCol() != nData.GetCol()) {
			Ctemp = Ctemp->getColLink();
			TempCData = Ctemp->getData();
		}
		if (Ctemp->getRowLink() == Ctemp) {
			n->setRowLink(Ctemp);
			Ctemp->setRowLink(n);
		}
		else {
			temp = Ctemp->getRowLink();
			ptemp = Ctemp;
			nData = n->getData();
			TempCData = temp->getData();
			while (TempCData.GetRow() < nData.GetRow() && temp->getRowLink() != Ctemp) {
				ptemp = temp;
				temp = temp->getRowLink();
				TempCData = temp->getData();
			}
			if (TempCData.GetRow() > nData.GetRow()) {
				n->setRowLink(temp);
				ptemp->setRowLink(n);
			}
			else {
				n->setRowLink(temp->getRowLink());
				temp->setRowLink(n);
			}
		}
	}
	void displayRows() {
		Node<DList> * temp = head->getColLink();
		Node<DList> * Dtemp = temp;
		int count = 1;
		while (count<= (head->getData()).GetRow()) {
			if (Dtemp->getRowLink() == temp){
				for (int i = 0; i < (head->getData()).GetCol(); i++){
					cout << " 0 ";
				}
				cout << endl;
			}
			else{
				Dtemp = Dtemp->getRowLink();
				DList value = Dtemp->getData();
				for (int i = 1; i <= (head->getData()).GetCol(); i++){
					if (value.GetRow() == i) {
						cout << " " << value.GetData() << " ";
						Dtemp = Dtemp->getRowLink();
						value = Dtemp->getData();
					}
					else {
						cout << " 0 ";
					}
				}
				cout << endl;
			}

			temp = temp->getColLink();
			Dtemp = temp;
			count++;
		}
	}
private:
	Node<DList> * head;
};

int main(){
	int Num = 0, Num1 = 0;
	cout << "Enter the order of the Matrix" << endl<<"Columns: ";
	cin >> Num;
	cout << "Rows: ";
	cin >> Num1;
	Matrix M1(Num, Num1, 0);
	DLinkList<Matrix> list(M1);
	Matrix M2(1, 1, 9);
	list.insert(M2);
	Matrix M3(4, 4, -8);
	list.insert(M3);
	Matrix M4(1, 4, 8);
	list.insert(M4);
	Matrix M5(2, 1, 7);
	list.insert(M5);
	Matrix M6(4, 1, -1);
	list.insert(M6);
	Matrix M7(4, 2, 6);
	list.insert(M7);
	list.displayRows();
	Matrix M8(4, 4, -8);
	/*
	list.DeleteMatrix(M8);
	list.displayRows();
	*/
	return 0;
}

