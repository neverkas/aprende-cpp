/*

 * Dada una serie de caracteres que conforman una oración,
 * donde cada palabra está separada de la siguiente por un
 * carácter blanco y la oración finaliza con un punto.
 * Se pide informar:
 * -Cantidad de veces que apareció cada vocal.
 * -Cantidad de palabras que contiene la oración.
 * -Cantidad de letras que posee la palabra más larga.
 * 
*/

#include <iostream>
#include <string>

using namespace std;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	string texto = "Dada una serie de pasos extensos no se continua.";
	char caracter;
	string palabra = "";
	
	int contador = 0;
	int contador_letras = 0;
	int contador_palabras = 0;
	int contador_palabra_mas_larga = 0;

	int contador_vocal_a = 0;
	int contador_vocal_e = 0;
	int contador_vocal_i = 0;
	int contador_vocal_o = 0;
	int contador_vocal_u = 0;
	
	/*********************************************************************/

	//
	// # 2. Proceso la información
	//

	// Recorro la cadena de caracteres
	// Finaliza al encontrar el punto
	while(caracter != '.'){
		// Almaceno el valor de cada caracter por separado
		caracter = texto[contador];

		// Verifico que el caracter sea una letra, sin importar si es minuscula o mayuscula
		if((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z')){
			// Acumulo +1 si es letra
			contador_letras++;
 			palabra += caracter;
		}
		// Si el caracter es un espacio o un punto
		else if(caracter == ' ' || caracter == '.'){
			// Entonces debe haber una nueva palabra, la cuento y acumulo +1
			
			// Función adicional para verificar que cadena de caracteres maneja
			contador_palabras++;
			cout << "-Palabra (" << contador_palabras << "): " << palabra;				
			cout << " (" << contador_letras << " letras)";
			cout << endl;
			// reinicio la variable para volver a guardar otra palabra
			palabra = "";
	
			// Si el contador de letras de la palabra es mayor que la anterior
			if(contador_letras > contador_palabra_mas_larga){
				// entonces almaceno la cantidad de letras que tiene
				contador_palabra_mas_larga = contador_letras;
			}
			// vuelvo el contador de letras a cero, para volver a contar
			// las próximas palabras
			// lo ejecuto luego del condicional, por mas que se cumpla o no
			contador_letras = 0;

		} // end if

		// Evalúo si el caracter es una vocal (a,e,i,o,u)
		// Otra opción sería con condicionales (if, else, elseif)
		switch(caracter){
			// Se verifica si es minuscula y mayuscula y acumulo +1 si lo es
			// de manera individual por cada vocal
			case 'a': case 'A':
				contador_vocal_a++;
				break;
			case 'e': case 'E':
				contador_vocal_e++;
				break;
			case 'i': case 'I':
				contador_vocal_i++;
				break;
			case 'o': case 'O':
				contador_vocal_o++;
				break;
			case 'u': case 'U':
				contador_vocal_u++;
				break;			
		} // end switch

		// Acumulo +1 para recorrer todo el string
		// se reutiliza para acceder al valor mediante la posición
		// Ej. texto[5] puede obtener el caracter que está en la posición 5
		contador++;
	} // end while
	cout << endl;
	
	/*********************************************************************/

	//
	// # 3. Imprimo los datos
	//
	cout << "Texto: " << texto << endl;
	cout << "Cantidad de palabras: " << contador_palabras << endl;
	cout << "La palabra más larga tiene " << contador_palabra_mas_larga << " letras" << endl;
	cout << "-La vocal 'a' se repite: " << contador_vocal_a << " veces"<< endl;
	cout << "-La vocal 'e' se repite: " << contador_vocal_e << " veces"<< endl;
	cout << "-La vocal 'i' se repite: " << contador_vocal_i << " veces"<< endl;
	cout << "-La vocal 'o' se repite: " << contador_vocal_o << " veces"<< endl;
	cout << "-La vocal 'u' se repite: " << contador_vocal_u << " veces"<< endl;
																																											
	return 0;
}
