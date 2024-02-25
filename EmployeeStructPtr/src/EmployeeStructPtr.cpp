#include <iostream>
using namespace std;

struct Employee{
	string name;
	int id,salary;
};

int main() {
	int size;
	cout << "Enter Number of Employees: " ;
	cin >> size;
	Employee arr[size], *ptr = arr;

	for(int i =0 ; i< size;i++){
		cout << " Enter Employee (Name-ID-Salary): ";
		cin >> (ptr+i) -> name >> (ptr+i) -> id >> (ptr+i) -> salary;
		// " -> "Takes the value and returns it to the address
	}
	for(int i = 0;i<size;i++){
		cout << endl << "Employee "<<i+1<<":\nName: " << (ptr+i)->name << "\tID: " << (ptr+i)->id << "\tSalary: " <<(ptr+i)->salary;
		// " -> " Returns the Value.
		cout <<endl<< "##############";
	}
	return 0;
}
