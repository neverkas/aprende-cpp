/*
 * BUSQUEDA BINARIA PARA VECTORES
 * BINARY SEARCH
 *
 * Exercise 2:
 *
 * Dado un vector {2,3,5,8,10} desarrollar una función que busque
 * al numero n ingresado por teclado
 *
*/

#include <iostream>
#include <cstdio> // printf

using namespace std;

// prototypes
void busqueda_binaria(int numero, int lista[], int cantidad_elementos);

int main(){
	int numeros[] = {2, 3, 5, 8, 10};
	int numero_ingresar;

	cout << "Ingrese un numero: "; cin >> numero_ingresar;
	cout << endl;
	
	busqueda_binaria(numero_ingresar, numeros, 5);
	
	return 0;
}

// functions
void busqueda_binaria(int numero, int lista[], int cantidad_elementos){
	int posicion_inicial = 0;
	int posicion_final = (cantidad_elementos - 1);
	int posicion_central;
	int numero_encontrado;

	bool encontrado = false;

	while(posicion_inicial < posicion_final && encontrado == false){
		posicion_central = ((posicion_inicial + posicion_final) / 2);
		numero_encontrado = lista[posicion_central];

		if(numero == numero_encontrado){
			printf("es (%d == %d) ? %s\n", numero, numero_encontrado, numero == numero_encontrado ? "si" : "no");
			
			encontrado = true;
		}
		else if(numero < numero_encontrado){
			printf("es (%d < %d) ? %s\n", numero, numero_encontrado, numero > numero_encontrado ? "si" : "no");
			
			posicion_final = posicion_central;
			posicion_central = ((posicion_inicial + posicion_final) / 2);
		}
		else if(numero > numero_encontrado){
			printf("es (%d > %d) ? %s\n", numero, numero_encontrado, numero > numero_encontrado ? "si" : "no");
			
			posicion_inicial = posicion_central;
			posicion_central = ((posicion_inicial + posicion_final) / 2);			
		}
		
		posicion_inicial++;
	} // end while

	cout << endl;
	if(encontrado == true)
		printf("El numero %d se encuentra en la posicion %d\n", numero, posicion_central);
	else
		printf("El numero %d no se encuentra en la lista\n", numero);
	
}

