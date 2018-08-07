/*
 * Una compania aerea desea emitir un listado con los movimientos mensuales de sus
 * m vuelos al exterior. Para ello cuenta con la siguiente informacion:
 * -De cada vuelo realizado el numero de vuelo, destino y cantidad de asientos.
 * -De cada pasajero el numero de pasaporte y el importe que abono por el pasaje (en dolares)
 * La informacion finaliza con un numero de pasaporte igual a cero. SE pide emitir el siguiente listado:
 * Nro de vuelo: 9999, Destino: xxxxxxxxxxxxxxxxx
 * Nro de Pasaporte Importe en U$S
 * 999999999				999.99
 * 999999999				999.99
 * Total recaudado del vuelo: $999999.99
 * % de Asientos Libres del vuelo: 999.99
 * % de Asientos Ocupados del vuelo: 999.99
 * Total recaudado en el mes: $999999.99
 * Cantidad de veces seguidas que se dieron vuelos completos: 99
 * El numero de vuelo que mas recaudo: 9999
*/
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_VUELOS 20
#define MAX_PASAJEROS 20

//
// # Registros
//
struct Pasajero{
	int pasaporte;
	float importe;
};

struct Vuelo{
	int numero;
	string destino;
	int cantidadAsientos;
	struct Pasajero pasajeros[MAX_PASAJEROS]; // vector
};

//
// # Main
//
int main(){
	//
	// # 1. Defino Variables
	//
	int cantidadDeVuelos; // Para bucle
	bool finalizar = false; // centinela
	bool puedeIngresar = false; // bandera

	// Utilizadas para calculos
	float vueloTotalRecaudado = 0;
	float vueloPorcentajeAsientosLibres;
	float vueloPorcentajeAsientosOcupados;
	float totalRecaudadoPorMes = 0;
	int cantidadVuelosCompletos = 0;
	int numeroVueloRecaudoMas = 0;
	
	/********************************************************************************************/
	
	//
	// # Entrada de Datos y
	// # Proceso de informacion
	// 

	// Asigno el tamanio maximo del vector vuelos	
	Vuelo vuelos[MAX_VUELOS];

	// Asigno la cantidad de veces que preguntare por los datos de cada vuelo
	cout << "Cantidad de vuelos al exterior: ";
	cin >> cantidadDeVuelos;

	// Si la cantidad de vuelos ingresada no supera el maximo prestablecido
	if(cantidadDeVuelos <= MAX_VUELOS){
		// habilito la bandera 'puedeIngresar'
		puedeIngresar = true;
	}

	if(puedeIngresar){
		// Itera tantas veces segun 'cantidadDeVuelos'
		for(int i=0; i < cantidadDeVuelos; i++){
			Vuelo vuelo;
			cout << "# Vuelo " << (i+1) << endl;
			cout << "Nro de vuelo: ";
			cin >> vuelo.numero;
			cout << "Destino del vuelo: ";
			cin >> vuelo.destino;
			cout << "Cantidad de asientos: ";
			cin >> vuelo.cantidadAsientos;

			// Condiciones para la ejecucion del bucle
			// 1. Si el centinela 'finalizar' del tipo booleano es verdadero
			// 2. Si el incremental 'j' es menor a cantidadAsientos
			// Si ambos se cumplen, seguira ejecutandose, caso contrario se detiene.
			cout << "Informacion de los pasajeros:" << endl;
			for(int j=0; j < vuelo.cantidadAsientos && !finalizar; j++){
				Pasajero pasajero;
			
				cout << "# Pasajero "<< (j+1) <<endl;
				cout << "\tPasaporte: ";
				cin >> pasajero.pasaporte;

				// Si el pasaporte ingresado tiene como valor cero
				if(pasajero.pasaporte == 0){
					// habilito el centinela 'finalizar' que controla el bucle for
					finalizar = true;
				}
				else{
					// Caso contrario que sigo completando los datos
					cout << "\tImporte (en dolares): ";
					cin >> pasajero.importe;

					// Luego de cargada toda la informacion a 'pasajero',
					// lo agrego al vector 'pasajeros' del registro Vuelo
					vuelo.pasajeros[j] = pasajero;
				} // end if
            
				cout << "\t--------------------------" << endl;
			} // end for
			
			// Luego de cargar toda la informacion a 'vuelo',
			// lo agrego al vector 'vuelos'
			vuelos[i] = vuelo;
			
			cout << "------------------------------------------" << endl;
		} // end for
	} // end if
	
	/********************************************************************************************/

	//
	// # Datos de Salida
	//
    
	for(int i=0; i < cantidadDeVuelos; i++){
	    Vuelo vuelo = vuelos[i];
	    
		cout << "Nro. de Vuelo: " << vuelo.numero << endl;
		cout << "Destino: " << vuelo.destino << endl;
		// Utilizo setw() para separar los datos y mostrarlos en dos columnas
		cout << "Nro pasaporte:" << setw(10) << "Importe en U$S" << endl;
		
		for(int j=0; j < vuelo.cantidadAsientos; j++){
		    Pasajero pasajero = vuelo.pasajeros[j];
				
				// Utilizo setw() para separar los datos y mostrarlos en dos columnas
		    cout << pasajero.pasaporte << setw(10) << pasajero.importe << endl;
				
				vueloTotalRecaudado += pasajero.importe;
		} // end for
		
		cout << "Total recaudado del vuelo: " << vueloTotalRecaudado  << endl;
		cout << "% de Asientos libres del vuelo: " << vueloPorcentajeAsientosLibres  << endl;
		cout << "% de Asientos Ocupados del vuelo: " << vueloPorcentajeAsientosOcupados << endl;					
		cout << "------------------------------------------" << endl;
	} // end for

	cout << "Total recaudado en el mes: $" << totalRecaudadoPorMes << endl;
	cout << "Cantidad de veces seguidas que se dieron vuelos completos: " << cantidadVuelosCompletos << endl;
	cout << "El numero de vuelo que mas recaudo: " << numeroVueloRecaudoMas << endl;
	
	return 0;
}
