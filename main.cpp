// --- Requirements ---
// + Queue = done
// + Sorting =
// + Searcing =
// + Struct = done
// + Array = done
// --------------------

#include <iostream>
#define max 25 //jadi maksimum data yang dimasukkan adalah 25

using namespace std;

//Strat Struct  
struct customer
{
    string nama;
    string noTlp;
    string tipeHp;
    string kerusakan;
    string tanggal;
};

struct antrian
{
    customer data[25];
    int awal;
    int akhir;
} antri;
//End Struct

//Start Queue 
void resetAntrian() //untuk reset antrian / menghapus semua antrian
{
    antri.awal = 0;
    antri.akhir = 0;
}

bool kosong()
{
    if (antri.akhir == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool penuh() //untuk mengecek apakah data sudah penuh / belum
{
    if (antri.akhir == max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void lihat() //menampilkan data yang sudah tersimpan pada array
{
    if (!kosong())
    {
            //Start Array
        for (int i = antri.awal; i <= antri.akhir - 1; i++)
        {
            cout << "---- Antrian ke-" << i + 1 << "- ---" << endl;
            cout << "Nama : " << antri.data[i].nama << endl;
            cout << "Nomor Telepon : " << antri.data[i].noTlp << endl;
            cout << "Tipe HP : " << antri.data[i].tipeHp << endl;
            cout << "Kerusakan : " << antri.data[i].kerusakan << endl;
            cout << "Tanggal : " << antri.data[i].tanggal << endl;
            cout << "------------------------" << endl;
        }
            //End Array
    }
}

void hapus()
{
    if (!kosong())
    {
        //Start Array
        for (int i = antri.awal; i <= antri.akhir - 1; i++)
        {
            cout << "---- Antrian ke-" << i + 1 << "- ---" << endl;
            cout << "Nama : " << antri.data[i].nama << endl;
            cout << "Nomor Telepon : " << antri.data[i].noTlp << endl;
            cout << "Tipe HP : " << antri.data[i].tipeHp << endl;
            cout << "Kerusakan : " << antri.data[i].kerusakan << endl;
            cout << "Tanggal : " << antri.data[i].tanggal << endl;
            cout << "------------------------" << endl;

            cout << "Sudah selesai service!!" << endl;
            antri.akhir--;
        }
        //End Array
    }
    else
    {
        cout << "Tidak ada antrian service!!" << endl;
    }
}
//End Queue

void input() //untuk menambahkan data
{
    customer cus; //untuk mengakses data yabg berada di customer

    if (!penuh())
    {
        cout << "Nama : ";
        cin >>cus.nama;
        cout << "Nomor Telepon : ";
        cin >>cus.noTlp;
        cout << "Tipe HP : ";
        cin >>cus.tipeHp;
        cout << "Kerusakan : ";
        cin >>cus.kerusakan;
        cout << "Tanggal (D-M-Y): ";
        cin >>cus.tanggal;

        antri.data[antri.akhir].nama = cus.nama;
        antri.data[antri.akhir].noTlp = cus.noTlp;
        antri.data[antri.akhir].tipeHp = cus.tipeHp;
        antri.data[antri.akhir].kerusakan = cus.kerusakan;
        antri.data[antri.akhir].tanggal = cus.tanggal;

        antri.akhir++;

        cout << "Antrian sudah ditambahkan" << endl;
    }
    else
    {
        cout << "antrian service sudah penuh!!" << endl;
    }
}

int main()
{
    int pil;
    do
    {
        cout << "Menu Utama" << endl;
        cout << "----------" << endl;
        cout << "[1] Input" << endl;
        cout << "[2] Lihat" << endl;
        cout << "[3] Hapus" << endl;
        cout << "[0] Keluar" << endl;
        cout << "-----------" << endl;
        cout << "Masukan pilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            input();
            break;
        case 2:
            lihat();
            break;
        case 3:
            hapus();
            break;
        default:
            break;
        }
    } while (pil != 0);
}
