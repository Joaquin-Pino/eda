#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "archivos.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("uso: %s archivo.txt", argv[0]);
        return 1;
    }

    Node *cabeza = obtenerDatos(argv[1]);
    //Node *cabeza = crearNodo(0);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // insertarNodoInicio(cabeza, 2);
    // recorrerLista(cabeza);
    
    recorrerLista(cabeza);
    eliminarElem(cabeza, 1);
    recorrerLista(cabeza);
    bubbleSort(cabeza);
    recorrerLista(cabeza);
    printf("largo de la lista: %d\n", len(cabeza));
    
    
    
    freeLista(cabeza);
}