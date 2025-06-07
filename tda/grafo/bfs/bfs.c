#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "limits.h"
#include "cola.h"

void imprimir(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bsf(Grafo *grafo, int vertice){
    int n = grafo->cantVertices;
    int visitado[n];
    int distancia[n];
    int padre[n];
    for (int i = 0; i < n; i++){
        if (i != vertice){
            visitado[i] = 0;
            distancia[i] = INT_MAX;
            padre[i] = -1;
        }  
    }

    visitado[vertice] = 1;
    distancia[vertice] = 0;
    padre[vertice] = -1;

    Cola *cola = crearCola();
    encolar(cola, vertice);

    while (cola->size != 0){
        
        int u = desencolar(cola); // lo mismo que hacer frente y luego desencolar
        Lista *adyacentes = obtenerAdyacentes(grafo, u);
        printf("visitando a %d: \n", u);
        //imprimirLista(adyacentes);
        Nodo *vert = adyacentes->head;
        while (vert != NULL){
            if (visitado[vert->value] == 0){
                visitado[vert->value] = 1;
                distancia[vert->value] = distancia[u] + 1;
                padre[vert->value] = u;
                encolar(cola, vert->value);
            }
            vert = vert->next;
        }
        freeLista(adyacentes);
    }
    
    printf("salida: \n");
    printf("visitados: ");
    imprimir(visitado, n);
    printf("distancia ");
    imprimir(distancia, n);
    printf("padres ");
    imprimir(padre, n);

    
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("uso: %s \"archivo.txt\" vertice\n", argv[0]);
        return 1;
    }

    Grafo *grafo = leerGrafoNoDirigido(argv[1]);

    // Grafo *grafo = crearGrafoVacio(5);
    printMatrizAdyacencia(grafo);
	// printf("adyacentes a vertice %s: ", argv[2]);
	// Lista *adyacentes = obtenerAdyacentes(grafo, atoi(argv[2]));
	// imprimirLista(adyacentes);
    bsf(grafo, atoi(argv[2]));
}

