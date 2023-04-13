#include<iostream>
using namespace std;

/*
1.- Un Profesor contiene su salario mensual,
y además posee una Identificacion, la cual consta de
un nombre y edad.
Cree ambas clases. Cree un método que compare
con otro Profesor y mencione cuál tiene más edad.
Cree una función imprimir.
*/

class Identificacion{
	private:
		string nombre;
		int edad;
	public:
		Identificacion(string nombre, int edad){
			this->nombre = nombre;
			this->edad = edad;
		}
		string getNombre(){
			return nombre;
		}
		int getEdad(){
			return edad;
		}
		void imprimir(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
		}
};

class Profesor{
	private:
		int salario_mensual;
		Identificacion *i;
	public:
		Profesor(int salario_mensual, Identificacion *i){
			this->salario_mensual = salario_mensual;
			this->i = i;
			//otra forma es recibir nombre y edad
		}
		void imprimir(){
			i->imprimir();
			cout<<"Salario mensual: "<<salario_mensual<<endl;
		}
		//comparar profesores
		void comparar(Profesor *p){
			
			int edad1 = i->getEdad();
			int edad2 = p->i->getEdad();
			
			if(edad1>edad2){
				cout<<"Es mayor el profesor "<<i->getNombre()<<endl;
			}else if(edad1==edad2){
				cout<<"Ambos tienen misma edad."<<endl;
			}else{
				cout<<"El profesor "<<p->i->getNombre()<<" es mayor."<<endl;
			}
			
		}
};

int main (){
	Identificacion *i1 = new Identificacion("Pedro",35);
	Identificacion *i2 = new Identificacion("Sofia",31);
	
	Profesor *p1 = new Profesor(300000,i1);
	Profesor *p2 = new Profesor(300000,i2);
	
	p1->comparar(p2);
	
	
	
	return 0;
}
