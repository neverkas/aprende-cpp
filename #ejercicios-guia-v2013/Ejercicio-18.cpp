/*
 * 
 * Se ingresa un conjunto de valores reales,
 * cada uno de los cuales representan el sueldo
 * de un empleado, excepto el último valor que será 0
 * para indicar el fin del ingreso de datos.
 * Se pide desarrollar un programa que determine e informe:
 * 1. Cuantos empleados ganan menos de $2.000
 * 2. Cuantos ganan $2.000 o más pero menos de $3.000
 * 3. Cuantos ganan $3.000 o más pero menos de $5.000
 * 4. Cuantos ganan $5.000 o más
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
	
	// Los contadores tienen valor 0,
	// en el caso que se cumpla ninguna de las condiciones,
	// entonces mostrará el valor predeterminado cero.
	float sueldo;
	int contadorSueldoA = 0; // Menos de $2.000
	int contadorSueldoB = 0; // Entre $2.000 y $3.000
	int contadorSueldoC = 0; // Entre $3.000 y $5.000
	int contadorSueldoD = 0; // Más de $5.000
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//

	// Bucle controlado por centinela
	// el centinela será 'sueldo'
	// el bucle seguirá iterando mientras que 'sueldo'
	// sea distinto a cero (Ej. 100,500,300,..)
	// cuando 'sueldo' sea igual a cero, se detendrá.
	while(sueldo != 0){
		// 1. Entrada de datos
		cout << "Ingrese el sueldo: ";
		cin >> sueldo;

		// Si el sueldo es menor a $2.000
		// Se agrega mayor a cero, porque este es
		// el valor del centinela que detiene el bucle.
		if(sueldo > 0 && sueldo < 2000)			
			contadorSueldoA++; // Acumular +1 en el 'contadorSueldoA'
		// Si el sueldo es mayor o igual a $2.000 y menor a $3.000
		else if(sueldo >= 2000 && sueldo < 3000)			
			contadorSueldoB++; // Acumular +1 en el 'contadorSueldoB'
		// Si el sueldo es mayor o igual a $3.000 y menor a $5.000
		else if(sueldo >= 3000 && sueldo < 5000)			
			contadorSueldoC++; // Acumular +1 en el 'contadorSueldoC'
		// Si el sueldo es mayor o igual a $5.000
		else if(sueldo >= 5000)			
			contadorSueldoD++; // Acumular +1 en el 'contadorSueldoD'
	} // end while
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "Cantidad de empleados segun su salario:" << endl;
	cout << "Menos de $2.000: " << contadorSueldoA	<< endl;
	cout << "Entre $2.000 y $2.999: " << contadorSueldoB << endl;
	cout << "Entre $3.000 y $4.999: " << contadorSueldoC << endl;
	cout << "Igual o mas de $5.000 " << contadorSueldoD << endl;

	return 0;
}
