/*
*
* HTML
*
* Se precisa validar la sintaxis del código fuente HTML. Para ello se debe analizar el equilibrio de
* las etiquetas. El programa debe evaluar las palabras clave de apertura, es decir: <body>, <center> o <h1>
* y, cuando encuentra una de cierre, evaluar si coincide con la correspondiente, o sea: </h1>, </center> o
*  </body>, por ejemplo:
* Correcto: <body> <center> <h1> </h1> </center> </body>
* Correcto: <body> <center> <h1> Texto del encabezado </h1> </center> </body>
* Incorrecto: <body> <center> </h1> </body>
* Incorrecto: <body> <center> <h1> </center> </center> </body>
* 
* Se pide: Crear la o las estructuras necesarias y la función evaluar() que recibirá como parámetro un array
* de cadenas de caracteres con todas las palabras del archivo html e iterarlo evaluando si existe alguna
* inconsistencia. La función debe retornar true (1) si es válido o false (0) en caso contrario.
* Info: Para comparar cadenas puede usar la función compare() de strings, que retorna 0 cuando coinciden, por ejemplo:
* string curso = “k1025”;
* if(curso.compare("k1025") == 0) cout << “son iguales”;
* 
*/

#include <iostream>

using namespace std;

struct Nodo{
	string etiqueta;
	Nodo *sig;
};

//
// # Prototipos
//
bool evaluar(Nodo *&pila, string etiquetas[], int len);
void push(Nodo *&, string);
string pop(Nodo *&);

//
// # Main
//
int main(){
	bool estado;
    int len; 
    Nodo *pila = NULL; 

	string codigo1[] = {"<body>", "<center>", "<h1>", "</h1>", "</body>"};		
    // obtengo la cantidad de elementos del array
    // divido la cantidad total de elementos por uno de ellos
	len = sizeof(codigo1) / sizeof(codigo1[0]);
	estado = evaluar(pila, codigo1, len);	
	cout << "El estado del codigo 1 es " << estado << endl;

	string codigo2[] = {"<body>", "<center>", "<h1>", "</body>"};		
    // obtengo la cantidad de elementos del array
    // divido la cantidad total de elementos por uno de ellos
	len = sizeof(codigo2) / sizeof(codigo2[0]);
	estado = evaluar(pila, codigo2, len);	
	cout << "El estado del codigo 2 es " << estado << endl;

	return 0;
}

//
// # Funciones
//
void push(Nodo *&pila, string etiqueta){
	Nodo *nuevo = new Nodo();
	nuevo->sig = NULL;
	nuevo->etiqueta = etiqueta;
	
	pila = nuevo;	
}

string pop(Nodo *&pila){
	Nodo *aux = pila;
	// guardo el dato a retorna
	string etiqueta = aux->etiqueta;
	// avanzo la lista al siguiente elemento
	pila = aux->sig;
	// borro de memoria el nodo anterior
	delete aux;
	// retorno el dato obtenido al principio
	return etiqueta;
}

bool evaluar(Nodo *&pila, string arr[], int len){
	// creo la pila el null
	string etiqueta;
	
	for(int i=0; i < len; i++){
		if(arr[i] == "<body>" || arr[i] == "<center>" || arr[i] == "<h1>"){
			push(pila, arr[i]);		
		} // end if
        
		else if(arr[i] == "</body>" || arr[i] == "</center>" || arr[i] == "</h1>"){
			etiqueta = pop(pila);
            
            if(arr[i] == "</body>" && etiqueta != "<body>"){
				return false;
            }
            else if(arr[i] == "</center>" && etiqueta != "<center>"){
				return false;
            }
            else if(arr[i] == "</h1>" && etiqueta != "<h1>"){
				return false;
            }
            else{
				return true;
            }
        } // end if
	} // end for	
}
