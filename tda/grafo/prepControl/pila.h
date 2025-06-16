#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NodeP{
    int value;
    struct NodeP *next;
}NodeP;

typedef struct pila{
    NodeP *tope;
    
}Pila;

NodeP *crearNodoP(int valor){
    NodeP *mi_nodo = (NodeP *) (sizeof(NodeP));
    mi_nodo->value = valor;
    mi_nodo->next = NULL;

    return mi_nodo;
}

Pila *crearPila(){
    Pila *mi_pila = (Pila *) (sizeof(Pila));
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
    NodeP *nodo = crearNodoP(valor);
  
    nodo->next = pila->tope;
    pila->tope = nodo;

}

int pop(Pila *pila){
    if (esPilaVacia(pila)){
        printf("no se puede hacer pop a pila vacia\n");
    
    } else {
        NodeP *aux = pila->tope;
        int valor = aux->value;
        pila->tope = aux->next;
    
        free(aux);
        return valor;
    }
}