#include <iostream>
using namespace std;

struct stack{
	int data;
	stack * next;
};

bool isEmpty(stack * top){
	if(!top) return true;
	else return false;
}

void display(stack * top){
	if (isEmpty(top)){
		cout << endl <<  "Stack is Empty !";
		return;
	}else {
		stack * temp = top;
		cout<< endl << "Stack: ";
		while (temp){
			cout << temp -> data << " ";
			temp = temp -> next;
		}
	}
}

void push(stack *& top,int data){
	stack * newNode = new stack;
	newNode -> data = data;
	newNode -> next = NULL;
	if ( !top){
		top = newNode;
	}else{
		newNode -> next = top;
		top = newNode;
	}
}

void pop(stack *& top){
	if ( !top){
		cout <<endl<< "Stack Empty !";
	}else{
		stack * temp = top;
		cout<<endl<< "The popped value is " << top->data;
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
			cout<<"1.Push a new item\n";
			cout<<"2.Pop an item\n";
			cout<<"3.Check Empty Stack\n";
			cout<<"4.Display elements\n";
			cout<<"5.Exit\n";
			cout<<endl<<"Please Enter your choice: ";
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
				if(isEmpty(s)) cout<<endl<<"Stack Empty."<<endl;
				else cout<<endl<<"Stack Not Empty"<<endl;
				break;
			case 4:
				display(s);
				break;
			default:
				cout << "Bye !";
				break;
			}
		}while(choice != 5);
		return 0;
}
