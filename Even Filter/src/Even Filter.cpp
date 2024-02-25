#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "Enter the size of array: ";
	cin >> x;
	int arr[x];
	for(int i = 0; i < x ;i++){
		cout << "Number[" << i+1<<"]: ";
		cin >> arr[i];
	}
	cout <<endl<<"Even: ";
	for(int i = 0; i < x ;i++){
		if(arr[i] % 2 == 0){
			cout << arr[i] << " ";
		}
	}
	return 0;
}
