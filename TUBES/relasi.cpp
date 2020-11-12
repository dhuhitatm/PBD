#include "doublelinklist.h"
#include "relasi.h"

void createList(listR &L) {
    first(L) = NULL;
    last(L) = NULL;

}


addressR alokasi(address m,address k) {
    addressR P = new elmListR;
    manajer(P) = m;
    karyawan(P) = k;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLast(listR &L, addressR P) {
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else {
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
}
}

void hubung(listR &L,address &m,address k){

    if(m != NULL && k != NULL){
        info(m).jumlah++;
        addressR manajer = alokasi(m,k);
        insertLast(L,manajer);
    }else{
        cout<<"Nama tidak ada"<<endl;
    }

}

void deleteFirst(listR &L, addressR &P) {
    P = first(L);
    if(next(first(L)) == NULL ) {
        first(L) = NULL;
        last(L) = NULL;
    }else{

        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLast(listR &L, addressR &P) {
    if(first(L) != NULL) {
      P = last(L);
      last(L) = prev(P);
      next(last(L)) = NULL;
      prev(P) = NULL;


    } else {
        cout << "List Kosong" << endl;
    }
}

void deleteAfter(listR &L, addressR Prec, addressR &P) {
    /* Menghapus Element(ditunjuk oleh P) yang berada didepan Element yang ditunjuk Prec  */
    if(next(Prec) != NULL)  {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        //dealokasi(P);

    } else {
        /* Mendelete Element setelah Element terakhir, impossible */
        cout << "Tidak ada Element yang bisa dihapus" << endl;
    }
}

