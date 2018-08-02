/*
 * Ordenamiento por Inserción
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int len = 4;
	int arr[] = {4,3,1,8};

	int tmp;
	// sort array
	for(int i=0; i < len-1; i++){
				tmp = arr[i];
		
		for(int j=0; j > i+1; j++){
			if(arr[i+1] < arr[i]){
				
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
	}
	
	cout << endl;
	
	// show elements
	for(int i=0; i < len; i++){
		cout << arr[i];
		
		if(i<len-1)
			cout << ", ";
	}

	cout << endl;

	return 0;
}
