#include<iostream>
#include<vector>
using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string nombre, int edad){
			this->nombre = nombre;
			this->edad = edad;
		}
		string getNombre(){
			return nombre;
		}
		int getEdad(){
			return edad;
		}
		int getDinero(){
			return edad*100;
		}		
};

int invitado(vector<string> nombres, string nombre){
	for(int i=0; i<nombres.size(); i++){
		if(nombres[i]==nombre){
			return i;
		}
	}
	return -1;
}

int main (){
	int opc;
	vector<string> lista;
	
	Persona p1= Persona("Pepe",25);
	Persona p2= Persona("Sofia",15);
	Persona p3= Persona("Juan",35);
	Persona p4= Persona("Gabriela",40);
	Persona p5= Persona("Pedro",50);
	Persona p6= Persona("Carolina",22);
	
	vector<Persona> personas;
	
	personas.push_back(p1);
	personas.push_back(p2);
	personas.push_back(p3);
	personas.push_back(p4);
	personas.push_back(p5);
	personas.push_back(p6);
	
	while(true){
		cout<<"1) Ingresar nombre."<<endl;
		cout<<"2) Salir."<<endl;
		cin>>opc;
		
		if(opc==2) break;
		
		if(opc==1){
			string nombre;
			cin>>nombre;
			lista.push_back(nombre);
			
		}else{
			cout<<"Mal digitado."<<endl;
		}
	}
	
	cout<<"Verificando invitados..."<<endl;
	
	for(int i=0; i<personas.size(); i++){
		
		int posicion = invitado(lista, personas[i].getNombre());
		
		if(posicion==-1) cout<<"La persona "<<personas[i].getNombre()<<" no esta invitada."<<endl;
		else{
			cout<<"Eliminando de la lista de invitados a "<<personas[i].getNombre()<<"..."<<endl;
			lista.erase(lista.begin()+posicion);
		}
	}
	
	cout<<"IMPRIMIENDO LISTA DE INVITADOS..."<<endl;
	
	for(int i=0; i<lista.size(); i++){
		cout<<lista[i]<<" // ";
	}
	
	return 0;
}
