#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(){

    Node *cabeza = crearNodo(0);

    // insertarNodoInicio(cabeza, 6);
    // insertarNodoInicio(cabeza, 5);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 1);


    printf("cantidad de elemenoos en la lista %d\n", cabeza->value);
    //recorrerLista(cabeza);

    
    insertarEnOrden(cabeza, 3);
    recorrerLista(cabeza);
    
}