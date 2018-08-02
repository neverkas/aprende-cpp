/*
 * BUSQUEDA BINARIA
 * Version Mejorada
*/

#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

//
// # PROTOTIPOS

int ordenar(int [], int);
int buscar(int [], int, int);
void imprimir(int [], int);

//
// # Prototipos

int main(){
	int longitud = 4;
	int lista[] = {2,4,1,3};
	int numero_ingresar, numero_posicion;
	
  imprimir(lista, longitud);
  ordenar(lista, longitud);
  imprimir(lista, longitud);

	cout << "Ingrese numero a buscar: ";
	cin >> numero_ingresar;
  numero_posicion = buscar(lista, longitud, numero_ingresar);
	
	if(numero_posicion == -1)
		cout<<"El numero ingresado no se encuentra"<<endl;
	else
		cout<<"El numero ingresado se encuentra en la posicion " << numero_posicion <<endl;

	return 0;
}

//
// # FUNCIONES
void imprimir(int lista[], int longitud){
	for(int i=0; i < longitud; i++)
		cout << setw(2) << lista[i];
	cout<<endl;
}

int buscar(int lista[], int longitud, int numero){
    int posicion_inicial, posicion_central, posicion_final;
    bool encontrado = false;
    
    posicion_inicial = 0;
    posicion_final = longitud;
    posicion_central = (posicion_inicial + posicion_final) / 2;
    		
    int contador = 0;
		// Ejecuta mientras encontrado == false y i < 4
		// Deja de iterar si encontrado cambia a 'true'
		// ó el valor de 'i' es mayor a 4
    while(!encontrado && contador < longitud){
        posicion_central = (posicion_inicial + posicion_final) / 2;
        
        if(numero == lista[posicion_central])
            encontrado = true;
        else if(numero < lista[posicion_central])
            posicion_final = posicion_central;
        else if(numero > lista[posicion_central])
            posicion_inicial = posicion_central;

        contador++;
    }

		if(!encontrado){
			return -1;
		}
		else{
			return posicion_central;
		}
}

int ordenar(int lista[], int longitud){
	int pos, aux;
	for(int i=0; i < longitud; i++){
		aux = lista[i];
		pos = i;
		
		while(lista[pos-1] > aux && pos > 0){
			lista[pos] = lista[pos-1];
			pos--;
		}
		/*
		for(pos=i; lista[pos-1]>aux && pos > 0; pos--){
			lista[pos] = lista[pos-1];
		}
		*/
		
		lista[pos] = aux;
	}    
}
