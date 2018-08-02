/*
 * 
 * Se dispone de un conjunto de valores enteros positivos que finaliza
 * con el ingreso de un número negativo.
 * El conjunto está dividido en subconjuntos mediante valores 0 (cero).
 * Se pide Desarrollar un programa que determine e informe:
 * -Por cada subconjunto, el promedio de valores que lo componen.
 * -El total de subconjuntos procesados.
 * -El valor máximo del conjunto indicando en que subconjunto se encontró
 *	y su posición relativa dentro del mismo.
 * -El valor mínimo de cada subconjunto.
 * Nota: El lote puede estar vacío (el primer valor ingresado será negativo),
 * o bien puede contener uno, varios o todos los sublotes vacios (ceros consecutivos)
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
	int ingresar_numero;
	int subconjuntos_cantidad=0;
	int numero_menor = 0;
	int numero_mayor = 0;
	int numero_mayor_subconjunto = 0;
	int subconjunto_sumatoria = 0;
	int subconjunto_promedio = 0;
	int contador = 0;

	/*********************************************************************/
	
	//
	// # 2. Entrada de datos && Proceso la información
	//
	cout << "Numero: ";
	cin >> ingresar_numero;

	while(ingresar_numero >= 0){
		if(ingresar_numero > 0){
			contador++;
			subconjunto_sumatoria += ingresar_numero;

			if(numero_menor == 0 || numero_mayor == 0){
				numero_menor = ingresar_numero;
				numero_mayor = ingresar_numero;
			}			
			if(ingresar_numero > numero_mayor){
				numero_mayor = ingresar_numero;
				numero_mayor_subconjunto = subconjuntos_cantidad;
			}
			else if(ingresar_numero < numero_menor)
				numero_menor = ingresar_numero;
		} // end if		
		else if(ingresar_numero == 0){
			subconjuntos_cantidad+=1;
			subconjunto_promedio = (subconjunto_sumatoria / contador);

			cout << "*Menor numero del subconjunto: " << numero_menor << endl;
			cout << "*Promedio del subconjunto: " << subconjunto_promedio << endl;
			cout << "\n";

			//
			contador = 0;
			subconjunto_promedio = 0;
			numero_menor = 0;
		} // end if		
		
		cout << "Numero: ";
		cin >> ingresar_numero;
		
	} // end while
	cout << endl;

	/*********************************************************************/
	
	//
	// # 3. Salida de datos
	//
	cout << "Cantidad de Subconjuntos: " << subconjuntos_cantidad << endl;
	cout << "El mayor numero es del subconjunto " << numero_mayor_subconjunto;
	cout << " y es " << numero_mayor << endl;																			
	
	return 0;
}
