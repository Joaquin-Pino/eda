#include <stdio.h>
#include <stdlib.h>

typedef struct punto
{
    int x;
    int y;
}punto;

punto crearPunto(int x, int y);
void modificarPunto(punto *pto, int x, int y);

int main(){

   punto pto1 = crearPunto(3, 4);

    printf("%d %d\n", pto1.x, pto1.y);

    modificarPunto(&pto1, 5, 30);
    printf("%d %d\n", pto1.x, pto1.y);

}

punto crearPunto(int x, int y){
    punto pto;
    pto.x = x;
    pto.y = y;

    return pto;
}

void modificarPunto(punto *pto, int x, int y){

    pto->x =x;
    pto->y = y;

    return;
}