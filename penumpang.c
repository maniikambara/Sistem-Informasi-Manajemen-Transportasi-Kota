#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "penumpang.h"
#include "queue.h"
#include "rute.h"

extern int jumlahRute; // Declare extern variable
extern Rute rute[MAX]; // Declare extern variable

Penumpang penumpang[MAX];
int jumlahPenumpang = 0;

void hapusPenumpang(int id) {
    for (int i = 0; i < jumlahPenumpang; i++) {
        if (penumpang[i].id == id) {
            for (int j = i; j < jumlahPenumpang - 1; j++) {
                penumpang[j] = penumpang[j + 1];
            }
            jumlahPenumpang--;
            return;
        }
    }
}

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

    // Cek apakah ID sudah ada
    hapusPenumpang(p.id);

    // Tampilkan pemberhentian dalam rute
    for (int i = 0; i < jumlahRute; i++) {
        if (rute[i].id == p.rute_id) {
            Node* temp = rute[i].head;
            printf("Pemberhentian dalam rute %s:\n", rute[i].nama);
            while (temp != NULL) {
                printf("- %s\n", temp->pemberhentian);
                temp = temp->next;
            }
            break;
        }
    }

    printf("Masukkan Nama Pemberhentian: ");
    char pemberhentian[50];
    scanf("%s", pemberhentian);

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
