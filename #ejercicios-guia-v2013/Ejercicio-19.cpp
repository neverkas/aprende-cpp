/*
 *
 * Dado un valor numérico entero m, determinar e imprimir
 * un listado con los m primeros múltiplos de 3
 * y que no sean múltiplos de 5
 *
 * # Tips:
 * El multiplo de un número, es el producto de ese número por otro entero.
 * (Ej. Multiplos de 3 son 6,9,12 porque 3*2=6, 3*3=9, 3*4=12
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
	int m;
	int contadorMultiplos = 0;
	int incremental = 0;

	/*********************************************************************/

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese un numero :";
	cin >> m;

	/*********************************************************************/

	//
	// # 3. Proceso la información && Salida de datos
	//
	// Verifico que 'm' no sea un entero negativo
	// si lo es, no permite continuar
	while(m < 1){
		cout << "Ingrese un numero :";
		cin >> m;
	}

	// El bucle iterara tantas veces mientras se cumpla
	// la condición. Se detendrá cuando 'contadorMultiplos'
	// sea igual al valor ingresado 'm'
	
	while(contadorMultiplos < m){
		// Incremento de 3 en 3, ya que son los multiplos de 3
		// Otra manera de hacerlo seria multiplicando el
		// 'contadorMultiplos' por 3
		incremental+=3;

		// Verifico que 'incremental' no sea multiplo de 5
		// Si la división entre 'incremental' por 5,
		// no da como resto cero, entonces no es multiplo de 5.
		if(incremental % 5 != 0){
			// Si se cumple, acumulo +1 en 'contadorMultiplos'
			contadorMultiplos++;
			cout << incremental << endl;
		}		
	} // end while
	
	return 0;
}
