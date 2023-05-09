/*
Este codigo está realizado de manera rápida, en caso de encontrar algún error.
*/

#include<iostream>
using namespace std;

class Estudiante{
	private:
		string nombre;
		float promedio;
	public:
		Estudiante(string nombre, float promedio){
			this->nombre = nombre;
			this->promedio = promedio;
		}
		string getNombre(){
			return nombre;
		}
		float getPromedio(){
			return promedio;
		}
};

class Colegio{
	private:
		Estudiante *estudiantes[10];
		string nombre;
	public:
		Colegio(string nombre){
			this->nombre = nombre;
			for(int i=0; i<10; i++){
				estudiantes[i] = NULL;
			}
		}
		bool agregarEstudiante(Estudiante *e){			
			for(int i=0; i<10; i++){
				if(estudiantes[i] == NULL){
					estudiantes[i] = e;
					return true;
				}
			}
			return false;
		}
		
		bool agregarEstudianteIndex(Estudiante *e, int index){			
			if(estudiantes[index] == NULL){
				estudiantes[i] = e;
				return true;
			}
			return false;
		}
		
		bool registrarEstudiante(string n, float p){
			Estudiante *e = new Estudiante(n,p);
			
			for(int i=0; i<10; i++){
				if(estudiantes[i] == NULL){
					estudiantes[i] = e;
					return true;
				}
			}
			return false;
			
		}
		void borrarEstudiantes(){
			for(int i=0; i<10; i++){
				estudiantes[i] = NULL;
			}
		}
		void borrarEstudianteEspecificoIndex(int index){
			if(estudiantes[index] != NULL){
				estudiantes[i] = NULL;
				return true;
			}
			return false;
		}
		void borrarEstudianteEspecificoNombre(string nombre){
			for(int i=0; i<10; i++){
				if(estudiantes[i] != NULL){
					if(estudiantes[i]->getNombre()==nombre)}
						estudiantes[i] = NULL;}
						return true;
					}
				}
			}
			return false;
		}
		void obtenerNombres(){
			for(int i=0; i<10; i++){
				if(estudiantes[i]!=NULL){
					cout<<estudiantes[i]->getNombre()<<endl;
				}
			}
		}
		float obtenerPromedioTotal(){
			float promedio=0;
			float totales=0;
			
			for(int i=0; i<10; i++){
				if(estudiantes[i]!=NULL){
					promedio = promedio + estudiantes[i]->getPromedio();
					totales++;
				}
			}
			
			return promedio/totales;
			
		}
		
};


int main (){
	return 0;
}
