#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    List *cabeza = crearLista();

    insertarNodoInicio(cabeza, 1);

    // recorrerLista(cabeza);
    // insertarNodoInicio(cabeza, 2);

    // recorrerLista(cabeza);

    insertarNodoFinal(cabeza, 30);
    
    recorrerLista(cabeza);

    printf("largo lista %d\n", largo(cabeza));
    printf("holaa\n");

}