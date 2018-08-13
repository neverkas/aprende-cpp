/*
* INTERCAMBIAR DIRECCION DE MEMORIA
*
* -Un PUNTERO es una variable que almacena la posicion/dirección de memoria
* que ocupa una variable. Esta dirección se guarda con un valor hexadecimal.
*
* -El tipo de variable del puntero, debe ser el mismo que se hace referencia,
* no puede ser diferente.
* Ej.: char letra='a', *letra_dir=&letra;
* Ej.: float precio=50.5, *precio_dir=&precio;
*
* -Para variables de tipo 'int, char, .." se necesita agregar el &
* Ej. int numero = 5, *numero_direccion = &numero;
*
* -Para Arrays se necesita agregar el & delante de la variable del array
* Ej.: int numeros[3] = {1,2,3}, *numeros_direccion = numeros; 
* 
*/
#include <iostream>

using namespace std;

void mostrar_numeros(int *, int);
void intercambiar_direccion(int *, int *);
void intercambiar_direccion_arr(int *, int *, int);
void mostrar_direccion(int, int);

int main(){
	int len;
	//
	// # Prueba 1
	// Mostrar dirección en memoria de cada elemento de un array
	// *numeros_dir es un puntero, que guarda la dirección en memoria de 'numeros'
	// no se utiliza el & porque es un array
	cout<<"Prueba 1:"<<endl;
	int numeros[3] = {1,2,3}, *numeros_dir = numeros;
	len = 3;
	mostrar_numeros(numeros_dir, len);
	
	cout<<"******************************"<<endl; // salto de linea
	
	//
	// # Prueba 2
	// Intercambiar direccion de memoria entre numeros enteros
	// *numero_par_dir, *numero_impar_dir son punteros que guardan la dirección del
	// espacio en memoria de 'numero_par' y 'numero_impar'
	// se utiliza el & porque no son arrays, caso contrario se debe remover el &
	cout<<"Prueba 2:"<<endl;
	int numero_par = 2, *numero_par_dir = &numero_par;
	int numero_impar = 5, *numero_impar_dir = &numero_impar;
	
	mostrar_direccion(numero_par, numero_impar);
	intercambiar_direccion(numero_par_dir, numero_impar_dir);
	mostrar_direccion(numero_par, numero_impar);
	
	cout<<"******************************"<<endl; // salto de linea
	
	//
	// # Prueba 3
	// Intercambiar direccion de memoria entre arrays
	// *numeros_pares_dir y *numeros_impares_dir son punteros que guardan la
	// dirección en memoria de los arrays 'numeros_pares' y 'numeros_impares'
	// como son array no se necesita agregar el & en los punteros,
	// si no fuesen array es necesario agrega el &
	cout<<"Prueba 3:"<<endl;
	int numeros_pares[4] = {2,4,6,8}, *numeros_pares_dir = numeros_pares;
	int numeros_impares[4] = {1,3,5,7}, *numeros_impares_dir = numeros_impares;
	len = 4;
	
	intercambiar_direccion_arr(numeros_pares_dir, numeros_impares_dir, len);
	cout<<"Numeros pares: "<<endl;
	mostrar_numeros(numeros_pares, len);
	cout<<endl; // salto de linea
	cout<<"Numeros impares: "<<endl;
	mostrar_numeros(numeros_impares, len);
	
	return 0;
}

void intercambiar_direccion(int *numero_par, int *numero_impar){
	int aux;

	aux = *numero_par;
	*numero_par = *numero_impar;
	*numero_impar = aux;
}

void intercambiar_direccion_arr(int *numeros_pares, int *numeros_impares, int len){
	int aux;

	for(int i=0; i<len; i++){
		aux = *(numeros_impares+i);
		*(numeros_impares+i) = *(numeros_pares+i);
		*(numeros_pares+i) = aux;
	}
}

void mostrar_direccion(int numero_par, int numero_impar){
	cout<<"numero par: "<<numero_par;
	cout<<", numero impar: "<<numero_impar<<endl;
}

void mostrar_numeros(int *numeros_p, int len){
	for(int i=0; i<len; i++){
		cout << "Numero: " << *numeros_p++;
		cout << "(Espacio en memoria: "<<numeros_p<<")";
		cout << endl;
	}
}

