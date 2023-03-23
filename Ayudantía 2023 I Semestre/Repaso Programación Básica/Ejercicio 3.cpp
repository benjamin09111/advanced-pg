#include<iostream>
using namespace std;

float calcularPromedio(float notas[], int n){
	float promedio = 0;
	
	for(int i=0; i<n; i++){
		promedio = promedio + notas[i];
	}
	
	return promedio/n;
	
}

int main (){
	
	float notas[3];
	
	for(int i=0; i<3; i++){
		cout <<"Ingrese la nota "<<i+1<<endl;
		cin>>notas[i];
	}
	
	float promedio = calcularPromedio(notas,3);
	
	cout <<"Su promedio es: "<<promedio<<endl;
	
	if(promedio>=4){
		cout <<"Aprueba."<<endl;
	}else{
		cout<<"No aprueba."<<endl;
	}
	
	return 0;
}
