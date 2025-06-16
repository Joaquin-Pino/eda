#include <stdio.h>
#include <stdlib.h>
#include "listaPrim.h"

int main(){
    Lista *lista = crearLista();

    for (int i = 0; i < 4; i++){
        Nodo *nodo = crearNodo(i, 2);
        insertarFinal(lista, nodo);
    }

    imprimirLista(lista);

    elminarNodo(lista, 2);
    imprimirLista(lista);
}