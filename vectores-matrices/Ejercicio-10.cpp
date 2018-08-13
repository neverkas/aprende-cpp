/*
// 3x2 = Matriz rectangular de 3 filas, 2 columnas
A= {1,2,3}, B={3,4}

// El cardinal de un conjunto dice la cantidad de elementos que tiene
// El producto cartesiano son las posibles combinaciones entre ambos conjuntos
|A|=3 , |B|= 2, |A|x|B|=6

AxB={{1,3}, {1,4}, {2,3}, {2,4}, {3,3}, {3,4}} // 6 posibles combinaciones

R={{1,3},{1,4}}

Matriz - Matriz transpuesta
1 0				0 1
0 1				1 0
0 0				1 1
*/
#include <iostream>
#include <cstdio> // printf

using namespace std;

void generar_producto_cartesiano(int [], int [], int, int, int [3][2]);
void imprimir_matriz(int [3][2], int, int);

int main(){
	int matriz[3][2] = {0};

	// Conjuntos
	int A[] = {1, 2, 3};
	int B[] = {3, 4};

	// Cardinales
	int A_cardinal = (sizeof(A) / sizeof(A[0])); // 3
	int B_cardinal = (sizeof(B) / sizeof(B[0])); // 2

	// Producto Cartesiano AxB
	int producto_cartesiano[3][2] = {0};

	// Relaciones
	int R1[2][2] = {{1,3}, {1,4}}; // R[0][0], R[0][1], R[1][0], R[1][1]
	int R2[2][2] = {{2,3}, {3,3}}; // R[0][0], R[0][1], R[1][0], R[1][1]

	generar_producto_cartesiano(A, B, A_cardinal, B_cardinal, producto_cartesiano);

	cout << "\n";
	
	imprimir_matriz(matriz, A_cardinal, B_cardinal);
	//int producto_cartesiano[6] = {{1,3}, {1,4}, {2,3}, {2,4}, {3,3}, {3,4}};
	
	return 0;
}

void imprimir_matriz(int matriz[3][2], int A_cardinal,int B_cardinal){
	cout << "Matriz: \n";
	for(int i=0; i < A_cardinal; i++){
		for(int j=0; j < B_cardinal; j++){
			printf("(%d) %d %d \n",matriz[i][j],i,j);
			}
	}
	
	cout << "\n";
}

void generar_producto_cartesiano(int A[],int B[],int A_cardinal,int B_cardinal, int producto_cartesiano[3][2]){
	cout << "Producto Cartesiano AxB: \n";
	for(int i=0; i < A_cardinal; i++){
		for(int j=0; j < B_cardinal; j++){
			for(int z=0; z < 2; z++){
				printf("{%d, %d}, ", A[i], B[j],i,j,z);
				
				//printf("(%d, %d) %d %d %d \n", A[i], B[j],i,j,z);
			}
		}
	}
	
	cout << "\n";
}
