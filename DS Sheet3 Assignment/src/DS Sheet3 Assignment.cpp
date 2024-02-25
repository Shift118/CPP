#include <iostream>
using namespace std;

struct Employee{
	string name;
	int id,salary;
};
void maxSalary(Employee emp[],int size){
	Employee* maxSalaryEmp = &emp[0];
	for(int i = 0;i < size ; i++){
		if (emp[i].salary > (maxSalaryEmp) ->salary){
			 maxSalaryEmp = &emp[i];
		}
	}
	cout << "Employee with Maximum Salary: ";
	cout << "\nName: " << (maxSalaryEmp)->name << "\tID: " << (maxSalaryEmp)->id << "\tSalary: " <<(maxSalaryEmp)->salary;
}

int main() {
	int x;
	cout << "Enter Employee Size: ";
	cin >> x;
	Employee emp[x];
	for(int i = 0; i < x ; i++){
		cout << "Enter Employee "<<i+1 <<" (Name - ID - Salary): ";
		cin >> emp[i].name >>emp[i].id >> emp[i].salary;
	}
	cout <<endl<< "##############"<< endl;
	maxSalary(emp, x);
	return 0;
}
