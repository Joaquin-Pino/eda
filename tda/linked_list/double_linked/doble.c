#include <stdio.h>
#include <stdlib.h>
#include "doble.h"

int main(){
    ListD *listD = crearListaD();

    insertarInicioD(listD, 1);
    insertarInicioD(listD, 2);
    insertarInicioD(listD, 3);
    insertarInicioD(listD, 4);
    insertarInicioD(listD, 5);

    insertarFinalD(listD, 10000);
    insertarFinalD(listD, 334);
    insertarFinalD(listD, 121234);
    
    imprimirListaD(listD);
    ordenarD(listD);

    imprimirListaD(listD);

    eliminarFinalD(listD);
    imprimirListaD(listD);

    eliminarInicioD(listD);
    imprimirListaD(listD);

    invertirListaD(listD);
    imprimirListaD(listD);
}