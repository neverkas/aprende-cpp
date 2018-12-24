/*
 *
 * Desarrolle y pruebe una funcion separarFecha que, dada una fecha en formato aaaammdd
 * separe sus componentes y los asigne a lso parametros que recibe por referencia.
 * void separarFecha(long fecha, int &dia, int &mes, int  &anio);
 *
*/
#include <iostream>

using namespace std;

void separarFecha(long fecha, int &dia, int &mes, int &anio){
	// Divido por 10.000 para mover la coma hacia la izquierda
	anio = (fecha / 10000);
	mes = (fecha / 100) % 100; // 20181230/100 = 201812, 201812%100=12
	dia = fecha % 100;

	cout << "dia: " << dia << endl;
	cout << "mes: " << mes << endl;
	cout << "anio: " << anio << endl;
	// 1521 / 100 = 15
}

int main(){
	long fecha = 20181230;
	int dia, mes, anio;
	
	separarFecha(fecha, dia, mes, anio);
	
	return 0;
}
