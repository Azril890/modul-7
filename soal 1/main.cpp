#include <iostream>
#include "stack.h"

using namespace std;

void tampilkanMenu() {
    cout << "\n--- MENU STACK ARRAY ---" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Tampilkan (Print Info)" << endl;
    cout << "4. Balik Stack" << endl;
    cout << "5. Keluar" << endl;
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
                cout << "Masukkan nilai integer yang ingin di-push: ";
                cin >> x;
                if (push(S, x)) {
                    cout << "Berhasil push " << x << " ke dalam stack." << endl;
                } else {
                    cout << "Gagal: Stack penuh! (Kapasitas maksimum 20 elemen)." << endl;
                }
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
                balikStack(S);
                cout << "Stack berhasil dibalik." << endl;
                printInfo(S);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}