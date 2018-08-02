/*
 *
 * Dada una serie de m pares (color, número) que corresponden a los tiros 
 * de una ruleta. Se pide informar:
 * -Cuantas veces salió el número 0 y, por cada 0, cual fue el número anterior.
 * -Cuantas veces seguidas llegó a repetirse el color negro.
 * -Cuantas veces seguidas llegó a repetirse el mismo número y cual fue.
 * -El mayor numero de veces seguidas que salieron alternados los colores rojo y negro
 * -El mayor numero de veces seguidas que se negó la segunda docena
 * Nota: Recuerde que la ruleta tiene números comprendidos entre 0 y 36.
 * "Negar la segunda docena" significa que el número en cuestion no esta comprendido
 * entre 12 y 23.
 *
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;
using std::string;

//
// # Main
//
int main(){
	srand(time(NULL));

	//
	// # 1. Defino las variables
	//
	int numero_anterior;
	char color_anterior;
	
	int ingresar_mpares;
	
	int contador_color_negro = 0;
	int contador_colores_alternados = 0;
	int contador_segunda_docena = 0;

	char lista_colores[] = {'N', 'R'};	

	int lista_numeros_repetidos[36];
  int lista_numeros_repetidos_length;
	int numero_veces_repetidas;
	
	int cero_numeros_anteriores[36];
	int cero_numeros_anteriores_length;
	int cero_numeros_anteriores_numero;
	bool hay_numeros_repetidos = false;
	
	int	contador = 0;
	
	int numero_aleatorio;
	char color_aleatorio;
	string color_elegido;
	
	/*********************************************************************/
	
	//
	// # 2. Entrada de datos && Proceso la información && Salida de datos
	//
	
	// Determino cantidad de elementos del array 'lista_numeros_repetidos'
	lista_numeros_repetidos_length = sizeof(lista_numeros_repetidos);
	lista_numeros_repetidos_length /= sizeof(lista_numeros_repetidos[0]);

	// Preasigno valor cero a todos, para luego comparar
	for(int i=0; i < lista_numeros_repetidos_length; i++){
		lista_numeros_repetidos[i] = 0;
		cero_numeros_anteriores[i] = 0;
	}

	cout << "Cantidad de tiros: ";
	cin >> ingresar_mpares;

	while(contador < ingresar_mpares){
		contador++;

		//  Generar número aleatorio de 0 a 36
		numero_aleatorio = (rand() % 36 + 1);
		
		if(numero_aleatorio > 0)
			numero_anterior = numero_aleatorio;
		// Si el número es igual a cero,
		else if(numero_aleatorio == 0){
			// Agrego al array 'cero_numeros_anteriores' el numero anterior al cero
			//cero_numeros_anteriores[contador] = numero_aleatorio;			
		}

		// Acumulo en el indice del array 'lista_numeros_repetidos'
		// las veces que se repite el numero
		lista_numeros_repetidos[numero_aleatorio] += 1;

		// Genero un número aleatorio entre 0 y 1
		// lo utilizo como indice para elegir un elemento del array 'lista_colores'
		color_aleatorio = lista_colores[(rand() % 2)]; // numeros aleatorios del 0 al 1		
		
		// Utilizo el valor tipo 'char' y lo paso a string
		switch(color_aleatorio){
		case 'R':
			color_elegido = "Rojo";
			break;
		case 'N':
			color_elegido = "Negro";
			break;
		} // end case

		// Imprimo en pantalla cada tiro de la ruleta 
		// con formato (color, numero)
		cout <<"("<<color_elegido<<", "<<numero_aleatorio<<")"<< endl;

		// Si el color es Negro, acumulo +1 en 'contador_color_negro'
		if(color_aleatorio == 'N')
			contador_color_negro+=1;

		// Si el número aleatorio no está entre el 12 y 23
		// acumulo +1 en 'contador_segunda_docena'
		if((numero_aleatorio < 12) || (numero_aleatorio > 23))
			contador_segunda_docena+=1;
	} // end while
	cout << '\n'; // new line

	cout << "Veces que se repite el cero: " << lista_numeros_repetidos[0] << endl;

	cout << "Numeros anteriores al cero: ";
	for(int i=0; i < lista_numeros_repetidos_length ; i++){
		cero_numeros_anteriores_numero = cero_numeros_anteriores[i];
		
		if(cero_numeros_anteriores_numero != 0)
			cout << cero_numeros_anteriores_numero << ",";
	}
	cout << '\n'; // new line

	cout << "Veces que se repite el color negro: " << contador_color_negro << endl;
	cout << "Veces que se nego la segunda docena: " << contador_segunda_docena << endl;
	
	cout << "Numeros repetidos: ";
	// Recorro la lista de numeros repetidos
	for(int i = 0; i < lista_numeros_repetidos_length; i++){
		// Guardo la cantidad de veces que se repite
		numero_veces_repetidas = lista_numeros_repetidos[i];		

		// Si se repite más de 1 vez 
		if(numero_veces_repetidas > 1){
			// Asigno 'true' para agregar el salto de linea al final
			hay_numeros_repetidos = true;

			// Muestro el número y la cantidad de veces
			cout << '\n'; // new line
			cout << "*El numero " << i << ": ";
			cout << numero_veces_repetidas << " veces";
		} // end if
		
	} // end for
	
	if(hay_numeros_repetidos == false)
		cout << "Ninguno" << endl;
	else
		cout << '\n'; // new line
	
	return 0;
}
