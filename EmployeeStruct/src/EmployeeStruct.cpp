#include <iostream>
using namespace std;

struct Employee{
	string name;
	int id,salary;
}E1,E2;


int main() {
	cout << "Enter Employee 1 (Name - ID - Salary): ";
	cin >> E1.name >>E1.id >> E1.salary;
	cout << "Enter Employee 2 (Name - ID - Salary): ";
	cin >> E2.name >>E2.id >> E2.salary;
	cout << endl << "Employee 1:\nName: " << E1.name << "\tID: " << E1.id << "\tSalary: " <<E1.salary;
	cout <<endl<< "##############";
	cout << endl << "Employee 2:\nName: " << E2.name << "\tID: " << E2.id << "\tSalary: " <<E2.salary;
	return 0;
}
