#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


Lista *eliminarDup(Lista *l1, Lista *l2){
    Node *aux1 = l1->head;
    Lista *nuevo = crearLista();

    while (aux1 != NULL){
        Node *aux2 = l2->head;
        bool rep = false;
        while (aux2 != NULL){
            if (aux1->value == aux2->value){
                rep = true;
            }
            aux2 = aux2->next;
        }

        if (!rep){
            insertarFinal(nuevo, aux1->value);
        }
        aux1 = aux1->next;
    }

    return nuevo;
}

void mezclarOrden(Lista *l1, Lista *l2){
    Node *aux1 = l1->head;

    while (aux1 != NULL){
        Node *aux2 = l2->head;

        while (aux2 != NULL){
            if (aux1->value > aux2->next->value){
                // insertar nodo
            }
            aux2 = aux2->next;
        }
        aux1 = aux2->next;
    }
}


int main(){
   
    Lista *l1 = crearLista();
    insertarFinal(l1, 1);
    insertarFinal(l1, 5);
    insertarFinal(l1, 6);
    insertarFinal(l1, 43);
    insertarFinal(l1, 82);
    insertarFinal(l1, 2);

    imprimirLista(l1);
    selection(l1);
    imprimirLista(l1);

    freeLista(l1);
}