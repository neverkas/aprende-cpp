/*
 *
 * Definir 2 matrices 2x3 y 3x2 y rellenar con valores aleatorios
 * Multiplicarlas y guardar el resultado en una  tercera matriz.
 * Mostrar las operaciones efectuadas y todas las matrices.
 * 
 * 2 3 1			2 3  		16 14  
 * 2 2 3 =>		3 2  	= 19 16
 *						3 2 
 *
 * MxN * RxN = MxN
 * 2x3 * 3x2 = 2x2
 *
 * [Fila 1][Columna 1] = 2*2 + 3*3 + 1*3 = 16 
 * [Fila 1][Columna 2] = 2*3 + 3*2 + 1*2 = 14
 *
 * [Fila 2][Columna 1] = 2*2 + 2*3 + 3*3 = 19
 * [Fila 2][Columna 2] = 2*3 + 2*2 + 3*2 = 16
 *
 * Si la cantidad de columnas del Matriz A es igual a la cantidad 
 * de filas de la Matriz B, el producto entre ambas da como resultado
 * una tercera matriz. La matriz resultante, tiene la cantidad de filas 
 * de la primera matriz, y de columnas la cantidad de la segunda matriz.
 *
 * Otra manera sería, si los numeros del centro son iguales, entonces 
 * junto los numeros de las puntas.
 *
 * https://es.wikipedia.org/wiki/Multiplicación_de_matrices
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	// 2x3 * 3x2 = 2x2
	int A[2][3] = {{2, 3, 1}, {2, 2, 3}};
	int B[3][2] = {{2, 3}, {3, 2}, {3, 2}};
	int C[2][2] = {0};
	
	cout << "Operaciones realizadas:" << endl;
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int z=0; z<3; z++){
				C[i][j]+=A[i][z]*B[z][j];
				printf("(%d*%d=%d)", A[i][z], B[z][j], A[i][z]*B[z][j]);
				
				if(z<2)
					cout << "+";
				else
					cout << "=" << C[i][j] << endl;
			}
		}		
	}
	
	cout << "\n";

	cout << "Matriz A de 2x3: " << endl;
	
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			cout << A[i][j] << " ";
		}

		cout << "\n";
	}

	cout << "\n";

	cout << "Matriz B de 3x2: " << endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			cout << B[i][j] << " ";
		}

		cout << "\n";
	}
	
	cout << "\n";
	
	cout << "Matriz C de 2x2: " << endl;	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout << C[i][j] << " ";
		}

		cout << "\n";
	}
	
	cout << "\n";

	
	return 0;
}
