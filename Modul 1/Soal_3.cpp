#include <iostream>
using namespace std;

struct DataInput {
    char huruf;
    string kata;
    int angka;
};

int main() {
    DataInput data;

    cout << "Masukkan sebuah huruf = ";
    cin >> data.huruf;

    cout << "Masukkan sebuah kata = ";
    cin >> data.kata;

    cout << "Masukkan Angka = ";
    cin >> data.angka;

    cout << "\nHuruf yang Anda masukkan adalah " << data.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << data.kata << endl;
    cout << "Angka yang Anda masukkan adalah " << data.angka << endl;

    return 0;
}

