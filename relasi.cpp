#include "relasi.h"

address_r alokasi_r(address_p x, address_c y){
    address_r P;
    P = new elmlist_r;
    next(P) = NULL;
    parent(P) = x;
    child(P) = y;
    return P;
}

void dealokasi_r(address_r P){
    delete P;
}

address_r findElm_rp(List_r L, address_p x){
    if (first(L)==NULL){
        return NULL;
    }
    else{
        address_r P;
        P = first(L);
        while ((parent(P)!=x) && (next(P)!=NULL)) {
            P = next(P);
        }
        if (parent(P)==x){
            return P;
        }
        else{
            return NULL;
        }
    }
}

address_r findElm_rc(List_r L, address_c x){
    if (first(L)==NULL){
        return NULL;
    }
    else{
        address_r P;
        P = first(L);
        while ((child(P)!=x) && (next(P)!=NULL)) {
            P = next(P);
        }
        if (child(P)==x){
            return P;
        }
        else{
            return NULL;
        }
    }
}

void create_list_r(List_r &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insert_last_r(List_r &L, address_r P){
    if (first(L)==NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        last(L) = P;
    }
}

address_r find_before_r(List_r L, address_r P){
    if (P==NULL){
        return NULL;
    }
    else{
        address_r Prec,Q;
        Q = first(L);
        Prec = NULL;
        while (Q!=P){
            Prec = Q;
            Q = next(Q);
        }
        return Prec;
    }
}

void delete_elemen_r(List_r &L, address_r &P){
    address_r Prec;
    if (P == first(L)){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
    else if (P == last(L)){
        Prec = find_before_r(L,P);
        next(Prec) = NULL;
        last(L) = Prec;
    }
    else{
        Prec = find_before_r(L,P);
        next(Prec) = next(P);
        next(P) = NULL;
    }
    dealokasi_r(P);
}
