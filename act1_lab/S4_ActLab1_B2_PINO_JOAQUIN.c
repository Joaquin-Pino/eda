#include <stdio.h>
#include <stdlib.h>

int **crearMatriz(int fila, int columa);
int **obtenerDatos(char *archivo);
void imprimirMatriz(int **datos, int numFilas); // para debug

int main(int argc, char *argv[]){
	// se verifica que se ingrese el nombre del archivo
	if (argc !=2){
		printf("uso %s archivo.txt\n", argv[0]);
		return 1;
	}
	
	// se abre el archivo para obtener el numero de filas
	FILE *archivo = fopen(argv[1], "r");
	if (archivo == NULL){
		printf("no se pudo abrir el archivo\n");
		return 1;
	}
	int numFilas;
	fscanf(archivo, "%d", &numFilas);
	fclose(archivo);
	
	
	// se crea matriz para guardar los datos
	int **datos = obtenerDatos(argv[1]);
	
	// ----------------- pregunta 2 ----------------
	printf(" ----------------- pregunta 2 ----------------\n");
	for (int i = 0; i < numFilas; i++){
		// se imprime la fila solo si ambos elementos son positivos
		if (datos[i][0] > 0 && datos[i][1] > 0){
			printf("%d %d\n", datos[i][0],  datos[i][1]);
		}
	}
	
	// ----------------- pregunta 3 ----------------
	printf("----------------- pregunta 3 ----------------\n");
	
	// se busca el menor suma en el archivo y se guarda la fila en la que ocurre
	int menor = datos[0][0] + datos[0][1];
	int indiceI = 0;
	
	for (int i = 1; i < numFilas; i++){
		int suma = datos[i][0] + datos[i][1];
		if (suma < menor){
			indiceI = i;
		}
		
	}
	// se imprime la fila con la menor suma
	printf("%d %d\n", datos[indiceI][0], datos[indiceI][1]);
	
	// ----------------- pregunta 4 ----------------
	
	FILE *nuevo = fopen("salida.txt", "w");
	fprintf(nuevo, "%d\n", numFilas);
	for (int i = 0; i < numFilas; i++){
		int suma = datos[i][0] + datos[i][1];
		fprintf(nuevo, "%d + %d = %d \n" , datos[i][0], datos[i][1], suma);
	}
	fclose(nuevo);
	
	// liberar memoria de **datos
	for (int i = 0; i < numFilas; i++){
		free(datos[i]);
	}
	free(datos);
	
	return 0;
}

int **obtenerDatos(char *nombreArch){
	// se lee el archivo, se retorna NULL si no se puede abrir
	FILE *archivo = fopen(nombreArch, "r");
	if (archivo == NULL){
		printf("no se pudo abrir el archivo\n");
		return NULL;
	}
	int numFilas;
	fscanf(archivo, "%d", &numFilas);
	
	// se asigna memoria para guardar los datos
	int **datos = crearMatriz(numFilas, 2);
	int dato;
	// se guarda cada dato en su posicion correspondiente
	for(int i = 0; i < numFilas; i++){
		for (int j = 0; j < 2; j++){
			fscanf(archivo, "%d", &dato);
			datos[i][j] = dato;
		}
	}
	fclose(archivo);
	// se devuelve el puntero hacia los datos leidos
	return datos;
}

int **crearMatriz(int fila, int columna){
	// se pide memeoria para guardar datos, se retorna NULL si 
	// no hay suficiente memoria
	int **matriz = (int **)malloc(sizeof(int *) * fila);
	if (matriz == NULL){
		return NULL;
	}
	for (int i = 0; i< fila; i++){
		matriz[i] = (int *) malloc(sizeof(int) * columna);
		if (matriz[i] == NULL){
			return NULL;
		}	
	}
	
	return matriz;
}

void imprimirMatriz(int **datos, int numFilas){
	// funcion para debug 
	for (int i = 0; i< numFilas; i++){
		for (int j = 0; j < 2; j++){
			printf("%d ", datos[i][j]);
		}
	printf("\n");
	
	}
}