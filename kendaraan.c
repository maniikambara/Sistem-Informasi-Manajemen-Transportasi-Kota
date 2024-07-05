#include <stdio.h>
#include <string.h>
#include "kendaraan.h"
#include "stack.h"
#include "utils.h"
#include "rute.h" // Pastikan ini sudah ada

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
    printf("Masukkan Kapasitas yang sudah terisi: ");
    scanf("%d", &k.terisi);
    k.kosong = k.kapasitas - k.terisi; // Hitung kapasitas yang kosong

    if (jumlahRute == 0) {
        printf("Tidak ada rute yang tersedia. Menyimpan kendaraan pada ID rute pertama dan pemberhentian pertama.\n");
        k.rute_id = 1;
        strcpy(k.pemberhentian, "Pemberhentian1");
    } else {
        // Tambahkan input ID Rute dan Nama Pemberhentian
        do {
            printf("Masukkan ID Rute: ");
            scanf("%d", &k.rute_id);
            if (!cekRute(k.rute_id)) {
                printf("ID Rute tidak ditemukan. Coba lagi.\n");
            }
        } while (!cekRute(k.rute_id));

        do {
            printf("Masukkan Nama Pemberhentian: ");
            scanf("%s", k.pemberhentian);
            if (!cekPemberhentian(k.rute_id, k.pemberhentian)) {
                printf("Nama Pemberhentian tidak ditemukan dalam rute. Coba lagi.\n");
            }
        } while (!cekPemberhentian(k.rute_id, k.pemberhentian));
    }

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
        printf("\t\t\t\t               Kapasitas: %-7d\n", kendaraan[i].kapasitas);
        printf("\t\t\t\t               Terisi   : %-7d\n", kendaraan[i].terisi);
        printf("\t\t\t\t               Kosong   : %-7d\n", kendaraan[i].kosong);

        // Tampilkan rute dan pemberhentian
        for (int j = 0; j < jumlahRute; j++) {
            if (rute[j].id == kendaraan[i].rute_id) {
                printf("\t\t\t\t               Rute     : %s\n", rute[j].nama);
                printf("\t\t\t\t               Pemberhentian: %s\n", kendaraan[i].pemberhentian);
                break;
            }
        }
        printf("\n");
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
            printf("Kendaraan ditemukan: ID: %d, Nama: %s, Kapasitas: %d, Terisi: %d, Kosong: %d\n",
                   kendaraan[i].id, kendaraan[i].nama, kendaraan[i].kapasitas, kendaraan[i].terisi, kendaraan[i].kosong);
            return;
        }
    }
    printf("Kendaraan dengan ID %d tidak ditemukan.\n", id);
}
