#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

// prototipos
void agregar_pila(Nodo *&, int);
int remover_pila(Nodo *&);

int main(){
	Nodo *lista = NULL;

	agregar_pila(lista, 3);
	agregar_pila(lista, 1);
	agregar_pila(lista, 9);

	cout << "Lista: ";
	while(lista != NULL){
		cout << remover_pila(lista) << " ";
	}
	cout << endl;
	
	return 0;
}

// funciones
int remover_pila(Nodo *&lista){
	Nodo *aux = lista;
	int dato = aux->dato;
	lista = aux->siguiente;

	delete aux;
	return dato;
}

void agregar_pila(Nodo *&lista, int dato){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = lista;
	
	lista = nuevo_nodo;
}
