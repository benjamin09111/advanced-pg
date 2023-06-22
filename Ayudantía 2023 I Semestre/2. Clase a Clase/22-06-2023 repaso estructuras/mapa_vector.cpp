#include<iostream>
#include<map>
#include<vector>
using namespace std;


/*
Se tiene un mapa que tiene el nombre del 
alumno (asuma que siempre sera diferente)
y un vector de notas de este. Almacene en el
mapa los datos de n alumnos. Luego:

- Imprima el mapa en forma clara
- Muestre el promedio de cada alumno
- Muestre el mayor promedio (puede usar otro vector)

*/

typedef map<string, vector<float> > mapa;
typedef pair<string, vector<float> > par;

int main (){
	vector<float> notas1;
	vector<float> notas2;
	vector<float> notas3;
	
	float nota1,nota2,nota3;
	string n1,n2,n3;
	
	cout<<"Ingrese el nombre del alumno 1: "<<endl;
	cin>>n1;
	
	cout<<"Ingrese el nombre del alumno 1: "<<endl;
	cin>>n2;
	
	cout<<"Ingrese el nombre del alumno 1: "<<endl;
	cin>>n3;
	
	float n;
	
	for(int i=0; i<3; i++){
		cout<<"Ingrese la nota: "<<endl;
		cin>>n;
		
		notas1.push_back(n);
	}
	
	for(int i=0; i<3; i++){
		
		cout<<"Ingrese la nota: "<<endl;
		cin>>n;
		
		notas2.push_back(n);
	}
	
	for(int i=0; i<3; i++){
		
		cout<<"Ingrese la nota: "<<endl;
		cin>>n;
		
		notas3.push_back(n);
	}
	
	
	//ingresar al mapa

		
	mapa m;
	
	m.insert( par( n1, notas1) );
	m.insert( par( n2, notas2) );
	m.insert( par( n3, notas3) );
	
	map<string, vector<float> >::iterator i;
	
	for(i= m.begin(); i!=m.end(); i++){
		cout<< i->first <<endl;
		
		for(int j=0; j< i->second.size(); j++ ){
			cout<< i->second[j] <<endl;
		}
		
		cout<<endl;
	}

	return 0;
}
