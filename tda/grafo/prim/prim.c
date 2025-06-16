#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"

void prim(Grafo *grafo, int vertice);
void insertarListaPrim(Lista *lista, int u, int distancia);
int extraerMinimoPrim(Lista *lista);
void imprimir(int arr[], int n);
void actualizarListaPrim(Lista *lista, int vert, int distancia);

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("uso: %s archivo.txt nodo_inicio\n", argv[0]);
        return 1;
    }

    Grafo *grafo = leerGrafoNoDirigido(argv[1]);
    printMatrizAdyacencia(grafo);

    prim(grafo, atoi(argv[2]));
}

void prim(Grafo *grafo, int vertice){
    int n = grafo->cantVertices;
    int distancia[n];
    int padre[n];  
    
    Lista *listaPrim = crearLista();

    for (int i = 0; i < n; i++){
        distancia[i] = INT_MAX;
        padre[i] = -1;
        insertarListaPrim(listaPrim, i, distancia[i]);
    }

    distancia[vertice] = 0;
    actualizarListaPrim(listaPrim, vertice, 0);

    while (!estaVacia(listaPrim)){
        int u = extraerMinimoPrim(listaPrim);
        Lista *adyacetes = obtenerAdyacentes(grafo, u);
        Nodo *aux = adyacetes->head;

        while (aux != NULL){
            int v = aux->id;
            if (estaEnLista(listaPrim, v) && distancia[v] > grafo->MA[u][v]){
                padre[v] = u;
                distancia[v] = grafo->MA[u][v];
                actualizarListaPrim(listaPrim, v, distancia[v]);
            }
            aux = aux->next;
        }
    }

    printf("salida: \n");
    printf("distancia ");
    imprimir(distancia, n);
    printf("precedencia ");
    imprimir(padre, n);
}

void insertarListaPrim(Lista *lista, int u, int distancia){
    Nodo *nodo = crearNodo(u, distancia);
    insertarFinal(lista, nodo);
}

void actualizarListaPrim(Lista *lista, int vert, int distancia){
    Nodo *aux = lista->head;

    while (aux != NULL){
        if (aux->id == vert){
            aux->dist = distancia;
        }

        aux = aux->next;
    }
}

int extraerMinimoPrim(Lista *lista){
    int min = INT_MAX;
    int elemento = -1;

    Nodo *aux = lista->head;

    while (aux != NULL){
        if (aux->dist < min){
            min = aux->dist;
            elemento = aux->id;
        }

        aux = aux->next;
    }

    // eliminar nodo
    elminarNodo(lista, elemento);

    return elemento;
}

void imprimir(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}