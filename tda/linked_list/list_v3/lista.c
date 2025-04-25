#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista *lista = crearLista();

    for (int i = 0; i < 10; i++){
        insertarInicio(lista, i);
    }
    
    imprimirLista(lista);

    invertirLista(lista);
    imprimirLista(lista);

    freeLista(lista);
}