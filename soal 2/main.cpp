#include <iostream>
#include "stack.h"

using namespace std;

void tampilkanMenu() {
    cout << "\n--- MENU STACK LINKED LIST (ASCENDING) ---" << endl;
    cout << "1. Tambah Terurut (Push Ascending)" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Tampilkan (Print Info)" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Stack S;
    createStack(S);
    int pilihan, x;

    do {
        tampilkanMenu();
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid." << endl;
            break;
        }

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai integer: ";
                cin >> x;
                pushAscending(S, x);
                cout << "Nilai " << x << " berhasil ditambahkan secara terurut." << endl;
                break;
            case 2:
                if (pop(S, x)) {
                    cout << "Berhasil pop. Nilai yang keluar: " << x << endl;
                } else {
                    cout << "Gagal: Stack kosong!" << endl;
                }
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                clearStack(S);
                cout << "Program selesai, memori dibersihkan." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}