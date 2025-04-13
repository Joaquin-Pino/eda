#include <stdio.h>

void modify(int array[]);
void swap(int a, int b);
void swapPtr(int *a, int *b);

int main(void){
    
    int numeros[3] = {4,5,6};
    modify(numeros);
    
    printf("el array de numeros tomo el valor de:\n");
    for (int i = 0;i < 3; i++){
        printf("%i\n", numeros[i]);
    }

    printf("\n\n\n");
    
    int x = 2;
    int y = 3;
    printf("el valor incial de x es: %i, el valor inicial de y es: %i\n", x, y);
    
    printf("pasando por valor:\n");
    swap(x, y);
    printf("el valor de x es %i, el valor de y es %i\n", x, y);

    x = 2;
    y = 3;
    swapPtr(&x, &y);
    printf("pasando por referencia:\n");
    printf("el valor de x es %i, el valor de y es %i\n", x, y);

}

void modify(int array[]){
    for (int i = 0; i < 3; i++){
        //*(array + i)= 1;
        array[i] = 1;
    }
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapPtr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}