#include <iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
	if(rear == N-1){
		cout<<endl<<"Overflow";
	}else if (front == -1 && rear == -1){
		front = rear =  0;
		queue[rear] = x;
	}else{
		rear++;
		queue[rear] = x;
	}
}

void displayQueue(){
	if (front == -1 && rear == -1){
		cout << endl << "Queue is Empty";
	}
	else{
		cout<<endl;
		for(int i = front; i <= rear;i++){
			cout << queue[i] << " ";
		}
	}
}

void dequeue(){
	if(front == -1 && rear == -1){
		cout <<endl<< "Underflow";
	}else if (front == rear){
		cout <<endl<<"Dequeued value: "<<queue[front];
		front = rear = -1;
	}else{
		cout <<endl<<"Dequeued value: "<<queue[front];
		front++;
	}
}

void peek(){
	if(front == -1 && rear == -1){
		cout <<endl<< "Underflow";
	}else{
		cout <<endl<<"Front value: "<<queue[front];
	}
}

int main() {
	enqueue(2);
	enqueue(3);
	enqueue(4);
	displayQueue();
	peek();
	dequeue();
	peek();
	displayQueue();
	return 0;
}
