#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){
    Pila *pila = crearPila();

    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    push(pila, 5);

    for (int i = 0; i < 3; i++){
        printf("%d ", pop(pila));
    }
    printf("pene\n");
}