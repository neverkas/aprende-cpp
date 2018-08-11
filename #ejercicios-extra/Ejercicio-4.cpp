/*
 * 
 * Crear un programa que permita calcular a partir de un solo dato de dimension en
 * centimetros, el area de: un circulo, un cuadrado, un triangulo (equilatero)
 * Cada calculo debera ser ejecutado por funciones sobrecargadas, con las
 * siguientes firmas:
 * float calcularArea (float);
 * float calcularArea (float,float);
 * float calcularArea (char,float,float);
 * Donde el compilador distinguira a la funcion que calcula el area del triangulo
 * cuando reciba el simbolo 't' como parametro. Solicitar el dato por consola, invocar
 * las 3 funciones y mostrar los 3 resultados desde la funcion principal.
 *   
 * Ejecutar las funciones de calculo desde un menu de opciones.
 * El menu estara disponible hasta que el usuario seleccione una opcion predeterminada para finalizar el programa.
 * Tambien se debera agregar la funcion imprimir() que reciba por referencia el
 * resultado del calculo (tanto enteros como decimales) y por valor la leyenda
 * correspondiente. Esta funcion se debera invocar inmediatamente luego de realizar
 * el calculo seleccionado por el usuario
 * 
 */

#include <iostream>
#include <string>

using namespace std;
using std::string;

//
// # Prototipos
//
float calcularArea(float);
float calcularArea(float, float);
float calcularArea(char, float, float);

template <typename t> void imprimir(t &, string);

/******************************************************************************************/

//
// # Main
//
int main(){
    //
    // # Defino Variables
    //
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
		
        //
        // # Entrada de Datos
        //
		cout << "Ingrese el dato: ";
		cin >> dato;
		
        //
        // # Proceso de informacion
        //
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
		
        //
        // # Salida de Datos
        //
		imprimir <float> (resultado, figura);
		
		cin >> opcion;		
	}
	
	return 0;
}

/******************************************************************************************/

//
// # Funciones
//
float calcularArea(float dato){
	return (3.14 * dato);
}

float calcularArea(float dato1, float dato2){
	return (dato1 * dato2);
}

float calcularArea(char dato1, float dato2, float dato3){
		return ((dato1 * dato2) / 2);
}

template <typename t>
void imprimir(t &resultado, string figura){
	cout << "El area del " << figura << " es " << resultado << endl;
}
