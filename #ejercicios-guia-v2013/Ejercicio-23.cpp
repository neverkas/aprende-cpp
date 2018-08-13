/*
 *
 * Dado un conjunto de valores numéricos que finaliza con el 
 * ingreso de un valor nulo, determinar e imprimir:
 * -El valor máximo negativo.
 * -El valor mínimo positivo.
 * -El valor mínimo dentro del rango -17.3 y 26.9
 * -El promedio de todos los valores ingresados
 * 
*/

#include <iostream>
#include <iomanip>

using namespace std;

//
// # Main
//
int main(){
	cout <<setprecision(2)<<fixed;
	
	//
	// # 1. Defino las variables
	//
	float ingresar_numero;
	float valor_maximo_negativo = 0;
	float valor_minimo_positivo = 0;
	float valor_minimo_rango = 0;
	float promedio_valores_ingresados;
	int contador_ingresos = 0;		
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	cout << "Ingresar numero: ";
	cin >> ingresar_numero;
	
	while(ingresar_numero != 0){		
		promedio_valores_ingresados += ingresar_numero;
		
		if(ingresar_numero != 0){
			// Si el numero es negativo
			if(ingresar_numero < 0){
				if(valor_maximo_negativo == 0)
					valor_maximo_negativo = ingresar_numero;					
				// es mayor negativo cuanto más cerca esta de cero
				else if(ingresar_numero > valor_maximo_negativo)
					valor_maximo_negativo = ingresar_numero;
			} // end if

			// Si el numero es positivo
			if(ingresar_numero > 0){					
				if(valor_minimo_positivo == 0)
					valor_minimo_positivo = ingresar_numero;
				// es menor positivo cuanto más cerca está de cero
				else if(ingresar_numero < valor_minimo_positivo)
					valor_minimo_positivo = ingresar_numero;
			} // end if

			// Si el número está entre -17 y 26
			if(ingresar_numero > -17.3 && ingresar_numero < 26.9){
				if(valor_minimo_rango == 0)
					valor_minimo_rango = ingresar_numero;
				// 
				else if(ingresar_numero < valor_minimo_rango)
					valor_minimo_rango = ingresar_numero;
			} // end if
			
		} // end if
		
		cout << "Ingresar numero: ";
		cin >> ingresar_numero;
		
		contador_ingresos++;
	} // end while

	promedio_valores_ingresados /= contador_ingresos;
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << '\n';
	cout << "Valor maximo negativo: " << valor_maximo_negativo << endl;
	cout << "Valor minimo positivo: " << valor_minimo_positivo << endl;
	cout << "Valor minimo rango: " << valor_minimo_rango << endl;
	cout << "Promedio entre los valores ingresados: " << promedio_valores_ingresados << endl;
		
	return 0;
}
