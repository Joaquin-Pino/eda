#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(){
    Cola *c = crearCola(20);

    for (int i = 20; i > 0; i--){
        encolar(c, i);
    }

    imprimirCola(c);

    // int num = desencolar(c);
    // imprimirCola(c);

    ordenarAscendente(c);
    imprimirCola(c);
}