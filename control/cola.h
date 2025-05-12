#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *pointer;
} Node;

typedef struct Cola{
    Node *first;
    Node *last;
    int capacity;
    int size;
} Cola;

Node *crearNodo(int val){
    Node *my_node = (Node *) malloc(sizeof(Node));
    if (my_node == NULL){
        printf("no hay suficinte memoria para crear un nodo\n");
        return NULL;
    }

    my_node->value = val;
    my_node->pointer = NULL;

    return my_node;
}

Cola *crearCola(int capacity){
    Cola *mi_cola = (Cola *) malloc(sizeof(Cola));
    if (mi_cola == NULL){
        printf("no hay suficiente memoria para crear cola\n");
        return NULL;
    }

    mi_cola->first = NULL;
    mi_cola->last = NULL;
    mi_cola->capacity = capacity;
    mi_cola->size = 0;

    return mi_cola;
}

int esColaVacia(Cola *c){
    if (c->size == 0){
        return 1;
    }
    return 0;
}

Node *obtenerFrente(Cola *c){
    if (esColaVacia(c)){
        return NULL;
    }

    return c->first;
}

Node *obtenerFinal(Cola *c){
    if (esColaVacia(c)){
        return NULL;
    }
    return c->last;
}

void encolar(Cola *c, int val){
    Node *node = crearNodo(val);
    
    if(esColaVacia(c)){
        c->first = node;
        c->last = node;
        c->size++;
    } else if(c->size < c->capacity){
        c->last->pointer = node;
        c->last = node;
        c->size++;
    } else {
        printf("Cola llena, no se puede agregar mas elementos\n");
    }
}   

int desencolar(Cola *c){

    if (esColaVacia(c)){
        printf("no hay valor para desencolar, cola vacia\n");

    } else {

        int valor = c->first->value;

        Node *aux = c->first;

        c->first = c->first->pointer;

        free(aux);
        return valor;
    }
}

void imprimirCola(Cola *c){
    Node *aux = c->first;

    while (aux != NULL){
        printf("%d ", aux->value);
        aux = aux->pointer;
    }

    printf("\n");
}

void ordenarAscendente(Cola *c){
    Node *aux1 = c->first;

    while (aux1 != NULL){
        Node *aux2 = aux1->pointer;

        int minx = aux1->value;
        Node *minp = aux1;

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