#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *obtenerDatos(char *file){
    FILE *datos = fopen(file, "r");

    int numDatos;
    fscanf(datos, "%d", &numDatos);
    

    Node *head = crearNodo(0);
    int dato;
    for (int i = 0; i < numDatos; i++){
        fscanf(datos, "%d", &dato);

        insertarNodoInicio(head, dato);
    }

    fclose(datos);
    return head;
}