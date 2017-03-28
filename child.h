#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include "parent.h"

struct infotype_c{
    long nik;
    string nama,alamat,dokter;
    int kelas;
};

typedef struct elmlist_c *address_c;

struct elmlist_c {
    address_c next;
    infotype_c info;
};

struct List_c{
    address_c first,last;
};

address_c alokasi_c(infotype_c x);
void dealokasi_c(address_c &P);
void create_list_c(List_c &L);
void insert_info_c(infotype_c &x);
void show_info_c(List_c L);
address_c find_elemen_c(List_c L, infotype_c x);
address_c find_before_c(List_c L, address_c P);
void insert_last_c(List_c &L, address_c P);
void delete_elemen_c(List_c &L, address_c P);
void sort_list_c(List_c &L);

#endif // CHILD_H_INCLUDED
