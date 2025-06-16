#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    Grafo *g = leerGrafoNoDirigido("grafo2.txt");

    printMatrizAdyacencia(g);
}