#ifndef STACK_H
#define STACK_H

struct Node {
    int info;
    Node* next;
};

struct Stack {
    Node* Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
Node* alokasi(int x);
void dealokasi(Node* &p);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif