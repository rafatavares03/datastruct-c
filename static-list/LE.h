#ifndef LE_H
#define LE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct List{
    int data[MAX];
    int amount;
} List;

List *createList() {
    List *li = (List*)malloc(sizeof(List));
    if(li != NULL) {
        li->amount = 0;
    }
    return li;
}

void destroyList(List *li) {
    free(li);
}

int IsEmpty(List *li) {
    if(li == NULL) return -1;
    return (li->amount == 0) ? 1 : 0;
}

int IsFull(List *li) {
    if(li == NULL) return -1;
    return (li->amount == MAX) ? 1 : 0;
}

int searchElement(List *li, int elem) {
    if(li == NULL) return -1;
    if(IsEmpty(li)) return -1;
    for(int i = 0; i < li->amount; i++) {
        if(li->data[i] == elem) return i;
    }
    return -1;
}

int insertElement(List *li, int elem){
    if(li == NULL) return -1;
    if(IsFull(li)) return 0;
    li->data[li->amount] = elem;
    li->amount++;
    return 1;
}

int removeElement(List *li, int elem) {
    if(li == NULL) return -1;
    if(IsEmpty(li)) return 0;
    int index = searchElement(li, elem);
    if(index < 0) return -1;
    for(int i = index + 1; i < li->amount; i++) {
        li->data[i - 1] = li->data[i];
    }
    li->amount--;
    return 1;
}

int removeLastElement(List *li) {
    if(li == NULL) return -1;
    if(IsEmpty(li)) return 0;
    li->amount--;
    return 1;
}

void printList(List *li) {
    if(!IsEmpty(li)) {
        printf("Elements: ");
        for(int i = 0; i < li->amount; i++){
            printf("%d ", li->data[i]);
        }
        printf("\n");
    }
}

#endif