#include <iostream>
using namespace std;

class Node{
public:
	int Value;
	Node * Next;
};

void printList(Node*n){
	while(n != NULL){
		cout << n->Value << endl;
		n = n -> Next;
	}
}

int main() {
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	// Head
	head -> Value = 1;
	head -> Next = second;
	// Second
	second -> Value = 2;
	second -> Next = third;
	// Third
	third -> Value = 3;
	third -> Next = NULL;
	//Print List
	printList(head);
	return 0;
}
