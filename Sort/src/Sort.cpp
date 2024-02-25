#include <iostream>
using namespace std;

void reverse(int arr[],int size){
	int rev[size];
	for (int i = 0 ; i < size ; i++){
		rev[size -i-1] = arr[i];
	}
	for (int i = 0; i < size ;i++){
				cout <<endl<<"/ "<< rev[i] <<" ";
		}

}


void sort(int arr[],int size){
	int still = 1,temp;
	while (still != 0){
		still = 0;
		for(int i = 0;i< size-1;i++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				still++;
			}
		}
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
	//// Not Sorted ////
	cout << "Not Sorted: ";
	for (int i = 0; i < size ;i++){
			cout << arr[i] <<" ";
	}
	cout << endl;
	//// Sorting ////
	sort(arr, size);
	cout << "Sorted: ";
	for (int i = 0; i < size ;i++){
			cout << arr[i] <<" ";
	}
	reverse(arr, size);
	return 0;
}
