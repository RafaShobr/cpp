#pragma once
#include "Node.h"
#include <ostream>

class DoublyLinkedList
{
private:
	Node *root;
	Node *tail;
	

public:
	int size;

	DoublyLinkedList(void);
	~DoublyLinkedList(void);
	
	void PushFront(Node*);
	void PushTail(Node*);

	void InsertNodesLeft(Node*, Node*);
	void InsertNodesRight(Node*, Node*);
	int* ToArray();

	friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList*);
	friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList&);
};

