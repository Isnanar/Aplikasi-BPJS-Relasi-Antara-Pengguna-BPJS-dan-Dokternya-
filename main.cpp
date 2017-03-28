#include "parent.h"
#include "child.h"
#include "relasi.h"

void header(){
    system("cls");
    cout << "\t\t            SELAMAT DATANG DI" << endl;
    cout << "\t\tAPLIKASI BADAN PENYELENGGARA JAMINAN SOSIAL" << endl << endl;
}

int main()
{
    List_p LP;
    List_c LC;
    List_r LR;
    address_p P;
    address_c C;
    address_r R;
    infotype_p x;
    infotype_c y;
    char pil1,pil2;

    create_list_p(LP);
    create_list_c(LC);
    create_list_r(LR);

    do{
        header();
        cout << "\t(1) Data Dokter" << endl;
        cout << "\t(2) Data Calon Pengguna BPJS" << endl;
        cout << "\t(3) Data BPJS" << endl;
        cout << "\t(0) Exit" << endl;
        cout << endl;
        cout << "\tPilihan : "; cin >> pil1;

        switch (pil1) {
            case '1' :
                do{
                    header();
                    cout << "\tData Dokter" << endl << endl;
                    cout << "\t(1) Input";
                    cout << "\t(2) Show";
                    cout << "\t(3) Search" << endl;
                    cout << "\t(4) Edit";
                    cout << "\t(5) Delete";
                    cout << "\t(6) Sort" << endl;
                    cout << "\t(0) Back" << endl;
                    cout << endl;
                    cout << "\tPilihan : "; cin >> pil2;
                    switch (pil2) {
                        case '1' :
                            insert_info_p(x);
                            P = alokasi_p(x);
                            insert_last_p(LP,P);
                            break;
                        case '2' :
                            show_info_p(LP);
                            break;
                        case '3' :
                            cout << endl << "\tMasukkan ID : "; cin >> x.id;
                            P = find_elemen_p(LP,x);
                            if (P==NULL){
                                cout << endl << "\tID Tidak Ditemukan";
                                getch();
                            }
                            else {
                                cout << endl;
                                cout << "\tID             : " << info(P).id << endl;
                                cout << "\tNama           : " << info(P).nama << endl;
                                cout << "\tRumah Sakit    : " << info(P).rs << endl;
                                cout << "\tJumlah Pasien  : " << info(P).jum << endl;
                                getch();
                            }
                            break;
                        case '4' :
                            cout << endl << "\tMasukkan ID : "; cin >> x.id;
                            P = find_elemen_p(LP,x);
                            if (P==NULL){
                                cout << endl << "\tID Tidak Ditemukan";
                                getch();
                            }
                            else {
                                cout << endl;
                                cout << "\tID             : "; cin >> info(P).id;
                                cout << "\tNama           : "; cin >> info(P).nama;
                                cout << "\tRumah Sakit    : "; cin >> info(P).rs;
                                cout << endl;
                                cout << "\tData Telah Diubah";
                                getch();
                            }
                            break;
                        case '5' :
                            cout << endl << "\tMasukkan ID : "; cin >> x.id;
                            P = find_elemen_p(LP,x);
                            if (P==NULL){
                                cout << endl << "\tID Tidak Ditemukan";
                                getch();
                            }
                            else {
                                R = findElm_rp(LR,P);
                                while (R!=NULL){
                                    info(child(R)).kelas = 0;
                                    info(child(R)).dokter = "Belum Terdaftar";
                                    delete_elemen_r(LR,R);
                                    R = findElm_rp(LR,P);
                                }
                                delete_elemen_p(LP,P);
                                cout << endl;
                                cout << "\tData Telah Dihapus";
                                getch();
                            }
                            break;
                        case '6' :
                            sort_list_p(LP);
                            break;
                        case '0' : break;
                        default : break;
                    }
                }while (pil2!='0');
                break;
            case '2' :
                do{
                    header();
                    cout << "\tData Calon Pengguna BPJS" << endl << endl;
                    cout << "\t(1) Input";
                    cout << "\t(2) Show";
                    cout << "\t(3) Search" << endl;
                    cout << "\t(4) Edit";
                    cout << "\t(5) Delete";
                    cout << "\t(6) Sort" << endl;
                    cout << "\t(0) Back" << endl;
                    cout << endl;
                    cout << "\tPilihan : "; cin >> pil2;
                    switch (pil2) {
                        case '1' :
                            insert_info_c(y);
                            C = alokasi_c(y);
                            insert_last_c(LC,C);
                            break;
                        case '2' :
                            show_info_c(LC);
                            break;
                        case '3' :
                            cout << endl << "\tMasukkan NIK : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else {
                                cout << endl;
                                cout << "\tNIK          : " << info(C).nik << endl;
                                cout << "\tNama         : " << info(C).nama << endl;
                                cout << "\tAlamat       : " << info(C).alamat << endl;
                                cout << "\tKelas        : ";
                                if (info(C).kelas==0){
                                    cout << "Belum Terdaftar" << endl;
                                }
                                else{
                                    cout << info(C).kelas << endl;
                                }
                                cout << "\tDokter       : " << info(C).dokter << endl;
                                getch();
                            }
                            break;
                        case '4' :
                            cout << endl << "\tMasukkan NIK : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else {
                                cout << endl;
                                cout << "\tNIK          : "; cin >> info(C).nik;
                                cout << "\tNama         : "; cin >> info(C).nama;
                                cout << "\tAlamat       : "; cin >> info(C).alamat;
                                cout << endl;
                                cout << "\tData Telah Diubah";
                                getch();
                            }
                            break;
                        case '5' :
                            cout << endl << "\tMasukkan NIK : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else {
                                R = findElm_rc(LR,C);
                                if (R!=NULL){
                                    info(parent(R)).jum = info(parent(R)).jum - 1;
                                    delete_elemen_r(LR,R);
                                }
                                delete_elemen_c(LC,C);
                                cout << endl;
                                cout << "\tData Telah Dihapus";
                                getch();
                            }
                            break;
                        case '6' :
                            sort_list_c(LC);
                            break;
                        case '0' : break;
                        default : break;
                    }
                }while (pil2!='0');
                break;
            case '3' :
                do{
                    header();
                    cout << "\tData BPJS" << endl << endl;
                    cout << "\t(1) Daftar BPJS" << endl;
                    cout << "\t(2) Ganti Kelas BPJS" << endl;
                    cout << "\t(3) Lihat Pengguna BPJS" << endl;
                    cout << "\t(4) Berhenti Berlangganan" << endl;
                    cout << "\t(5) Lihat Dokter Pengguna BPJS" << endl;
                    cout << "\t(6) Lihat Pasien" << endl;
                    cout << "\t(0) Back" << endl;
                    cout << endl;
                    cout << "\tPilihan : "; cin >> pil2;
                    switch (pil2) {
                        case '1' :
                            cout << endl << "\tMasukkan NIK        : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else {
                                cout << "\tMasukkan ID Dokter  : "; cin >> x.id;
                                P = find_elemen_p(LP,x);
                                if (P==NULL){
                                    cout << endl << "\tID Tidak Ditemukan";
                                    getch();
                                }
                                else{
                                    cout << "\tMasukkan Kelas      : "; cin >> info(C).kelas;
                                    R = alokasi_r(P,C);
                                    insert_last_r(LR,R);
                                    info(parent(R)).jum = info(parent(R)).jum + 1;
                                    info(child(R)).dokter = info(parent(R)).nama;
                                    cout << endl;
                                    cout << "\tAnda Telah Terdaftar Sebagai Pengguna BPJS";
                                }
                            }
                            break;
                        case '2' :
                            cout << endl << "\tMasukkan NIK        : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else{
                                R = findElm_rc(LR,C);
                                if (R==NULL){
                                    cout << endl << "\tAnda Tidak Terdaftar Sebagai Pengguna BPJS";
                                    getch();
                                }
                                else{
                                    cout << "\tMasukkan Kelas      : "; cin >> info(C).kelas;
                                    cout << endl;
                                    cout << "\tKelas BPJS Berhasil Diubah";
                                    getch();
                                }
                            }
                            break;
                        case '3' :
                            if (first(LR)==NULL){
                                cout << endl << "\tBelum Ada Pengguna BPJS";
                                getch();
                            }
                            else {
                                R = first(LR);
                                while (R!=NULL){
                                    cout << endl;
                                    cout << "\tNIK          : " << info(child(R)).nik << endl;
                                    cout << "\tNama         : " << info(child(R)).nama << endl;
                                    cout << "\tAlamat       : " << info(child(R)).alamat << endl;
                                    cout << "\tKelas        : " << info(child(R)).kelas << endl;
                                    cout << "\tDokter       : " << info(child(R)).dokter << endl;
                                    getch();
                                    R = next(R);
                                }
                            }
                            break;
                        case '4' :
                            cout << endl << "\tMasukkan NIK        : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else{
                                R = findElm_rc(LR,C);
                                if (R==NULL){
                                    cout << endl << "\tAnda Tidak Terdaftar Sebagai Pengguna BPJS";
                                    getch();
                                }
                                else {
                                    info(parent(R)).jum = info(parent(R)).jum - 1;
                                    info(child(R)).kelas = 0;
                                    info(child(R)).dokter = "Belum Terdaftar";
                                    delete_elemen_r(LR,R);
                                    cout << endl << "\tAnda Telah Berhenti Menggunakan BPJS";
                                    getch();
                                }
                            }
                            break;
                        case '5' :
                            cout << endl << "\tMasukkan NIK        : "; cin >> y.nik;
                            C = find_elemen_c(LC,y);
                            if (C==NULL){
                                cout << endl << "\tNIK Tidak Ditemukan";
                                getch();
                            }
                            else{
                                R = findElm_rc(LR,C);
                                if (R==NULL){
                                    cout << endl << "\tAnda Tidak Terdaftar Sebagai Pengguna BPJS";
                                    getch();
                                }
                                else{
                                    cout << endl;
                                    cout << "\tID             : " << info(parent(R)).id << endl;
                                    cout << "\tNama           : " << info(parent(R)).nama << endl;
                                    cout << "\tRumah Sakit    : " << info(parent(R)).rs << endl;
                                    cout << "\tJumlah Pasien  : " << info(parent(R)).jum << endl;
                                    getch();
                                }
                            }
                            break;
                        case '6' :
                            cout << endl << "\tMasukkan ID Dokter  : "; cin >> x.id;
                            P = find_elemen_p(LP,x);
                            if (P==NULL){
                                cout << endl << "\tID Tidak Ditemukan";
                                getch();
                            }
                            else{
                                if (info(P).jum == 0){
                                    cout << endl << "\tAnda Tidak Memiliki Pasien";
                                    getch();
                                }
                                else{
                                    R = first(LR);
                                    while (R!=NULL){
                                        if (parent(R)==P){
                                            cout << endl;
                                            cout << "\tNIK          : " << info(child(R)).nik << endl;
                                            cout << "\tNama         : " << info(child(R)).nama << endl;
                                            cout << "\tAlamat       : " << info(child(R)).alamat << endl;
                                            cout << "\tKelas        : " << info(child(R)).kelas << endl;
                                            getch();
                                        }
                                        R = next(R);
                                    }
                                }
                            }
                            break;
                        case '0' : break;
                        default : break;
                    }
                }while (pil2!='0');
                break;
            case '0' : break;
            default : break;
        }
    }while (pil1!='0');
    return 0;
}
