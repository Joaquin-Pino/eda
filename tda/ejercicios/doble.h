#include <stdio.h>
#include <stdlib.h>

typedef struct NodeD{
    int value;
    struct NodeD *next;
    struct NodeD *prev;
} NodeD;

typedef struct list{
    NodeD *head;
    int len;
} ListD;

NodeD *createNodeD(int value){
    NodeD *my_NodeD = (NodeD *) malloc(sizeof(NodeD));
    if (my_NodeD == NULL){
        printf("no hay suficiente memoria para crear nodo\n");
        return NULL;
    }

    my_NodeD->value = value;
    my_NodeD->next = NULL;
    my_NodeD->prev = NULL;

    return my_NodeD;
}

ListD *createListD(){
    ListD *my_list =  (ListD *) malloc(sizeof(ListD));
    if (my_list == NULL){
        printf("no hay suficiente memoria para crear lista\n");
        return NULL;
    }

    my_list->head = NULL;
    return my_list;
}

void insertBeginning(ListD *list, int value){
    NodeD *NodeD = createNodeD(value);

    if (list->head == NULL){
        list->head = NodeD;
        list->len++;
        return;
    }

    list->head->prev = NodeD;
    NodeD->next = list->head;
    list->head = NodeD;
}

void insertEnd(ListD *list, int value){
    NodeD *aux = list->head;
    NodeD *NodeD = createNodeD(value);

    while (aux->next != NULL){
        aux = aux->next;
    }
    
    NodeD->prev = aux;
    aux->next = NodeD;
    list->len++;
}

void printList(ListD *list){
    NodeD *aux = list->head;

    while (aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

