/*
 Display. ​Se debe agregar una funcionalidad que permita rotar caracteres de una pantalla
monocromática. Cada caracter está conformado por una matriz cuadrada (16 filas x 16 columnas) de
booleanos y, según el valor recibido por parámetro, la función rotará 90, 180 o 270 grados la matriz
hacia la derecha. El prototipo de la función es:
void rotar(bool[][], short);
Se pide: Implementar la función rotar() contemplando las 3 alternativas. En caso de no recibir
ninguno de esos 3 valores, no realizar ningún cambio. Ejemplo de rotación 90º:
*/

#include <iostream>
#include <cstdio>

using namespace std;

// defino variables globales
const int MATRIX_DIMENSION = 4;

// prototipos
void rotar(bool [MATRIX_DIMENSION][MATRIX_DIMENSION], short);
void imprimir(bool [MATRIX_DIMENSION][MATRIX_DIMENSION]);

int main(){
	bool matrix[MATRIX_DIMENSION][MATRIX_DIMENSION] = {{1,1,1,1}, {0,1,1,0}, {0,1,1,0}, {0,1,1,0} };

	imprimir(matrix);
	cout << endl;

	rotar(matrix, 90);
	imprimir(matrix);
	
	return 0;
}

// funciones
void rotar(bool matrix[MATRIX_DIMENSION][MATRIX_DIMENSION], short grados){
	int matrix_tmp1[MATRIX_DIMENSION][MATRIX_DIMENSION];
	int matrix_tmp2[MATRIX_DIMENSION][MATRIX_DIMENSION];

	if(grados == 90){
		
		for(int i=0; i<2; i++){			
			matrix[0][0] = matrix[0][3];
			matrix[0][3] = matrix[3][3];
			matrix[3][3] = matrix[3][0];
			matrix[3][0] = matrix[0][0];

			/*
			matrix[0][0] = matrix[0][3];
			matrix[0][3] = matrix[3][3];
			matrix[3][3] = matrix[3][0];
			matrix[3][0] = matrix[0][0];
			*/
	}
	
}

void imprimir(bool matrix[MATRIX_DIMENSION][MATRIX_DIMENSION]){
	for(int i=0; i<MATRIX_DIMENSION; i++){ // filas
		for(int j=0; j<MATRIX_DIMENSION; j++){ // columnas
			printf("%i ", matrix[i][j]);
			//printf("%i[%i][%i] ", matrix[i][j], i, j);
		}
		
		cout << endl; // salto de linea por fila
	}
}
