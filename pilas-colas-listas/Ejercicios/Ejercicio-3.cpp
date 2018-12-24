/*
*
* Como parte de un equipo desarrollador de un navegador web, le asignaron la
* tarea de crear un programa que de soporte a la funcionalidad “Atrás”.
* El líder técnico le comentó que, como es sabido, la estructura pila es la solución
* estándar y probada para implementar el comportamiento LIFO.
*
* Se pide: Implementar esta funcionalidad para que las direcciones de los sitios
* visitados (URL*) sean guardados en memoria y de forma secuencial, de modo tal
* que siempre se obtengan primero las últimas visitadas.
*
*/
#include <iostream>
#include <stdio.h> // null

using namespace std;

// 
// # Structs
//
struct Nodo{
	string dato;
	Nodo *sig;
};

/******************************************************************************/

// 
// # Prototipos
//

// genericos (no modificar)
int push(Nodo *&, string);
string pop(Nodo *&);
bool empty(Nodo *);
// propios de programa
void navegar(Nodo *&, string);
void atras(Nodo *&);
void volverAtras(Nodo *&);

/******************************************************************************/

// 
// # Main
//
int main(){
    // agrego el primer elemento a la pila que es 'null'
    // para luego chequear el final del listado al utilizar pop()
	Nodo *historial = NULL;
    
    navegar(historial, "http://www.google.com.ar");
    navegar(historial, "http://www.yahoo.com.ar");
    navegar(historial, "http://www.wikipedia.com");    
    cout << endl;
    volverAtras(historial);
	
	return 0;
}

/******************************************************************************/

// 
// # Funciones
//

// genericos (no modificar)
int push(Nodo *&p, string dato){
	Nodo *nuevo = new Nodo();
	nuevo->dato = dato;
	nuevo->sig = p;
	
	p = nuevo;
}

string pop(Nodo *&p){
	Nodo *aux = p;
	string dato = aux->dato;	
	p = aux->sig;
	
	delete aux;		
	
	return dato;
}

bool empty(Nodo *p){	
	return p == NULL;
}

// propios de programa
void atras(Nodo *&p){
    // remuevo elementos de la pila e informo cuales
	cout << pop(p) << endl;
}
void navegar(Nodo *&historial, string url){
    // utilizo la funcion push() de pilas
	push(historial, url);
    cout << "Se accedio a " << url << endl;
}
void volverAtras(Nodo *&historial){
    char respuesta;
    bool finalizar = false; // centinela que controla el loop while

	cout << "Desea volver atras? (s/n) ";
	cin >> respuesta;
	
    // ejecuto el bucle mientras se cumplan las siguientes condiciones
    // 1. la respuesta no sea "no"
    // 2. el historial aun tenga elementos
	while(respuesta != 'n' && !finalizar){
        // si aun hay elementos en historial 
		if(!empty(historial)){
            // vuelvo un sitio atras en el historial
            atras(historial);

            // pregunto si desea volver un sitio atras
			cout << "Desea volver atras? (s/n) ";
			cin >> respuesta;		
		}
        // si no hay mas elementos en el historial
		else{
            if(respuesta != 'n'){
    			cout << "El historial se encuentra vacio." << endl;
            }

            // habilito el centinela que detiene la ejecucion del bucle
            finalizar = true;
            //break;
		}
	}
}