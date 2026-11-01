#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(const Stack &S) {
    return S.Top == nullptr;
}

Node* alokasi(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(Node* &p) {
    delete p;
    p = nullptr;
}

bool push(Stack &S, int x) {
    Node* p = alokasi(x);
    if (p == nullptr) return false;
    p->next = S.Top;
    S.Top = p;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    Node* p = S.Top;
    x = p->info;
    S.Top = p->next;
    dealokasi(p);
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    Node* p = S.Top;
    cout << "TOP: ";
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void pushAscending(Stack &S, int x) {
    Stack tempStack;
    createStack(tempStack);
    int val;

    // Pindahkan elemen yang lebih kecil dari x ke stack bantu agar x bisa disisipkan pada posisi yang tepat
    // Urutan dari bawah ke TOP adalah menaik, sehingga dari TOP ke bawah adalah menurun.
    // Elemen di TOP bernilai paling besar.
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, val);
        push(tempStack, val);
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari stack bantu ke stack utama
    while (!isEmpty(tempStack)) {
        pop(tempStack, val);
        push(S, val);
    }
}

void clearStack(Stack &S) {
    int x;
    while (!isEmpty(S)) {
        pop(S, x);
    }
}