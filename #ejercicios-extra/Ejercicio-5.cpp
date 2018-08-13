/*
 * 
 * Crear un programa modularizado en funciones especificas para:
 * a) Ingresar el importe de 10 ventas en un array.
 * b) Calcular y mostrar la suma y el promedio de todos sus elementos.
 * c) Encontrar el elemento con el importe mayor (y retornarlo).
 * La funcion main() debe crear el array de ventas e invocar a las funciones
 * especificas pasando el array como parametro. Por ultimo, desde esa misma
 * funcion se debera mostrar la cifra de la venta mas alta
 * 
 * Incorporar al programa la funcion busquedaSec() y modificarla de
 * forma tal que:
 * 	-Sea compatible con el tipo de dato
 *	-Acepte un margen de tolerancia
 *  Tanto la cifra objetivo como el valor de tolerancia seran ingresados por el usuario
 * una vez cargados los 10 importes de ventas. Finalmente el programa debera
 * mostrar por consola:
 * A) Suma y promedio de todos sus elementos.
 * B) El importe mas alto.
 * C) El indice del primer elemento del array que este dentro del rango objetivo.
 *  
 */
#include <iostream>

using namespace std;

//
// # Variables globales
//
#define CANTIDAD_VENTAS 3

//
// # Prototipos
//
void ingresarVentas(int [], int);
void calcularVentas(int [], int);
int calcularMayorImporte(int [], int);
int busquedaSecuencial(int, int, int []);

/**********************************************************************************/

//
// # Main
//
int main(){
	//
	// # Defino Variables
	//
	int ventas[CANTIDAD_VENTAS];
	int objetivo, tolerancia, posicion, importe;
    
    /***************************************************************/
    
    //
    // # Entrada de Datos
    //
	ingresarVentas(ventas, CANTIDAD_VENTAS);
	
	cout << "Objetivo: ";
	cin >> objetivo;
	
	cout << "Tolerancia: ";
	cin >> tolerancia;
    
    /***************************************************************/
    
    //	
    // # Proceso de informacion
    //
	importe = calcularMayorImporte(ventas, CANTIDAD_VENTAS);
	posicion = busquedaSecuencial(objetivo, tolerancia, ventas);

    /***************************************************************/
    
    //
    // # Salida de Datos
    //
    cout << endl;
    
	calcularVentas(ventas, CANTIDAD_VENTAS);
	
	cout << "El mayor importe es: " << importe << endl;

	if(posicion != -1)
    	cout << "La posicion de la Busqueda secuencial es " << posicion;
	else
	    cout << "El dato ingresado no ha sido encontrado.";
	
	cout << endl;
	
	return 0;
}

/**********************************************************************************/

//
// # Funciones
//
int busquedaSecuencial(int objetivo, int tolerancia, int ventas[]){
	bool encontrado = false; // centinela
	int indice = 0;
	// El bucle while se ejecutara mientras se cumplan las siguientes condiciones:
	// -El incremental 'indice' sea menor al tamanio del vector 'ventas'
	// -El centinela 'encontrado' sea 'false'
	while(indice < CANTIDAD_VENTAS && !encontrado){
	    // Ej.
	    // ventas: 300, 400, 500, 600
	    // objetivo: 300
	    // tolerencia: 100
	    // 300>200 && 300<400

	    // Recorro los elementos del vector 'ventas'
	    // analizo si el elemento esta entre un rango fijado por objetivo y tolerencia
	    // elemento >= objetivo-tolerencia && elemento <= objetivo+tolerencia
		 if(ventas[indice] >= objetivo - tolerancia && ventas[indice] <= objetivo + tolerancia)
			encontrado = true;
		 else
		 	indice++;
	}
	
	// Si encuentra un elemento entre el rango del condicional retorno su indice (posicion en el arreglo)
	if(encontrado)
		return indice;
	// Sino lo encuentra retorno un -1 
	else
		return -1;
}

void ingresarVentas(int ventas[], int len){
	for(int i=0; i< len; i++){
		cout << "Importe: ";
		cin >> ventas[i];
	}
}

void calcularVentas(int ventas[], int len){
	int suma = 0;
	
	for(int i=0; i < len;i++){
		suma += ventas[i];
	}
	
	cout << "Suma: " << suma << endl;
	cout << "Promedio: " << (suma / CANTIDAD_VENTAS) << endl;
}

int calcularMayorImporte(int ventas[], int len){
	int mayor_numero = 0;
	
	for(int i=0; i < len; i++){
		if(ventas[i] > mayor_numero){
			mayor_numero = ventas[i];
		}
	}
	
	return mayor_numero;
	
}
