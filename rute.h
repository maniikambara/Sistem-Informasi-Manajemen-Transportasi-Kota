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

void tambahRute();
void tampilRute();

#endif
