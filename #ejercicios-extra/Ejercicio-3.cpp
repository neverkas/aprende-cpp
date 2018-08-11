/*
 *
 * Retomando el Ejercicio 1 (Empresa de TV por cable), reorganizar
 * el programa separando el cC!lculo de la facturaciC3n por modulos especificos para
 * clientes residenciales y comerciales. Ambas funciones recibiran por parametro la
 * cantidad de conexiones HD y deberan retornar el importe calculado. Para el caso
 * que fuera necesario solicitar mas datos (cantidad de conexiones adicionales),
 * agregar las sentencias dentro del cuerpo de la funcion especifica.
 * 
 * La funcion main() solicitara el numero de cliente, tipo de cliente, la cantidad de
 * conexiones HD y decidira que funcion invocar segun el tipo de cliente ingresado
 * por el usuario. Finalmente mostrara por pantalla el importe calculado, junto con el
 * numero de cliente.
 * 
 * Pista: Puede declarar variables constantes globales con el importe de cada cargo
 * 
 */
#include <iostream>
#include <iomanip>

using namespace std;

//
// # Prototipos
//
float cliente_residencial_importe(int);
float cliente_comercial_importe(int);

//
// # Variables Globales
//
int CLIENTE_COMERCIAL_ENVIO_FACTURA = 15;
int CLIENTE_COMERCIAL_SERVICIO_BASICO = 75;
int CLIENTE_COMERCIAL_POR_CANAL_HD = 5;
int CLIENTE_COMERCIAL_CONEXIONES_ADICIONALES_MIN = 10;

float CLIENTE_RESIDENCIAL_ENVIO_FACTURA = 4.50;
float CLIENTE_RESIDENCIAL_SERVICIO_BASICO = 20.5;
int CLIENTE_RESIDENCIAL_POR_CANAL_HD = 5;

int main(){
	// Defino la cantidad de decimales a mostrar en los campos tipo float
	cout << setprecision(2);
	cout << fixed << showpoint;
	
	//
	// Defino Variables
	//
	int numeroCliente;
	float importe;
	short cantidadCanalesHD;
	short cantidadConexiones;
 
	char tipoCliente;
	
	/****************************************************************************/

	//
	// # Entrada de Datos
	//
	cout << "Numero de cliente: ";
	cin >> numeroCliente;

	cout << "Indique el Tipo de Cliente"<<endl;
	cout << "Escriba 'R' si es Residencial, y	'C' si es Comercial"<<endl;
	cout << "Tipo de cliente: ";
	cin >> tipoCliente;

	cout << "Cantidad de canales: ";
	cin >> cantidadCanalesHD;

	/****************************************************************************/
	
	//
	// # Proceso de informacion
	//
	switch(tipoCliente){
	case 'r': case 'R':
		importe = cliente_residencial_importe(cantidadCanalesHD);
		break;
	case 'c': case 'C':		
		importe = cliente_comercial_importe(cantidadCanalesHD);
		break;
	}
	
	/****************************************************************************/
	
	//
	// # Salida de Datos
	//
	cout << "Numero de Cliente: " << numeroCliente << endl;
	cout << "Importe: " << importe <<endl;								
	return 0;
}

//
// # Funciones
//
float cliente_residencial_importe(int cantidadCanalesHD){	
	// Multiplico cantidad de canales contratados por el importe por cada canal
	float importeCanales = (CLIENTE_RESIDENCIAL_POR_CANAL_HD * cantidadCanalesHD);
	
	// Sumatoria total de todos los importes
	return ( CLIENTE_RESIDENCIAL_ENVIO_FACTURA + CLIENTE_RESIDENCIAL_SERVICIO_BASICO + importeCanales);
}

float cliente_comercial_importe(int cantidadCanalesHD){
	float importeCanales;
	int cantidadConexiones;
	int cantidadConexionesAdicionales;
		// Si supera esta cantidad, se cobra un adicional por c/conexion
		cout << "Cantidad de conexiones: ";
		cin >> cantidadConexiones;
	
		if(cantidadConexiones > CLIENTE_COMERCIAL_CONEXIONES_ADICIONALES_MIN){
			cantidadConexionesAdicionales = (cantidadConexiones - CLIENTE_COMERCIAL_CONEXIONES_ADICIONALES_MIN);
			CLIENTE_COMERCIAL_SERVICIO_BASICO += (cantidadConexionesAdicionales * CLIENTE_COMERCIAL_POR_CANAL_HD);
		}
		
	// Multiplico cantidad de canales contratados por el importe por cada canal
		importeCanales = (CLIENTE_COMERCIAL_POR_CANAL_HD * cantidadCanalesHD);	

		// Sumatoria total de todos los importes
		return (CLIENTE_COMERCIAL_ENVIO_FACTURA + CLIENTE_COMERCIAL_SERVICIO_BASICO + importeCanales);		
}
