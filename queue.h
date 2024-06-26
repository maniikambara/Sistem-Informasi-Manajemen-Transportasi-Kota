#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initQueue();
int isQueueFull();
int isQueueEmpty();
void enqueue(int id);
int dequeue();
void tampilAntrianPenumpang();

#endif
