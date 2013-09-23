#include "DoublyLinkedList.h"
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	this->root = NULL;
	this->tail = NULL;
	this->size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	cout << "delete list" << endl;
	Node *tmp = root->right;
	while (root != NULL)
	{
		tmp = root->right;
		delete root;
		root = tmp;
	}
	root = NULL;
	tail = NULL;
}

std::ostream& operator<<(std::ostream& o, const DoublyLinkedList *list) {
	return o << "*List (" << list->size << " elements): [ " << list->root << " ]" << endl;
}

std::ostream& operator<<(std::ostream& o, const DoublyLinkedList &list) {
	return o << "&List (" << list.size << " elements): [ " << *(list.root) << " ]" << endl;
}

void DoublyLinkedList::InsertNodesLeft(Node* leftOf, Node* node) {
	Node* tmp = leftOf->left;
	leftOf->left = node->RightMost();
	node->LeftMost()->left = tmp;	
	tmp = node;
	while (tmp != NULL)
	{
		this->size++;
		tmp = tmp->right;
	}
}

void DoublyLinkedList::InsertNodesRight(Node* rightOf, Node* node) {
	Node* tmp = rightOf->right;
	rightOf->right = node->LeftMost();
	node->RightMost()->right = tmp;
	tmp = node;
	while (tmp != NULL)
	{
		this->size++;
		tmp = tmp->right;
	}
}

void DoublyLinkedList::PushFront(Node *node) {
	if (root != NULL) {
		root->left = node;
		node->RightMost()->right = root;
	}
	if (tail == NULL)
		tail = node;
	root = node;
	this->size++;
}

void DoublyLinkedList::PushTail(Node *node){
	if (tail != NULL) {
		tail->right = node;
		node->LeftMost()->left = tail;
	}
	if (root == NULL)
		root = node;
	tail=node;
	this->size++;
}

int* DoublyLinkedList::ToArray() {
	int *myArray = new int[this->size];
	int i= 0;
	Node* tmp = root;
	while (tmp!= NULL)
	{
		myArray[i++] = tmp->value;
		tmp = tmp->right;
	}
	return myArray;
}