#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int value;
    struct node *next;
}Node;

Node *crearNodo(int val){
    Node *nodo = (Node *)malloc(sizeof(Node));
    // TODO: verificar si hay suficiente memoria
    
    nodo->value = val;
    nodo->next = NULL;
    return nodo;
}

void insertarNodoInicio(Node *head, int val){
    Node *nodo = crearNodo(val);

    if (head->next == NULL){
        head->next = nodo;
        head->value = 1;
        return;
    }

    nodo->next =head->next;
    head->next = nodo;
    head->value++;
}

void insertarNodoFinal(Node *head, int val){
    Node *nodo = crearNodo(val);

    Node *aux = head->next;

    while (aux->next != NULL){
        aux = aux->next;
    }

    aux->next = nodo;
    head->value++;
    // printf("%d\n", aux->value);
}

void recorrerLista(Node *head){
    Node *aux = head->next;
    while (aux != NULL){
        printf("%d__", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void insertarEnOrden(Node *head, int val){
    // siempre y cuando la lista este ordenada de menor a mayor
    Node *aux = head->next;
    Node *nodo = crearNodo(val);
    
    while (aux->next->value < val){
        aux = aux->next;
    }

    nodo->next = aux->next;
    aux->next = nodo;
    head->value++;
}

void swap(Node *node1, Node *node2){
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void bubbleSort(Node *head){
    if (head->next == NULL){
        return;
    }
    
    Node *aux;
    Node *tope = NULL; // para emular que se vaya acortando la lista
    
    bool swapped; 
    do{
        swapped = false;
        aux = head->next;
        
        while (aux->next != tope){
            if (aux->value > aux->next->value){
                swap(aux, aux->next);
                swapped = true;
            }
            aux = aux->next;
        }

        tope = aux; 
    } while (swapped);
}

