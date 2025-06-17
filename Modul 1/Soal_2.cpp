#include <iostream>
using namespace std;

struct Kendaraan {
    string platNomor;
    string jenis;
    string namaPemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan kendaraan1 = {
        "DA1234MK",
        "RUSH",
        "Andika Hartanto",
        "Jl. Kayu Tangi 1",
        "Banjarmasin"
    };

    cout << "Plat Nomor Kendaraan : " << kendaraan1.platNomor << endl;
    cout << "Jenis Kendaraan      : " << kendaraan1.jenis << endl;
    cout << "Nama Pemilik         : " << kendaraan1.namaPemilik << endl;
    cout << "Alamat               : " << kendaraan1.alamat << endl;
    cout << "Kota                 : " << kendaraan1.kota << endl;

    return 0;
}
