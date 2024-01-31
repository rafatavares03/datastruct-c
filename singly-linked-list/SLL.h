#ifndef DL_H
#define DL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int elem;
    struct NODE *next;
} NODE;

typedef struct NODE * List;

List *createList() {
    List *li = (List*)malloc(sizeof(List));
    if(li != NULL) {
        *li = NULL;
    }
    return li;
}

NODE *nodeAlloc() {
    return (NODE*)malloc(sizeof(NODE));
}

void destroyNODE(NODE *n) {
    free(n);
}

void destroyList(List *li) {
    if(li == NULL) return;
    NODE *aux = *li;
    while((*li) != NULL) {
        *li = aux->next;
        destroyNODE(aux);
        aux = *li;
    }
    free(li);
}

int IsEmpty(List *li) {
    if(li == NULL) return -1;
    return (*li == NULL) ? 1 : 0;
}

#endif