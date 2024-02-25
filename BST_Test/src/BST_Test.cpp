#include <iostream>
using namespace std;

struct Node{
	int val;
	Node * left, *right;
};

void insert(Node *& root, int val){
	if(!root){
		Node * newRoot = new Node();
		newRoot -> val = val;
		newRoot -> left = newRoot -> right = NULL;
		root = newRoot;
	}else if(val < root -> val){
		insert(root -> left,val);
	}else if(val > root -> val){
		insert(root -> right,val);
	}
}

void preOrderTraversal(Node * root){ // Root -> Left -> Right
	if(!root) return;
	cout <<root -> val << " ";
	preOrderTraversal(root -> left);
	preOrderTraversal(root -> right);
}
void inOrderTraversal(Node * root){ // Left-> Root -> Right
	if(!root) return;
	inOrderTraversal(root -> left);
	cout <<root -> val << " ";
	inOrderTraversal(root -> right);
}
void postOrderTraversal(Node * root){ // Left -> Right -> Root
	if(!root) return;
	postOrderTraversal(root -> left);
	postOrderTraversal(root -> right);
	cout <<root -> val << " ";
}

int treeHeight(Node * root){
	if(!root) return 0;
	int leftHeight = treeHeight(root -> left);
	int rightHeight = treeHeight(root -> right);
	if(leftHeight >= rightHeight) return leftHeight +1;
	else return rightHeight +1;
}

void printLevel(Node * root,int lv){
	if(!root) return;
	if(lv == 0) cout << root -> val << " ";
	else if (lv > 0){
	printLevel(root -> left , lv - 1);
	printLevel(root -> right , lv - 1);
	}
}

void breadthFirst(Node * root){
	int height = treeHeight(root);
	for(int i = 0; i < height ; i++){
		printLevel(root,i);
	}
}

Node * search(Node * root, int val){
	if(!root || root -> val == val) return root;
	if (val < root -> val) return search(root -> left,val);
	else return search(root -> right,val);
}

int main() {
	Node * root = NULL;
	insert(root,15);
	insert(root,11);
	insert(root,26);
	insert(root,8);
	insert(root,12);
	insert(root,20);
	insert(root,30);
	insert(root,6);
	insert(root,9);
	insert(root,14);
	insert(root,35);

	cout <<endl<< "Tree Height: " << treeHeight(root);
	cout <<endl<< "post: ";postOrderTraversal(root);
	cout <<endl<< "In: ";inOrderTraversal(root);
	cout <<endl<< "Pre: ";preOrderTraversal(root);
	cout <<endl<< "Breadth: ";breadthFirst(root);

	return 0;
}
