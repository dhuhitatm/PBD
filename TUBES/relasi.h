#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define manajer(P) P->manajer
#define karyawan(P) P->karyawan

typedef struct elmListR*addressR;
struct elmListR{
    address manajer;
    address karyawan;
    addressR next;
    addressR prev;
};

struct listR{
    addressR first;
    addressR last;
};
void createList(listR &L);
addressR alokasi(address m,address k);
void hubung(listR &L,address &m,address k);
void insertLast(listR &L, addressR P);
void deleteFirst(listR &L, addressR &P);
void deleteLast(listR &L, addressR &P);
void deleteAfter(listR &L, addressR Prec, addressR &P);


#endif // RELASI_H_INCLUDED
