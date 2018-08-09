/*
 * 
 * Crear un programa que permita calcular a partir de un solo dato de dimensión en
 * centímetros, el área de: un círculo, un cuadrado, un triángulo (equilátero)
 * Cada cálculo deberá ser ejecutado por funciones sobrecargadas, con las
 * siguientes firmas:
 * float calcularArea (float);
 * float calcularArea (float,float);
 * float calcularArea (char,float,float);
 * Donde el compilador distinguirá a la función que calcula el área del triángulo
 * cuando reciba el símbolo ‘t’ como parámetro. Solicitar el dato por consola, invocar
 * las 3 funciones y mostrar los 3 resultados desde la función principal.
 *   
 * Ejecutar las funciones de cálculo desde un menú de opciones.
 * El menú estará disponible hasta que el usuario seleccione una opción predeterminada para finalizar el programa.
 * También se deberá agregar la función imprimir() que reciba por referencia el
 * resultado del cálculo (tanto enteros como decimales) y por valor la leyenda
 * correspondiente. Está función se deberá invocar inmediatamente luego de realizar
 * el cálculo seleccionado por el usuario
 * 
 */

#include <iostream>
#include <string>

using namespace std;
using std::string;

float calcularArea(float dato){
	return (3.14 * dato);
}

float calcularArea(float dato1, float dato2){
	return (dato1 * dato2);
}

float calcularArea(char dato1, float dato2, float dato3){
		return ((dato1 * dato2) / 2);
}

template <typename t> void imprimir(t &resultado, string figura){
	cout << "El area del " << figura << " es " << resultado << endl;
}

int main(){
	float dato, resultado;
	int opcion;
	string figura;

	cout << "Menu de opciones: " << endl;
	cout << "1: para circulo" << endl;
	cout << "2: para cuadrado" << endl;
	cout << "3: para triangulo" << endl;
	cout << "4: para finalizar" << endl;
	cin >> opcion;		
			
	while(opcion < 4){
		
		cout << "Ingrese el dato: ";
		cin >> dato;
		
		switch(opcion){
			case 1:  // circulo
				resultado = calcularArea(dato);
				figura = "Circulo";
			break;
			case 2:  //cuadrado
				resultado = calcularArea(dato, dato);
				figura = "Cuadrado";
			break;
			case 3:  //triangulo
				resultado = calcularArea('t', dato, dato);
				figura = "Triangulo";
			break;
		}
		
		imprimir <float> (resultado, figura);

		cout << "Menu de opciones: " << endl;
		cout << "1: para circulo" << endl;
		cout << "2: para cuadrado" << endl;
		cout << "3: para triangulo" << endl;
		cout << "4: para finalizar" << endl;
		cin >> opcion;		

		
	}
	
	return 0;
}
