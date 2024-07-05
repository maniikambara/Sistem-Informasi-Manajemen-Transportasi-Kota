#ifndef KENDARAAN_H
#define KENDARAAN_H

#define MAX 100

typedef struct {
    int id;
    char nama[50];
    int kapasitas;
    int terisi; // Kapasitas yang sudah terisi
    int kosong; // Kapasitas yang kosong
    int rute_id; // Tambahkan ID Rute
    char pemberhentian[50]; // Tambahkan Nama Pemberhentian
} Kendaraan;

extern Kendaraan kendaraan[MAX];
extern int jumlahKendaraan;

void tambahKendaraan();
void tampilKendaraan();
void urutkanKendaraan();
void cariKendaraan();
void hapusKendaraan(int id);

#endif
