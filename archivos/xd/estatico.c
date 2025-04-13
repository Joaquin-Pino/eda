#include <stdio.h>
#include <stdlib.h>

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

    int cantidaDatos;
    fscanf(archivo, "%d", &cantidaDatos);
    
    // pedir memoria y asingar valores a array
    int *array = malloc(sizeof(int) * cantidaDatos);
    int valor;
    for (int i = 0; i < cantidaDatos; i++){
        fscanf(archivo, "%d", &valor);
        array[i]= valor;
    }
    
    for (int i = 0; i < cantidaDatos; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

   fclose(archivo);
}

