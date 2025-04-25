#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct pila{
    Node *tope;
    
}Pila;

Node *crearNodo(int valor){
    Node *mi_nodo = (Node *) malloc(sizeof(Node));
    mi_nodo->value = valor;
    mi_nodo->next = NULL;

    return mi_nodo;
}

Pila *crearPila(){
    Pila *mi_pila = (Pila *) malloc(sizeof(Pila));
    mi_pila->tope = NULL;
    return mi_pila;
}

bool esPilaVacia(Pila *pila){
    if (pila->tope == NULL){
        return true;
    }
    return false;
}

void push(Pila *pila, int valor){
    Node *nodo = crearNodo(valor);
    if (esPilaVacia(pila)){
        pila->tope = nodo;
    }

    nodo->next = pila->tope;
    

}