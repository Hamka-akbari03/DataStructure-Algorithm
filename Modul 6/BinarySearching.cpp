#include <iostream>
using namespace std;

int main()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; 1 < n; i++)
    {
        cout << "Angka ke - [" << i <<"] : ";
        cin >> angka[i];
    }

    for (int i = 0; i <  n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j +1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "================================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; 1 < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n================================================================\n";
    cout << "Masukan angka yang diari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }
    if (ketemu == true)
    {
        cout << "Angka ditemukan ";
    }
    else 
        cout << "Angka tidak ditemukan";
    return 0; 
}