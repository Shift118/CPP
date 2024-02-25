#include <iostream>
using namespace std;

float avg(float * arr, int size){
	float sum=0;
	for (int i = 0; i< size; i++){
//		sum+=arr[i];
//		OR
		sum += *(arr+i);
	}
	sum/=size;
	return sum;
}

int main() {
	int size ;
	cout << "Enter Array Size: ";
	cin >> size;
	float arr[size];
	for (int i = 0; i<size ; i++){
		cout << "Enter Element "<<i+1<<": ";
		cin >> arr[i];
	}

	float* ptr = arr;
	cout << "List average: "<<avg(ptr, size);

	return 0;
}
