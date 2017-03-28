#include "child.h"

address_c alokasi_c(infotype_c x){
    address_c P;
    P = new elmlist_c;
    next(P) = NULL;
    info(P) = x;
    return P;
}

void dealokasi_c(address_c &P){
    delete P;
}

void create_list_c(List_c &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insert_info_c(infotype_c &x){
    cout << endl;
    cout << "\tNIK          : "; cin >> x.nik;
    cout << "\tNama         : "; cin >> x.nama;
    cout << "\tAlamat       : "; cin >> x.alamat;
    x.kelas = 0;
    x.dokter = "Belum Terdaftar";
    cout << endl;
    cout << "\tData Telah Terinput";
    getch();
}

void show_info_c(List_c L){
    if (first(L)==NULL){
        cout << endl;
        cout << "\tData Kosong";
        getch();
    }
    else {
        address_c P;
        P = first(L);
        while (P!=NULL){
            cout << endl;
            cout << "\tNIK          : " << info(P).nik << endl;
            cout << "\tNama         : " << info(P).nama << endl;
            cout << "\tAlamat       : " << info(P).alamat << endl;
            cout << "\tKelas        : ";
            if (info(P).kelas==0){
                cout << "Belum Terdaftar" << endl;
            }
            else{
                cout << info(P).kelas << endl;
            }
            cout << "\tDokter       : " << info(P).dokter << endl;
            getch();
            P = next(P);
        }
    }
}

address_c find_elemen_c(List_c L, infotype_c x){
    if (first(L)==NULL){
        return NULL;
    }
    else{
        address_c P;
        P = first(L);
        while ((x.nik!=info(P).nik) && (next(P)!=NULL)) {
            P = next(P);
        }
        if (x.nik==info(P).nik){
            return P;
        }
        else{
            return NULL;
        }
    }
}

address_c find_before_c(List_c L, address_c P){
    if (P==NULL){
        return NULL;
    }
    else{
        address_c Prec,Q;
        Q = first(L);
        Prec = NULL;
        while (Q!=P){
            Prec = Q;
            Q = next(Q);
        }
        return Prec;
    }
}

void insert_last_c(List_c &L, address_c P){
    if (first(L)==NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void delete_elemen_c(List_c &L, address_c P){
    address_c Prec;
    if (P == first(L)){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
    else if (P == last(L)){
        Prec = find_before_c(L,P);
        next(Prec) = NULL;
        last(L) = Prec;
    }
    else{
        Prec = find_before_c(L,P);
        next(Prec) = next(P);
        next(P) = NULL;
    }
    dealokasi_c(P);
}

void sort_list_c(List_c &L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address_c P,Q,Min,After,Prec,Prec2;
        P = first(L);
        while (P!=last(L)){
            Min = P;
            Q = next(P);
            while (Q!=NULL){
                if (info(Min).nik > info(Q).nik){
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
                    Prec = find_before_c(L,Min);
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
                    Prec = find_before_c(L,P);
                    next(Prec) = Min;
                    next(Min) = P;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Min)){
                    Prec = find_before_c(L,Min);
                    After = next(P);
                    next(P) = next(Min);
                    next(Prec) = P;
                    next(Min) = After;
                    first(L) = Min;
                    P = After;

                }
                else if ((next(P)!=Min)&&(last(L)==Min)){
                    Prec = find_before_c(L,P);
                    Prec2 = find_before_c(L,Min);
                    After = next(P);
                    next(Min) = After;
                    next(Prec) = Min;
                    next(Prec2) = P;
                    next(P) = NULL;
                    last(L) = P;
                    P = After;
                }
                else if (next(P)==Min){
                    Prec = find_before_c(L,P);
                    next(P) = next(Min);
                    next(Prec) = Min;
                    next(Min) = P;
                }
                else {
                    Prec = find_before_c(L,P);
                    Prec2 = find_before_c(L,Min);
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
