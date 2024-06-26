#ifndef KENDARAAN_H
#define KENDARAAN_H

#define MAX 100

typedef struct {
    int id;
    char nama[50];
    int kapasitas;
} Kendaraan;

extern Kendaraan kendaraan[MAX];
extern int jumlahKendaraan;

void tambahKendaraan();
void tampilKendaraan();
void urutkanKendaraan();
void cariKendaraan();
void hapusKendaraan(int id);

#endif
