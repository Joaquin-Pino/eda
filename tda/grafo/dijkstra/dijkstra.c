#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
//#include "lista.h"

void dijkstra(Grafo *grafo, int vertice);
int quedanSinVisitar(int visto[], int n);
void imprimir(int arr[], int n);

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("uso: %s archivo.txt nodo_inicio\n", argv[0]);
        return 1;
    }

    Grafo *grafo = leerGrafoNoDirigido(argv[1]);
    printMatrizAdyacencia(grafo);

    dijkstra(grafo, atoi(argv[2]));
}

int extraerMinimo(int distancia[], int visto[], int n){
    int min = INT_MAX;
    int indice = -1;
    for (int i = 0; i < n; i++){
        if (visto[i] == 0 && distancia[i] < min){
            min = distancia[i];
            indice = i;
        }
    }

    return indice;
}

void dijkstra(Grafo *grafo, int vertice){
    int n = grafo->cantVertices;
    int padre[n];
    int visto[n];
    int distancia[n];
    for (int i = 0; i < n; i++){
        padre[i] = -1;
        visto[i] = 0;

        if (grafo->MA[vertice][i] > 0){
            distancia[i] = grafo->MA[vertice][i];
            padre[i] = vertice;
        }
        else {
            distancia[i] = INT_MAX;
        }
    }

    distancia[vertice] = 0;
    visto[vertice] = 1;
    
    while (quedanSinVisitar(visto, n)){
        int u = extraerMinimo(distancia, visto, n);
        visto[u] = 1;
        Lista *adyacentes = obtenerAdyacentes(grafo, u);
        Nodo *aux = adyacentes->head;

        while (aux != NULL){
            if (distancia[aux->value] > 
                distancia[u] + grafo->MA[u][aux->value]){
                    distancia[aux->value] = distancia[u] + grafo->MA[u][aux->value];
                    padre[aux->value] = u;
            }

            aux = aux->next;
        }
    }

    printf("salida: \n");
    printf("visitados ");
    imprimir(visto, n);
    printf("distancia ");
    imprimir(distancia, n);
    printf("precedencia ");
    imprimir(padre, n);
}

int quedanSinVisitar(int visto[], int n){
    for(int i = 0; i < n; i++){
        if (visto[i] == 0){
            return 1;
        }
    }

    return 0; // no quedan elementos sin visitar
}

void imprimir(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}