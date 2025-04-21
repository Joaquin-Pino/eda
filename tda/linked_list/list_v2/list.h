#ifndef LISTA_H
#define LISTA_H

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

// void freeNodo(Node *nodo){
//     // Node **xd = &nodo;
//     free(xd);
// }

void insertarNodoInicio(Node *head, int val){
    Node *nodo = crearNodo(val);

    if (head->next == NULL){
        head->next = nodo;
        head->value = 1;
        
        return;
    }

    nodo->next = head->next;
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

void printLista(Node *head){
    Node *aux = head->next;
    while (aux->next != NULL){
        printf("%d__", aux->value); 
        aux = aux->next;
    }
    printf("%d__NULL\n", aux->value);
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

void eliminarElem(Node *head, int target){
    Node *aux = head;

    while (aux->next != NULL){
        if (aux->next->value == target && aux->next->next == NULL){
            Node *xd = aux->next;
            
            aux->next = NULL;
            head->value--;
            
            free(xd);
            
            return;
        } else if (aux->next->value == target){
            //printf("%d\n",aux->value);
            Node *xd = aux->next;
            
            Node *temp = aux->next->next;
            aux->next =aux->next->next;
            head->value--;
            
            free(xd);
            
            return;
        }
        aux = aux->next;
    }
}

int len(Node *head){
    return head->value;
}


void freeLista(Node *head){
    Node *aux = head->next;
    
    while (aux != NULL){
        Node *xd = aux;
        aux = aux->next;
        free(xd);
    }
    free(head);
}

void  **invertirLista(Node **head){
    Node *anterior = NULL;
    Node *actual = (*head)->next;
    Node *siguiente;
    
    while (actual != NULL){
        siguiente = actual->next;
        
        actual->next = anterior;
        anterior = actual;
        actual = siguiente;
    }
    
    (*head)->next = anterior;
    
    
}
#endif