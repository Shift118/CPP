#include <iostream>
using namespace std;

struct Employee{
	string name;
	int id,salary;
};


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
	for(int i = 0; i < x ; i++){
		cout << endl << "Employee "<<i+1<<":\nName: " << emp[i].name << "\tID: " << emp[i].id << "\tSalary: " <<emp[i].salary;
		cout <<endl<< "##############";
	}
	return 0;
}
