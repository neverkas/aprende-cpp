/*
 * 
 * Codigo de barras.
 * Un sistema de gestion de logistica debe almacenar en memoria los codigos de
 * barra de los paquetes a medida que son leidos por un scanner. El lider tecnico determino que la
 * mejor estructura para este caso seria una matriz bidimensional que almacene hasta 100 codigos.
 * Como se desea que no haya repeticion de datos, el array tambien almacenara la cantidad de lecturas
 * sobre un mismo codigo, como se muestra en este ejemplo:
 * codigo  cantidad
 * 0001     1
 * 102      3
 * 0        1
 
 * Se pide:
 * Crear la funcion nuevaLectura() que recibira por parametro: la matriz, el valor del indice al
 * proximo elemento y el nuevo codigo a ingresar. Si el array no tiene mas capacidad, debera retornar el
 * valor '-1'. Tambien se debera crear la definicion de la funcion validar() que buscara lecturas erroneas
 * (identificadas con el codigo de valor '0') y en cuyo caso se debera eliminar la fila desplazando las
 * siguientes de modo tal que no queden elementos vacios intermedios (solo podra haber una fila con
 * error). Por ultimo, tambien se pide implementar la funcion ordenar() para ordenar las filas de la
 * matriz ascendentemente por la columna 'cantidad'.
 * 
*/

#include <iostream>
#include <iomanip>

// 
// # Variables Globales
//
#define MATRIZ_FILAS 5
#define MATRIZ_COLUMNAS 2

using namespace std;

//
// # Prototipos
//
int nuevaLectura(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int &, int);
void validar(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int &);
void ordenar(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int);

// Se adicionaron estas dos funciones para modularizar el codigo
void cargarDatos(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int &);
void mostrar(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int);
//
// # Main
//
int main(){
	//
	// # Defino variables
	//
	int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS];
	int indice_ultimo_codigo = 0; // Le asigno cero, porque su valor se ira modificando
		
	//
	// # Entrada de datos
	// # Proceso de informacion
	//
	cargarDatos(matriz, indice_ultimo_codigo);
	ordenar(matriz, indice_ultimo_codigo);

	//
	// # Salida de datos
	//	
	mostrar(matriz, indice_ultimo_codigo);

	return 0;
}

//
// # Funciones
//
void cargarDatos(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int &indice_ultimo_codigo){
	int nuevo_codigo;
	int lectura; // centinela, controla la ejecucion del bucle while
	
	// Segui iterando mientras 'lectura' sea distinto a -1
	while(lectura != -1){
	    cout << "Codigo: ";
	    cin >> nuevo_codigo;
	    
    	lectura = nuevaLectura(matriz, indice_ultimo_codigo, nuevo_codigo);
    	validar(matriz, indice_ultimo_codigo);
	}
	
	cout << endl;
}

void mostrar(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int indice_ultimo_codigo){
	// Utilizo el setw() para generar un espacio entre ambas palabras 
	// para visualizar 2 columnas en la pantalla
	cout << "Codigo" << setw(12) << "Cantidad" << endl;
	
	for(int i=0; i < indice_ultimo_codigo; i++){
	    cout << matriz[i][0] << setw(12) << matriz[i][1] << endl;
	}
}

void ordenar(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int indice_ultimo_codigo){
    int aux;
    
    // Ordenamiento Burbuja
    // Ordeno de forma ascendente por la columna 'cantidad'
    for(int x=0; x < indice_ultimo_codigo; x++){
        for(int fila=0; fila < indice_ultimo_codigo-1; fila++){
            if(matriz[fila][1] > matriz[fila+1][1]){
                for(int columna=0; columna < MATRIZ_COLUMNAS; columna++){
                    aux = matriz[fila][columna];
                    
                    matriz[fila][columna] = matriz[fila+1][columna];
                    matriz[fila+1][columna] = aux;
                } // end for
            } // end if
        } // end for
    } // end for 
}

void validar(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int &indice_ultimo_codigo){
    // Busqueda secuencial
    // Iterar n veces segun el valor 'indice_ultimo_codigo'
    for(int i=0; i < indice_ultimo_codigo; i++){
        // si el valor de la primera columna 'codigo' es igual a cero
        if(matriz[i][0] == 0){
            // recorro desde la ultima fila hasta la fila que cumple la condicion anterior
            // se ejecuta mientras el decremental 'j' sea mayor al indice de la fila actual
            for(int j=indice_ultimo_codigo; j > i; j--){
                // elimino la fila, desplazando las filas que le siguen 
                matriz[i][0] = matriz[i-1][0]; // desplazo la columna 1 de la fila
                matriz[i][1] = matriz[i-1][1]; // desplazo la columna 2 de la fila
            }
            // Por cada fila encontrada decremento el indice del ultimo codigo en 1
            // esto es porque una fila fue eliminada, y ahora hay un elemento menos
            indice_ultimo_codigo--;
        }
    }
}

int nuevaLectura(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int &indice_ultimo_codigo, int nuevo_codigo){
    bool puedeContinuar = true; // bandera
    bool encontrado = false; // centinela

    // Si el indice del ultimo codigo ingresado es igual a la cantidad de filas de la matriz     
    if(indice_ultimo_codigo == MATRIZ_FILAS){
        // no le permito continuar ingresando informacion
        puedeContinuar = false;
    }
    
    // Si se supera la capacidad de la matriz
    if(!puedeContinuar){
        return -1;
    }
    // Si aun se pueden ingresar filas a la matriz entonces
    else{
        // Busqueda secuencial        
        // El bucle for se seguira ejecutando mientras se cumplan las condicones:
        // 1. El incremental 'i' sea menor al valor del indice del ultimo codigo ingresado
        // 2. Que el centinela 'encontrado' sea 'false'
        for(int i=0; i < indice_ultimo_codigo && !encontrado; i++){
            // si el nuevo codigo ingresado ya se encuentra en alguna de las filas
            if(matriz[i][0] == nuevo_codigo){
                // modifico la fila actual incrementando en +1 el valor de la columna 'cantidad'
                matriz[i][1]++;
                // cambio el valor de 'encontrado' para detener la ejecucion del bucle for
                encontrado = true;
            }
        } // end for
        
        // Si el nuevo codigo ingresado no fue encontrado en la busqueda secuencial
        if(!encontrado){
            // Agrego una nueva fila a la matriz con el nuevo codigo
            matriz[indice_ultimo_codigo][0] = nuevo_codigo;
            matriz[indice_ultimo_codigo][1] = 1;
            
            // Por cada vez que se llame a la funcion incremento +1 el valor de 'ultimo_codigo',
            // que se usara para definir cuantos filas se ingresaron a la matriz
            // unicamente si el codigo no se repite
            indice_ultimo_codigo++; 
        }
    } // end if
}
