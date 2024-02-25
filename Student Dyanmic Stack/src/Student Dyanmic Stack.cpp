#include <iostream>
using namespace std;
int count = 0;
struct stack{
	int id;
	float grade;
	stack * next;
};

bool isEmpty(stack * top){
	if(!top) return true;
	else return false;
}
void display(stack * top){
	if(isEmpty(top)) cout << "\nStack is Empty!";
	else{
		cout <<"\nStack Elements are:\n";
		stack * temp = top;
		while(temp){
			cout<< endl <<"Student ID: "<<temp->id << " Grade: "<<temp->grade;
			temp =temp->next;
		}
	}
}
void push(stack *& top , int id,float grade){
	stack * newNode = new stack();
	newNode -> id = id;
	newNode -> grade = grade;
	newNode -> next = NULL;
	count++;
	if(isEmpty(top)){
		top = newNode;
	}else{
		newNode -> next = top;
		top = newNode;
	}
}
void pop(stack *& top){
	if(isEmpty(top)) cout<<"\nStack is Empty !!";
	else{
		count--;
		cout<< "\nThe popped Student is -> "<<endl << "Student ID: "<<top->id << " Grade: "<<top->grade;
		stack * temp = top;
		top = top -> next;
		delete temp;
		temp = NULL;
	}
}
int main() {
	stack * s = NULL;
	int choice;
	do {
		cout<<"\n=================================\n";
		cout<<" Dynamic Stack Operations Menu\n";
		cout<<"=================================\n";
		cout<<"1.Push a Student\n";
		cout<<"2.Pop a Student\n";
		cout<<"3.Check Empty Stack\n";
		cout<<"4.Display elements\n";
		cout<<"5.Students Count\n";
		cout<<"6.Exit\n";
		cout<<endl<<"Please Enter your choice: ";
		cin >> choice;
		switch(choice){
		case 1:
			int id;
			float grade;
			cout<<"Enter the ID to push: ";
			cin >> id;
			cout<<"Enter the Grade to push: ";
			cin >> grade;
			push(s,id,grade);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			if(isEmpty(s)) cout<<endl<<"Stack Empty."<<endl;
			else cout<<endl<<"Stack Not Empty"<<endl;
			break;
		case 4:
			display(s);
			break;
		case 5:
			cout << endl <<"Students Count: " << count << endl;
			break;
		default:
			cout << "\nOnly enter you choice from the list!!!\n";
			break;
		}
	}while(choice != 6);
	return 0;
}
