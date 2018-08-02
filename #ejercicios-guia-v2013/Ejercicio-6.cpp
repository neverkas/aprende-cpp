/*
 * 
 * Dados tres valores numericos diferentes, indicar:
 * -Cual es el menor
 * -Cual esta en el medio
 * -Cual es el mayor
 * 
*/

#include <iostream>

using namespace std;
/*********************************************************************/

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//	
	int a,b,c;
	int numeroMayor;
	int numeroMedio;
	int numeroMenor;
	
	//
	// # 2. Entrada de datos
	//
	cout << "Se pide que ingrese 3 numeros" << endl;
	cout << "Primer numero: ";
	cin >> a;

	cout << "Segundo numero: ";
	cin >> b;

	cout << "Tercer numero: ";
	cin >> c;

	//
	// # 2. Proceso la información
	//
	// Si el mayor numero es A 
	if((a > b) && (a > c)){
		numeroMayor = a;

		// Solo me quedan 2 numeros a evaluar
		// Determino si B es mayor que C
		if(b > c){
			numeroMenor = c;
			numeroMedio = b;
		}
		else{
			numeroMenor = b;
			numeroMedio = c;
		}
	}
	// Si el mayor es B
	else if((b > a) && (b > c)){
		numeroMayor = b;

		// Solo me quedan 2 numeros a evaluar
		// Determino si A es mayor que C		
		if(a > c){
			numeroMenor = c;
			numeroMedio = a;
		}
		else{
			numeroMenor = c;
			numeroMedio = a;
		}
	}
	// Por descarte
	// Si el mayor es C
	else{
		numeroMayor = c;

		// Solo me quedan 2 numeros a evaluar
		// Determino si A es mayor que B		
		if(a > b){
			numeroMenor = b;
			numeroMedio = a;
		}
		else{
			numeroMenor = a;
			numeroMedio = b;
		}
	}

	//
	// # 3. Salida de datos
	//
	cout << "El mayor numero es: " << numeroMayor << endl;
	cout << "El numero medio es: " << numeroMedio << endl;
	cout << "El menor numero es: " << numeroMenor << endl;
	
	return 0;
}
