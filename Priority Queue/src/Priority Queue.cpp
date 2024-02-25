#include <iostream>
using namespace std;

struct Node{
	float data;
	int priority;
	Node * Next;
};

void enqueue(Node *& head,float value,int priority){
	Node * newNode = new Node;
	newNode -> data = value;
	newNode -> priority = priority;
	newNode -> Next = NULL;
	if (!head){
		head = newNode;
	}else if (head -> priority < newNode -> priority){
		newNode -> Next = head;
		head = newNode;
	}else{
		Node * nodePtr = head;
		while(nodePtr->Next && nodePtr -> Next -> priority > newNode -> priority){
			nodePtr = nodePtr -> Next;
		}
		newNode -> Next = nodePtr -> Next;
		nodePtr -> Next = newNode;
	}
}

void dequeue(Node *& head){
	if(!head){
		cout <<endl<< "Head is Empty!";
		return;
	}else{
		Node * temp = head;
		cout <<endl<< "Dequeued Element: "<<head->data;
		cout<<"\tPriority: "<< head->priority;
		head = head -> Next;
		delete temp;
		temp = NULL;
	}
}

void display(Node * head){
	if (!head){
		cout <<endl<< "Head is Empty!";
		return;
	}else{
		Node* temp = head;
		while(temp){
			cout <<endl<<"Element: "<<temp->data<<"\tPriority: "<<temp->priority;
			temp = temp -> Next;
		}
	}
}

int main() {
	Node * head = NULL;
	enqueue(head, 90, 9);
	enqueue(head, 50, 1);
	enqueue(head, 70, 3);
	enqueue(head, 80, 6);
	enqueue(head, 60, 2);
	enqueue(head, 100, 10);
	display(head);
	return 0;
}
