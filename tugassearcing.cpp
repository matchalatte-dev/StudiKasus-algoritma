#include <iostream>
using namespace std;

struct Buku {
    string nama;
    int harga;
};

Buku buku[5] = {
    {"Bintang", 300000},
    {"Bumi", 150000},
    {"Matahari", 185000},
    {"Bulan", 155000},
    {"Sagaras", 800000}
};

void tampilDaftar() {
    cout << "===== DAFTAR BUKU =====" << endl;
    for(int i = 0; i < 5; i++) {
        cout << i+1 << buku[i].nama << endl;
    }
    cout << endl;
}

void TanpaSentinel() {

    string cari;
    bool ketemu = false;
    int i = 0;

    cout << "Masukkan nama buku yang dicari: ";
    cin >> cari;

    while(i < 5 && !ketemu){
        if(buku[i].nama == cari)
            ketemu = true;
        else
            i++;
    }

    if(ketemu){
        cout << "Buku DITEMUKAN!" << endl;
        cout << "Harga : Rp " << buku[i].harga << endl;
    } else {
        cout << "Buku TIDAK DITEMUKAN" << endl;
    }
}

void DenganSentinel() {

    Buku temp[6];
    for(int i=0;i<5;i++)
        temp[i] = buku[i];

    string cari;
    int i = 0;

    cout << "Masukkan nama buku yang dicari: ";
    cin >> cari;

    temp[5].nama = cari; 

    while(temp[i].nama != cari){
        i++;
    }

    if(i > 4){
        cout << "Buku TIDAK DITEMUKAN" << endl;
    } else {
        cout << "Buku DITEMUKAN!" << endl;
        cout << "Harga : Rp " << temp[i].harga << endl;
    }
}

void binarySearch() {

    string cari;
    int kiri = 0, kanan = 4, tengah;
    bool found = false;

    cout << "Masukkan nama buku yang dicari: ";
    cin >> cari;

    while(!found && kiri <= kanan){
        tengah = (kiri + kanan)/2;

        if(cari == buku[tengah].nama)
            found = true;
        else if(cari < buku[tengah].nama)
            kanan = tengah - 1;
        else
            kiri = tengah + 1;
    }

    if(found){
        cout << "Buku DITEMUKAN!" << endl;
        cout << "Harga : Rp " << buku[tengah].harga << endl;
    } else {
        cout << "Buku TIDAK DITEMUKAN" << endl;
    }
}

int main(){

    int pilihan, cara;

    
    tampilDaftar();

    cout << "===== MENU PENCARIAN =====" << endl;
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Pilih menu : ";
    cin >> pilihan;

    cout << endl;

    
    if(pilihan == 1){

        cout << "1. Tanpa Sentinel" << endl;
        cout << "2. Dengan Sentinel" << endl;
        cout << "Pilih metode : ";
        cin >> cara;
        cout << endl;

        if(cara == 1)
            TanpaSentinel();
        else if(cara == 2)
            DenganSentinel();
        else
            cout << "Pilihan tidak valid!" << endl;
    }

    
    else if(pilihan == 2){
        binarySearch();
    }
    else{
        cout << "Menu tidak tersedia!" << endl;
    }

    return 0;
}
