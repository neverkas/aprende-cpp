/*
 * Crear un programa que permita ingresar las ventas mensuales por articulo de las
 * 5 sucursales de una cadena de venta de articulos electronicos (5 articulos).
 * Organizar los datos en una matriz tridimensional y modularizar el programa de
 * forma tal que: exista una funcion principal para declarar la matriz y organizar el
 * flujo del programa, otra para cargar los datos en la estructura y una tercera
 * funcion que permita obtener y mostrar las ventas totales (todos los articulos de
 * todas las sucursales) en un mes. Una vez finalizada la carga de datos, el sistema
 * solicitara el numero de mes a calcular.
 * 
 * Ampliar el programa de forma tal que permita obtener un b ranking
 * de ventas por sucursal para ese mes. El sistema debera mostrar por pantalla un
 * listado con las sucursales y el importe total de ventas ordenado de mayor a
 * menor.
 * 
*/

#include <iostream>
#include <cstdio>

using namespace std;

//
// # Variables Globales
//
const int SUCURSALES = 3; // 5
const int ARTICULOS = 2; // 5
const int MESES = 2; // 12

const int LISTA_COLUMNAS = 2;
//
// # Prototipos
//
void cargarDatos(float [SUCURSALES][ARTICULOS][MESES]);
void calcularImportesPorMes(float [SUCURSALES][ARTICULOS][MESES], float [SUCURSALES][LISTA_COLUMNAS]);
void mostrarDatos(float [SUCURSALES][LISTA_COLUMNAS]);
void ordenar(float [SUCURSALES][LISTA_COLUMNAS]);

//
// # Main
//
int main(){
	float ventas[SUCURSALES][ARTICULOS][MESES];
	float lista[SUCURSALES][LISTA_COLUMNAS];
	// Cargo los importes de articulos por mes de cada sucursal
	cargarDatos(ventas);
	// A partir de la matriz 'ventas' calculo la suma total de los importes 
	// de los articulos de las surcursales de un mes elegido.
	// La funcion 'calcularImportesPorMes' preguntara el mes
	// del cual se sumaran los importes de todos los articulos de cada sucursal,
	// la informacion generada se guarda en la matriz 'lista'
	calcularImportesPorMes(ventas, lista);
	mostrarDatos(lista);
	
	// Ordeno la lista y la vuelvo a mostrar
	ordenar(lista);
	mostrarDatos(lista);
	
	return 0;
}

//
// # Funciones
//
void cargarDatos(float ventas[SUCURSALES][ARTICULOS][MESES]){
    // Recorro las surcursales
	for(int sucursal=0; sucursal < SUCURSALES; sucursal++){
        // Recorro las articulos
		for(int articulo=0; articulo < ARTICULOS; articulo++){
            // Recorro los meses
			for(int mes=0; mes < MESES; mes++){
			    // Como en la matriz los elementos que se guardan 
			    // son representados por su indice que comienza desde cero
			    // le sumo +1
				cout << "Sucursal " << (sucursal + 1);
				cout << ", Articulo " << (articulo + 1);
				cout << " Mes " << (mes + 1);
				cout << endl;
                // Cargo los importes de cada articulo por mes
                // preguntando el importe del mes de cada articulo
				cout << "Cargar importe mensual: "; 
				cin >> ventas[sucursal][articulo][mes];
			}
		}
		cout << endl;
	}
}

void calcularImportesPorMes(float ventas[SUCURSALES][ARTICULOS][MESES], float lista[SUCURSALES][LISTA_COLUMNAS]){
	int mes;
	float sumatoria = 0;
    
    // Pregunto el mes del que quiere que sume el importe
    // de todos los articulos de cada sucursal
	cout << "Mes: ";
	cin >> mes;

	for(int sucursal=0; sucursal < SUCURSALES; sucursal++){
		for(int articulo=0; articulo < ARTICULOS; articulo++){
			// Al mes le resto 1, porque estan ordenados por indice
			sumatoria += ventas[sucursal][articulo][mes-1];
		}
		
        // Guardo en una matriz de 2 columnas, y tantas filas segun la cantidad de sucursales
	    // Le sumo +1 a la sucursal, porque en el vector esta ordenado por indice
        lista[sucursal][0] = (sucursal + 1); // Columna 1
        lista[sucursal][1] = sumatoria; // Columna 2
        
		// Por cada surcursal que recorro inicializo 'sumatoria' a cero 
		// para sumar los importes de cada sucursal por separado
		sumatoria = 0;
	}
}

void mostrarDatos(float lista[SUCURSALES][LISTA_COLUMNAS]){
	// Imprimo la suma total de todos los articulos por mes de cada sucursal
	// informacion que se procesa en el paso anterior
	cout << "LISTA:" << endl;
	
	for(int i=0; i < SUCURSALES; i++){
		cout << "SUCURSAL " << lista[i][0]; // Columna 1
		cout << ", VENTA $" << lista[i][1]; // Columna 2
		cout << endl;
	}
	cout << endl;
	
}

void ordenar(float lista[SUCURSALES][LISTA_COLUMNAS]){
    int importe;
    int aux1, aux2;
    // Ordenamiento Burbuja (el ejercicio exige este)
    for(int i=0; i < SUCURSALES; i++){
        for(int j=0; j < SUCURSALES; j++){
            aux1 = lista[j][0]; // Columna 1, numero de sucursal 
            aux2 = lista[j][1]; // Columna 2, importe total del mes
            
            // Si el importe de esta sucursal es menor 
            // a la que le sigue
            if(lista[j][1] < lista[j + 1][1]){
                // Cambio el orden de los datos
                
                // Intercambio los datos de la primera columna
                lista[j][0] = lista[j + 1][0];
                lista[j + 1][0] = aux1;

                // Intercambio los datos de la segunda columna
                lista[j][1] = lista[j + 1][1];
                lista[j + 1][1] = aux2;
            }
        }
    }
}
