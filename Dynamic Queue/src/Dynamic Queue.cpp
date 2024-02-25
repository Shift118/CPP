#include <iostream>
using namespace std;

struct Node {
	float data;
	Node *Next;
};

bool isEmpty(Node* front, Node * rear){
	if (!rear && !front) return true;
	else return false;
}

void enqueue(Node *& front, Node *& rear , float value){
	Node * newNode = new Node;
	newNode -> data = value;
	newNode -> Next = NULL;
	if (isEmpty(front,rear)) { // We add to the rear and delete from the front
		rear = newNode;
		front = rear;
	}else {
		rear -> Next = newNode;
		rear = newNode;
	}
}

void dequeue(Node *& front, Node *& rear){
	if (isEmpty(front, rear)){
		cout <<endl<<"List is Empty!";
		return;
	}else if (front -> Next == NULL){
		cout <<endl<< "Dequeued Element is: " << front -> data <<endl;
		delete front;
		front = NULL;
		rear = NULL;
	}else{
		Node * temp = front;
		cout <<endl<< "Dequeued Element is: " << front -> data <<endl;
		front = front -> Next;
		delete temp;
		temp = NULL;
	}
}

void displayQueue(Node * front, Node * rear){
	if (isEmpty(front,rear)){
		cout <<endl<<"List is Empty!";
		return;
	}else{
		cout <<endl<< "Queue Elements: ";
		Node * temp = front;
		while(temp){
			cout << temp -> data << " ";
			temp = temp ->Next;
		}
	}
}


int main() {
	Node * front = NULL,*rear = NULL;
	int choice = 0,value;
	do{
		cout <<endl<<"1. Enqueue Queue.";
		cout <<endl<<"2. Dequeue Queue.";
		cout <<endl<<"3. Display Queue Nodes.";
		cout <<endl<<"4. Check If Empty.";
		cout <<endl<<"5. Exit.";
		cout <<endl<< "Enter Your Choice: ";
		cin >> choice;
		switch(choice){
		case 1: cout<<endl<<"Enter The Value: ";cin>>value;enqueue(front, rear, value);break;
		case 2: dequeue(front, rear);break;
		case 3: displayQueue(front, rear);break;
		case 4: cout<<endl<<"List is Empty: "<< isEmpty(front, rear);break;
		case 5: choice = 6;cout<<endl<<"Bye Bye ;)";break;
		default: cout<<endl<<"Only Enter Your Choice from the List Please !!!";break;
		}
	}while(choice != 6);
	return 0;
}
