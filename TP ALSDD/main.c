#include <stdio.h>
#include <stdlib.h>
#include "LibFunctions.c"


int main(){
    int index;
    NodeItem  * head = NULL;
    loadItemListFromfile(&head,"./items.txt");
    NodeItem * next;
    
    printItemList(head);

    NodeItem * p = priorItem(head);
    printItem(valueItem(p));

    p = priorItem(head);
    printItem(valueItem(p));

     p = priorItem(head);
    printItem(valueItem(p));
    printf("hola");


    


}