#include <stdio.h>
#include <stdlib.h>
#include "listaPrim.h"

typedef struct NodoG{
    int value;
    struct NodoG *next;
} NodoG;

typedef struct matrizGrafo{
    int cantVertices;
    int **MA;
} Grafo;

Grafo *crearGrafoVacio(int vertices){
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    if (grafo == NULL){
        printf("no hay suficiente memoria para crear grafo\n");
        return NULL;
    }
    grafo->cantVertices = vertices;
    
    // crear matriz cuadrada
    grafo->MA = (int **) malloc(sizeof(int *) * vertices);
    if (grafo->MA == NULL){
        printf("no hay suficiente memoria para crear matriz de grafo\n");
        return NULL;
    }

    for (int i = 0; i < vertices; i++){
        grafo->MA[i] = (int *) malloc(sizeof(int) * vertices);
        if (grafo->MA[i] == NULL){
            printf("no hay suficiente memoria para crear matriz de grafo\n");
            return NULL;
        }

        for (int j = 0; j < vertices; j++){
            grafo->MA[i][j] = 0;
        }
    }

    return grafo;
}

void printMatrizAdyacencia(Grafo *grafo){
    for (int i = 0; i < grafo->cantVertices; i++){
        for (int j = 0; j < grafo->cantVertices; j++){
            printf("%2d ", grafo->MA[i][j]);
        }
        printf("\n");
    }
}

Grafo *leerGrafoNoDirigido(char* archivo){
    FILE *arch = fopen(archivo, "r");
    if (arch == NULL){
        printf("error al abir el archivo\n");
        return NULL;
    }

    int n_vertices, n_aristas;
    
    fscanf(arch, "%d %d", &n_vertices, &n_aristas);

    Grafo *grafo = crearGrafoVacio(n_vertices);

    int i, j, peso;
    for (int k = 0; k < n_aristas; k++){
        fscanf(arch, "%d %d %d", &i, &j, &peso);

        grafo->MA[i][j] = peso;
        grafo->MA[j][i] = peso;
    }

    fclose(arch);
    return grafo;
}

int sonAdyacentes(Grafo *grafo, int vertA, int vertB){
    if (grafo->MA[vertA][vertB] == 1){
        return 1;
    }
    return 0;
}

Lista *obtenerAdyacentes(Grafo *grafo, int vertice){
	Lista *adyacentes = crearLista();
	
	for(int i = 0; i < grafo->cantVertices; i++){
		if (grafo->MA[i][vertice] != 0 && vertice < grafo->cantVertices){
            Nodo *nodo = crearNodo(i, grafo->MA[i][vertice]);
			insertarFinal(adyacentes, nodo);
		}
	}
	
	return adyacentes;
}

void freeGrafo(Grafo *grafo){
    for (int i = 0; i < grafo->cantVertices; i++){
        free(grafo->MA[i]);
    }
    free(grafo);
}
