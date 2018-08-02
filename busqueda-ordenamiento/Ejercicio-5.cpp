/*
 *  ORDENAMIENTO BURBUJA
 * (Se utiliza para la busqueda binaria)
 *
 * Exercise 4:
 * Dado un vector con los elementos desordenados {2,4,5,7,1},
 * desarrollar una función que ordene el vector, y otra que lo muestre.
 *
*/

#include <iostream>

using namespace std;

// prototypes
void ordenar_lista(int [], int);
void mostrar_lista(int [], int);

int main(){
	int numeros[] = {2,4,5,7,1};
	int cantidad_numeros = 5;

	ordenar_lista(numeros, cantidad_numeros);
	mostrar_lista(numeros, cantidad_numeros);

	return 0;
}

// functions
void ordenar_lista(int numeros[], int cantidad_numeros){
	int numero;
	
	for(int i=0; i < cantidad_numeros; i++){
		for(int j=0; j < cantidad_numeros-1; j++){
			
			if(numeros[j] > numeros[j+1]){
				numero = numeros[j];

				numeros[j] = numeros[j+1];
				numeros[j+1] = numero;
			} // end if
			
		} // end for
	} // end for
}

void mostrar_lista(int numeros[], int cantidad_numeros){
	int numero;

	for(int i=0; i < cantidad_numeros; i++){
		numero = numeros[i];
		
		cout << numero;
		
		if(numero <= cantidad_numeros)
			cout << ", ";

	} // end for
	
	cout << endl;
}
