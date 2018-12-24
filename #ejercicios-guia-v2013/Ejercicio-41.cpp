/*
 *
 * Desarrollar la funcion esMultiplo que recibe dos valores a y b y retorna true o false
 * segun 'a' sea o no multiplo de 'b'.
 * El prototipo sera:
 * bool esMultiplo(int a, int b);
 *
*/
#include <iostream>

using namespace std;

int decrementar(int n){	
	if(n >= 0){
		cout << n << " ";
		decrementar(n -1);
	}
}
int incrementar(int a, int b){
	if(a <= b){
		cout << a << " ";
		incrementar(a + 1, b);
	}
}

bool esMultiplo(int a, int b);

int main(){
	/*
	decrementar(10);
	cout << endl;
	incrementar(1, 5);
	cout << endl;
	*/
	int a, b;
	
	a = 14;
	b = 2;

	cout << esMultiplo(a, b) << endl;
	
	return 0;
}

bool esMultiplo(int a, int b){
	return (a % b == 0) ? true : false;
}
