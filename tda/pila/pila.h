#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct pila{
    int datos[MAX];
    int top;
}Pila;

bool estaLLena(Pila *pila){
    if (pila->top + 1== MAX){
        return true;
    }
    return false;
}

bool estaVacia(Pila *pila){
    if (pila->top == -1){
        return true;
    }
    return false;
}

Pila *crearPila(){
    Pila *mi_pila = (Pila *) malloc(sizeof(Pila));
    mi_pila->top = -1;

    return mi_pila;
}

void push(Pila *pila, int valor){
    if (estaLLena(pila)){      
        printf("no se ingreso valor, pila llena\n");
        return;
    }
    pila->top++;
    pila->datos[pila->top] = valor;
}

int pop(Pila *pila){
    if (!estaVacia(pila)){
        int dato = pila->datos[pila->top];
        pila->top--;

        return dato;
    }   
}

int tope(Pila *pila){
    if (!estaVacia){
        return pila->datos[pila->top];
    }
}

void printPila(Pila *pila){
    
    for (int i = 0; i < MAX; i++){
        printf("%d ", pila->datos[i]);
    }
    printf("\n");
}