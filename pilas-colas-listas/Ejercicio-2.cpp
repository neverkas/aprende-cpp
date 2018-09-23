#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregar_cola(Nodo *&, Nodo *&, int);
int remover_cola(Nodo *&, Nodo *&);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	char respuesta;
	
	do{
		cout<<"Desea agregar nuevos datos? (s/n)";
		cin>>respuesta;
		
		if(respuesta == 's' || respuesta == 'S'){
			cout<<"Ingrese un numero: ";
			cin>>dato;
		}
		
		agregar_cola(frente, fin,  dato);
	}while(respuesta == 's' || respuesta == 'S');

	cout << "Listado:" << endl;
	
	while(frente != NULL){
		cout<<"frente: "<<frente->dato;
		cout<<", fin: "<<fin->dato;
		cout<<endl;
		
		cout << remover_cola(frente, fin) << " ";
	}
	cout << endl;

	return 0;
}

void agregar_cola(Nodo *&frente, Nodo *&fin, int dato){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = NULL;

	// no hay elementos
	if(frente == NULL){
		frente = nuevo_nodo;
	}
	// hay mas de un elemento
	else{
		fin->siguiente = nuevo_nodo;
		//fin = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	//fin->siguiente = nuevo_nodo;
}

int remover_cola(Nodo *&frente, Nodo *&fin){
	int dato = frente->dato;
	Nodo *aux = frente;
	
	// Si frente es igual a fin,
	// es porque solo hay 1 elemento
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}

	delete aux;
	return dato;
}
