#include <iostream>
using namespace std;

void swap(int arr[], int size){
	int temp,j=size-1;
	for (int i = 0; i<j;i++,j--){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}


int main() {
	short size;
	cout << "Enter the Array size: ";
	cin >> size;
	int arr[size];
	for (int i = 0; i < size ;i++){
		cout << "Enter Number[" << i+1 << "]: ";
		cin >> arr[i];
	}
	cout << "####Reverse####" << endl;

	cout << "Reversed: ";
	swap(arr, size);
	for (int i = 0; i < size ;i++){
			cout << arr[i] <<" ";
	}
	return 0;
}
