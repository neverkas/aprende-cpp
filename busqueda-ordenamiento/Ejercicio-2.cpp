/*
 * BUSQUEDA BINARIA PARA VECTORES
 * BINARY SEARCH
 *
 * Exercise 2:
 * Dado un vector {2,3,5,8,10} buscar el elemento con valor 2
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){	
	int numeros[] = {2,3,5,8,10};
	int cantidad_numeros = 5;

	int numero_ingresar;

	int numero;
	int posicion_inicial = 0;
	int posicion_final = cantidad_numeros;
	int posicion_central;

	bool encontrado = false;

	int posicion = 0;

	cout << "Ingrese un numero: "; cin >> numero_ingresar;
	cout << endl;
	//numero_ingresar = 2;
	// {2,3,5,8,10}	
	while(posicion < cantidad_numeros && encontrado == false){
		// ((0+5) / 2) = 2.5 (redondear a 2)
		posicion_central = ((posicion_inicial + posicion_final) / 2);

		// 1) Obtengo el valor del elemento que está en el medio
		//
		// numero = numeros[2]
		// numero = 5;
		numero = numeros[posicion_central];

		// Info adicional		
		cout << "Posicion Inicial: " << posicion_inicial << endl;
	  cout << "Posicion Final: " << posicion_final << endl;
		cout << "Posicion Central: " << posicion_central << endl;
		cout << "Numero encontrado: " << numero << endl;
		cout << "************************" << endl;

		// 2) Comparo
		//			cout << "Es menor" << endl;

		// 2.1) Si son iguales
		// x == 5
		// si x=5, entonces 5 == 5
		if(numero_ingresar == numero){
			encontrado = true;
		}
		// 
		// 2.2) Si es menor
		// x < 5
		// si x=2, entonces (2 < 5)
		// numeros = {2,3}
		else if(numero_ingresar < numero){
			posicion_final = posicion_central;
			posicion_central = ((posicion_inicial + posicion_final) / 2);

			// Info adicional
			printf("si (%d < %d) entonces: \n", numero_ingresar, numero);
		}
		// 
		// 2.3) Si es mayor
		// x > 5
		// si x=10, entonces (10 > 5)
		// numeros = {8, 10}
		else if(numero_ingresar > numero){
			posicion_inicial = posicion_central;
			posicion_central = ((posicion_inicial + posicion_final) / 2);

			// Info adicional
			printf("si (%d >  %d) entonces: \n", numero_ingresar, numero);			
		}
		
		posicion++;
	}

	cout << endl;
	
	if(encontrado == true)
			printf("El número %d se encuentra en la posicion %d \n", numero, posicion_central);			
	else
		printf("El número %d no se encuentra en el lista de numeros \n", numero);
		
	return 0;
}
