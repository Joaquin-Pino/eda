#include <stdio.h>
#include <stdlib.h>

typedef struct NodoC{
    int value;
    struct NodoC *pointer;
} NodoC;

typedef struct Cola{
    NodoC *first;
    NodoC *last;
    int capacity;
    int size;
} Cola;

NodoC *crearNodoC(int val){
    NodoC *my_NodoC = (NodoC *) malloc(sizeof(NodoC));
    if (my_NodoC == NULL){
        printf("no hay suficinte memoria para crear un nodo\n");
        return NULL;
    }

    my_NodoC->value = val;
    my_NodoC->pointer = NULL;

    return my_NodoC;
}

Cola *crearCola(){
    Cola *mi_cola = (Cola *) malloc(sizeof(Cola));
    if (mi_cola == NULL){
        printf("no hay suficiente memoria para crear cola\n");
        return NULL;
    }

    mi_cola->first = NULL;
    mi_cola->last = NULL;
    //mi_cola->capacity = capacity;
    mi_cola->size = 0;

    return mi_cola;
}

int esColaVacia(Cola *c){
    if (c->size == 0){
        return 1;
    }
    return 0;
}

NodoC *obtenerFrente(Cola *c){
    if (esColaVacia(c)){
        return NULL;
    }

    return c->first;
}

NodoC *obtenerFinal(Cola *c){
    if (esColaVacia(c)){
        return NULL;
    }
    return c->last;
}

void encolar(Cola *c, int val){
    NodoC *NodoC = crearNodoC(val);
    
    if(esColaVacia(c)){
        c->first = NodoC;
        c->last = NodoC;
        c->size++;
    } else{
        c->last->pointer = NodoC;
        c->last = NodoC;
        c->size++;
    } 
}   

int desencolar(Cola *c){
    if (esColaVacia(c)){
        printf("no hay valor para desencolar, cola vacia\n");

    } else {

        int valor = c->first->value;

        NodoC *aux = c->first;

        c->first = c->first->pointer;
        c->size--;
        free(aux);
        return valor;
    }
}

void imprimirCola(Cola *c){
    NodoC *aux = c->first;

    while (aux != NULL){
        printf("%d ", aux->value);
        aux = aux->pointer;
    }

    printf("\n");
}

void ordenarAscendente(Cola *c){
    NodoC *aux1 = c->first;

    while (aux1 != NULL){
        NodoC *aux2 = aux1->pointer;

        int minx = aux1->value;
        NodoC *minp = aux1;

        while (aux2 != NULL){
            if (minx > aux2->value){
                minx = aux2->value;
                minp = aux2;
            }
            aux2 = aux2->pointer;
        }
        
        // swap
        int temp = aux1->value;
        aux1->value = minx;
        minp->value = temp;

        aux1 = aux1->pointer;
    }
}