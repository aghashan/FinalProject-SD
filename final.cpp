#include <iostream>
#include <string>

#define max 25 // Maximum data that can be input

using namespace std;

// Start Struct
struct customer {
    string nama;
    string noTlp;
    string tipeHp;
    string kerusakan;
    string tanggal;
};

struct antrian {
    customer data[max];
    int awal;
    int akhir;
} antri;
// End Struct

// Start Queue
void resetAntrian() {
    antri.awal = 0;
    antri.akhir = 0;
}

bool kosong() {
    return antri.akhir == 0;
}

bool penuh() {
    return antri.akhir == max;
}

void lihat() {
    if (!kosong()) {
        for (int i = antri.awal; i < antri.akhir; i++) {
            cout << "---- Antrian ke-" << i + 1 << " ----" << endl;
            cout << "Nama : " << antri.data[i].nama << endl;
            cout << "Nomor Telepon : " << antri.data[i].noTlp << endl;
            cout << "Tipe HP : " << antri.data[i].tipeHp << endl;
            cout << "Kerusakan : " << antri.data[i].kerusakan << endl;
            cout << "Tanggal : " << antri.data[i].tanggal << endl;
            cout << "------------------------" << endl;
        }
    }
}

void hapus() {
    if (!kosong()) {
        cout << "---- Menghapus Antrian ----" << endl;
        cout << "Nama : " << antri.data[antri.awal].nama << endl;
        cout << "Nomor Telepon : " << antri.data[antri.awal].noTlp << endl;
        cout << "Tipe HP : " << antri.data[antri.awal].tipeHp << endl;
        cout << "Kerusakan : " << antri.data[antri.awal].kerusakan << endl;
        cout << "Tanggal : " << antri.data[antri.awal].tanggal << endl;
        cout << "---------------------------" << endl;

        for (int i = antri.awal; i < antri.akhir - 1; i++) {
            antri.data[i] = antri.data[i + 1];
        }
        antri.akhir--;
        cout << "Antrian sudah dihapus" << endl;
    } else {
        cout << "Tidak ada antrian service!!" << endl;
    }
}
// End Queue

void input() {
    if (!penuh()) {
        customer cus;
        cout << "Nama : ";
        cin >> cus.nama;
        cout << "Nomor Telepon : ";
        cin >> cus.noTlp;
        cout << "Tipe HP : ";
        cin >> cus.tipeHp;
        cout << "Kerusakan : ";
        cin >> cus.kerusakan;
        cout << "Tanggal (D-M-Y): ";
        cin >> cus.tanggal;

        antri.data[antri.akhir] = cus;
        antri.akhir++;
        cout << "Antrian sudah ditambahkan" << endl;
    } else {
        cout << "Antrian service sudah penuh!!" << endl;
    }
}

// Start Sorting
void sortByName() {
    for (int i = antri.awal; i < antri.akhir - 1; i++) {
        for (int j = antri.awal; j < antri.akhir - i - 1; j++) {
            if (antri.data[j].nama > antri.data[j + 1].nama) {
                customer temp = antri.data[j];
                antri.data[j] = antri.data[j + 1];
                antri.data[j + 1] = temp;
            }
        }
    }
    cout << "Antrian telah diurutkan berdasarkan nama" << endl;
}
// End Sorting

// Start Searching
void searchByName() {
    if (!kosong()) {
        string searchName;
        cout << "Masukkan nama yang dicari: ";
        cin >> searchName;
        bool found = false;

        for (int i = antri.awal; i < antri.akhir; i++) {
            if (antri.data[i].nama == searchName) {
                cout << "---- Antrian ke-" << i + 1 << " ----" << endl;
                cout << "Nama : " << antri.data[i].nama << endl;
                cout << "Nomor Telepon : " << antri.data[i].noTlp << endl;
                cout << "Tipe HP : " << antri.data[i].tipeHp << endl;
                cout << "Kerusakan : " << antri.data[i].kerusakan << endl;
                cout << "Tanggal : " << antri.data[i].tanggal << endl;
                cout << "------------------------" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Nama tidak ditemukan dalam antrian" << endl;
        }
    } else {
        cout << "Antrian kosong, tidak ada yang bisa dicari!" << endl;
    }
}
// End Searching

int main() {
    int pil;
    do {
        cout << "Menu Utama" << endl;
        cout << "----------" << endl;
        cout << "[1] Input" << endl;
        cout << "[2] Lihat" << endl;
        cout << "[3] Hapus" << endl;
        cout << "[4] Urutkan Berdasarkan Nama" << endl;
        cout << "[5] Cari Berdasarkan Nama" << endl;
        cout << "[0] Keluar" << endl;
        cout << "-----------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pil;

        switch (pil) {
        case 1:
            input();
            break;
        case 2:
            lihat();
            break;
        case 3:
            hapus();
            break;
        case 4:
            sortByName();
            lihat();
            break;
        case 5:
            searchByName();
            break;
        default:
            break;
        }
    } while (pil != 0);

    return 0;
}