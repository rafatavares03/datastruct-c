#include <stdio.h>
#include "./LE.h"

int main() {
    List *li = createList();
    int selector, x;
    printf(
        ">>>>>Static Lita<<<<<\n"
        "1 - Insert element.\n"
        "2 - Remove element.\n"
        "3 - Remove last element.\n"
        "4 - Print list.\n"
        "5 - Exit.\n"
    );
    do {
        scanf("%d", &selector);
        switch (selector)
        {
        case 1:
            printf("Type the element: ");
            scanf("%d", &x);
            insertElement(li, x);
            break;
        case 2:
            printf("Type the element: ");
            scanf("%d", &x);
            x = removeElement(li, x);
            if(x == -1) printf("Element not inserted.\n");
            break;
        case 3:
            removeLastElement(li);
            break;
        case 4:
            printList(li);
            break;
        }
    } while (selector != 5);
    destroyList(li);
    return 0;
}