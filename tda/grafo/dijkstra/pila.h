#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct pila{
    Node *tope;
    
}Pila;

Node *crearNodoP(int valor){
    Node *mi_nodo = malloc(sizeof(Node));
    mi_nodo->value = valor;
    mi_nodo->next = NULL;

    return mi_nodo;
}

Pila *crearPila(){
    Pila *mi_pila = malloc(sizeof(Pila));
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
    Node *nodo = crearNodoP(valor);
  
    nodo->next = pila->tope;
    pila->tope = nodo;

}

int pop(Pila *pila){
    if (esPilaVacia(pila)){
        printf("no se puede hacer pop a pila vacia\n");
    
    } else {
        Node *aux = pila->tope;
        int valor = aux->value;
        pila->tope = aux->next;
    
        free(aux);
        return valor;
    }
}