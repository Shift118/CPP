#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Queue{
	Node* front;
	Node* rear;
};

Queue * createQueue(){
	Queue * queue = new Queue;
	queue -> front = nullptr;
	queue -> rear = nullptr;
	return queue;
}

void enqueue (Queue * queue , int data){
	Node *newNode = new Node;
	newNode -> data = data;
	newNode -> next = nullptr;
	if (queue -> front == nullptr){
		queue -> front  = newNode;
		queue -> rear = newNode;
	}else{
		queue -> rear -> next = newNode;
		queue -> rear = newNode;
	}
}

int dequeue(Queue* queue){
	if (queue -> front == nullptr){
		cout << "Queue it empty";
	}
	Node * temp = queue -> front ;

}

void display (Queue * queue){

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
