#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list{
    Node *head;
    int len;
} ListD;

Node *createNode(int value){
    Node *my_node = (Node *) malloc(sizeof(Node));
    if (my_node == NULL){
        printf("no hay suficiente memoria para crear nodo\n");
        return NULL;
    }

    my_node->value = value;
    my_node->next = NULL;
    my_node->prev = NULL;

    return my_node;
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
    Node *node = createNode(value);

    if (list->head == NULL){
        list->head = node;
        list->len++;
        return;
    }

    list->head->prev = node;
    node->next = list->head;
    list->head = node;
}

void insertEnd(ListD *list, int value){
    Node *aux = list->head;
    Node *node = createNode(value);

    while (aux->next != NULL){
        aux = aux->next;
    }
    
    node->prev = aux;
    aux->next = node;
    list->len++;
}

void printList(ListD *list){
    Node *aux = list->head;

    while (aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

