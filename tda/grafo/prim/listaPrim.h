#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int dist;
    int id;
    struct Nodo *next;
}Nodo;

typedef struct lista{
    Nodo *head;
    int len;
}Lista;


void insertarInicio(Lista *lista, Nodo *nodo);
void insertarFinal(Lista *lista, Nodo *nodo);
void imprimirLista(Lista *lista);
void freeLista(Lista *lista);
bool estaVacia(Lista *lista);
void eliminarNodoInicio(Lista *lista);
void eliminarNodoFinal(Lista *lista);
void insertarPosicion(Lista *lista, int pos, Nodo *nodo);
void invertirLista(Lista *lista);
void ordenarLista(Lista *lista);
void elminarNodo(Lista *lista, int elem);

Nodo *crearNodo(int elem, int u){
    Nodo *mi_nodo = (Nodo *)malloc(sizeof(Nodo));
    mi_nodo->dist = elem;
    mi_nodo->id = u;
    mi_nodo->next = NULL;

    return mi_nodo;
}

Lista *crearLista(){
    Lista *mi_lista = (Lista *) malloc(sizeof(Lista));
    mi_lista->head = NULL;

    return mi_lista;
}

void insertarInicio(Lista *lista, Nodo *nodo){
    
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
    Nodo *aux = lista->head;

    while (aux!= NULL){
        printf("%d ", aux->dist);
        aux = aux->next;
    }
    printf("\n");
}

void insertarFinal(Lista *lista, Nodo *nodo){
    
    Nodo *aux = lista->head;

    if (lista->head == NULL){
        lista->head = nodo;
        return;
    }

    while (aux->next != NULL){
        aux = aux->next;
    }
    //printf("%d\n", aux->dist);

    aux->next = nodo;
    lista->len++;

}

void freeLista(Lista *lista){
    Nodo *aux = lista->head;

    while (aux != NULL){
        Nodo *xd = aux;
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
    
    Nodo *aux = lista->head;
    lista->head = aux->next;
    lista->len--;

    free(aux);
}

void eliminarNodoFinal(Lista *lista){
  
    Nodo *aux = lista->head;
    while (aux->next->next != NULL){
        aux = aux->next;
    }
    //printf("%d\n", aux->dist);
    free(aux->next->next);
    aux->next = NULL;
    lista->len--;

}

void insertarPosicion(Lista *lista, int pos, Nodo *nodo){
    if(pos >= lista->len){
        printf("no existe esa posicion en la lista, ");
        printf("lista tiene largo de %d\n", lista->len);
        return;
    }

    if (pos == 0) return insertarInicio(lista, nodo); 

    Nodo *aux = lista->head;
    for (int i = 0; i < pos - 1; i++){
        aux = aux->next;
    }

    nodo->next = aux->next;
    aux->next = nodo;
}

void invertirLista(Lista *lista){
    Nodo *aux = lista->head;
    Nodo *anterior = NULL;

    while (aux != NULL){
        Nodo *siguiente = aux->next;
        aux->next = anterior;
        
        anterior = aux;
        aux = siguiente;

    }

    lista->head = anterior;
}

void ordenarLista(Lista *lista){
    Nodo *aux1 = lista->head;

    while (aux1 != NULL){
        int minx = aux1->dist;
        Nodo *minp = aux1;
        Nodo *aux2 = aux1->next;

        while (aux2 != NULL){
            if (minx > aux2->dist){
                minx = aux2->dist;
                minp = aux2;
            }
            aux2 = aux2->next;
        }

        int temp = aux1->dist;
        aux1->dist = minx;
        minp->dist = temp;

        aux1 = aux1->next;
    }
}

void elminarNodo(Lista *lista, int elem){
    Nodo *actual = lista->head;
    Nodo *anterior = NULL;

    if (actual != NULL && actual->id == elem){
        lista->head = actual->next;
        free(actual);
        return;
    }

    while (actual != NULL && actual->id != elem){
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL) return;

    anterior->next = actual->next;
    free(actual);
    return;
}

bool estaEnLista(Lista *lista, int elem){
    Nodo *aux = lista->head;

    while (aux != NULL){
        if (aux->id == elem){
            return true;
        }
        
        aux = aux->next;
    }

    return false;
}