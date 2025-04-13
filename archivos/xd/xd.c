#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("uso: %s \"nombre archivo\" \n", argv[0]);
        return 1;
    }
    FILE *archivo = fopen(argv[1], "r");

    if (archivo == NULL){
        printf("no se pudo abrir el archivo\n");
        return 2;
    }

    // for (int i = 0; i < 20; i++){
    //     int valor = fgetc(archivo);

    //     printf("%c, %d\n", valor, valor);
    // }
    
    
    // while (!feof(archivo)){
    //     int valor = fgetc(archivo);
    //     if ( valor == '\n'){
    //         // printf("%c, %d\n", valor, valor);
    //         lineas++;
            
    //     }
    //     else if (valor != '\r') {
    //         printf("%c, %d\n", valor, valor);
    //     }
    // }

    // char lineas[100];
    // while (!feof(archivo)){
    //     char *valor = fgets(lineas, 100, archivo);
    //     printf("%s", valor);
    // }

    // char array[] = {'h','o','l','a'};

    // char *string = (char *) array;

    // printf("%s\n", string);

    int valor;
    fscanf(archivo, "%d", &valor);
    printf("%d\n", valor);
    fscanf(archivo, "%d", &valor);
    printf("%d\n", valor);
    fscanf(archivo, "%d", &valor);
    printf("%d\n", valor);
    fscanf(archivo, "%d", &valor);
    printf("%d\n", valor);
    
}

