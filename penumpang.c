#include <stdio.h>
#include <stdlib.h>
#include "penumpang.h"
#include "queue.h"

Penumpang penumpang[MAX];
int jumlahPenumpang = 0;

void tambahPenumpang() {
    Penumpang p;
    printf("Masukkan ID Penumpang: ");
    scanf("%d", &p.id);
    printf("Masukkan Nama Penumpang: ");
    scanf("%s", p.nama);
    printf("Masukkan Umur: ");
    scanf("%d", &p.umur);
    printf("Masukkan ID Rute: ");
    scanf("%d", &p.rute_id);
    penumpang[jumlahPenumpang++] = p;
    enqueue(p.id); // Tambahkan ke antrian
    printf("Data penumpang berhasil ditambahkan!\n");
}

void tampilPenumpang() {
    printf("\t\t Data Penumpang:\n");
    printf("\t\t ------------------------------------------\n");
    printf("\t\t |  ID  |      NAMA      | UMUR | ID RUTE |\n");
    printf("\t\t ------------------------------------------\n");
    for (int i = 0; i < jumlahPenumpang; i++) {
        printf("\t\t | %-4d | %-14s | %-4d | %-7d |\n",
               penumpang[i].id, penumpang[i].nama, penumpang[i].umur, penumpang[i].rute_id);
    }
    printf("\t\t ------------------------------------------\n");
}
