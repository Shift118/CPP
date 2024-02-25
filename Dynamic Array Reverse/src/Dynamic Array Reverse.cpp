//============================================================================
// Name        : Dynamic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int *reverse(int *arr, int size){
	int* reversedArray = new int[size];
	for (int i = size - 1 ; i >=0 ; i--){
		reversedArray[i] = arr[size - i - 1];
	}
	return reversedArray;
}

int main() {

	return 0;
}
