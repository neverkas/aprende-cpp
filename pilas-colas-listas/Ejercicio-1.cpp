#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo{
    int valor;
    nodo *siguiente;
};

void agregar_pila(nodo *&, int);
int sacar_pila(nodo *&);

int main(){
    nodo *pila = NULL;
    int valor;
    char respuesta; // s/n
    
    do{
        cout << "Desea agregar un nuevo valor? (s/n)";
        cin >> respuesta;
        
        if(respuesta == 's' || respuesta == 'S'){
            cout << "Ingrese el valor: ";
            cin >> valor;
            
            agregar_pila(pila, valor);
        }
    }while(respuesta == 's' || respuesta == 'S');
    
    
    cout << "*************************************" << endl;
    
    cout << "Listado: " << endl;
    while(pila != NULL){
			cout << sacar_pila(pila) << " ";
    } // end while
    cout<<endl;
		
    return 0;
}

// Funciona como los algoritmos de ordenamiento (insercion)
// pero desplaza valores anteriores hacia abajo de la pila
void agregar_pila(nodo *&pila, int valor){
	// reservo espacio en memoria para un nuevo nodo
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->valor = valor;
	// guardo como referencia la pila que estará debajo de esta,
	// quien estuvo antes encima de la pila
	nuevo_nodo->siguiente = pila;
	// guardo en pila el nuevo nodo (que tiene referencia al anterior)
	pila = nuevo_nodo;
}

// Funciona como los algoritmos de ordenamiento (burbuja,insercion,etc)
// guarda un valor en una variable auxiliar para luego reutilizar
int sacar_pila(nodo *&pila){
	// guardo en una variable auxiliar del mismo tipo que 'pila'
	// la variable que luego se borrara de memoria
	nodo *aux = pila;
	// guardo la referencia que tiene de la pila que tiene debajo
	// quien estaba debajo de la que se imprimira y borrara
	pila = aux->siguiente;
	// guardo en otra el valor de la variable auxiliar
	int n = aux->valor;
  // borro la memoria de la pila que se retornara
	// y esta encima de la pila
	delete aux;
	// retorno el valor separado de auxiliar
	return n;
}
