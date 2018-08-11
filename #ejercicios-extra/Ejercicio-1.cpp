/*
 * 
* El objetivo es crear un programa de facturación para los clientes de
* una empresa de TV por cable. Para calcular el importe primero se debe conocer
*si el cliente es residencial o comercial y la cantidad de canales HD que posee
* contratados. Para el caso de los clientes comerciales, también se debe conocer la
* cantidad de conexiones adicionales. Los cargos son:
* Clientes residenciales 	
* 	-Envío de factura: $4,50
* 	-Servicio básico: $20,50
* 	-Canales HD: $5 por canal. 
* 
* Clientes comerciales
* 	-Envío de factura: $15
* 	-Servicio básico: $75 (por las primeras 10 conexiones y $5 por cada conexión adicional).
* 	-Canales HD: $5 por canal.
* 
* Además el programa deberá solicitar el número de cliente (entero) y el tipo de
* cliente ('R' o 'r' para residencial y 'C' o 'c' para comercial) cuya entrada deberá
* evaluarse en una estructura switch y determinará el flujo de ejecución.
* 
* Nota: Para mostrar las cifras con 2 decimales se deberá incluir la biblioteca «iomanip».
* Incluir las siguientes sentencias: cout << setprecision(2); cout << fixed << showpoint;
* 
*/
#include <iostream>
#include <iomanip>

using namespace std;

//
// # Main
//
int main(){
  // Defino la cantidad de decimales a mostrar en los campos tipo float
  cout << setprecision(2);
  cout << fixed << showpoint;
  
  //
  // # Defino Variables
  //
  int numeroCliente;
  short cantidadCanalesHD;
  short cantidadConexiones;
  short cantidadConexionesAdicionales;
  short cantidadConexionesAdicionalesMinimo;
 
  char tipoCliente;

  float importeTotal;
  float importeEnvioFactura;
  float importeServicioBasico;
  float importePorCadaCanalHD;
  float importeCanalesHD;
  
  /*****************************************************************************************************/
 
  //
  // # Entrada de Datos
  //
  cout << "Numero de cliente: ";
  cin >> numeroCliente;

  cout << "Indique que Tipo de Cliente es"<<endl;
  cout << "*Escriba 'R' si es Residencial"<<endl;
  cout << "*Escriba 'C' si es Comercial"<<endl;
  cout << "Tipo de cliente: ";
  cin >> tipoCliente;

  cout << "Cantidad de canales: ";
  cin >> cantidadCanalesHD;

  /*****************************************************************************************************/
  
  //
  // # Proceso de informacion
  //
  switch(tipoCliente){
  case 'r': case 'R':
    // valores predefinidos para Cliente Residencial
    importeEnvioFactura = 4.50;
    importeServicioBasico = 20.5;
    importePorCadaCanalHD = 5;
    break;
  case 'c': case 'C':
    // valores predefinidos para Cliente Comercial
    importeEnvioFactura = 15;
    importeServicioBasico = 75;
    importePorCadaCanalHD = 5;
    
    // Si supera esta cantidad, se cobra un adicional por c/conexion
    cantidadConexionesAdicionalesMinimo = 10; 

    cout << "Cantidad de conexiones: ";
    cin >> cantidadConexiones;

    // Si la cantidad de conexiones supera la cantidadConexionesAdicionalesMinimo
    if(cantidadConexiones > cantidadConexionesAdicionalesMinimo){
      // Se resta la cantidad conexiones totales
      // para establecer la cantidad cuantas conexiones se adicionan
      // si se supera la cantidad de conexiones adicionales
      cantidadConexionesAdicionales = (cantidadConexiones - cantidadConexionesAdicionalesMinimo);

      // Mostrar la cantidad conexiones adicionales
      cout << "Cantidad de Conexiones adicionales " << cantidadConexionesAdicionales << endl;
      
      // Se cobra un adicional por cada canal
      // si supera la cantidad de conexiones adicionales
      importeServicioBasico += (cantidadConexionesAdicionales * importePorCadaCanalHD);
    } // end if
    
    break;
    
  }
  
  // Se multiplica la cantidad de canales contratados por el importe predefinidos de por cada canal
  importeCanalesHD = (importePorCadaCanalHD * cantidadCanalesHD);
  // Sumatoria total de todos los importes
  importeTotal = (importeEnvioFactura + importeServicioBasico + importeCanalesHD);
  
  /*****************************************************************************************************/

  //
  // # Salida de datos
  //  
  cout << '\n'; // salto de linea
  cout << "*Importe por Envio de Factura: $" << importeEnvioFactura << endl;
  cout << "*Importe por Servicio Basico: $" << importeServicioBasico << endl;
  cout << "*Importe por cada Canal HD: $" << importePorCadaCanalHD << endl;
  cout << '\n'; // Salto de linea

  cout << "Importe total: $" << importeTotal << endl;

  return 0;
}
