#include <stdio.h>
#include "queue.h"
#include "penumpang.h"  // Tambahkan header ini untuk mengakses penumpang dan jumlahPenumpang

Queue antrianPenumpang;

void initQueue() {
    antrianPenumpang.front = 0;
    antrianPenumpang.rear = -1;
    antrianPenumpang.size = 0;
}

int isQueueFull() {
    return antrianPenumpang.size == MAX;
}

int isQueueEmpty() {
    return antrianPenumpang.size == 0;
}

void enqueue(int id) {
    if (!isQueueFull()) {
        antrianPenumpang.rear = (antrianPenumpang.rear + 1) % MAX;
        antrianPenumpang.data[antrianPenumpang.rear] = id;
        antrianPenumpang.size++;
    } else {
        printf("Antrian penumpang penuh!\n");
    }
}

int dequeue() {
    if (!isQueueEmpty()) {
        int id = antrianPenumpang.data[antrianPenumpang.front];
        antrianPenumpang.front = (antrianPenumpang.front + 1) % MAX;
        antrianPenumpang.size--;
        return id;
    } else {
        printf("Antrian penumpang kosong!\n");
        return -1;
    }
}

void tampilAntrianPenumpang() {
    if (!isQueueEmpty()) {
        printf("Antrian Penumpang:\n");
        printf("\t\t ------------------------------------------\n");
        printf("\t\t |  ID  |      NAMA      | UMUR | ID RUTE |\n");
        printf("\t\t ------------------------------------------\n");
        for (int i = antrianPenumpang.front; i < antrianPenumpang.front + antrianPenumpang.size; i++) {
            int id = antrianPenumpang.data[i % MAX];
            for (int j = 0; j < jumlahPenumpang; j++) {  // Akses jumlahPenumpang dari penumpang.h
                if (penumpang[j].id == id) {  // Akses penumpang dari penumpang.h
                    printf("\t\t | %-4d | %-14s | %-4d | %-7d |\n",
                           penumpang[j].id, penumpang[j].nama, penumpang[j].umur, penumpang[j].rute_id);
                    break;
                }
            }
        }
        printf("\t\t ------------------------------------------\n");
    } else {
        printf("Antrian penumpang kosong!\n");
    }
}
