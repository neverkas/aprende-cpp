/*
 * 
 * Encuesta. Se deben registrar los resultados de una encuesta a clientes de una libreria.
 * El encuestador carga la cantidad de libros que los clientes dicen leer durante un anio y el sistema
 * registra en un array de 20 elementos la respuesta segun el siguiente criterio:
 * -Mas de 10 libros Asiduo (A)
 * -Entre 3 y 10 libros Frecuente (F)
 * -Por debajo de 3 Ocasional (O).
 * 
 * Siempre se trabaja de a 20 encuestas por informe.
 * Se pide: Crear un programa que permita cargar la cantidad de libros leidos por cliente por pantalla y 
 * muestre, tambien por pantalla, cuantos se registraron de cada categoria. Modularizar mediante
 * subprogramas para que desde una funcion principal se invoque a una especifica para cargar datos y a otra para obtener el informe
 * 
*/

#include <iostream>

using namespace std;

//
// # Variables Globales
//
#define CANTIDAD_ELEMENTOS 10

//
// # Prototipos
//
void cargarDatos(char []);
void obtenerInforme(char []);

//
// # Main
//
int main(){
	//
	// # Defino variables
	//
	char listado[CANTIDAD_ELEMENTOS];
	
	//
	// # Entrada de datos
	// # Proceso la informacion	
	//
	cargarDatos(listado);
	
	//
	// # Salida de datos
	//
	obtenerInforme(listado);
	
	return 0;
}

//
// # Funciones
//
void cargarDatos(char listado[]){
	//
	// # Defino variables
	//
	int cantidad;
	
	//
	// # Entrada de datos
	// # Proceso de informacion	
	//
	
	// Itero tantas veces segun 'CANTIDAD_ELEMENTOS'
	for(int i=0; i < CANTIDAD_ELEMENTOS; i++){
		cout << "Cantidad de libros: ";
		cin >> cantidad;
				
		// Segun el valor de 'cantidad' guardo en el vector 'arr'
		// un caracter diferente, categorizo por 'cantidad'		
		// Más de 10 libros Asiduo (A)
		if(cantidad > 10)			
			listado[i] = 'A';
		// Entre 3 y 10 libros Frecuente (F)
		else if(cantidad > 3 && cantidad < 10)
			listado[i] = 'F';
		// por debajo de 3 Ocasional (O).
		else if(cantidad < 3)
			listado[i] = 'O';
	}
	
}

void obtenerInforme(char listado[]){
	//
	// # Defino variables
	//
	// Preestablezco los contadores a cero, para luego incrementar su valor
	int contador_A = 0, contador_F = 0, contador_O = 0;
	char categoria;
	
	//
	// # Proceso la informacion	
	//
	// Itero tantas veces segun 'CANTIDAD_ELEMENTOS'
	for(int i=0; i < CANTIDAD_ELEMENTOS; i++){
		// Asigno a 'categoria' el valor de cada elemento del vector 'listado'
		// para una facil interpretacion del codigo
		categoria = listado[i];
		
		// Dependiendo del valor de 'categoria' acumulo +1 en los contadores
		if(categoria == 'A')
			contador_A++;
		else if(categoria == 'F')
			contador_F++;
		else if(categoria == 'O')
			contador_O++;
	}
	
	//
	// # Salida de datos
	//
	cout << "Categoria A: " << contador_A << endl;
	cout << "Categoria F: " << contador_F << endl;
	cout << "Categoria O: " << contador_O << endl;
}
