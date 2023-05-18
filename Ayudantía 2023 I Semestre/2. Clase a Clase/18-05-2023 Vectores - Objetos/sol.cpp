#include<iostream>
#include<vector>
using namespace std;

/*

- Permita agregar estudiantes.
- Muestre todos los nombres de los estudiantes.
- Mostrar el mayor promedio del estudiante.
- Mostrar cuantos estudiantes son mayores de edad.
*/

class Estudiante{
	private:
		string nombre;
		int edad;
		float promedio;
		bool mayor_edad;
	public:
		Estudiante(string nombre, int edad, float promedio){
			this->nombre = nombre;
			this->edad = edad;
			this->promedio = promedio;
			
			if(edad>=18){
				mayor_edad = true;
			}else{
				mayor_edad = false;
			}
		}
		string getNombre(){
			return nombre;
		}
		float getPromedio(){
			return promedio;
		}
		bool getMayorEdad(){
			return mayor_edad;
		}
		void imprimir(){
			cout<<nombre<<", "<<edad<<" anios."<<endl;
		}
};

class Colegio{
	private:
		vector<Estudiante> estudiantes;
	public:
		Colegio();
		
		void agregar(Estudiante e){
			estudiantes.push_back(e);
		}
		
		float mayorPromedio(){
			float promedio=0;
			
			for(int i=0; i<estudiantes.size(); i++){
				promedio = promedio + estudiantes.at(i).getPromedio();
			}
			
			return promedio/estudiantes.size();
		}
		
		void mayoresdeEdad(){
			int contador=0;
			
			for(int i=0; i<estudiantes.size(); i++){
				if(estudiantes[i].getMayorEdad()){
					contador++;
				}
			}
			
			cout<<"Mayores de edad: "<<contador<<endl;
		}
		
		bool existe(string name){
			
			for(int i=0; i<estudiantes.size(); i++){
				
				if(estudiantes[i].getNombre()==name){
					return true;
				}
				
			}
			
			return false;
		}
		
};

int main (){

	return 0;
}
