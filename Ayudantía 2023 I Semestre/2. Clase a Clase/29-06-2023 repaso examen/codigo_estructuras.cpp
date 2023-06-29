#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Persona{
	protected:
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
		void aumentarEdad(){
			this->edad++;
		}
		virtual void imprimir(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
		}
};

class Estudiante : public Persona{
	private:
		float promedio;
	public:
		Estudiante(string nombre, int edad, float promedio) : Persona(nombre,edad){
			this->promedio = promedio;
		}
		float getPromedio(){
			return promedio;
		}
		void modificarPromedio(float promedio){
			this->promedio = promedio;
		}
		void imprimir(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Promedio: "<<promedio<<endl;
		}
};

/*
4
3
2
1
*/

class ClaseDos{
	private:
		stack<Estudiante*> alumnos;
	public:
		ClaseDos(){}
		void agregar(Estudiante *e){
			alumnos.push(e);
		}
		void mostrarTop(){
			alumnos.top()->imprimir();
			cout<<endl;
		}
		void imprimirPila(){
			vector<Estudiante*> respaldo;
			
			while(!alumnos.empty()){
				alumnos.top()->imprimir();
				respaldo.push_back(alumnos.top());
				alumnos.pop();
			}
			
			for(int i=0; i<respaldo.size(); i++){
				alumnos.push( respaldo[i] );
			}
		}
};

class ClaseTres{
	private:
		queue<Estudiante*> alumnos;
	public:
		ClaseDos(){}
		void agregar(Estudiante *e){
			alumnos.push(e);
		}
		void mostrarFront(){
			alumnos.front()->imprimir();
			cout<<endl;
		}
		void imprimirPila(){
			vector<Estudiante*> respaldo;
			
			while(!alumnos.empty()){
				alumnos.front()->imprimir();
				respaldo.push_back(alumnos.top());
				alumnos.pop();
			}
			
			for(int i=0; i<respaldo.size(); i++){
				alumnos.push( respaldo[i] );
			}
		}
};

class Clase{
	private:
		vector<Estudiante*> alumnos;
		string codigo;
	public:
		Clase(string codigo){this->codigo = codigo;}
		string getCodigo(){return codigo;}
		//metodos
		void agregarObjeto(Estudiante *e){
			
			if(v.size() == 20){
				cout<<"No es posible agregar."<<endl;
			}else{
				alumnos.push_back(e);
			}	
		}
		void agregar(string nombre, int edad, float promedio){
			if(v.size() == 20){
				Estudiante *e = new Estudiante(nombre,edad,promedio);
				alumnos.push_back(e);
			}else{
				alumnos.push_back(e);
			}
		}
		bool eliminar(string nombre){
			for(int i=0; i<alumnos.size(); i++){
				if(v[i]->getNombre() == nombre){
					alumnos.erase(alumnos.begin()+i);
					return true;
				}
			}
			return false;
		}
		void imprimirClase(){
			cout<<"Codigo: "<<codigo<<endl<<endl;
			for(int i=0; i<alumnos.size(); i++){
				v[i]->imprimir();
				cout<<endl;
			}
		}
		
};

typedef pair<int, Estudiante*> par;
typedef mapa<int,Estudiante*> mapa;

class Mapa1{
	private:
		mapa alumnos;
		int contador;
	public:
		Mapa1(){
			contador = 0;
		}
		void agregar(Estudiante *e){
			contador++;
			alumnos.insert( par(contador, e) );
		}
		bool existe(int id){
			mapa<int,Estudiante*>::iterator i;
			
			i = alumnos.find(id);
			
			if(i!=alumnos.end()){
				return true;
			}else{
				return false;
			}
			
		}
		void imprimirAlumno(string nombre){
			bool encontrado=false;
			mapa<int,Estudiante*>::iterator i;
			for(i=alumnos.begin(); i!= alumnos.end(); i++){
				if( i->second->getNombre() == nombre ){
					i->second->imprimir();
					cout<<endl;
					encontrado = true;
					break;
				}
			}
			if(!encontrado){
				cout<<"No encontrado."<<endl;
			}
		}
		bool eliminar(int id){
			bool resultado = alumnos.erase(id);
			return resultado;
		}
};

typedef pair<int, vector<Estudiante*> > par2;
typedef mapa<int, vector<Estudiante*> > mapa2;

class Mapa2{
	private:
		mapa2 alumnos;
		int contador=0;
	public:
		/*
		1 | [a1,a2,a3]
		2 | [a1,a2,a3]
		3 | [a1,a2,a3,a4]
		4 | [a1,a2,a3]
		
		*/
		Mapa2(){
			contador=0;
		}
		void agregarVector(vector<Estudiante*> v){
			contador++;
			alumnos.insert( par(contador, v) );
		}
		bool agregarPorIdAlCurso(int id, Estudiante *e){
			mapa<int, vector<Estudiante*> >::iterator i;
			
			i = alumnos.find(id);
			
			if(i != alumnos.end()){
				i->second.push_back(e);
				return true;
			}else{
				return false;
			}	
		}
		bool existeCurso(int id){
			mapa<int, vector<Estudiante*> >::iterator i;
			
			i = alumnos.find(id);
			
			if(i!=alumnos.end()){
				return true;
			}else{
				return false;
			}
			
		}
		void imprimirCursos(string nombre){
			mapa<int, vector<Estudiante*> >::iterator i;
			
			
			for(i=alumnos.begin(); i!= alumnos.end(); i++){
				
				cout<<"Curso: "<<i->first<<endl;
				cout<<"Alumnos: "<<endl;
				
				for(int j=0; j<i->second.size(); j++){
					
					i->second[j]->imprimir();
					
					cout<<endl;	
				}
			}	
		}
		
		bool eliminarCurso(int id){
			bool resultado = alumnos.erase(id);
			return resultado;
		}
		bool eliminarEstudiante(string nombre){
			
			mapa<int, vector<Estudiante*> >::iterator i;
			
			for(i=alumnos.begin(); i!= alumnos.end(); i++){

				for(int j=0; j<i->second.size(); j++){
					
					if(i->second[i]->getNombre() == nombre){
						i->second.erase( i->second.begin() + j );
					}
					
				}
			}	
			
		}
		
		bool eliminarEstudiantePorCurso(int id, string nombre){
			
			mapa<int, vector<Estudiante*> >::iterator i;
			
			i = alumnos.find(id);
			
			if(i!=alumnos.end()){
				
				for(int j=0; j<i->second.size(); j++){
					
					if(i->second[i]->getNombre() == nombre){
						i->second.erase( i->second.begin() + j );
						return true;
					}
					
				}
				
				return false;
				
			}else{
				
				return false;
			}
			
		}
};

int main (){
	//crear objetos
	Persona *pe1 = new Persona("Juan",23);
	Persona *pe2 = new Persona("Pepe",22);
	Persona *pe3 = new Persona("Roberto",25);
	Persona *pe4 = new Persona("Alejandro",28);
	Estudiante *p1 = new Estudiante("Josefa",21,6.5);
	Estudiante *p2 = new Estudiante("Max",22,6.1);
	Estudiante *p3 = new Estudiante("Antonia",24,6.8);
	Estudiante *p4 = new Estudiante("Alejandra",25,5.2);
	
	//vector
	vector<Estudiante*> v;
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	
	
	return 0;
}
