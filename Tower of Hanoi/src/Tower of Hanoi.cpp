#include <iostream>
using namespace std;
#define N 3

struct Stack {
    int value[N];
    int pos = -1;
};

void push(Stack*& head, int disk) {
    if (head->pos + 1 >= N) {
        cout << endl << "Stack is Full";
    }
    else {
        head->value[++head->pos] = disk;
    }
}

void pop(Stack*& head) {
    if (head->pos + 1 == 0) {
        cout << endl << "List Is Empty";
    }
    else {
        cout << endl << "Value popped: " << head->value[head->pos--];
    }
}

void display(const Stack& head, const string& name) {
    cout << name;
    for (int i = 0; i <= head.pos; i++) {
        cout << head.value[i] << " ";
    }
    cout << endl;
}

void moveDisk(Stack*& source, Stack*& destination) {
    if (source->pos >= 0) {
        int disk = source->value[source->pos--];
        push(destination, disk);
        cout << "Moved disk " << disk << endl;
    }
    else {
        cout << "Source tower is empty." << endl;
    }
}

void hanoiTower(Stack*& source, Stack*& destination, Stack*& auxiliary) {
    int totalMoves = (1 << N) - 1;
    if (N % 2 == 0) {
        moveDisk(destination, auxiliary);
    }

    for (int move = 1; move <= totalMoves; ++move) {
        if (move % 3 == 1) {
            moveDisk(source, destination);
            display(*source, "Tower1");
            display(*auxiliary, "Tower2");
            display(*destination, "Tower3");
            cout << "========\n";
        }
        else if (move % 3 == 2) {
            moveDisk(source, auxiliary);
        }
        else {
            moveDisk(auxiliary, destination);
        }
    }
}

int main() {
    Stack* source = new Stack;
    Stack* destination = new Stack;
    Stack* auxiliary = new Stack;

    for (int i = N; i > 0; --i) {
        push(source, i);
    }

    display(*source, "Tower1");

    hanoiTower(source, destination, auxiliary);

    delete source;
    delete destination;
    delete auxiliary;

    return 0;
}
