#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack();
int isStackFull();
int isStackEmpty();
void push(int id);
int pop();
void dataKendaraanBaru();

#endif
