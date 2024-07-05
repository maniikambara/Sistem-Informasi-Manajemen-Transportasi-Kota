#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rute.h"
#include "linkedlist.h"
#include "utils.h"

Rute rute[MAX];
int jumlahRute = 0; // Define here

void hapusRute(int id) {
    for (int i = 0; i < jumlahRute; i++) {
        if (rute[i].id == id) {
            // Hapus semua pemberhentian dalam rute
            Node *temp = rute[i].head;
            while (temp != NULL) {
                Node *next = temp->next;
                free(temp);
                temp = next;
            }
            // Hapus rute dari array
            for (int j = i; j < jumlahRute - 1; j++) {
                rute[j] = rute[j + 1];
            }
            jumlahRute--;
            return;
        }
    }
}

void tambahRute() {
    Rute r;
    char pemberhentian[50];
    system("cls");
    printf("\t\t\t        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    printf("\t\t\t        \xb3             SISTEM INFORMASI MANAJEMEN            \xb3\n");
    printf("\t\t\t        \xb3                 TRANSPORTASI KOTA                 \xb3\n");
    printf("\t\t\t        \xb3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb3\n");
    printf("\t\t\t        \xb3              ==== Tambahkan Rute ====\n");
    printf("\t\t\t        \xb3\n");
    printf("\t\t\t        \xb3              Masukkan ID Rute: ");
    scanf("%d", &r.id);
    printf("\t\t\t        \xb3              Masukkan Nama Rute: ");
    scanf("%s", r.nama);
    r.head = NULL;

    // Cek apakah ID sudah ada
    hapusRute(r.id);

    printf("\t\t\t        \xb3\n");
    printf("\t\t\t        \xb3              Masukkan Jumlah Pemberhentian: ");
    int jumlah;
    scanf("%d", &jumlah);
    for (int i = 0; i < jumlah; i++) {
        printf("\t\t\t        \xb3              Masukkan Pemberhentian %d: ", i + 1);
        scanf("%s", pemberhentian);
        addPemberhentian(&r, pemberhentian);
    }
    rute[jumlahRute++] = r;
    printf("\t\t\t        \xb3\n");
    printf("\t\t\t        \xb3          Data rute berhasil ditambahkan!\n");
    printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    MarqueeText("\t\t\t\t\xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3\n",3999900);
}

void tampilRute() {
    system("cls");
    printf("\t\t\t        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    printf("\t\t\t        \xb3             SISTEM INFORMASI MANAJEMEN            \xb3\n");
    printf("\t\t\t        \xb3                 TRANSPORTASI KOTA                 \xb3\n");
    printf("\t\t\t        \xb3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb3\n");
    printf("\t\t\t        \xb3               ==== Data Rute ====\n");
    printf("\t\t\t        \xb3\n");
    for (int i = 0; i < jumlahRute; i++) {
        printf("\t\t\t        \xb3         ID: %d, Nama: %s\n", rute[i].id, rute[i].nama);
        Node* temp = rute[i].head;
        int j = 1;
        while (temp != NULL) {
            printf("\t\t\t        \xb3         Pemberhentian %d: %s\n", j++, temp->pemberhentian);
            temp = temp->next;
        }
    }
    printf("\t\t\t        \xb3\n");
    printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    MarqueeText("\t\t\t\t\xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3\n",3999900);
}

int cekRute(int id) {
    for (int i = 0; i < jumlahRute; i++) {
        if (rute[i].id == id) {
            return 1; // Rute ditemukan
        }
    }
    return 0; // Rute tidak ditemukan
}

int cekPemberhentian(int id, const char *pemberhentian) {
    for (int i = 0; i < jumlahRute; i++) {
        if (rute[i].id == id) {
            Node* temp = rute[i].head;
            while (temp != NULL) {
                if (strcmp(temp->pemberhentian, pemberhentian) == 0) {
                    return 1; // Pemberhentian ditemukan
                }
                temp = temp->next;
            }
        }
    }
    return 0; // Pemberhentian tidak ditemukan
}