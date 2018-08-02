/*
 * ARREGLOS DINAMICOS
*/
#include <iostream>
#include <cstdlib> // new && delete
#include <cstdio>

using namespace std;


void agregar(int *, int);
void imprimir(int *, int);
void ordenar(int *, int);

int main(){
	int *notas_listado; // puntero
	int notas_cantidad = 3;	

	// Reservo espacio en memoria para el arreglo 'notas_listado'
	notas_listado = new int[notas_cantidad];
	
	agregar(notas_listado, notas_cantidad);
	imprimir(notas_listado, notas_cantidad);
	
	ordenar(notas_listado, notas_cantidad);
	imprimir(notas_listado, notas_cantidad);

	// Libero memoria del arreglo 'notas_listado' utilizado
	delete [] notas_listado;
	
	return 0;
}

void ordenar(int *listado, int cantidad){
	// Ordenamiento burbuja con punteros
	int aux;
	// 3 4 5 1
	for(int i=0; i<cantidad; i++){
		for(int j=0; j<cantidad-1; j++){			
			if(*(listado+j+1) < *(listado+j)){
				aux = *(listado+j);
				*(listado+j) = *(listado+j+1);
				*(listado+j+1) = aux;
			}
		}
	}
}

void agregar(int *listado,  int cantidad){	
	for(int i=0; i<cantidad; i++){
		cout<<"Nota: ";
		cin>>listado[i];
	}
}

void imprimir(int *listado, int cantidad){
	cout<<"Notas: ";
	for(int i=0; i<cantidad; i++)
		cout << *(listado+i) << " "; 
	//cout << *listado++ << " "; // esta sería otra manera
	cout<<endl;
}
