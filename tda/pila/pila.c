#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){
    
    Pila *mi_pila = crearPila();
    for (int i = 0; i < MAX; i++){
        push(mi_pila, i);
        printf("%d\n", mi_pila->top);
    }


    for (int i = 0; i < MAX; i++){
        printf("%d ", mi_pila->datos[i]);
    }
    printf("\n");
   

    for (int i = 0; i < MAX-1; i++){
        pop(mi_pila);
        printf("top %d\n", mi_pila->top);
        //printf("hice pop\n");
    }

    if (estaLLena(mi_pila)) {
        printf("-----esta llena\n");
        printf("%d\n", mi_pila->top);
    } else {
        printf("no esta llena\n");
    }

    free(mi_pila);
    return 0;
}