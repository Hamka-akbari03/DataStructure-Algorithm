#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <conio.h>    // Untuk _getch()
using namespace std;

// Fungsi untuk menampilkan array integer
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ================== Sorting untuk Nama (String) ==================
// 1. Insertion Sort untuk string
void insertionSort(string &str) {
    int n = str.length();
    for (int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && tolower(str[j]) > tolower(key)) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

// 2. Merge Sort untuk string
void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L = str.substr(left, n1);
    string R = str.substr(mid + 1, n2);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (tolower(L[i]) <= tolower(R[j])) {
            str[k] = L[i];
            i++;
        } else {
            str[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        str[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        str[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

// 3. Shell Sort untuk string
void shellSort(string &str) {
    int n = str.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && tolower(str[j - gap]) > tolower(temp); j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

// ================== Sorting untuk NIM (Integer) ==================
// 4. Quick Sort untuk integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 5. Bubble Sort untuk integer
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 6. Selection Sort untuk integer
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int pilihan;
    do {
        // ---------- Tampilkan menu sorting terlebih dahulu ----------
        cout << "\n|================ SORTING ================|\n";
        cout << "| 1. Insertion Sort (Nama)                |\n";
        cout << "| 2. Merge Sort (Nama)                    |\n";
        cout << "| 3. Shell Sort (Nama)                    |\n";
        cout << "| 4. Quick Sort (NIM)                     |\n";
        cout << "| 5. Bubble Sort (NIM)                    |\n";
        cout << "| 6. Selection Sort (NIM)                 |\n";
        cout << "| 7. Exit                                 |\n";
        cout << "|----------------------------------------|\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Insertion Sort untuk Nama (string)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nama;
                cout << "\nMasukkan Nama: ";
                getline(cin, nama);

                cout << "Nama sebelum: " << nama << endl;
                insertionSort(nama);
                cout << "Nama setelah Insertion Sort: " << nama << endl;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 2: {
                // Merge Sort untuk Nama (string)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nama;
                cout << "\nMasukkan Nama: ";
                getline(cin, nama);

                cout << "Nama sebelum: " << nama << endl;
                mergeSort(nama, 0, nama.length() - 1);
                cout << "Nama setelah Merge Sort: " << nama << endl;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 3: {
                // Shell Sort untuk Nama (string)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nama;
                cout << "\nMasukkan Nama: ";
                getline(cin, nama);

                cout << "Nama sebelum: " << nama << endl;
                shellSort(nama);
                cout << "Nama setelah Shell Sort: " << nama << endl;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 4: {
                // Quick Sort untuk NIM (integer)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nimStr;
                cout << "\nMasukkan NIM (hanya angka, tanpa spasi): ";
                getline(cin, nimStr);

                int n_nim = nimStr.length();
                int* nim = new int[n_nim];
                for (int i = 0; i < n_nim; i++) {
                    nim[i] = nimStr[i] - '0';
                }

                cout << "NIM sebelum: ";
                printArray(nim, n_nim);

                int* temp = new int[n_nim];
                copy(nim, nim + n_nim, temp);
                quickSort(temp, 0, n_nim - 1);

                cout << "NIM setelah Quick Sort: ";
                printArray(temp, n_nim);

                delete[] nim;
                delete[] temp;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 5: {
                // Bubble Sort untuk NIM (integer)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nimStr;
                cout << "\nMasukkan NIM (hanya angka, tanpa spasi): ";
                getline(cin, nimStr);

                int n_nim = nimStr.length();
                int* nim = new int[n_nim];
                for (int i = 0; i < n_nim; i++) {
                    nim[i] = nimStr[i] - '0';
                }

                cout << "NIM sebelum: ";
                printArray(nim, n_nim);

                int* temp = new int[n_nim];
                copy(nim, nim + n_nim, temp);
                bubbleSort(temp, n_nim);

                cout << "NIM setelah Bubble Sort: ";
                printArray(temp, n_nim);

                delete[] nim;
                delete[] temp;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 6: {
                // Selection Sort untuk NIM (integer)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nimStr;
                cout << "\nMasukkan NIM (hanya angka, tanpa spasi): ";
                getline(cin, nimStr);

                int n_nim = nimStr.length();
                int* nim = new int[n_nim];
                for (int i = 0; i < n_nim; i++) {
                    nim[i] = nimStr[i] - '0';
                }

                cout << "NIM sebelum: ";
                printArray(nim, n_nim);

                int* temp = new int[n_nim];
                copy(nim, nim + n_nim, temp);
                selectionSort(temp, n_nim);

                cout << "NIM setelah Selection Sort: ";
                printArray(temp, n_nim);

                delete[] nim;
                delete[] temp;

                // Tunggu tombol apa saja
                cout << "\nPress any key to continue...";
                _getch();
                break;
            }
            case 7:
                cout << "\nTerima kasih! Program was made by Muhammad Hamka Akbari (2410817110007)." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi." << endl;
                // Tidak perlu pause di sini, langsung kembali ke menu
        }
    } while (pilihan != 7);

    return 0;
}