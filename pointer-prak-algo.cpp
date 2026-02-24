#include <iostream>              
using namespace std;             

int main() {

    int A[3] = {1, 5, 10};        
    int *ptr = A;                

    int panjang = 3;             

    cout << "Isi array: ";
    for(int i = 0; i < panjang; i++) {    
        cout << *(ptr + i) << " ";         
    }

    int max = *ptr;              
    int min = *ptr;              
    int jumlah = 0;              

     for(int i = 0; i < panjang; i++) {     

        if(*(ptr + i) > max) {             
            max = *(ptr + i);              
        }

        if(*(ptr + i) < min) {             
            min = *(ptr + i);              
        }

        jumlah += *(ptr + i);              
    }

    float rata = (float)jumlah / panjang;  

    
    cout << "\nNilai maksimum : " << max << endl;
    cout << "Nilai minimum  : " << min << endl;
    cout << "Jumlah         : " << jumlah << endl;
    cout << "Rata-rata      : " << rata << endl;

    return 0;                  
}
