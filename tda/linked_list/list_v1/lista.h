#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
}List;

List *crearLista(){
    List *list = (List *)malloc(sizeof(List));
    
    list -> head = NULL;

    return list;
}

Node *crearNodo(int valor){
    Node *node = (Node *)malloc(sizeof(Node));

    node->val = valor;
    node->next = NULL;

    return node;

}

void insertarNodoInicio(List *lista, int valor){
    Node *nodo = crearNodo(valor);

    if (lista->head == NULL){
        lista->head = nodo;
        return;
    }

    nodo->next = lista->head;
    lista->head = nodo;


}

void recorrerLista(List *lista){
    Node *aux= lista->head;
    while (aux != NULL){
        printf("%d--", aux->val);

        aux= aux->next;
    }
    printf("\n");

}

void insertarNodoFinal(List *lista, int val){
    Node *aux = lista->head;
    Node *nodo = crearNodo(val);
    
    while (aux->next != NULL){
        aux = aux->next;
    }

    aux->next = nodo;
    
}
int largo(List *lista){
    Node *aux = lista->head;
    int n = 0;
    while (aux != NULL){
        n++;
        aux = aux->next;
    }

    return n;
}

