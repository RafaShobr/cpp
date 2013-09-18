#include "DoublyLinkedList.h"
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	this->root = NULL;
	this->tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
	cout << "delete root" << endl;
	delete root;
	root = NULL;
	tail = NULL;
}

std::ostream& operator<<(std::ostream& o, const DoublyLinkedList& list) {
	return o << "List: [ " << *list.root << " ]" << endl;
}

void DoublyLinkedList::InsertNodesLeft(Node* leftOf, Node* node) {
	Node* tmp = leftOf->left;
	leftOf->left = node->RightMost();
	node->LeftMost()->left = tmp;	
}

void DoublyLinkedList::InsertNodesRight(Node* rightOf, Node* node) {
	Node* tmp = rightOf->right;
	rightOf->right = node->LeftMost();
	node->RightMost()->right = tmp;
}

void DoublyLinkedList::PushFront(Node *node) {
	if (root != NULL) {
		root->left = node;
		node->RightMost()->right = root;
	}
	if (tail == NULL)
		tail = node;
	root = node;
}

void DoublyLinkedList::PushTail(Node *node){
	if (tail != NULL) {
		tail->right = node;
		node->LeftMost()->left = tail;
	}
	if (root == NULL)
		root = node;
	tail=node;
}