#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
	cout << "START" << endl;

	DoublyLinkedList *list = new DoublyLinkedList();
	list->PushFront(new Node(0));
	list->PushTail(new Node(1));
	list->PushTail(new Node(2));
	list->PushTail(new Node(3));
	list->PushTail(new Node(4));
	list->PushTail(new Node(5));

	cout << "print list: " << endl;
	cout << *list << endl;

	cout << "delete list" << endl;
	delete list;


	cout << "FINISH";
	std::getchar();
}