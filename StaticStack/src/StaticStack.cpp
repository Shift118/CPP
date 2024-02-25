#include <iostream>
#define STACKSIZE 100
using namespace std;


struct stack{
	int items[STACKSIZE];
	int top = -1;
};
bool isFull(stack stk){
	if (stk.top == STACKSIZE-1) return true;
	else return false;
}
bool isEmpty(stack stk){
	if (stk.top == -1) return true;
	else return false;
}
void display(stack stk){
	if(isEmpty(stk)) cout<<"\nStack Is Empty !";
	else {
		cout << "\nStack Elements are\n";
		for(int i = stk.top; i >= 0; i--){
			cout << stk.items[i] << "  ";
			cout << endl;
		}
	}
}
void push(stack & stk, int value){
	if (isFull(stk)) cout<<"\nOverflow. You can't insert new item !";
	else{
		stk.top++;
		stk.items[stk.top] = value;
	}
}
void pop (stack & stk){
	if(isEmpty(stk)) cout <<"\nUnderflow. Nothing to pop.";
	else{
		cout << "\nPoped Element is -> "<<stk.items[stk.top] << endl;
		stk.top--;
	}
}
int main() {
	stack s;
	int choice;
	do {
		cout<<"\n=================================\n";
		cout<<"Stack Operations Menu\n";
		cout<<"=================================\n";
		cout<<"1.Push a new item\n";
		cout<<"2.Pop an item\n";
		cout<<"3.Check Full Stack\n";
		cout<<"4.Check Empty Stack\n";
		cout<<"5.Display elements\n"<<endl;
		cout<<"6.Exit\n";
		cout<<"Please Enter your choice: ";
		cin >> choice;
		switch(choice){
		case 1:
			int value;
			cout<<"Enter the value to push: ";
			cin >> value;
			push(s,value);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			if(isFull(s)) cout<<endl<<"Stack Full."<<endl;
			else cout<<endl<<"Stack Not Full"<<endl;
			break;
		case 4:
			if(isEmpty(s)) cout<<endl<<"Stack Empty."<<endl;
			else cout<<endl<<"Stack Not Empty"<<endl;
			break;
		case 5:
			display(s);
			break;

		default:
			cout << "\nOnly enter you choice from the list!!!\n";
			break;
		}
	}while(choice != 6);
	return 0;
}
