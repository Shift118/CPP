#include <iostream>
#include <math.h>
using namespace std;

struct stack{
	int value;
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
void push(stack *& top , int value){
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
		stack * temp = top;
		top = top -> next;
		delete temp;
		temp = NULL;
	}
}
int stackSize(stack * top){
	int size = 0;
	if(!top) return size;
	else{
		stack * node = top;
		while(node){
			size++;
			node = node->next;
		}
		return size;
	}
}
double postfixEvaluate(stack *& top){
	double a,b,n,count,result;
	while(stackSize(top) > 1 ){
		a = b =0;
		while(top->value != (' '-'0')){
			if(top->value % 10 == 0 && count == 0) {a *= 10;count++;}
			else{
				a += top -> value*pow(10,n);
				n++;
			}
			pop(top);
		}n = 0;
		pop(top);
		while(top->value != (' '-'0')){
			if(top->value % 10 == 0) b *= 10;
			else{
				b += top -> value*pow(10,n);;
				n++;
			}
			pop(top);

		}n = 0;
		pop(top);
		switch(top->value){
		case '+'-'0': pop(top); push(top,a+b);break;
		case '-'-'0': pop(top); push(top,a-b);break;
		case '*'-'0': pop(top); push(top,a*b);break;
		case '/'-'0': pop(top); push(top,a/b);break;
		}
	}
	result = top -> value;
	pop(top);
	return result;
}
int main() {
	stack * s = NULL;
	string postfix = "3 2 + 5 * 5 - 6 *"; // ((3+2)*5-5)*6 = 120
	for(int i = postfix.length() -1; i >= 0 ; i--){
		push(s,postfix[i] - '0');
	}
	cout <<endl<< postfixEvaluate(s);
//	cout<<(int)(' ') <<(int)('0');
}
