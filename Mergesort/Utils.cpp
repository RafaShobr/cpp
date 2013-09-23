#include <stdlib.h>

using namespace std;


int GetRandomNumber(){
	return rand() % 100;
}

int* GetRandomArray(int size) {
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = GetRandomNumber();
	}
	return arr;
}

