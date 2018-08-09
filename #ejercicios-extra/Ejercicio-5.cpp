/*
 * 
 * Crear un programa modularizado en funciones específicas para:
 * a) Ingresar el importe de 10 ventas en un array.
 * b) Calcular y mostrar la suma y el promedio de todos sus elementos.
 * c) Encontrar el elemento con el importe mayor (y retornarlo).
 * La función main() debe crear el array de ventas e invocar a las funciones
 * específicas pasando el array como parámetro. Por último, desde esa misma
 * función se deberá mostrar la cifra de la venta más alta
 * 
 * Incorporar al programa la función busquedaSec() y modificarla de
 * forma tal que:
 * 	-Sea compatible con el tipo de dato
 *	-Acepte un margen de tolerancia
 *  Tanto la cifra objetivo como el valor de tolerancia serán ingresados por el usuario
 * una vez cargados los 10 importes de ventas. Finalmente el programa deberá
 * mostrar por consola:
 * A) Suma y promedio de todos sus elementos.
 * B) El importe más alto.
 * C) El índice del primer elemento del array que esté dentro del rango objetivo.
 *  
 */
#include <iostream>

using namespace std;

void ingresar_ventas(int [], int);
void calcular_ventas(int [], int);
int mayor_importe(int [], int);
int busqueda_secuencial(int, int, int []);

int main(){
	int ventas[10];
	int len = 10;
	int objetivo, tolerancia;
	
	ingresar_ventas(ventas, len);
	calcular_ventas(ventas, len);
	cout << "El mayor importe es: " << mayor_importe(ventas, len) << endl;
	
	cout << "objetivo: ";
	cin >> objetivo;
	
	cout << "tolerancia: ";
	cin >> tolerancia;
	cout << "La posicion de la Busqueda secuencial es " << busqueda_secuencial(objetivo, tolerancia, ventas);
	
	cout << '\n';
	
	return 0;
}

int busqueda_secuencial(int objetivo, int tolerancia, int ventas[]){
	bool encontrado = false;
	int indice = 0;
	
	while(indice < 10 && !encontrado){
		 if(ventas[indice] >= objetivo - tolerancia && ventas[indice] <= objetivo + tolerancia){
			encontrado = true;
		 }else{
		 	indice++;
		 }
		 	
	}
	
	if(encontrado){
		return indice;
	}else{
		return -1;
	}

}

void ingresar_ventas(int ventas[], int len){
	for(int i=0; i< len; i++){
		cout << "Importe: ";
		cin >> ventas[i];
	}
}

void calcular_ventas(int ventas[], int len){
	int suma = 0;
	
	for(int i=0; i < len;i++){
		suma+=ventas[i];
	}
	
	cout << "Suma: " << suma << endl;
	cout << "Promedio: " << (suma / 10) << endl;
}

int mayor_importe(int ventas[], int len){
	int mayor_numero = 0;
	
	for(int i=0; i < len; i++){
		if(ventas[i] > mayor_numero){
			mayor_numero = ventas[i];
		}
				
	}
	
	return mayor_numero;
	
}
