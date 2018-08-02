/*
 * 
 * Dado un número entero positivo entre 1 y 3999 informar
 * su correspondiente "número romano".
 * 
*/


#include <iostream>
#include <string>

using namespace std;

//
// # Prototipos
//
void imprimir_numero_romano(int, int);
void obtener_digitos(int, int [], int &);

/*********************************************************************/

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int numero_ingresado;
	int cantidad_digitos;
	int lista_digitos[4];

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese un numero: ";
	cin >> numero_ingresado;

	while(numero_ingresado < 0){
		cout << "Ingrese un numero: ";
		cin >> numero_ingresado;
	}

	if(numero_ingresado > 0){	
		//
		// # 2. Proceso la información
		//
		obtener_digitos(numero_ingresado, lista_digitos, cantidad_digitos);

		//
		// # 3. Salida de datos
		//
		cout << "Numero ingresado: " << numero_ingresado << endl;
		cout << "Numero romano: ";

		if(cantidad_digitos == 1)
			imprimir_numero_romano(numero_ingresado, 1);
		else{
			for(int i=0; i < cantidad_digitos; i++)
				imprimir_numero_romano(lista_digitos[i], cantidad_digitos-i);
		}
	
		cout << endl;
	} // end if
	
	return 0;
}

/*********************************************************************/

//
// # Funciones
//
void imprimir_numero_romano(int numero, int cantidad_digitos){
	string numero_romano, numero_seleccionado, numero_seleccionado_b;	
		
	switch(numero){
	case 1: case 2: case 3:
		switch(cantidad_digitos){
		case 1:
			numero_seleccionado = "I";
			break;
		case 2:
			numero_seleccionado = "X";
			break;
		case 3:
			numero_seleccionado = "C";
			break;
		case 4:
			numero_seleccionado = "M";
			break;
		}
		
		for(int i = 0; i < numero; i++)
			numero_romano+=numero_seleccionado;
		
		break;
			
	case 4:
		switch(cantidad_digitos){
		case 1:
			numero_romano = "IV";
			break;
		case 2:
			numero_romano = "XL";
			break;
		case 3:
			numero_romano = "DC";
			break;
		}
		break;
	case 5: case 6: case 7: case 8:		
		switch(cantidad_digitos){
		case 1:
			numero_seleccionado = "V";
			numero_seleccionado_b = "I";
			break;
		case 2:
			numero_seleccionado = "L";
			numero_seleccionado_b = "X";
			break;
		case 3:		
			numero_seleccionado = "D";	
			numero_seleccionado_b = "C";
			break;
		}

		numero_romano += numero_seleccionado;
		
		for(int i=5; i < numero; i++)
			numero_romano+=numero_seleccionado_b;
		
		break;
	case 9:
		switch(cantidad_digitos){
		case 1:
			numero_romano = "IX";
			break;
		case 2:
			numero_romano = "XC";
			break;
		case 3:
			numero_romano = "CM";
			break;
		}
		break;			
	}

	cout << numero_romano;
}

void obtener_digitos(int n, int lista_digitos[], int &cantidad_digitos){
	// Analizo si tiene 1 dígito (1-9)
		if(n < 10){
		cantidad_digitos = 1;
		}
	// Analizo si tiene 2 dígitos (1-99)
	 else if(n < 100){
		cantidad_digitos = 2;
		
		lista_digitos[0] = (n / 10);
		lista_digitos[1] = (n % 10);
		}
	// Analizo si tiene 3 dígitos (1-999)
		else if(n < 1000){
		cantidad_digitos = 3;
		
		lista_digitos[0] = (n / 100);
		lista_digitos[1] = ((n / 10) % 10);
		lista_digitos[2] = (n % 10);			
		}
	// Analizo si tiene 4 dígitos (1-9999)
		else if(n < 10000){
		cantidad_digitos = 4;
		
		lista_digitos[0] = (n / 1000);
		lista_digitos[1] = ((n / 100) % 10);
		lista_digitos[2] = ((n / 10) % 10);
		lista_digitos[3] = ((n % 100)) - (((n / 10) % 10) * 10); // mejorar			
		}		
}
