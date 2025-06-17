#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

int main()
{
    int menu;
    do
    {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> menu;

        if (menu == 1)
        {
            clrscr();
            int data[100];
            int cari = 20;
            int counter = 0;
            int flag = 0;
            int save;
            randomize();
            printf("generating 100 number . . \n");
            for (int i = 0; i < 100; i++)
            {
                data[i] = random(100) + 1;
                printf("%d ", data[i]);
            }
            printf("\ndone.\n");

            for (int i = 0; i < 100; i++)
            {
                if (data[i] == cari)
                {
                    counter++;
                    flag = 1;
                    save = i;
                }
            }

            if (flag == 1)
            {
                printf("Data ada, sebanyak %d!\n", counter);
                printf("pada indeks ke-%d", save);
            }
            else
            {
                printf("Data tidak ada!\n");
            }

            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();

        }
        else if (menu == 2)
        {
            int n, kiri, kanan, tengah, temp, key;
            bool ketemu = false;

            cout << "Masukkan jumlah data: ";
            cin >> n;
            int angka[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Angka ke-[" << i << "] : ";
                cin >> angka[i];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (angka[j] > angka[j + 1])
                    {
                        temp = angka[j];
                        angka[j] = angka[j + 1];
                        angka[j + 1] = temp;
                    }
                }
            }

            cout << "===============================================================================\n";
            cout << "Data yang telah diurutkan adalah:\n";
            for (int i = 0; i < n; i++)
            {
                cout << angka[i] << " ";
            }

            cout << "\n===============================================================================\n";
            cout << "Masukan angka yang dicari: ";
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
                cout << "Angka ditemukan! ";
            }
            else
                cout << "Angka tidak ditemukan!";

            cout << "\nPress any key to continue...";
            cin.ignore();
             cin.get();

        }
        else if (menu == 3)
        {
            cout << "\nPerbandingan Sequential Search vs Binary Search\n\n";
        
            cout << "1. Sequential Search\n";
            cout << "   - Prinsip : Cek elemen satu per satu dari awal hingga akhir.\n";
            cout << "   - Kelebihan :\n";
            cout << "         Tidak memerlukan data terurut.\n";
            cout << "         Implementasi sangat sederhana.\n";
            cout << "   - Kekurangan :\n";
            cout << "         Bisa sangat lambat jika data banyak.\n\n";
        
            cout << "2. Binary Search\n";
            cout << "   - Prinsip : Bandingkan target dengan elemen tengah, lalu ulang di setengah kiri/kanan.\n";
            cout << "   - Kelebihan :\n";
            cout << "         Sangat cepat pada data besar.\n";
            cout << "         Jumlah perbandingan jauh lebih sedikit.\n";
            cout << "   - Kekurangan :\n";
            cout << "         Hanya berlaku untuk data yang sudah terurut.\n";
            cout << "         Perlu proses sorting jika data belum terurut.\n\n";

            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        
        }

        if (menu == 4) {
            cout << "\nProgram Selesai\n";
            cout << "Program was made by: Muhammad Hamka Akbari (2410817110007)\n\n";
        }

    } while (menu != 4);

    return 0;
}