/*
 *
 * Sea el conjunto A de valores enteros, descripto más abajo; 
 * se pide calcular e informar lo siguiente:
 * -Cuantos valores 0 hubo
 * -Promedio de valores positivos
 * -La sumatoria de valores negativos
 * 
 * Resolver el ejercicio considerando que:
 * -El conjunto A se compone de 167 valores enteros.
 * -El conjunto A se compone de n valores numéricos, donde el valor
 *  de n debe ser leído previamente.
 * -El conjunto A se compone de varios valores (no se sabe cuantos), 
 *  cuyo ingreso finaliza con la llegada de un valor igual al anterior.
 * -El conjunto A se compone de n valores, pero el proceso deberá
 *  finalizar si se procesan todos los valores o si la cantidad de ceros
 *  supera a cuatro.
 * -El conjunto A se compone de n, pero el proceso deberá finalizar si el
 *  promedio de positivos resulta mayor que seis.
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
	int conjunto_A[167] = {0};
	int conjunto_A_elemento;
	int conjunto_A_elemento_anterior = 0;
	int contador_de_ceros = 0;
	int contador_numeros_positivos = 0;
	int sumatoria_numeros_positivos = 0;
	int sumatoria_numeros_negativos = 0;
	int promedio_numeros_positivos = 0;
	int ingresar_N_elementos;
	int contador = 0;
	bool finalizar_conjunto = false; // bandera
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	cout << "Ingrese cuantos elementos se agregaran al conjunto: ";
	cin >> ingresar_N_elementos;
	
	while(contador < ingresar_N_elementos && finalizar_conjunto == false){
		// Evaluo si es mayor a cero, ya que es igual a cero
		// no se habria agregado ningún elemento nuevo
		if(contador > 0){
			// Obtengo el elemento anterior restandole 1 a 'contador'
			// que establece el indice/posicion de los elementos del Conjunto A
			//
			// Ej. si contador=4, entonces guardará un nuevo elemento en
			// la posicion 4 del conjunto, para obtener su elemento anterior
			// solo le resto 1 a 'contador' y obtengo el valor de la posición 3
			//
			conjunto_A_elemento_anterior = conjunto_A[contador-1];
		} // end if
				
		cout << "Ingresar valor del nuevo elemento: ";
		cin >> conjunto_A_elemento;

		// Si el valor del elemento ingresado es igual a cero
		if(conjunto_A_elemento == 0){
			// Acumulo +1 en el contador de ceros
			// Se reutiliza para la condición de finalizar la ejecución el bucle
			contador_de_ceros++;
			
			// Si la cantidad de ceros ingresados es mayor a 4
			if(contador_de_ceros > 4)
				// Finaliza la ejecucion del bucle while		
				finalizar_conjunto = true;
		} // end if
		
		// Si el valor del elemento ingresado es un número entero negativo
		if(conjunto_A_elemento < 0){
			// Lo sumo a los anteriores valores negativos ingresados
			sumatoria_numeros_negativos += conjunto_A_elemento;
		}
		
		// Si el valor del elemento ingresado es un número entero positivo
		if(conjunto_A_elemento > 0){
			// Acumulo la suma de este con los anteriores si los hubiera
			sumatoria_numeros_positivos+=conjunto_A_elemento;
			// Acumulo en +1 en la cantidad de numeros enteros positivos
			contador_numeros_positivos++;

			// Calculo el promedio de los enteros positivos diviendo la suma total de ellos 
			promedio_numeros_positivos = (sumatoria_numeros_positivos / contador_numeros_positivos);

			// Si el promedio total de los numeros naturales ingresado es mayor a 6			
			if(promedio_numeros_positivos > 6){
				// Finaliza la ejecucion del bucle while		
				finalizar_conjunto = true;
			}
		} // end if
		
		// Si el valor del elemento ingresado es identico al anterior,
		if(contador > 0 && conjunto_A_elemento == conjunto_A_elemento_anterior){
			// Finaliza la ejecucion del bucle while		
			finalizar_conjunto = true; 
		}
		// Agrego nuevo elemento al Conjunto A
		conjunto_A[contador] = conjunto_A_elemento;

		// El incremental va al final del bucle para poder agregar
		// el elemento de indice cero al conjunto A
		contador++;
	} // end while
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "Cantidad de ceros ingresados: " << contador_de_ceros << endl;
	cout << "Promedio de valores positivos: " << promedio_numeros_positivos << endl;
	cout << "Sumatoria de valores negativos: " << sumatoria_numeros_negativos << endl;
	
	return 0;
}
