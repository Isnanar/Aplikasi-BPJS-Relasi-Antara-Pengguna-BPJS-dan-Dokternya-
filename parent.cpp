#include "parent.h"

address_p alokasi_p(infotype_p x){
    address_p P;
    P = new elmlist_p;
    next(P) = NULL;
    info(P) = x;
    return P;
}

void dealokasi_p(address_p &P){
    delete P;
}

void create_list_p(List_p &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insert_info_p(infotype_p &x){
    cout << endl;
    cout << "\tID           : "; cin >> x.id;
    cout << "\tNama         : "; cin >> x.nama;
    cout << "\tRumah Sakit  : "; cin >> x.rs;
    cout << endl;
    cout << "\tData Telah Terinput";
    x.jum = 0;
    getch();
}

void show_info_p(List_p L){
    if (first(L)==NULL){
        cout << endl;
        cout << "\tData Kosong";
        getch();
    }
    else {
        address_p P;
        P = first(L);
        while (P!=NULL){
            cout << endl;
            cout << "\tID             : " << info(P).id << endl;
            cout << "\tNama           : " << info(P).nama << endl;
            cout << "\tRumah Sakit    : " << info(P).rs << endl;
            cout << "\tJumlah Pasien  : " << info(P).jum << endl;
            getch();
            P = next(P);
        }
    }
}

address_p find_elemen_p(List_p L, infotype_p x){
    if (first(L)==NULL){
        return NULL;
    }
    else{
        address_p P;
        P = first(L);
        while ((x.id!=info(P).id) && (next(P)!=NULL)) {
            P = next(P);
        }
        if (x.id==info(P).id){
            return P;
        }
        else{
            return NULL;
        }
    }
}

address_p find_before_p(List_p L, address_p P){
    if (P==NULL){
        return NULL;
    }
    else{
        address_p Prec,Q;
        Q = first(L);
        Prec = NULL;
        while (Q!=P){
            Prec = Q;
            Q = next(Q);
        }
        return Prec;
    }
}

void insert_last_p(List_p &L, address_p P){
    if (first(L)==NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void delete_elemen_p(List_p &L, address_p P){
    address_p Prec;
    if (P == first(L)){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
    else if (P == last(L)){
        Prec = find_before_p(L,P);
        next(Prec) = NULL;
        last(L) = Prec;
    }
    else{
        Prec = find_before_p(L,P);
        next(Prec) = next(P);
        next(P) = NULL;
    }
    dealokasi_p(P);
}

void sort_list_p(List_p &L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address_p P,Q,Min,After,Prec,Prec2;
        P = first(L);
        while (P!=last(L)){
            Min = P;
            Q = next(P);
            while (Q!=NULL){
                if (info(Min).id > info(Q).id){
                    Min = Q;
                }
                Q = next(Q);
            }

            if (P!=Min){
                if (next(first(L))==last(L)){
                    next(Min) = P;
                    next(P) = NULL;
                    first(L) = Min;
                    last(L) = P;
                }
                else if ((first(L)==P)&&(last(L)==Min)){
                    Prec = find_before_p(L,Min);
                    After = next(P);
                    next(Min) = next(P);
                    next(Prec) = P;
                    next(P) = NULL;
                    first(L) = Min;
                    last(L) = P;
                    P = After;
                }
                else if ((P==first(L))&&(next(P)==Min)){
                    next(P) = next(Min);
                    next(Min) = P;
                    first(L) = Min;
                }
                else if ((next(P)==Min)&&(Min==last(L))){
                    Prec = find_before_p(L,P);
                    next(Prec) = Min;
                    next(Min) = P;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Min)){
                    Prec = find_before_p(L,Min);
                    After = next(P);
                    next(P) = next(Min);
                    next(Prec) = P;
                    next(Min) = After;
                    first(L) = Min;
                    P = After;

                }
                else if ((next(P)!=Min)&&(last(L)==Min)){
                    Prec = find_before_p(L,P);
                    Prec2 = find_before_p(L,Min);
                    After = next(P);
                    next(Min) = After;
                    next(Prec) = Min;
                    next(Prec2) = P;
                    next(P) = NULL;
                    last(L) = P;
                    P = After;
                }
                else if (next(P)==Min){
                    Prec = find_before_p(L,P);
                    next(P) = next(Min);
                    next(Prec) = Min;
                    next(Min) = P;
                }
                else {
                    Prec = find_before_p(L,P);
                    Prec2 = find_before_p(L,Min);
                    After = next(P);
                    next(P) = next(Min);
                    next(Prec2) = P;
                    next(Prec) = Min;
                    next(Min) = After;
                    P = After;
                }
            }
            else{
                P = next(P);
            }
        }
    }
}
