#include <stdio.h>
#include <string.h>
#include "kendaraan.h"
#include "stack.h" // Added this line to access the stack functions
#include "utils.h"

Kendaraan kendaraan[MAX];
int jumlahKendaraan = 0;

void tambahKendaraan() {
    Kendaraan k;
    printf("Masukkan ID Kendaraan: ");
    scanf("%d", &k.id);
    printf("Masukkan Nama Kendaraan: ");
    scanf("%s", k.nama);
    printf("Masukkan Kapasitas: ");
    scanf("%d", &k.kapasitas);

    // Cek apakah ID sudah ada
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (kendaraan[i].id == k.id) {
            // Simpan nama kendaraan yang dihapus ke riwayat perjalanan
            push(kendaraan[i].id);
            // Hapus kendaraan lama
            for (int j = i; j < jumlahKendaraan - 1; j++) {
                kendaraan[j] = kendaraan[j + 1];
            }
            jumlahKendaraan--;
            break;
        }
    }

    kendaraan[jumlahKendaraan++] = k;
    // Simpan ID kendaraan yang baru ditambahkan ke riwayat perjalanan
    push(k.id);
    printf("Data kendaraan berhasil ditambahkan!\n");
}

void hapusKendaraan(int id) {
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (kendaraan[i].id == id) {
            // Simpan ID kendaraan yang dihapus ke riwayat perjalanan
            push(kendaraan[i].id);
            for (int j = i; j < jumlahKendaraan - 1; j++) {
                kendaraan[j] = kendaraan[j + 1];
            }
            jumlahKendaraan--;
            printf("Kendaraan dengan ID %d berhasil dihapus.\n", id);
            return;
        }
    }
    printf("Kendaraan dengan ID %d tidak ditemukan.\n", id);
}

void tampilKendaraan() {
    printf("\t\t\t        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    printf("\t\t\t        \xb3                 Data Kendaraan                    \xb3\n");
    printf("\t\t\t        \xb3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb3\n");
    for (int i = 0; i < jumlahKendaraan; i++) {
        // Pastikan nama kendaraan tidak melebihi 14 karakter
        char nama[15];
        strncpy(nama, kendaraan[i].nama, 14);
        nama[14] = '\0'; // Pastikan nama ter-terminate dengan baik

        // Simpan nama kendaraan yang ditampilkan ke riwayat perjalanan
        push(kendaraan[i].id);

        printf("\t\t\t\t               ID       : %-4d\n", kendaraan[i].id);
        printf("\t\t\t\t               NAMA     : %-14s\n", nama);
        printf("\t\t\t\t               Kapasitas: %-7d \n\n", kendaraan[i].kapasitas);
    }
    printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    MarqueeText("\t\t\t\t\xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3\n", 3999900);
}

void urutkanKendaraan() {
    // Implementasi bubble sort
    for (int i = 0; i < jumlahKendaraan - 1; i++) {
        for (int j = 0; j < jumlahKendaraan - i - 1; j++) {
            if (kendaraan[j].id > kendaraan[j + 1].id) {
                Kendaraan temp = kendaraan[j];
                kendaraan[j] = kendaraan[j + 1];
                kendaraan[j + 1] = temp;
            }
        }
    }
    printf("Data kendaraan berhasil diurutkan berdasarkan ID.\n");
}

void cariKendaraan() {
    int id;
    printf("Masukkan ID Kendaraan yang dicari: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (kendaraan[i].id == id) {
            printf("Kendaraan ditemukan: ID: %d, Nama: %s, Kapasitas: %d\n",
                   kendaraan[i].id, kendaraan[i].nama, kendaraan[i].kapasitas);
            return;
        }
    }
    printf("Kendaraan dengan ID %d tidak ditemukan.\n", id);
}
