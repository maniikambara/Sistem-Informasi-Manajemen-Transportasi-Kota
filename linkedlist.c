#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void addPemberhentian(Rute *r, const char *pemberhentian) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->pemberhentian, pemberhentian);
    newNode->next = NULL;

    if (r->head == NULL) {
        r->head = newNode;
    } else {
        Node *temp = r->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
