#ifndef RUTE_H
#define RUTE_H

#define MAX 100

typedef struct Node {
    char pemberhentian[50];
    struct Node* next;
} Node;

typedef struct {
    int id;
    char nama[100];
    Node* head;
} Rute;

extern Rute rute[MAX]; // Declare as extern
extern int jumlahRute; // Declare as extern

void tambahRute();
void tampilRute();
void hapusRute(int id);
int cekRute(int id);
int cekPemberhentian(int id, const char *pemberhentian);

#endif
