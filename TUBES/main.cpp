#include <iostream>
#include "doublelinklist.h"
#include "relasi.h"
#include <windows.h>
using namespace std;
int besar = 0;
int kecil = 0;

address getInput() {
    cout<<"+++++++++++++++++++++++++++++++"<<endl;
    infotype x;
    cout << "Masukkan Nama : ";
    cin >> x.nama;
    x.jumlah =0;
    cout<<"+++++++++++++++++++++++++++++++"<<endl;
    cout<<endl;
    return alokasi(x);
}

void viewmanajerkaryawan(List L,listR L3){
    addressR Q;
    address P;
    P = first(L);
    while(P != NULL){
        Q = first(L3);
        cout<<info(P).nama<<" : ";
        while(Q != NULL){
            if(P == manajer(Q)){
                cout<<info(karyawan(Q)).nama<<" , ";
            }
            Q = next(Q);
        }
        P = next(P);
        cout<<endl;
    }
}

void viewmanajerkaryawantertentu(List L2,listR L3){
    address P;
    addressR Q;
    string nama;
    cout<<"Masukan nama karyawan: "<<endl;
    cin>>nama;
    P = findElm(L2,nama);
    if(P != NULL){
        Q = first(L3);
        cout<<"Manajernya "<<endl;
        while(Q != NULL){
            if(P == karyawan(Q)){
                cout<<info(manajer(Q)).nama<<" , ";
            }
            Q = next(Q);
        }
    }else{
        cout<<"Nama tidak ditemukan.";
    }
}

void hapusrelasikaryawan(listR &L3,address x){
addressR y,temp,prev;
y = first(L3);
while(y != NULL){
    prev = y;
    y = next(y);
    if(x == karyawan(prev)){

        if(prev == first(L3)){
            deleteFirst(L3,temp);
        }else if(prev == last(L3)){
            deleteLast(L3,temp);
        }else{
            deleteAfter(L3,prev(y),temp);
        }
    }
}
}

void hapusrelasimanajer(listR &L3,address x){
addressR y,temp,prev;
y = first(L3);
while(y != NULL){
    prev = y;
    y = next(y);
    if(x == manajer(prev)){

        if(prev == first(L3)){
            deleteFirst(L3,temp);
        }else if(prev == last(L3)){
            deleteLast(L3,temp);
        }else{
            deleteAfter(L3,prev(y),temp);
        }
    }
}
}

void terbanyak(List L,List L2,listR L3){
cout<<"Terbanyak:"<<endl;
                if(first(L) != NULL) {
                address P = first(L);
                address Z = next(first(L));
                address G = first(L);

                while(P != NULL && Z != NULL) {
                if(info(P).jumlah > info(Z).jumlah){
                    besar = info(P).jumlah;
                }
                P = next(P);
                Z = next(Z);
                }

                while (G != NULL && info(G).jumlah != besar){
                    G = next(G);
                }
                if(info(G).jumlah = besar){
                cout <<info(G).nama<<endl;
                }

                cout<<"Karyawan nya: "<<endl;
                addressR N;
                N = first(L3);
                while(N != NULL){
                    if(manajer(N) == G){
                        cout<<info(karyawan(N)).nama<<" , ";
                    }
                    N = next(N);
                }
        } else {
        cout << "List Kosong" << endl;
    }
                cout<<endl;
}

void tersedikit(List L,List L2,listR L3){
cout<<"Paling Sedikit:"<<endl;
                if(first(L) != NULL) {
                address P = first(L);
                address Z = next(first(L));
                address G = first(L);

                while(P != NULL && Z != NULL) {
                if(info(Z).jumlah < info(P).jumlah){
                    kecil = info(Z).jumlah;
                }
                P = next(P);
                Z = next(Z);
                }

                while (G != NULL && info(G).jumlah != kecil){
                    G = next(G);
                }
                if(info(G).jumlah = kecil){
                cout <<info(G).nama<<endl;
                }

                cout<<"Karyawan nya: "<<endl;
                addressR J;
                J = first(L3);
                while(J != NULL){
                    if(manajer(J) == G){
                        cout<<info(karyawan(J)).nama<<" , ";
                    }
                    J = next(J);
                }
        } else {
        cout << "List Kosong" << endl;
    }
                cout<<endl;

}

void mainMenu(List L,List L2,listR L3) {
    address P, Q,m,k;
    infotype dicari;
    string y;
    string nmanajer;
    string nkaryawan;
    string temp;
    cout<<"============================================="<<endl;
    cout<<"               Main Menu"<<endl;
    cout<<"============================================="<<endl;
    int pil;

        cout << "1.  Manajer" << endl;
        cout << "2.  Karyawan" << endl;
        cout << "3.  Relasi" << endl;
        cout << "0.  Exit" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pil;
        cout << endl;
        switch(pil) {
        case 1 :

            int pilmanajer;
            do {
            system("cls");
             cout<<"============================================="<<endl;
            cout<<"               Menu Manajer"<<endl;
            cout<<"============================================="<<endl;
            cout << "1. Tambah Manajer" << endl;
            cout << "2. Delete Manajer" << endl;
            cout << "3. View Manajer" << endl;
            cout << "0. Menu Utama" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilmanajer;
            cout << endl;
            switch(pilmanajer) {
                case 1 :
                system("cls");
                P = getInput();
                insertLast(L, P);
                cout << "Berhasil ditambahkan ..." << endl;
                cout<<endl;
                system("pause");
                //system("cls");
                //mainMenu(L,L2,L3);
                break;
                case 2 :
                system("cls");
                cout << "Delete Data Manajer" << endl;
                printInfo(L);
                cout<<endl;
                cout<<"Masukan Nama yang ingin dihapus: "<<endl;
                cin>>y;
                hapus(L,y);
                cout << "Terhapus..." << endl;
                system("pause");
                break;
                case 3 :
                system("cls");
                cout << "Data Manajer" << endl;
                printInfo(L);
                cout<<endl;
                system("pause");
                break;
                case 0 :
                system("cls");
                mainMenu(L,L2,L3);
                break;
                default :
                cout << "Invalid Input!" << endl;
                break;
            }
            cout << endl;
        }    while(pilmanajer != 0);
            break;
        case 2 :

            int pilkaryawan;
            do {
            system("cls");
             cout<<"============================================="<<endl;
            cout<<"               Menu Karyawan"<<endl;
            cout<<"============================================="<<endl;
            cout << "1. Tambah Karyawan" << endl;
            cout << "2. Delete Karyawan" << endl;
            cout << "3. View Karyawan" << endl;
            cout << "0. Menu Utama" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilkaryawan;
            cout << endl;
            switch(pilkaryawan) {
                case 1 :
                system("cls");
                P = getInput();
                insertLast(L2, P);
                cout << "Berhasil ditambahkan ..." << endl;
                cout<<endl;
                system("pause");
                break;
                case 2 :
                system("cls");
                cout << "Delete Data Karyawan" << endl;
                printInfo(L2);
                cout<<endl;
                cout<<"Masukan Nama yang ingin dihapus: "<<endl;
                cin>>y;
                hapus(L2,y);
                cout << "Terhapus..." << endl;
                system("pause");
                break;
                case 3 :
                system("cls");
                cout << "Data Karyawan" << endl;
                printInfo(L2);
                cout<<endl;
                system("pause");
                break;
                case 0 :
                system("cls");
                mainMenu(L,L2,L3);
                break;
                default :
                cout << "Invalid Input!" << endl;
                break;
            }
            cout << endl;
        }    while(pilkaryawan != 0);
            break;

        case 3 :

            int pilrelasi;
            do {
            system("cls");
             cout<<"============================================="<<endl;
            cout<<"               Menu Relasi"<<endl;
            cout<<"============================================="<<endl;
            cout << "1. Hubungkan Karyawan dengan Manajer" << endl;
            cout << "2. Delete Karyawan dan Relasinya" << endl;
            cout << "3. Delete Manajer dan Relasinya" << endl;
            cout << "4. View Semua Hubungan Manajer & Karyawan" << endl;
            cout << "5. View Hubungan Karyawan Tertentu" << endl;
            cout << "6. Manajer dengan karyawan terbanyak" << endl;
            cout << "7. Manajer dengan karyawan paling sedikit" << endl;
            cout << "0. Menu Utama" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilrelasi;
            cout << endl;
            switch(pilrelasi) {
                case 1 :
                system("cls");
                cout<<"Nama Manajer:"<<endl;
                printInfo(L);
                cout<<endl;
                cout<<"Nama Karyawan: "<<endl;
                printInfo(L2);
                cout<<endl;
                cout<<"Nama Manajer: "<<endl;
                cin>>nmanajer;
                cout<<"Nama Karyawan: "<<endl;
                cin>>nkaryawan;
                m = findElm(L,nmanajer);
                k = findElm(L2,nkaryawan);
                hubung(L3,m,k);
                system("pause");
                break;
                case 2 :
                system("cls");
                cout << "Delete Data Karyawan dan Relasinya" << endl;
                printInfo(L2);
                cout<<endl;
                cout<<"Masukan nama yang ingin dihapus: "<<endl;
                cin>>y;
                hapusrelasikaryawan(L3,findElm(L2,y));
                hapus(L2,y);
                cout << "Terhapus..." << endl;
                system("pause");
                break;
                case 3 :
                system("cls");
                cout << "Delete Data Manajer dan Relasinya" << endl;
                printInfo(L);
                cout<<endl;
                cout<<"Masukan nama yang ingin dihapus: "<<endl;
                cin>>y;
                hapusrelasimanajer(L3,findElm(L,y));
                hapus(L,y);
                cout << "Terhapus..." << endl;
                system("pause");
                break;
                case 4 :
                system("cls");
                cout<<"Nama Manajer:"<<endl;
                viewmanajerkaryawan(L,L3);
                cout<<endl;
                system("pause");
                break;
                case 5 :
                system("cls");
                cout<<"Data Karyawan "<<endl;
                printInfo(L2);
                cout<<endl;
                viewmanajerkaryawantertentu(L2,L3);
                cout<<endl;
                cout<<endl;
                system("pause");
                break;
                case 6 :
                system("cls");
                terbanyak(L,L2,L3);
                system("pause");
                break;
                case 7 :
                system("cls");
                tersedikit(L,L2,L3);
                system("pause");
                break;
                case 0 :
                system("cls");
                mainMenu(L,L2,L3);
                break;
                default :
                cout << "Invalid Input!" << endl;
                break;
            }
            cout << endl;
        }    while(pilrelasi != 0);
            break;
        case 0 :
            break;
        default :
            cout << "Invalid Input!" << endl;
            break;
        }
        cout << endl;
    };

/*              cout<<"Nama Manajer:"<<endl;
                printInfo(L);
                cout<<endl;
                cout<<"Nama Karyawan: "<<endl;
                printInfo(L2);
                cout<<endl;
                cout<<"Nama Manajer: "<<endl;
                cin>>nmanajer;
                cout<<"Nama Karyawan: "<<endl;
                cin>>nkaryawan;
                address m = findElm(L,nmanajer);
                address k = findElm(L2,nkaryawan);
                hubung(L3,m,k);
                cout<<first(L3);
                cout<<"============================================="<<endl;
                cout<<"               1. Main Menu"<<endl;
                cout<<"============================================="<<endl;
                cout<<"Masukan Pilihan: ";
            int penghubung;
            cin>>penghubung;
            switch(penghubung) {
            case 1 :
                system("cls");
                mainMenu(L,L2,L3);
                break;
            }
            break;*/


int main()
{
    List L;
    List L2;
    listR L3;
    createList(L);
    createList(L2);
    createList(L3);

    infotype x;
    x.nama = "Maiza";
    x.jumlah = 0;
    insertLast(L,alokasi(x));
    x.nama = "Dita";
    x.jumlah = 0;
    insertLast(L,alokasi(x));
    x.nama = "Lintang";
    x.jumlah = 0;
    insertLast(L,alokasi(x));
    x.nama = "Yogi";
    x.jumlah = 0;
    insertLast(L2,alokasi(x));
    x.nama = "Krisna";
    x.jumlah = 0;
    insertLast(L2,alokasi(x));
    x.nama = "Nopal";
    x.jumlah = 0;
    insertLast(L2,alokasi(x));

    mainMenu(L,L2,L3);

    return 0;
}
