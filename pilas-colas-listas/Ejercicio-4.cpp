#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

// prototipos
void agregar(Nodo *&, Nodo *&, int);
int quitar(Nodo *&, Nodo *&);

// main
int main(){
	Nodo *frente = NULL;
	Nodo *cola = NULL;
	int n;

	do{
		cout << "Ingrese un numero: ";
		cin >> n;
		agregar(frente, cola, n);
		cout << endl;
	}while(n != -1);
	cout << endl;

	while(frente != NULL){
		cout << quitar(frente, cola) << " ";
	}
	cout << endl;
	
	return 0;
}

// funciones
void agregar(Nodo *&frente, Nodo *&cola, int dato){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = NULL;

	if(frente == NULL){
		frente = nuevo_nodo;
	}else{
		cola->siguiente = nuevo_nodo;
	}
	
	cola = nuevo_nodo; // Esto no pisa cola->siguiente ??
}

int quitar(Nodo *&frente, Nodo *&cola){
	Nodo *aux = frente;
	int dato = aux->dato;

	if(frente == cola){
		frente = NULL;
		cola = NULL;
	}else{
		// Porque no cola->siguiente? si en agregar() los agrego ahi
		frente = frente->siguiente;
	}

	delete aux;
	return dato;
}
