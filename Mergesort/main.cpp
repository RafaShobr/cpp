#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

#include "MergeSort.h"
#include "Utils.h"

using namespace std;

#define SORT_ELEMS 20

void PrintArray(int * arr, int length)
{
	cout << "print array: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "[" << arr[i] << "]";
	}
	cout << endl;
}

int main()
{
	cout << "START" << endl;

	DoublyLinkedList *list = new DoublyLinkedList();
	list->PushFront(new Node(3));
	list->PushFront(new Node(2));
	list->PushFront(new Node(1));
	list->PushFront(new Node(0));
	list->PushTail(new Node(4));
	list->PushTail(new Node(5));

	cout << "print list: " << endl;
	cout << list << endl;
	cout << *list << endl;

	cout << "list to array: " << endl;
	int *arr = list->ToArray();
	int arrLength = list->size;
	cout << "print array: " << endl;
	for (int i = 0; i < arrLength; i++)
	{
		cout << "[" << arr[i] << "]";
	}
	cout << endl;
	delete[] arr;
	arr = NULL;

	cout << "delete list" << endl;
	delete list;

	cout << "get array of " << SORT_ELEMS << " elements :" << endl;
	arr = GetRandomArray(SORT_ELEMS);
	PrintArray(arr, SORT_ELEMS);


	cout << endl << "MergeSort" << endl;

	//MergeSort()

	delete[] arr;
	cout << endl << "FINISH";
	std::getchar();
}