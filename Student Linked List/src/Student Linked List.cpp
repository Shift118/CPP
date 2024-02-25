#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    float degree;
    Student* next;
};

typedef Student* Sptr; // Make a Nickname for Student* that is Sptr
                                       // It just as replacing all Sptr with Student*

void add_to_end(Sptr & listHead, int id, string name, float degree) { //Sptr & listHead == Student* listHead
    Sptr newNode = new Student();                   // Sptr & listHead. The & is for changing the original value of the
                                                                         // Head of the linked List
    newNode->id = id;
    newNode->name = name;
    newNode->degree = degree;
    newNode->next = NULL;

    if (!listHead) {               // If listHead == NULL , NULL is set in the Main() , Then Make the New Node the head.
        listHead = newNode;
//        cout << "New Head Added" << endl;
    } else {
        Sptr nodePtr = listHead;
        while (nodePtr->next) {    // If the next node is NULL then I am at the last Node
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;  // Make the last Node point to the New Node
//        cout << "New Node Added" << endl;
    }
}

void printList(Sptr listHead) {  //Sptr & listHead == Student* listHead
    if (!listHead) {   // If there is no content in Linked List Then print Empty
        cout << "Empty List!" << endl;
        return; // return means don't complete the code and return void.
    }
    while (listHead) { //When the node I am standing on is not = NULL then continue.
        cout << "ID: " << listHead->id << "\tName: " << listHead->name << "\tDegree: " << listHead->degree << endl;
        listHead = listHead->next; // Go to the next node to print its content
    }
}

float avgDegree(Sptr listHead){
	if(!listHead){
		cout << "List is Empty!"<<endl;
		return 0;
	}
	else{
		float sum = 0 , count = 0;
		while(listHead){
			count++;
			sum += listHead -> degree;
			listHead = listHead -> next;
		}
		return sum/count;
	}
}

int main() {
    Sptr head = NULL;
    int available = 1 ; // I made this to make the While continue untill I set it to 0
    int choice = 0; // The choice of the user
    int id;
    float degree;
    string name;
    while(available == 1){
    	cout << "##############"<<endl;
    	cout << "1.  Add a Student"<<endl;
    	cout << "2. View Students" << endl;
    	cout << "3. Average Degree of All Students" << endl;
    	cout << "4. Exit" << endl;
    	cout << "Enter either 1,2,3,4: ";
    	cin >> choice;
    	switch(choice){
    	case 1:
    		cout << "Enter Name: ";
    		cin >> name;
    		cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Degree: ";
			cin >> degree;
			add_to_end(head, id, name, degree);
			break;
    	case 2:
    		printList(head);
    		break;
    	case 3:
    		cout <<endl<<"Average = "<< avgDegree(head) << endl;
    		break;
    	case 4:
    		cout << "See You Later ;)";
    		available = 0;
    		break;
    	default:
    		cout<< endl << "ONLY ENTER EITHER 1,2,3" << endl;
    		break;
    	}
    }
    return 0;
}
