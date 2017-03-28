#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "child.h"

typedef struct elmlist_r *address_r;

struct elmlist_r {
    address_r next;
    address_p parent;
    address_c child;
};

struct List_r{
    address_r first,last;
};

address_r alokasi_r(address_p x, address_c y);
void dealokasi_r(address_r P);
address_r find_before_r(List_r L, address_r P);
address_r findElm_rp(List_r L, address_p x);
address_r findElm_rc(List_r L, address_c x);
void create_list_r(List_r &L);
void insert_last_r(List_r &L, address_r P);
void delete_elemen_r(List_r &L, address_r &P);

#endif // RELASI_H_INCLUDED
