#ifndef PENUMPANG_H
#define PENUMPANG_H

#define MAX 100

typedef struct {
    int id;
    char nama[50];
    int umur;
    int rute_id;
} Penumpang;

extern Penumpang penumpang[MAX];  // Deklarasi variabel global
extern int jumlahPenumpang;       // Deklarasi variabel global

void tambahPenumpang();
void tampilPenumpang();

#endif
