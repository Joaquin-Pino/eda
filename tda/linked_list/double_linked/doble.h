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

ListD *crearListaD();
void insertarInicioD(ListD *list, int value);
void insertarFinalD(ListD *list, int value);
void imprimirListaD(ListD *list);
void ordenarD(ListD *l);
void eliminarFinalD(ListD *l);
void eliminarInicioD(ListD *l);
void invertirListaD(ListD *l);

Node *crearNodo(int value){
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

ListD *crearListaD(){
    ListD *my_list =  (ListD *) malloc(sizeof(ListD));
    if (my_list == NULL){
        printf("no hay suficiente memoria para crear lista\n");
        return NULL;
    }

    my_list->head = NULL;
    return my_list;
}

void insertarInicioD(ListD *list, int value){
    Node *node = crearNodo(value);

    if (list->head == NULL){
        list->head = node;
        list->len++;
        return;
    }

    list->head->prev = node;
    node->next = list->head;
    list->head = node;
}

void insertarFinalD(ListD *list, int value){
    Node *aux = list->head;
    Node *node = crearNodo(value);

    while (aux->next != NULL){
        aux = aux->next;
    }
    
    node->prev = aux;
    aux->next = node;
    list->len++;
}

void imprimirListaD(ListD *list){
    Node *aux = list->head;

    while (aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void ordenarD(ListD *l){
    Node *aux1 = l->head;
    
    while (aux1 != NULL){
        int minx = aux1->value;
        Node *minp = aux1;

        Node *aux2 = aux1->next;

        while (aux2 != NULL){
            if (minx > aux2->value){
                minx = aux2->value;
                minp = aux2;
            }

            aux2 = aux2->next;
        }

        int temp = aux1->value;
        aux1->value = minx;
        minp->value = temp;

        aux1 = aux1->next;
    }
}

void eliminarFinalD(ListD *l){
    Node *aux = l->head;

    while (aux->next != NULL){
        aux = aux->next;
    }

    aux->prev->next = NULL;
    free(aux);
}

void eliminarInicioD(ListD *l){
    Node *aux = l->head;

    l->head = aux->next;

    free(aux);
}

void invertirListaD(ListD *l){
    if (l == NULL || l->head == NULL) return;

    Node *curr = l->head;
    Node *prev = NULL;

    while (curr != NULL) {
        Node *next = curr->next;  

        curr->next = prev;
        curr->prev = next;
        
        prev = curr;
        curr = next;
    }

    l->head = prev;
}