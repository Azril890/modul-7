#ifndef STACK_H
#define STACK_H

const int MAX_CAPACITY = 20;

struct Stack {
    int info[MAX_CAPACITY + 1]; // Indeks 1-20
    int Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif