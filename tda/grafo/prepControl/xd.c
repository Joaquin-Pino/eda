#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "cola.h"
#include <limits.h>

int verticesDeGrado(Grafo *g, int grado){
    int contador = 0;
    for (int i = 0; i < g->cantVertices; i++){
        int temp = 0;
        for (int j = 0; j < g->cantVertices; j++){
            if (g->MA[i][j] != 0){
                temp++;
            }
        }

        if (temp == grado){
            contador++;
        }
    }

    if (contador != 0){
        return contador;
    } else{
        return -1;
    }
}

int esRegular(Grafo *g){
    int grado = verticesDeGrado(g, 0);
    for (int i = 1; i < g->cantVertices; i++){
        int temp = verticesDeGrado(g, i);

        if (temp != grado){
            return -1;
        }
    }

    return grado;
}

int *bfs(Grafo *g, int vertice){
    int *visitados = malloc(sizeof(int) * g->cantVertices);

    for (int i = 0; i < g->cantVertices; i++){
        visitados[i] =0;
    }
    Cola *q = crearCola();
    visitados[vertice] = 1;

    encolar(q, vertice);

    while (!esColaVacia(q)){
        int u = desencolar(q);
        Lista *adyacentes = obtenerAdyacentes(g, u);

        Nodo *aux = adyacentes->head;

        while (aux != NULL){
            if (visitados[aux->value] == 0){
                encolar(q, aux->value);
                visitados[aux->value] = 1;
            }

            aux = aux->next;
        }
    }

    return visitados;
}

int esConexo(int *visitados, int n){
    for (int i = 0; i < n; i++){
        if (visitados[i] != 1){
            return 0;
        }
    }
    return 1;
}

void imprimir(int *arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

Grafo *modificarGrafo(Grafo *g, int vertice){
    Grafo *temp = crearGrafoVacio(g->cantVertices);

    for(int i = 0; i < g->cantVertices; i++){
        for (int j = 0; j < g->cantVertices; j++){
            temp->MA[i][j] = g->MA[i][j];
        }
    }

    for (int i = 0; i < g->cantVertices; i++){
        temp->MA[vertice][i] = 0;
        temp->MA[i][vertice] = 0;
    }

    return temp;
}

Grafo *desconexar(Grafo *g){
    for (int i = 0; i < g->cantVertices; i++){
        Grafo *grafoTemp = modificarGrafo(g, i);
        int *visitadosTemp;
        if (i == 0){
            visitadosTemp = bfs(grafoTemp, 1);
        } else {
            visitadosTemp = bfs(grafoTemp, 0);
        }

        if (!esConexo(visitadosTemp, grafoTemp->cantVertices)){
            return grafoTemp;
        }
    }

    return NULL;
}

int bfsProblema3(Grafo *g, int vertice, int final){
    int n = g->cantVertices;
    int distancia[n];
    int visitados[n];
    
    for (int i = 0; i < g->cantVertices; i++){
        distancia[i] =INT_MAX;
        visitados[i] = 0;
    }
    
    Cola *q = crearCola();
    visitados[vertice] = 1;
    distancia[vertice] = 0;

    encolar(q, vertice);

    while (!esColaVacia(q)){
        int u = desencolar(q);
        Lista *adyacentes = obtenerAdyacentes(g, u);

        Nodo *aux = adyacentes->head;

        while (aux != NULL){
            if (visitados[aux->value] == 0){
                encolar(q, aux->value);
                visitados[aux->value] = 1;
                distancia[aux->value] = distancia[u] + 1;
            }

            aux = aux->next;
        }
    }

    if (distancia[final] == INT_MAX){
        return -1;
    } else{
        return distancia[final];
    }
}

int cantidadDeAristas(Grafo *g){
    int contador = 0;

    for (int i = 0; i < g->cantVertices; i++){
        for (int j = 0; j < g->cantVertices; j++){
            if (g->MA[i][j] != 0){
                contador++;
            }
        }
    }

    return contador/2;
}
int main(int argc, char* argv[]){
    if (argc != 5){
        printf("uso: %s archivo.txt vertice grado final\n", argv[0]);
        return 1;
    }
    
    Grafo *g = leerGrafoNoDirigido(argv[1]);
    printMatrizAdyacencia(g);
    // problema 1
    printf("%d\n", verticesDeGrado(g, atoi(argv[3])));
    
    if (esRegular(g)){
        printf("es regular\n");
    } else {
        printf("no es regular\n");
    }
    // problema 2 a
    int *visitados = bfs(g, atoi(argv[2]));
    
    imprimir(visitados, g->cantVertices);
    // problema 2 b
    if (esConexo(visitados, g->cantVertices)){
        printf("es conexo\n");
    } else {
        printf("no es conexo\n");
    }
    
    //problmea 2 (c), no funciono esta wea
    Grafo *desconexo = desconexar(g);

    printMatrizAdyacencia(desconexo);

    //falta escribir al archivo
    FILE *salida = fopen("grafo2.txt", "w");
    int cantAristas = cantidadDeAristas(desconexo);
    int cantVert = g->cantVertices;
    fprintf(salida, "%d %d\n",cantVert, cantAristas);

    for (int i = 0; i < g->cantVertices; i++){
        for (int j = 0; j < g->cantVertices; j++){
            if (j > i && desconexo->MA[i][j] != 0){
                fprintf(salida, "%d %d\n", i, j);
            }
        }
    }

    // problema 3
    int salida3 = bfsProblema3(g, atoi(argv[2]), atoi(argv[4]));

    printf("salida problema 3 %d\n", salida3);
}