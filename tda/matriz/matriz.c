#include <stdio.h>
#include <stdlib.h>

int **asignarMemoria(int m, int n);

typedef struct Matriz{
    int m;
    int n;
    int **A;
}Matriz;
int main(){

    Matriz mi_matriz;
    mi_matriz.m = 3;
    mi_matriz.n = 3;

    mi_matriz.A = asignarMemoria(mi_matriz.m, mi_matriz.n);
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){

            mi_matriz.A[i][j]= i;
        }
    }
    

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", mi_matriz.A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < mi_matriz.m; i++){
        free(mi_matriz.A[i]);
    }
    free(mi_matriz.A);
}

int **asignarMemoria(int m, int n){
    int **matriz = malloc(sizeof(int *) * m);
    if (matriz == NULL){
        return NULL;
    }

    for (int i = 0; i < m; i++){
        matriz[i] = malloc(sizeof(int) * n);
        if (matriz[i] == NULL){
            return NULL;
        }
    }

    return matriz;
}