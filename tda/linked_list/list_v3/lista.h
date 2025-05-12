#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct lista{
    Node *head;
    int len;
}Lista;

void insertarInicio(Lista *lista, int valor);
void insertarFinal(Lista *lista, int valor);
void imprimirLista(Lista *lista);
void freeLista(Lista *lista);
bool estaVacia(Lista *lista);
void eliminarNodoInicio(Lista *lista);
void eliminarNodoFinal(Lista *lista);
void insertarPosicion(Lista *lista, int pos, int valor);
void invertirLista(Lista *lista);
void ordenarLista(Lista *lista);

Node *crearNodo(int valor){
    Node *mi_nodo = (Node *)malloc(sizeof(Node));
    mi_nodo->value = valor;
    mi_nodo->next = NULL;

    return mi_nodo;
}

Lista *crearLista(){
    Lista *mi_lista = (Lista *) malloc(sizeof(Lista));
    mi_lista->head = NULL;

    return mi_lista;
}

void insertarInicio(Lista *lista, int valor){
    Node *nodo = crearNodo(valor);
    
    if (lista->head == NULL){
        lista->head = nodo;
        lista->len++;
        return;
    }

    nodo->next = lista->head;
    lista->head = nodo;
    lista->len++;

}

void imprimirLista(Lista *lista){
    Node *aux = lista->head;

    while (aux!= NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void insertarFinal(Lista *lista, int valor){
    Node *nodo = crearNodo(valor);
    
    Node *aux = lista->head;

    if (lista->head == NULL){
        lista->head = nodo;
        return;
    }

    while (aux->next != NULL){
        aux = aux->next;
    }
    //printf("%d\n", aux->value);

    aux->next = nodo;
    lista->len++;

}

void freeLista(Lista *lista){
    Node *aux = lista->head;

    while (aux != NULL){
        Node *xd = aux;
        aux = aux->next;
        free(xd);
        
    }
    free(lista);
}

bool estaVacia(Lista *lista){
    if (lista->head == NULL){
        return true;
    }
    return false;
}

void eliminarNodoInicio(Lista *lista){
    if (estaVacia(lista)){
        return;
    }
    
    Node *aux = lista->head;
    lista->head = aux->next;
    lista->len--;

    free(aux);
}

void eliminarNodoFinal(Lista *lista){
  
    Node *aux = lista->head;
    while (aux->next->next != NULL){
        aux = aux->next;
    }
    //printf("%d\n", aux->value);
    free(aux->next->next);
    aux->next = NULL;
    lista->len--;

}

void insertarPosicion(Lista *lista, int pos, int valor){
    if(pos >= lista->len){
        printf("no existe esa posicion en la lista, ");
        printf("lista tiene largo de %d\n", lista->len);
        return;
    }

    if (pos == 0) return insertarInicio(lista, valor); 

    Node *aux = lista->head;
    Node *nodo = crearNodo(valor);
    for (int i = 0; i < pos - 1; i++){
        aux = aux->next;
    }

    nodo->next = aux->next;
    aux->next = nodo;
}

void invertirLista(Lista *lista){
    Node *aux = lista->head;
    Node *anterior = NULL;

    while (aux != NULL){
        Node *siguiente = aux->next;
        aux->next = anterior;
        
        anterior = aux;
        aux = siguiente;

    }

    lista->head = anterior;
}

void ordenarLista(Lista *lista){
    Node *aux1 = lista->head;

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