#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){
    Pila *mi_pila = crearPila();

    push(mi_pila, 1);
    push(mi_pila, 2);
    push(mi_pila, 3);
    push(mi_pila, 4);

    for (int i = 0; i < 10; i++){
        printf("%d ", pop(mi_pila));
    }
    printf("\n");

}