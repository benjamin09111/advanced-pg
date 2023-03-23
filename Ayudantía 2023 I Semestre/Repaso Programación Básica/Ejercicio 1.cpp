#include<iostream>
using namespace std;

/*
Cree una función que retorne el número mayor y
otra que retorne el menor de un arreglo.
*/

int retornarMenorNumero(int arreglo[], int n){
	
	int referencia = arreglo[0];
	
	for(int i=0; i<n; i++){
		
		if(arreglo[i]<referencia){
			referencia = arreglo[i];
		}
		
	}
	
	return referencia;
}

int retornarMayorNumero(int arreglo[], int n){
	
	int referencia = arreglo[0];
	
	for(int i=0; i<n; i++){
		
		if(arreglo[i]>referencia){
			referencia = arreglo[i];
		}
		
	}
	
	return referencia;
}


int main (){
	
	int arreglo[] = {3,4,10,5};
	
	int menor = retornarMenorNumero(arreglo,4);
	
	cout << "El menor dato es: "<<menor<<endl;
	
	cout << "El mayor dato es: "<<retornarMayorNumero(arreglo,4)<<endl;
	
	return 0;
}
