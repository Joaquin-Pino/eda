#include <stdio.h>
#include <stdlib.h>

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
        printf("%d--", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void insertarEnOrden(Node *head, int val){
    Node *aux = head->next;
    Node *nodo = crearNodo(val);
    
    while (aux->next->value < val){
        aux = aux->next;
    }

    nodo->next = aux->next;
    aux->next = nodo;
    head->value++;
}