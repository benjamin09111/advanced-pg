#include<iostream>
using namespace std;

class Duenio{
	private:
		string nombre;
		int edad;
	public:
		Duenio(string nombre, int edad){
			this->nombre = nombre;
			this->edad = edad;
		}
		void imprimir(){
			cout<<"Nombre del duenio: "<<nombre<<endl;
			cout<<"Edad del duenio: "<<edad<<endl;
		}
		int getEdad(){
			return edad;
		}
		
};

class Gimnasio{
	private:
		string nombre;
		int precio;
		Duenio *d;
	public:
		Gimnasio(string nombre, int precio, string nombre, int edad){
			this->nombre = nombre;	
			this->precio = precio;
			d = new Duenio(nombre,edad);
		}
		void imprimir(){
			cout<<"Nombre gimnasio: "<<nombre<<endl;
			cout<<"Precio: "<<precio<<endl;
			d->imprimir();
		}
		void comparar(Gimnasio *g){
			
			if (precio > g->precio){
				cout<<"Es mayor el gimnasio: "<<endl;
				imprimir();
			}else if(precio == g->precio){
				cout<<"Ambos valen lo mismo."<<endl;
			}else{
				cout<<"Es mayor el gimnasio: "<<endl;
				g->imprimir();
			}
		}
		void compararDuenios(Gimnasio *g){
			int edad1 = this->d->edad;
			int edad2 = g->d->getEdad();
			
			if(edad1>edad2){
				cout<<"Es mayor el duenio "<<this->d->imprimir()<<endl;
			}else if(edad1==edad2){
				cout<<"Ambos tienen misma edad."<<endl;
			}else{
				cout<<"Es mayor el duenio "<<g->d->imprimir()<<endl;
			}
		}
};

int main (){
	
	
	return 0;
}
