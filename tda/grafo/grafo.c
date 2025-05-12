#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("uso: %s \"archivo.txt\" vertice", argv[0]);
        return 1;
    }

    Grafo *grafo = leerGrafoNoDirigido(argv[1]);

    // Grafo *grafo = crearGrafoVacio(5);
    printMatrizAdyacencia(grafo);
}