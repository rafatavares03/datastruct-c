#include <stdio.h>
#include "./SLL.h"

int main(){
    List *li = createList();
    destroyList(li);
    return 0;
}