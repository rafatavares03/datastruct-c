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

int addLastElement(List *li, int elem){
    if(li == NULL) return -1;
    NODE *new = nodeAlloc();
    if(new == NULL) return 0;
    new->elem = elem;
    if(IsEmpty(li)) {
        *li = new;
    } else {
        NODE *aux = *li;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new;
    }
    new->next = NULL;
    return 1;
}

int removeLastElement(List *li) {
    if(li == NULL) return -1;
    if(IsEmpty(li)) return 0;
    NODE *aux = *li, *prev;
    while(aux->next != NULL){
        prev = aux;
        aux = aux->next;
    }
    if(aux == *li) {
        *li = NULL;
    } else {
        prev->next = NULL;
    }
    destroyNODE(aux);
    return 1;
}

void printList(List *li){
    if(li == NULL) return;
    if(IsEmpty(li)) {
        printf("The list is empty, add new elements to it.\n");
        return;
    }
    NODE *aux = *li;
    printf("Elements:");
    while(aux != NULL) {
        printf(" %d", aux->elem);
        aux = aux->next;
    }
    printf("\n");
}

#endif