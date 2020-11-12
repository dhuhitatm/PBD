#include "doublelinklist.h"
bool isEmpty(List L){
   bool status = true;
   if (first(L) != NULL){
    status = false;

   }
   return status;

}
void createList(List &L) {
    first(L) = NULL;
    last(L) = NULL;

}


address alokasi(infotype x) {
    address P = new elmList;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address &P) {
    next(P) = NULL;
    delete P;
}


void insertFirst(List &L, address P) {
   if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else {
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
}
}

void insertLast(List &L, address P) {
    if (first(L) == NULL){
        insertFirst(L,P);
    }
    else {
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
}
}

address findElm(List L, string x) {
    if(first(L) != NULL) {
        address Q = first(L);
        while((next(Q) != NULL) && (info(Q).nama!= x)) {
            Q = next(Q);
        }
        /* next(Q) == NULL  || info(Q).nim == x.nim*/
        if(info(Q).nama == x) {
            return Q;
        } else {
            /* Not Found */
            return NULL;
        }
    } else {
        /* List Kosong */
        return NULL;
    }
}

void deleteFirst(List &L, address &P) {
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

void deleteLast(List &L, address &P) {
    if(first(L) != NULL) {
      P = last(L);
      last(L) = prev(P);
      next(last(L)) = NULL;
      prev(P) = NULL;


    } else {
        cout << "List Kosong" << endl;
    }
}

void printInfo(List L) {
    if(first(L) != NULL) {
        address P = first(L);
        while(P != NULL) {
            cout << info(P).nama<<",";
            P = next(P);
        }
        cout<<endl;
    } else {
        cout << "List Kosong" << endl;
    }
}
void insertAfter(List &L, address Prec, address P) {
    /* Yang dimasukkan adalah element yang ditunjuk oleh P dan ditaruh didepan element yang ditunjuk oleh Prec */
//    next(P) = next(Prec);
//    next(Prec) = P;
//    prev(P) = Prec;
//    prev(next(P)) = P;
//
//
    next(P) = next(Prec);
    cout<<"D";
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;
}

void deleteAfter(List &L, address Prec, address &P) {
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

void hapus(List &L, string x){
address z = findElm(L,x);
if (z != NULL){
    if(z == first(L)){
        deleteFirst(L,z);
    }else if(z == last(L)){
        deleteLast(L,z);
    }else{
        deleteAfter(L,prev(z),z);
    }
}else{
    cout<<"Nama yang dicari tidak ditemukan.."<<endl;
}
}


