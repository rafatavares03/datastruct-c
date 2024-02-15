#include <stdio.h>
#include "./SLL.h"

int main(){
    List *li = createList();
    addLastElement(li, 5);
    addLastElement(li, 10);
    printList(li);
    removeLastElement(li);
    printList(li);
    removeLastElement(li);
    printList(li);
    destroyList(li);
    return 0;
}