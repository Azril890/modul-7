#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(const Stack &S) {
    return S.Top == 0;
}

bool isFull(const Stack &S) {
    return S.Top == MAX_CAPACITY;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (isEmpty(S) || S.Top == 1) return;

    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    int val;
    // Pindahkan dari S ke temp1 (membalik urutan pertama)
    while (!isEmpty(S)) {
        pop(S, val);
        push(temp1, val);
    }

    // Pindahkan dari temp1 ke temp2
    while (!isEmpty(temp1)) {
        pop(temp1, val);
        push(temp2, val);
    }

    // Pindahkan kembali ke S untuk mengembalikan urutan asli yang sudah dibalik
    while (!isEmpty(temp2)) {
        pop(temp2, val);
        push(S, val);
    }
}