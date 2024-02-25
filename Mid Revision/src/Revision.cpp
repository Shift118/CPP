#include <iostream>
using namespace std;


struct Tenant{
	string name;
	int age;
	Tenant * Next;
};

void listNodeAdd(Tenant *& listHead,string name,int age){
	Tenant * newNode = new Tenant();
	newNode -> name = name;
	newNode -> age = age;
	newNode -> Next = NULL;
	if(!listHead){
		listHead = newNode;
	}else{
		Tenant * node = listHead;
		while (node -> Next){
			node = node -> Next;
		}
		node -> Next = newNode;
	}
}

int listCount(Tenant * listHead){
	int count = 0;
	while (listHead){
		count++;
		listHead = listHead -> Next;
	}
//	cout << "List Count = " << count << endl;
	return count;
}
void listPrint(Tenant * listHead){
	if(!listHead){
			cout << endl <<"List is Empty!";
			return;
	}
	while(listHead){
		cout  <<"Name: " << listHead->name << " ,  Age: "<< listHead -> age;
		cout << endl;
		listHead = listHead->Next;
	}
}
void listFirstNodeDelete(Tenant *& listHead){
	if(!listHead){
		cout << endl <<"List is Empty!";
	}else{
		Tenant * temp = listHead;
		listHead = listHead -> Next;
		delete temp;	// Delete the Node
		temp = NULL;  // Assign NULL to Pointer
	}
}

void listNodeDelete(Tenant *& listHead,int nodeDeletePosition){
	if (!listHead){
		cout <<endl<< "List is Empty!"<<endl;
		return;
	}else{
		if(nodeDeletePosition < 1 || nodeDeletePosition > listCount(listHead)){
			cout << "Wrong Position"<<endl;
		}else{
			Tenant *bnode , *node = listHead;
			for(int i = 1; i < nodeDeletePosition ; i++){
				bnode = node;
				node = node ->Next;
			}
			bnode -> Next = node->Next;
			delete node;
			node = NULL;
		}
	}
}

void listLastNodeDelete(Tenant *& listHead){
	if(!listHead){
			cout << endl <<"List is Empty!";
			return;
	}
	else if(listHead -> Next == NULL){
		delete listHead;
		listHead = NULL;
	}
	else{
		Tenant * nextNode = listHead -> Next;
		Tenant * pnextNode =  listHead;
		while(nextNode -> Next){
			nextNode = nextNode -> Next;
			pnextNode = pnextNode -> Next;
		}
		pnextNode -> Next = NULL;
		delete nextNode;
		nextNode = NULL;
	}
}

int main(void) {
	//////////Dynamic Memory Allocation/////////////
		int *ptr1 = new int[10]; // Rent Size "10" in memory
		int *ptr2 = new int(50); // Store value 50 in the int.
//		cout << "Enter Int: ";
//		for (int i = 0 ; i< 10 ; i++){
//			cin >> ptr1[i];
//		}
//		cout << endl<< "new:";
//		for (int i = 0 ; i< 10 ; i++){
//			cout << " "<<ptr1[i];
//		}
		cout << "ptr2 = " << *ptr2<<endl;
		delete[]ptr1; //  Delete the Rented Memory
		ptr1 = NULL; //  Made the pointer point to nothing.
//	 	delete p x new p// new makes a variable but delete deletes them.

///////////////////////////////////////////////////////////////////
		/////////////Pointer to Pointer/////////////
		char a = 'g';
		char *b;
		char **c;
		b = &a;
		c = &b;
		cout << "**c = *b  = a = '" <<**c<<"'"<<endl;
///////////////////////////////////////////////////////////////////
		/////////// Pointer to 2D Array /////////////
		int x [3][2] = {{1,2},{3,4},{5,6}};
		int (*ptr)[2];
		ptr = x;
		cout << "x[3][2] = "<<*(*(ptr+2)+1)<<endl;
		///////////////////////////////////////////
		int kk = 0b01111111111111111111111111111111;
		cout <<"Tmax of 4 Byte signed int: "<< kk<<endl;
///////////////////////////////////////////////////////////////////
		/////////// Linked List /////////////
		Tenant * head = NULL;
		cout <<"#############"<<endl;
		listNodeAdd(head, "Mostafa",18);
		listNodeAdd(head, "Ahmed",18);
		listNodeAdd(head, "Moataz",32);
		listNodeAdd(head, "Mazen",18);
		listCount(head);
		listPrint(head);
		cout <<"#############"<<endl;
		listFirstNodeDelete(head);
		listPrint(head);
		cout <<"#############"<<endl;
		listLastNodeDelete(head);
		listPrint(head);
		cout <<"#############"<<endl;
		listNodeAdd(head, "Osama",18);
		listNodeAdd(head, "Khaled",18);
		listNodeAdd(head, "Mohamed",32);
		listNodeAdd(head, "Tarek",18);
		listPrint(head);
		cout <<"#############"<<endl;
		listNodeDelete(head, 3);
		listPrint(head);
///////////////////////////////////////////////////////////////////

}
