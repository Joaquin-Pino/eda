#include <stdio.h>
#include "cola.h"

int main(){
    Cola *cola = crearCola();
    encolar(cola, 1);
    encolar(cola, 2);
    printf("tamano de cola %d\n", cola->size);
    desencolar(cola);
    printf("tamano de cola %d\n", cola->size);

}