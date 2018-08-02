/*
 * 
 * Dado un valor numerico entero que se ingresa por teclado
 * se pide informar:
 * -La quinta parte de dicho valor
 * -El resto de la division por 5 
 * -La septima parte de la quinta parte
 * 
*/

#include <iostream>
#include <cctype>

/*********************************************************************/


using namespace std;
// Se lo adiciona a std para evitar escribir std::isdigit en cada linea
using std::isdigit;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	char caracter;
	int resto;
	int quintaParte;
	int septimaParte;

	//
	// # 2. Entrada de datos
	//
	cout << "Para finalizar el programa ingrese el caracter '#'" << endl;
	cout << "Ingrese un numero entero: ";
	cin >> caracter;

	//
	// # 3. Proceso la información && Salida de datos
	//
	// La funcion isdigit() solo soporta variables tipo 'char'
	// Si la variable 'caracter' no es ni # ni una letra seguira el loop
		while(isdigit(caracter) && caracter != '#'){
			// Obtengo la quinta parte del numero ingresado
			quintaParte = (caracter / 5);
			// Obtengo el resto del numero dividido por 5
			// para obtener el resto de una divison se utiliza el '%'
			resto = (caracter % 5);
			// Obtengo la septima parte de la quinta parte ya obtenida
			septimaParte= (quintaParte / 7);

			cout << "*La quinta parte de " << caracter << " es " << quintaParte << endl;
			cout << "*El resto de dividir " << caracter << " por 5 es " << resto << endl;
			cout << "*La septima parte de la quinta parte de " << caracter << " es " << septimaParte << endl;

			cout << "****************************" << endl;
			
			// Se repite el ingreso de informacion luego de mostrarla
			// caso contrario aparece una sola vez
			cout << "Ingrese un numero entero: ";
			cin >> caracter;		
		}
	
	return 0;
}
