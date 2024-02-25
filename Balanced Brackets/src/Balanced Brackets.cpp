#include <iostream>
using namespace std;

struct stack{
	char	value;
	stack * next;
};
bool isEmpty(stack * top){
	if(!top) return true;
	else return false;
}
void display(stack * top){
	if(isEmpty(top)) cout << "\nStack is Empty!";
	else{
		cout <<"\nStack Elements are:\n";
		stack * temp = top;
		while(temp){
			cout<< temp->value << "->" ;
			temp =temp->next;
		}
	}
}
void push(stack *& top , char value){
	stack * newNode = new stack();
	newNode -> value = value;
	newNode -> next = NULL;
	if(isEmpty(top)){
		top = newNode;
	}else{
		newNode -> next = top;
		top = newNode;
	}
}
void pop(stack *& top){
	if(isEmpty(top)) cout<<"\nStack is Empty !!";
	else{
//		cout<< "The popped value is " << top->value;
		stack * temp = top;
		top = top -> next;
		delete temp;
		temp = NULL;
	}
}
bool isBalanced(string expr,stack *& str){
	char x;
	for (int i = 0 ; i < expr.length() ; i++){
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
			push(str,expr[i]);
			continue;
		}
		if(isEmpty(str)) return false;

		switch(expr[i]){
		case ']':
			x = str -> value;
			pop(str);
			if(x != '[') return false;
			break;
		case ')':
			x = str -> value;
			pop(str);
			if(x != '(') return false;
			break;
		case '}':
			x = str -> value;
			pop(str);
			if(x != '{') return false;
			break;
		}
	}
	return true;
}

int main() {
	stack * str = NULL;
	string x = "{[(())]}";
	cout << endl<<endl <<isBalanced(x, str);
	return 0;
}
