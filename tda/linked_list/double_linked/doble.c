#include <stdio.h>
#include <stdlib.h>
#include "doble.h"

int main(){
    ListD *listD = createListD();

    insertBeginning(listD, 1);
    insertBeginning(listD, 2);
    insertBeginning(listD, 3);
    insertBeginning(listD, 4);
    insertBeginning(listD, 5);

    insertEnd(listD, 10000);
    insertEnd(listD, 334);
    insertEnd(listD, 121234);

    printList(listD);
}