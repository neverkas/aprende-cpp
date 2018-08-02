/*
 *
 * Dado 10 valores numéricos, informar cual es el mayor.
 *
*/

#include <iostream>

using namespace std;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int numeroMayor = 0;
	int incremental = 0;
	int numero;
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	for(int i = 0; i < 10; i++){
		cout << "Ingrese un número: ";
		cin >> numero;

		// Si el 'numero' es mayor a 'numeroMayor', entonces		
		if(numero > numeroMayor)
			// reemplazo 'numeroMayor' por 'numero'		
			numeroMayor = numero; 
	} // end for
	
	/*********************************************************************/
	
	//
	// # 3. Salida de datos
	//
	cout << "El mayor número es: " << numeroMayor << endl;
	
	return 0;
}
