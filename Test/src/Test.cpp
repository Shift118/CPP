//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node{
	int value;
	Node * next;
};

void addatStart(Node *& head, int value){
	Node* newHead;
	newHead -> value = value;
	newHead -> next = NULL;
	if(!head){
		head = newHead;
	}else{
		newHead -> next = head;
		head = newHead;
	}
}

void deleteStart(Node *& head){

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
