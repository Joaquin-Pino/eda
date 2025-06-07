#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "pila.h"

void imprimir(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void dsf(Grafo *grafo, int vertice){
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

    visitado[vertice] = 0;
    distancia[vertice] = 0;
    padre[vertice] = -1;

    Pila *pila = crearPila();
    push(pila, vertice);
    
    while(!esPilaVacia(pila)){
        int u = pop(pila);
        if (visitado[u] == 0){
            printf("visitando %d\n", u);
            visitado[u] = 1;
            Lista *lista = obtenerAdyacentes(grafo, u);
            Nodo *aux = lista->head;
            while (aux != NULL){
                if (visitado[aux->value] == 0){
                    push(pila, aux->value);
                    distancia[aux->value] = distancia[u] + 1;
                    padre[aux->value] = u;
                }

                aux = aux->next;
            }
           freeLista(lista);
        }
    }

    free(pila);
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
    printMatrizAdyacencia(grafo);

    dsf(grafo, atoi(argv[2]));

    freeGrafo(grafo);
}