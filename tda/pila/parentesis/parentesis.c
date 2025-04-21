// programa que determina si una epxresion tiene parentesis balanceados
// es decir, que cada parenteisis este bien terminado y anidados.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

bool estaBalanceado(char expresion[], int len_exp);

int main(){
    char *expresion = "[(])";
    printf("%s\n", expresion);
     
    int len_exp = strlen(expresion);
    printf("largo de exp %d\n", len_exp);

    if (estaBalanceado(expresion, len_exp)){
        printf("los parentesis estan balanceados\n");
    } else {
        printf("los parentesis no estan balanceados--\n");
    }  
}

bool estaBalanceado(char expresion[], int len_exp){
    Pila *parentesis = crearPila();
    
    for (int i = 0; i < len_exp; i++){ 
        switch (expresion[i]){
            case '[':
                push(parentesis, expresion[i]);
                break;
            case '{':
                push(parentesis, expresion[i]);
                break;
            case '(':
                push(parentesis, expresion[i]);
                break;

            case ']':
                if (tope(parentesis) == '['){
                    pop(parentesis);
                    break;  
                    
                } else {
                    free(parentesis);
                    return false;
                    
                }  
            case '}':
                if (tope(parentesis) == '{' ){
                    pop(parentesis);
                    break;
                
                } else {
                    free(parentesis);
                    return false;
                    
                } 
            case ')':
                if (tope(parentesis) == '('){
                    pop(parentesis);
                    break;

                } else {
                    free(parentesis);
                    return false;
                    
                } 
        }  
    }

    if (estaVacia(parentesis)){
        free(parentesis);
        return true;

    }
    
    free(parentesis);
    return false;
}