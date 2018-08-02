/*
1. Encuesta. Se deben registrar los resultados de una encuesta a clientes de una librería. El
encuestador carga la cantidad de libros que los clientes dicen leer durante un año y el sistema
registra en un array de 20 elementos la respuesta según el siguiente criterio: Más de 10 libros
Asiduo (A), Entre 3 y 10 libros Frecuente (F) y por debajo de 3 Ocasional (O). Siempre se trabaja de
a 20 encuestas por informe.
Se pide: Crear un programa que permita cargar la cantidad de libros leídos por cliente por pantalla y
muestre, también por pantalla, cuántos se registraron de cada categoría. Modularizar mediante
subprogramas para que desde una función principal se invoque a una específica para cargar datos y
a otra para obtener el informe
*/
#include <iostream>
#include <cstdio>

using namespace std;

// variables globales
const int CANTIDAD_ELEMENTOS = 10;
// prototipos
void cargar_datos(char []);
void obtener_informe(char []);

int main(){
	char arr[CANTIDAD_ELEMENTOS];

	cargar_datos(arr);
	obtener_informe(arr);
	
	return 0;
}

/*
El encuestador carga la cantidad de libros que los clientes dicen leer durante un año y el sistema
registra en un array de 20 elementos la respuesta según el siguiente criterio: 
*/
void cargar_datos(char arr[]){
	int cantidad;
	
	// Siempre se trabaja de a 20 encuestas por informe.
	for(int i=0; i < CANTIDAD_ELEMENTOS; i++){
		cout << "Cantidad de libros: ";
		cin >> cantidad;
		
		// Más de 10 libros Asiduo (A)
		if(cantidad > 10)
			arr[i] = 'A';
		// Entre 3 y 10 libros Frecuente (F)
		else if(cantidad > 3 && cantidad < 10)
			arr[i] = 'F';
		// por debajo de 3 Ocasional (O).
		else if(cantidad < 3)
			arr[i] = 'O';
	}
	
}

/*
Se pide: Crear un programa que permita cargar la cantidad de libros leídos por cliente por pantalla y
muestre, también por pantalla, cuántos se registraron de cada categoría. Modularizar mediante
subprogramas para que desde una función principal se invoque a una específica para cargar datos y
a otra para obtener el informe
*/
void obtener_informe(char arr[]){
	int contador_A = 0;
	int contador_F = 0;
	int contador_O = 0;
	char categoria;
	
	for(int i=0; i < CANTIDAD_ELEMENTOS; i++){
		categoria = arr[i];

		if(categoria == 'A')
			contador_A++;
		else if(categoria == 'F')
			contador_F++;
		else if(categoria == 'O')
			contador_O++;
	}

	printf("Categoria A: %i \n", contador_A);
	printf("Categoria F: %i \n", contador_F);
	printf("Categoria O: %i \n", contador_O);
	
}


// funciones
