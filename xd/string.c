#include <stdio.h>

int main(int argc, char *argv[]){

    char *string_1 ="string 1";

    char *string_2[] = {"string", "2"};

    for (int i = 0; i < 2; i++){

        printf("%s\n", string_2[i]);
    }
}