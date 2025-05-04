#include <stdio.h>
#include <stdlib.h>
#include "../lista.h"
#include "../doble.h"


Lista *eliminarRep(Lista *l1, ListD *l2){
    Lista *nuevo = crearLista();
    Node *aux1 = l1->head;

    while (aux1 != NULL){
        bool rep = false;
        NodeD *aux2 = l2->head;
        
        while (aux2 != NULL){
            if (aux1->value == aux2->value){
                printf("%d %d\n", aux1->value, aux2->value);
                rep = true;
            }
    
            aux2 = aux2->next;  
        }

        if (rep == false){
            insertarFinal(nuevo, aux1->value);
        }

        aux1 = aux1->next;
    }

    return nuevo;
}

void insertar(Lista *l1, ListD *l2){
    Node *aux1 = l1->head;


}
int main(){
    Lista *l1 = crearLista();
    insertarFinal(l1, 1);
    insertarFinal(l1, 29);
    insertarFinal(l1, 2);
    insertarFinal(l1, 3);
    insertarFinal(l1, 4);

    ListD *l2 = createListD();
    insertBeginning(l2, 1);
    insertEnd(l2, 3);
    insertEnd(l2, 4);
    insertEnd(l2, 6);
    insertEnd(l2, 8);

    imprimirLista(l1);
    printList(l2);
    Lista *nuevo = eliminarRep(l1, l2);
    imprimirLista(nuevo);

    
}