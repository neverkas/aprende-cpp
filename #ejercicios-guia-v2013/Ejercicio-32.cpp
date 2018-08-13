/*
 * PENDIENTE
 *
 * Exercise 32a:
 *
 * Desarrollar un programa tal que, dado un valor entero positivo
 * que se ingresa por teclado y que indica la posición de un término
 * dentro de la sucesión de Fibonacci, muestre por consola el valor
 * del término ubicado en dicha posición.
 *
 * Nota: La sucesión de Fibonacci es una serie numérica cuyos primeros
 * dos términos son 1 y los siguientes términos se calculan como la 
 * suma de los dos anteriores.
 * Los primeros términos de la serie son los siguientes:
 * 1,1,2,3,5,8,13,21,34,55,89,...ti, ti+2, ti+(ti+1),...
 *
*/

#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
	cout << setprecision(0) << fixed;
	//cout << "Ingrese un numero: "; cin >> numero;
	/*
		resultado = numero1+numero2
		resultado = numero2+resultado
		resultado = numero2+resultado
		resultado = numero2+resultado

		2  = 1+1
		3  = 1+2
		5  = 2+3
		8  = 3+5
		13 = 5+8
		21 = 8+13

  1,1,2,3,5,8,13,21,34,55,89,...ti, ti+2, ti+(ti+1),...

	*/		
	int resultado = 1;
	int numero_anterior;
	int suma = 0;
	
	for(int i=1; i<10; i++){
		numero_anterior = resultado;
		
		resultado += i;

		suma = numero_anterior + i;
		
		printf("%d - %d - %d - %d \n", i, numero_anterior, resultado, suma);
	}

	return 0;
}
