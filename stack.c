#include <stdio.h>
#include "stack.h"
#include "kendaraan.h" // Added this line to access the kendaraan array
#include "utils.h"

Stack kendaraanBaru;

void initStack() {
    kendaraanBaru.top = -1;
}

int isStackFull() {
    return kendaraanBaru.top == MAX - 1;
}

int isStackEmpty() {
    return kendaraanBaru.top == -1;
}

void push(int id) {
    if (!isStackFull()) {
        kendaraanBaru.data[++kendaraanBaru.top] = id;
    } else {
        printf("Data kendaraan sudah penuh!\n");
    }
}

int pop() {
    if (!isStackEmpty()) {
        return kendaraanBaru.data[kendaraanBaru.top--];
    } else {
        printf("Data kendaraan kosong!\n");
        return -1;
    }
}

void dataKendaraanBaru() {
    if (!isStackEmpty()) {
    printf("\t\t\t        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    printf("\t\t\t        \xb3                 Data Kendaraan Terbaru            \xb3\n");
    printf("\t\t\t        \xb3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb3\n");
        int id = kendaraanBaru.data[kendaraanBaru.top]; // Only display the latest input
        // Cari nama kendaraan dan kapasitas berdasarkan ID
        for (int j = 0; j < jumlahKendaraan; j++) {
            if (kendaraan[j].id == id) {
                printf("\t\t\t        \xb3                 ID Kendaraan: %d                   \xb3\n", id);
                printf("\t\t\t        \xb3                 Nama Kendaraan: %s                 \xb3\n",kendaraan[j].nama);
                printf("\t\t\t        \xb3                 Kapasitas: %d                      \xb3\n",kendaraan[j].kapasitas);
                break;
            }
        }
    printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    MarqueeText("\t\t\t\t\xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3\n", 3999900);
    } 
    else {
        printf("Belum ada data kendaraan terbaru!\n");
    }
}
