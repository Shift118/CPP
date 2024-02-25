#include <iostream>
using namespace std;
const int row = 3,col = 3;

void matrixIN(int arr[][col]){
	for(int i =0 ; i<row ; i++){
			for(int j = 0; j<col;j++){
				cout << "Enter Row " << i+1 << ", Col " << j+1 <<" value: ";
				cin >> arr[i][j];
			}
	}
}
void printMatrix(int arr[][col]){
	for(int i =0 ; i<row ; i++){
		for(int j = 0; j<col;j++){
			cout << arr[i][j] <<"\t";
		}
		cout << endl;
	}
}
void dotMultiplication(int arr1[][col],int arr2[][col],int arr3[][col]){
	for(int i =0 ; i<row ; i++){
		for(int j = 0; j<col;j++){
			arr3[i][j] = 0;
			arr3[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}
int main() {
	int arr1[row][col], arr2[row][col], arr3[row][col];
	cout << "### Enter the values of Matrix 1 ##"<<endl;
	matrixIN(arr1);
	cout << "### Enter the values of Matrix 2 ##"<<endl;
	matrixIN(arr2);
	dotMultiplication(arr1, arr2,arr3);

	// PRINTING
	cout << "Matrix 1:"<<endl;
	printMatrix(arr1);
	cout << endl<<"Matrix 2:"<<endl;
	printMatrix(arr2);
	cout << endl<<"Result:"<<endl;
	printMatrix(arr3);
	return 0;
}
