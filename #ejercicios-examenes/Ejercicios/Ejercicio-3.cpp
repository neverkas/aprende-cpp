/*
 * Display. ​Se debe agregar una funcionalidad que permita rotar caracteres de una
 * pantalla monocromática. Cada caracter está conformado por una matriz cuadrada 
 * (16 filas x16 columnas) de booleanos y, según el valor recibido por parámetro, 
 * la función rotará 90, 180 o 270 grados la matriz hacia la derecha.
 *
 * El prototipo de la función es: 
 * void rotar(bool[][], short);
 *
 * Se pide:
 * Implementar la función rotar() contemplando las 3 alternativas. En caso de no recibir
 * ninguno de esos 3 valores, no realizar ningún cambio.
 *
 * Pruebas: Desde la función main() crear, invocar la función mostrar, rotar 90 grados y volver
 * a mostrar la matriz.
*/

#include <iostream>

  using namespace std;

void imprimir(bool[16][16]);
void rotar(bool[16][16], int);

int main() {
	
	bool matrix[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
 
  imprimir(matrix);

  rotar(matrix, 90); // solo 90,180,270,360
  imprimir(matrix);

  rotar(matrix, 180); // solo 90,180,270,360
  imprimir(matrix);

  return 0;
}

void imprimir(bool matrix[16][16]) {
  // filas    
  for (int i = 0; i < 16; i++) {
    // columnas
    for (int j = 0; j < 16; j++) {
			if(matrix[i][j] == 0)
				cout << " ";
			else
				cout << matrix[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void rotar(bool matrix[16][16], int angle) {
  int matrix_aux[16][16] = {0};
  int rotarVeces;
  bool puedeRotar = false; // bandera que determina si rotar o no

  if (angle == 90 || angle == 180 || angle == 270 || angle == 360) {
    rotarVeces = (angle / 90);
    puedeRotar = true;
  }

  if (puedeRotar) {
    // 'x' determina cuantas veces se gira la matriz
    for (int x = 0; x < rotarVeces; x++) {
      // cada vez que itera 'x' vuelvo a cambiar los valores 
      // de la matriz auxiliar
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
          matrix_aux[i][j] = matrix[i][j];
        }
      }

      // filas    
      for (int i = 0; i < 16; i++) {
        // columnas
        for (int j = 0; j < 16; j++) {
          // Con matrix[i][j] recorro todas las columnas de cada fila
          // En el segundo for 'j' representa todas las columnas de c/fila
          // mientras que 'i' se mantiene fija.
          // Ej. i=0, j=0,j=1,j=2,j=3, ..
          // Ej. i=1, j=0,j=1,j=2,j=3, .. 
          //
          // Con matrix[j][15-i] recorro todos las filas de cada columna
          // 'j' representa cada fila de una columna
          // [15-i] toma las columnas de derecha a izquierda
          // La primera fila => cuarta columna
          // La segunda fila => tercera columna
          // La tercera fila => segunda columna
          // La cuarta fila => primera columna
          matrix[i][j] = matrix_aux[j][15 - i];
        }
      }
    }
  }
}
