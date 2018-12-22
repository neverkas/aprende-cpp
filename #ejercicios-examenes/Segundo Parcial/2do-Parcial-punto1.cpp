/*
*
* CALCULADORA
*
* ​ Se necesita validar la sintaxis de las ecuaciones ingresadas. Para ello, se debe
* analizar el equilibrio de los signos agrupadores (), [] y {}. El algoritmo debe agregar a la estructura de
* datos cada vez que encuentre el símbolo abierto, es decir: (, [ o { y evaluar si el siguiente símbolo es
* el​ ​ mismo​ ​ pero​ ​ cerrado,​ ​ o ​ ​ sea:​ ​ ),​ ​ ] ​ ​ o ​ ​ },​ ​ por​ ​ ejemplo:
* Correcto:​ ​ ( ​ ​ )((​ ​ )){([(​ ​ )])}
* Correcto:​ ​ (((​ ​ )((​ ​ )){([(​ ​ )])}))
* Incorrecto:​ ​ )((​ ​ )){([(​ ​ )])}
* Incorrecto:​ ​ ({[​ ​ ])}
* Incorrecto:​ ​ (
* 
* Se​ ​ pide​ :
* Crear la función ​ evaluar() que reciba como parámetro un array de caracteres e itere sus elementos
* evaluando​ ​ si​ ​ existe​ ​ alguna​ ​ inconsistencia.​ ​ Retornará​ ​ true​ ​ si​ ​ es​ ​ correcto.​ ​ Probar​ ​ con:
* entrada1​ ​ = ​ ​ {‘a’,’+’,’b’,’*’,’-’,’[’,’(’,’-1’,’*’,’c’,’)’,’/’,’7’,’]’,’*’,’d’};
* entrada2​ ​ = ​ ​ {'3a','+','{','-5x','-a','+','(','9x','-a','-x',')',']','}'};
* 
*/
#include <iostream>
#include <string.h>

using namespace std;
using std::string;

struct Nodo{
	string dato;
	Nodo *sig;	
};

void push(Nodo *&p, string dato);
string pop(Nodo *&p);
bool evaluar(Nodo *&, string [], int);

int main(){
	Nodo *p = NULL;
    int cantidadCaracteres;
    bool ecuacionValida;

    //
    // # Primera ecuación arimetica a evaluar
    //

    // datos de la ecuación
    string ecuacionArimetica1[] = {"a","+","b","*","-","[","(","-1","*","c",")","/","7","]","*","d"};
    // determino la cantidad de caracteres
    cantidadCaracteres = sizeof(ecuacionArimetica1) / sizeof(ecuacionArimetica1[0]);
    // verifico si los datos son correctos
    ecuacionValida = evaluar(p, ecuacionArimetica1, cantidadCaracteres);

    // imprimo informacion procesada
    cout << "# Ecuacion: " ;
    for(int i=0; i < cantidadCaracteres; i++)
        cout << ecuacionArimetica1[i];
    cout << endl;

    if(!ecuacionValida)
        cout << "La ecuacion arimética ingresada no es válida" << endl;

    /**********************************************************1********************************/

    //
    // # Segunda ecuación arimetica a evaluar
    //
    
    // datos de la ecuación
    string ecuacionArimetica2[] = {"3a","+","{","-5x","-a","+","(","9x","-a","-x",")","]","}"};	
    // determino la cantidad de caracteres
    cantidadCaracteres = sizeof(ecuacionArimetica2) / sizeof(ecuacionArimetica2[0]);
    // verifico si los datos son correctos
    ecuacionValida = evaluar(p, ecuacionArimetica2, cantidadCaracteres);
    
    // imprimo informacion procesada
    cout << "# Ecuacion: " ;
    for(int i=0; i < cantidadCaracteres; i++)
        cout << ecuacionArimetica2[i];
    cout << endl;

    if(!ecuacionValida)
        cout << "La ecuacion arimética ingresada no es válida" << endl;

	return 0;
}

bool evaluar(Nodo *&p, string ecuacionArimetica1[], int len){
	string caracter;
	bool operacionValida = false;
	
    // {"a", "+", "*", "{", "[", ")", "a"}
	for(int i=0; i < len; i++){		
		// si caracter es abierto
		if(ecuacionArimetica1[i] == "{" || ecuacionArimetica1[i] == "[" || ecuacionArimetica1[i] == "(" ){
			// inserto en la pila
			push(p, ecuacionArimetica1[i]);					
		}
		// si caracter es cerrado
		else if(ecuacionArimetica1[i] == "}" || ecuacionArimetica1[i] == "]" || ecuacionArimetica1[i] == ")" ){
            // retorno el ultimo caracter insertado en la pila
            // para comparar con el nuevo a insertar
			caracter = pop(p);

            // verifico si cerró el parentesis            
			if(ecuacionArimetica1[i] == ")" && caracter == "("){
				operacionValida = true;
			}
            // verifico si cerró el corchete
			else if(ecuacionArimetica1[i] == "]" && caracter == "["){
				operacionValida = true;
			}
            // verifico si cerró las llaves
			else if(ecuacionArimetica1[i] == "}" && caracter == "{"){
				operacionValida = true;
			}
            // sino se cumple alguna de las condiciones anteriores
            else{
                return false;
            }
            
		} // end if
	} // end if
	
	return operacionValida;
}


void push(Nodo *&p, string dato){
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
