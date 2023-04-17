#include<iostream>
using namespace std;

class Padre{
	private:
		bool vivo;
	public:
		Padre(bool vivo){
			this->vivo = vivo;
		}
		int getVivo(){
			return vivo;
		}
		void kill(){
			if(vivo) this->vivo = false;
		}
		void revive(){
			if(!vivo) this->vivo = true;
		}
		void imprimir(){
			cout<<"Vivo: "<<vivo<<endl;
		}
};

class Hijo : public Padre{
	private:
		int edad;
	public:
		Hijo(bool vivo, int edad) : Padre(vivo){
			this->edad = edad;
		}
		int getEdad(){
			return edad;
		}
		void aumentarEdad(){
			this->edad = this->edad + 1;
		}
		void imprimir(){
			cout<<"Vivo: "<<vivo<<endl;
			cout<<"Edad: "<<edad<<endl;
		}
};

int main (){
	//crear objetos, sin arreglo del padre (sin polimorfismo)
	
	
	return 0;
}
