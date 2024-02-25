#include <iostream>
using namespace std;

int main() {
	int row = 3,col = 2;
	int x [row][col] = {{1,2},{3,4},{5,6}};
	int *ptr;
	for (ptr = &x[0][0] ; ptr <= &x[row-1][col-1] ; ptr++){
		cout << *ptr << endl;
	}
	// OR
	int i,j, (*ptr2)[col];
	cout << "Enter i,j: ";
	cin >> i >> j;
	i--;j--;
	ptr2 = x;
	cout << *(*(ptr2+i)+j);
	return 0;
}
