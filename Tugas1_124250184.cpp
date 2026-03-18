#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct produk{
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

produk dataProduk[100];
int n = 0;

void load()
    {
    FILE *file = fopen("lelele.csv","r");

    if(file == NULL){
        cout<<"File belum ada, data kosong.\n";
        return;
        }

    while(n < 100 && fscanf(file," %[^,],%f,%[^,],%d",
        dataProduk[n].nama,
        &dataProduk[n].harga,
        dataProduk[n].kategori,
        &dataProduk[n].stok) == 4)
        {
        n++;
         }

    fclose(file);
     }


void save()
    {
    FILE *file = fopen("lelele.csv","w");

    if(file == NULL){
        cout<<"Gagal menyimpan file!\n";
        return;
    }

    for(int i=0;i<n;i++)
      {
        fprintf(file,"%s,%.1f,%s,%d\n",
            dataProduk[i].nama,
            dataProduk[i].harga,
            dataProduk[i].kategori,
            dataProduk[i].stok);
       }

    fclose(file);
    }


void tambah()
    {
    if(n >= 100){
        cout<<"Data penuh!\n";
        return;
     }

    cin.ignore(); 

    cout<<"Nama: ";
    cin.getline(dataProduk[n].nama,50);

    cout<<"Harga: ";
    cin>>dataProduk[n].harga;

    do{
        cout<<"Kategori (makanan/minuman): ";
        cin>>dataProduk[n].kategori;
    }while(strcmp(dataProduk[n].kategori,"makanan")!=0 &&
           strcmp(dataProduk[n].kategori,"minuman")!=0);

    cout<<"Stok: ";
    cin>>dataProduk[n].stok;

    n++;
    save();

    cout<<"Data berhasil ditambahkan!\n";
     }


void tampil()
    {
    if(n == 0)
    {
        cout<<"Data kosong!\n";
        return;
    }

    cout<<"\n=== DATA PRODUK ===\n";
    cout<<"No | Nama | Harga | Kategori | Stok\n";

    for(int i=0;i<n;i++)
       {
        cout<<i+1<<" | "
            <<dataProduk[i].nama<<" | "
            <<dataProduk[i].harga<<" | "
            <<dataProduk[i].kategori<<" | "
            <<dataProduk[i].stok<<endl;
        }
    }


void bubble()
    {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(dataProduk[j].nama,dataProduk[j+1].nama)>0)
            {
                produk temp = dataProduk[j];
                dataProduk[j] = dataProduk[j+1];
                dataProduk[j+1] = temp;
            }
            }
            }
     }


int partisi(int low,int high)
    {
    float pivot = dataProduk[high].harga;
    int i = low-1;

    for(int j=low;j<high;j++)
       {
        if(dataProduk[j].harga > pivot)
        {
            i++;
            produk temp = dataProduk[i];
            dataProduk[i] = dataProduk[j];
            dataProduk[j] = temp;
        }
       }

    produk temp = dataProduk[i+1];
    dataProduk[i+1] = dataProduk[high];
    dataProduk[high] = temp;

    return i+1;
    }

void quick(int low,int high)
    {
    if(low<high) 
        {
        int p = partisi(low,high);
        quick(low,p-1);
        quick(p+1,high);
        }
   }


void seq()
    {
    if(n == 0){
        cout<<"Data kosong!\n";
        return;
    }

    cin.ignore();

    char cari[50];
    cout<<"Cari nama: ";
    cin.getline(cari,50);

    bool ketemu=false;

    for(int i=0;i<n;i++)
       {
        if(strcmp(dataProduk[i].nama,cari)==0) 
           {
            cout<<"\nData ditemukan:\n";
            cout<<"Nama: "<<dataProduk[i].nama<<endl;
            cout<<"Harga: "<<dataProduk[i].harga<<endl;
            cout<<"Kategori: "<<dataProduk[i].kategori<<endl;
            cout<<"Stok: "<<dataProduk[i].stok<<endl;
            ketemu=true;
            break;
           }
      }

    if(!ketemu){
        cout<<"Produk tidak ditemukan!\n";
    }
}


void binary()
     {
    if(n == 0){
        cout<<"Data kosong!\n";
        return;
    }

    cin.ignore();

    char cari[50];
    cout<<"Cari nama: ";
    cin.getline(cari,50);

    bubble(); 

    int l=0,r=n-1;
    bool ketemu=false;

    while(l<=r)
      {
        int mid=(l+r)/2;
        int cmp = strcmp(dataProduk[mid].nama,cari);

        if(cmp==0){
            cout<<"\nData ditemukan:\n";
            cout<<"Nama: "<<dataProduk[mid].nama<<endl;
            cout<<"Harga: "<<dataProduk[mid].harga<<endl;
            cout<<"Kategori: "<<dataProduk[mid].kategori<<endl;
            cout<<"Stok: "<<dataProduk[mid].stok<<endl;
            ketemu=true;
            break;
        }else if(cmp<0){
            l=mid+1;
        }else{
            r=mid-1;
        }
      }

    if(!ketemu){
        cout<<"Produk tidak ditemukan!\n";
     }
    }


int main()
    {
    load();
    int pilih, sub;

    do{
        cout<<"\n=== MENU ===\n";
        cout<<"1. Tambah Produk\n";
        cout<<"2. Urutkan Produk\n";
        cout<<"3. Cari Produk\n";
        cout<<"4. Tampilkan Data\n";
        cout<<"5. Keluar\n";
        cout<<"Pilih: ";
        cin>>pilih;

        switch(pilih)
        {

            case 1: 
                tambah(); 
                break;

            case 2: 
                cout<<"\n=== MENU SORT ===\n";
                cout<<"1. Nama Produk (Ascending - Bubble)\n";
                cout<<"2. Harga Produk (Descending - Quick)\n";
                cout<<"Pilih: ";
                cin>>sub;

                if(sub == 1){
                    bubble();
                    tampil();
                }else if(sub == 2){
                    quick(0,n-1);
                    tampil();
                }else{
                    cout<<"Pilihan tidak valid!\n";
                }
                break;

            case 3: 
                cout<<"\n=== MENU CARI ===\n";
                cout<<"1. Sequential Search\n";
                cout<<"2. Binary Search\n";
                cout<<"Pilih: ";
                cin>>sub;

                if(sub == 1){
                    seq();
                }else if(sub == 2){
                    binary();
                }else{
                    cout<<"Pilihan tidak valid!\n";
                }
                break;

            case 4: 
                tampil(); 
                break;

            case 5: 
                cout<<"Program selesai\n"; 
                break;

            default: 
                cout<<"Pilihan tidak valid!\n";
        }

    }while(pilih!=5);

    return 0;
}
