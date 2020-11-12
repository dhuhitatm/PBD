#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct infotype{
    string nama;
    int jumlah;
};

typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};
bool isEmpty(List L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L2, address P);
void insertLast(List &L, address P);
address findElm(List L, string x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void printInfo(List L2);
void insertAfter(List &L, address Prec, address P);
void deleteAfter(List &L, address Prec, address &P);
void hapus(List &L, string x);

#endif // DOUBLELINKLIST_H_INCLUDED
