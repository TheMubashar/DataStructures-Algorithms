// AVL-Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class AvlNode
{
private:
	int element;
	AvlNode *left;
	AvlNode *right;
	int       height;
public:
	AvlNode(const int & theElement, AvlNode *lt, AvlNode *rt, int h = 0)
		: element(theElement), left(lt), right(rt), height(h){

	}
	friend class AvlTree;
};

class AvlTree
{
public:
	explicit AvlTree(const int & notFound);
	AvlTree(const AvlTree & rhs);
	~AvlTree();

	const int & findMin() const;
	const int & findMax() const;
	const int & find(const int & x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const int & x);
	void remove(const int & x);

	const AvlTree & operator=(const AvlTree & rhs);

private:
	AvlNode * root;
	const int ITEM_NOT_FOUND;

	const int & elementAt(AvlNode *t) const;

	void insert(const int & x, AvlNode * & t) const;
	AvlNode * findMin(AvlNode *t) const;
	AvlNode * findMax(AvlNode *t) const;
	AvlNode * find(const int & x, AvlNode *t) const;
	void makeEmpty(AvlNode * & t) const;
	void printTree(AvlNode *t) const;
	AvlNode * clone(AvlNode *t) const;

	// Avl manipulations
	int height(AvlNode *t) const;
	int max(int lhs, int rhs) const;
	void rotateWithLeftChild(AvlNode * & k2) const;
	void rotateWithRightChild(AvlNode * & k1) const;
	void doubleWithLeftChild(AvlNode * & k3) const;
	void doubleWithRightChild(AvlNode * & k1) const;
};

AvlTree::AvlTree(const int & notFound) :ITEM_NOT_FOUND(notFound)
{
	root = NULL;
}
AvlTree::AvlTree(const AvlTree & rhs) :
	ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND)
{
	root = NULL;
	*this = rhs;
}
AvlTree::~AvlTree()
{
	makeEmpty();
}
void AvlTree::insert(const int & x)
{
	insert(x, root);
}
void AvlTree::remove(const int & x)
{
	cout << "Sorry, remove unimplemented; " << x <<
		" still present" << endl;
}
const int & AvlTree::findMin() const
{
	return elementAt(findMin(root));
}
const int & AvlTree::findMax() const
{
	return elementAt(findMax(root));
}
const int & AvlTree::find(const int & x) const
{
	return elementAt(find(x, root));
}
void AvlTree::makeEmpty()
{
	makeEmpty(root);
}
bool AvlTree::isEmpty() const
{
	return root == NULL;
}
void AvlTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

const AvlTree & AvlTree::operator=(const AvlTree & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}
const int & AvlTree::elementAt(AvlNode *t) const
{
	if (t == NULL)
		return ITEM_NOT_FOUND;
	else
		return t->element;
}
void AvlTree::insert(const int & x, AvlNode * & t) const
{
	if (t == NULL) {
		t = new AvlNode(x, NULL, NULL);
	}
	else if (x < t->element)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
			if (x < t->left->element)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else if (t->element < x)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
			if (t->right->element < x)
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
	}
	else
		;  // Duplicate; do nothing
	t->height = max(height(t->left), height(t->right)) + 1;
}
AvlNode * AvlTree::findMin(AvlNode *t) const
{
	if (t == NULL)
		return t;

	while (t->left != NULL)
		t = t->left;
	return t;
}
AvlNode *AvlTree::findMax(AvlNode *t) const
{
	if (t == NULL)
		return t;

	while (t->right != NULL)
		t = t->right;
	return t;
}
AvlNode *
AvlTree::find(const int & x, AvlNode *t) const
{
	while (t != NULL)
		if (x < t->element)
			t = t->left;
		else if (t->element < x)
			t = t->right;
		else
			return t;    // Match

	return NULL;   // No match
}
void AvlTree::makeEmpty(AvlNode * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}
AvlNode *
AvlTree::clone(AvlNode * t) const
{
	if (t == NULL)
		return NULL;
	else
		return new AvlNode(t->element, clone(t->left),
			clone(t->right), t->height);
}
int AvlTree::height(AvlNode *t) const
{
	return t == NULL ? -1 : t->height;
}
int AvlTree::max(int lhs, int rhs) const
{
	return lhs > rhs ? lhs : rhs;
}
void AvlTree::rotateWithLeftChild(AvlNode * & k2) const
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;
}
void AvlTree::rotateWithRightChild(AvlNode * & k1) const
{
	AvlNode *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	k1 = k2;
}
void AvlTree::doubleWithLeftChild(AvlNode * & k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}
void AvlTree::doubleWithRightChild(AvlNode * & k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}
void AvlTree::printTree(AvlNode *t) const
{
	if (t != NULL)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}
int main() {

	AvlTree avlTree(0);
	if (avlTree.isEmpty() == 0)
		cout << "Empty " << endl;
	else
		cout << "Not Empty " << endl;


	avlTree.insert(5);
	avlTree.insert(13);
	avlTree.insert(26);
	avlTree.insert(4);
	avlTree.insert(99);
	avlTree.insert(45);
	avlTree.insert(76);
	avlTree.insert(23);
	avlTree.insert(88);
	avlTree.insert(43);
	avlTree.insert(56);
	avlTree.insert(82);
	avlTree.insert(19);
	avlTree.printTree();
	return 0;
}