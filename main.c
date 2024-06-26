#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "kendaraan.h"
#include "rute.h"
#include "penumpang.h"
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "utils.h"
 
void loadingAnimation() {
    system ("cls");
    const char *loading = "|/-\\";
    for (int i = 0; i < 10; i++) {
        printf("\rLoading... %c", loading[i % 4]);
        fflush(stdout);
        usleep(100000); // Sleep for 100 milliseconds
    }
    printf("\rLoading... Done!\n");
}
// Fungsi untuk menampilkan UI menu utama
void tampilMenuUtama() {
    printf("\t\t\t        \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    printf("\t\t\t        \xb3             SISTEM INFORMASI MANAJEMEN            \xb3\n");
    printf("\t\t\t        \xb3                 TRANSPORTASI KOTA                 \xb3\n");
    printf("\t\t\t        \xb3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb3\n");
    printf("\t\t\t        \xb3              ========= Menu =========             \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             1. Tambah Data Kendaraan              \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             2. Tampilkan Data Kendaraan           \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             3. Tambah Data Rute                   \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             4. Tampilakn Data Rute                \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             5. Tambah Data Penumpang              \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             6. Tampilkan Data Penumpang           \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             7. Urutkan Kendaraan Berdasarkan ID   \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             8. Cari Kendaraan Berdasarkan ID      \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             9. Tampilkan Antrian Penumpang        \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             10. Tampilkan Kendaraan Baru Masuk    \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xb3             0. Keluar                             \xb3\n");
    printf("\t\t\t        \xb3                                                   \xb3\n");
    printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
    MarqueeText("\t\t\t\t\xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3\n",3999900);
    printf("\t\t\t                              Pilih menu: ");
}

int main() {
    int pilUser;
    
    // Inisialisasi struktur data
    initStack();
    initQueue();

    while (1) {
        system("cls"); // Ganti dengan 'cls' untuk Windows
        tampilMenuUtama();
        scanf("%d", &pilUser);

        switch (pilUser) {
            case 1:
            loadingAnimation();
                tambahKendaraan();
                break;
            case 2:
            loadingAnimation();
                tampilKendaraan();
                break;
            case 3:
            loadingAnimation();
                tambahRute();
                break;
            case 4:
            loadingAnimation();
                tampilRute();
                break;
            case 5:
            loadingAnimation();
                tambahPenumpang();
                break;
            case 6:
            loadingAnimation();
                tampilPenumpang();
                break;
            case 7:
            loadingAnimation();
                urutkanKendaraan();
                break;
            case 8:
            loadingAnimation();
                cariKendaraan();
                break;
            case 9:
            loadingAnimation();
                tampilAntrianPenumpang();
                break;
            case 10:
            loadingAnimation();
                dataKendaraanBaru();
                break;
            case 0:
            loadingAnimation();
                exit(0);
            default:
            loadingAnimation();
                printf("Pilihan tidak valid. Coba lagi.\n");
        }

        printf("\nTekan Enter untuk melanjutkan...");
        while (getchar() != '\n'); // Membersihkan input buffer
        getchar(); // Menunggu Enter
    }

    return 0;
}
