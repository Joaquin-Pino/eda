#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "archivos.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("uso: %s archivo.txt", argv[0]);
        return 1;
    }

    Node *cabeza = obtenerDatos(argv[1]);

    recorrerLista(cabeza);
    bubbleSort(cabeza);
    recorrerLista(cabeza);
}