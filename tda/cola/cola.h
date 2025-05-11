#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *pointer;
} Node;

typedef struct queue{
    Node *first;
    Node *last;
    int capacity;
    int size;
} Queue;

Node *crearNodo(int val){
    Node *my_node = (Node *) malloc(sizeof(Node));
    if (my_node == NULL){
        printf("no hay suficinte memoria para crear un nodo\n");
        return NULL;
    }

    my_node->value = val;
    my_node->pointer = NULL;

    return my_node;
}

Queue *crearCola(int capacity){
    Queue *my_queue = (Queue *) malloc(sizeof(Queue));
    if (my_queue == NULL){
        printf("no hay suficiente memoria para crear cola\n");
        return NULL;
    }

    my_queue->first = NULL;
    my_queue->last = NULL;
    my_queue->capacity = capacity;
    my_queue->size = 0;

    return my_queue;
}

int esColaVacia(Queue *c){
    if (c->size == 0){
        return 1;
    }
    return 0;
}

Node *obtenerFrente(Queue *c){
    if (esColaVacia(c)){
        return NULL;
    }

    return c->first;
}

Node *obtenerFinal(Queue *c){
    if (esColaVacia(c)){
        return NULL;
    }
    return c->last;
}

void encolar(Queue *c, int val){
    Node *node = crearNodo(val);
    
    if(esColaVacia(c)){
        c->first = node;
        c->last = node;
        c->size++;
    } else if(c->size < c->capacity){
        c->last->pointer = node;
        c->last = node;
    }
}   

void desencolar(Queue *c){
    
}