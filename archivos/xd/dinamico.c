#include <stdio.h>
#include <stdlib.h>

int *obtenerDatos(FILE *archivo);


int main(int argc, char *argv[]){

    if (argc != 2){
        printf("uso %s \"nombre archivo.txt\"", argv[0]);
        return 1;
    }
    FILE *archivo = fopen(argv[1], "r");
    if (archivo == NULL){
        printf("no se pudo abrir el archivo\n");
        return 2;
    }

    int *datos = obtenerDatos(archivo);

    int cantidadDatos = datos[0];

    for (int i = 1; i <= cantidadDatos; i++){
        printf("%d ", datos[i]);
    }
    printf("\n");

    free(datos);
    fclose(archivo);
    return 0;
}

int *obtenerDatos(FILE *archivo){
    // devuelve cantidad de datos en posicion 0 
    
    int cantidadDatos;
    fscanf(archivo, "%d", &cantidadDatos);

    // pedir memoria e ingresar datos en array
    int *array = malloc(sizeof(int) * (cantidadDatos+1));
    array[0] = cantidadDatos;
    int valor;
    for (int i = 1; i <= cantidadDatos; i++){
        fscanf(archivo, "%d", &valor);
        array[i]= valor;
    }
    
    return array;

}
