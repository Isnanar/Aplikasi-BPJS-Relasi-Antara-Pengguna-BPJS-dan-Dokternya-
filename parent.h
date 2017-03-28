#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define next(P) P->next
#define parent(P) P->parent
#define child(P) P->child
#define info(P) P->info
#define first(L) (L).first
#define last(L) (L).last

struct infotype_p{
    long id;
    string nama,rs;
    int jum;
};

typedef struct elmlist_p *address_p;

struct elmlist_p {
    address_p next;
    infotype_p info;
};

struct List_p{
    address_p first,last;
};

address_p alokasi_p(infotype_p x);
void dealokasi_p(address_p &P);
void create_list_p(List_p &L);
void insert_info_p(infotype_p &x);
void show_info_p(List_p L);
address_p find_elemen_p(List_p L, infotype_p x);
address_p find_before_p(List_p L, address_p P);
void insert_last_p(List_p &L, address_p P);
void delete_elemen_p(List_p &L, address_p P);
void sort_list_p(List_p &L);

#endif // PARENT_H_INCLUDED
