#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int val)
{
	this->value = val;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(void)
{
	Node(0);
}

Node::~Node(){
	
	cout << "delete node" << this->value << endl;
}

std::ostream& operator<<(std::ostream& o, const Node *node) {
	if (node->right != NULL)
		return o << "[*" << node->value << "]" << node->right;
	return o << "[*" << node->value << "]";
}

std::ostream& operator<<(std::ostream& o, const Node &node) {
	if (node.right != NULL)
		return o << "[&" << node.value << "]" << *(node.right);
	return o << "[&" << node.value << "]";
}

Node* Node::LeftMost() {
	if (this->left == NULL)
		return this;
	return this->left->LeftMost();
}

Node* Node::RightMost() {
	if (this->right == NULL)
		return this;
	return this->right->RightMost();
}