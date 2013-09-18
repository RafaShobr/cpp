#pragma once
#include <cstdlib>
#include <ostream>

using namespace std;

class Node
{
public:
	Node *left;
	Node *right;
	int value;

	Node(void);
	Node(int);
	~Node(void);

	Node* RightMost();
	Node* LeftMost();

	friend std::ostream& operator<<(std::ostream&, const Node&);
	
};

