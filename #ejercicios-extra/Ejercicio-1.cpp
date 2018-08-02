#include <iostream>
#include <cstdio>

using namespace std;

// prototipos
void ordenar_arr(int [], int);
void ordenar_insercion(int [], int);
int buscar_elemento(int [], int, int);
void imprimir_arr(int [], int);
void insertar_elemento(int [], int &, int);

int main(){
	int arr[] = {5,8,3,1,2};
	int longitud = 5;
	int numero_ingresar;
	int numero_posicion;
	
	cout << "Lista original: " << endl;
	imprimir_arr(arr, longitud);

	// Ordenar
	//ordenar_arr(arr, longitud);
	ordenar_insercion(arr, longitud);
	
	cout << "Lista ordenada: " << endl;
	imprimir_arr(arr, longitud);
	/*
	// Buscar
	cout << "Ingrese el numero que desea buscar: ";
	cin >> numero_ingresar;
	numero_posicion = buscar_elemento(arr, longitud, numero_ingresar);
	
	if(numero_posicion == -1)
		cout << "No se encontró el número" << endl;
	else
		cout << "La posición de número es: " << numero_posicion << endl;
	
	// Insertar
	cout << "Ingrese el numero que desea agregar: ";
	cin >> numero_ingresar;
	
	insertar_elemento(arr, longitud, numero_ingresar);
	
	cout << "Lista modificada: " << endl;
	imprimir_arr(arr, longitud);
	*/
	return 0;
}

// Funciones
void ordenar_insercion(int arr[], int longitud){
	// 5,8,3,1,2
	int key;
	
	for(int i=0; i < longitud; i++){
		key = arr[i];
		
		while(){
			if(key < arr[i+1]){
				
			}
		}
	} 
}

void insertar_elemento(int arr[], int &longitud, int numero_ingresar){
	//
	// ALGORITMO: "CARGAR SIN REPETIR"
	//

	// El parametro "longitud" se agrega por referencia, para poder
	// modificarlo. Al agregar un elemento a la lista, esta incrementará su tamaño en +1.
	// Sino se agregara el &, sólo cambiaría el valor dentro de esta función.

	// Busco si el elemento ya se encuentra en la lista
	// para que no se repita
	int numero_posicion = buscar_elemento(arr, longitud, numero_ingresar);
	int posicion_inicial = 0;
	int posicion_final = (longitud - 1);
	// Sino se encuentra en el listado, la función "buscar_elemento()" retorna -1
	if(numero_posicion == -1){		
		for(int i=posicion_final;i >= posicion_inicial;i--){
			arr[i+1] = arr[i];
		}

		arr[posicion_inicial] = numero_ingresar;
				
		longitud++; // Incremento el tamaño de la lista en +1, porque habra un nuevo elemento
	}
		
}

int buscar_elemento(int arr[], int longitud, int numero_ingresar){
	//
	// ALGORITMO: "BUSQUEDA BINARIA"
	//
	
	// 1. Defino variables
	bool encontrado = false;
	int posicion_inicial;
	int posicion_central;
	int posicion_final;

	posicion_inicial = 0;
	// Se resta 1 al numero total de elementos
	// para obtener la posición del ultimo elemento
	// Ej.: Si tengo 3 elementos {1,2,3} entonces resto 3-1=2, y
	// obtengo que el ultimo elemento que es el 3, tiene posición 2.
	posicion_final = (longitud-1);
	
	// Determino el elemento que se ubica en el centro de todos
	// Ej. Si tengo 4 elementos{1,2,3,4}, el elemento central (se determina
	// con la suma de la posicion inicial y final dividido 2) entonces
	// ((0+4)/2)=2, 2 es la posicion central (no se confundan con el elemento
	// que tiene valor 2). El elemento 3 está en la posición 2.
	// Las posiciones van del 0 a la cantidad de elementos menos 1.
	posicion_central = ((posicion_inicial + posicion_final) / 2);
	
	// NOTA:
	// Para que los condicionales funcionen, la lista de elementos
	// debe estar ordenada (puede ser de manera ascendente/descendente)
	while(posicion_inicial <= posicion_final && !encontrado){
		posicion_central = ((posicion_inicial + posicion_final) / 2);
	
		if(numero_ingresar == arr[posicion_central]){
			encontrado = true;
		}

		// Si el numero ingresado es menor al que está en el medio de la lista
		else if(numero_ingresar < arr[posicion_central]){
			// Acorto el rango de busqueda, utilizando la posición del elemento
			// del medio que es mayor al que se busca, como posición final.
			// Se le resta 1 a esa posición, porque ese número no está incluido.
			posicion_final = (posicion_central - 1);
		}
		// Si el número ingresado es mayor al que está en el medio de la lista
		else if(numero_ingresar > arr[posicion_central]){
			// 1,2,3,4,5
			// Acorto la busqueda, utilizando como posición inicial la posición
			// del elemento del medio.
			// Se le suma 1 a la posicion, porque ese numero del medio no está incluido,
			// es a partir del siguiente número en adelante.
			posicion_inicial = (posicion_central + 1);
		}
	} // end while
	
	if(encontrado)
		return posicion_central;
	else
		return -1;
		
}

void ordenar_arr(int arr[], int longitud){
	//
	// ALGORITMO: "ORDENAMIENTO BURBUJA"
	//
	int numero_tmp;
    
	for(int i=0; i < longitud; i++){
		for(int j=0; j < longitud-1; j++){
			if(arr[j] > arr[j+1]){
				numero_tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = numero_tmp;			
			}
		}
	}    
}

void imprimir_arr(int arr[], int longitud){
	for(int i=0; i<longitud; i++){
		cout << arr[i];

		if(i < longitud-1)
			cout << ", ";

	}
	
	cout << endl;
}
