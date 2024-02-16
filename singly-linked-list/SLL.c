#include <stdio.h>
#include "./SLL.h"

int main(){
    List *li = createList();
    int selector, x;
    printf(
        ">>> Singly Linked List <<<\n"
        "1 - Insert an element at the end of the list.\n"
        "2 - Insert an element at the beginning of the list.\n"
        "3 - Remove element from end of list.\n"
        "4 - Remove element from beginning of list.\n"
        "5 - Print list.\n"
        "6 - Exit.\n"
    );
    do{
        scanf("%d", &selector);
        switch(selector) {
            case 1:
                printf("Type the element: ");
                scanf("%d", &x);
                InsertLastElement(li, x);
                break;
            case 2:
                printf("Type the element: ");
                scanf("%d", &x);
                InsertFirstElement(li, x);
                break;
            case 3:
                removeLastElement(li);
                break;
            case 4:
                removeFirstElement(li);
                break;
            case 5:
                printList(li);
                break;
        }
    } while(selector != 6);
    destroyList(li);
    return 0;
}