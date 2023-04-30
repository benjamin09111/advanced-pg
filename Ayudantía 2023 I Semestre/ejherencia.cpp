#include<iostream>
using namespace std;

class Padre{
	protected:
		int edad;
	public:
		Padre(int edad){
			this->edad = edad;
		}
		int getEdad(){
			return edad;
		}
		void imprimir(){
			cout<<"Soy el padre."<<endl;
		}
};

class HijoUno : public Padre{
	private:
		int monto;
	public:
		HijoUno(int edad, int monto) : Padre(edad){
			this->monto = monto;
		}
		int getMonto(){
			return monto;
		}
		void imprimir(){
			cout<<"Soy el hijo 1."<<endl;
		}
};

class HijoDos : public Padre{
	private:
		int promedio;
	public:
		HijoDos(int edad, int promedio) : Padre(edad){
			this->promedio = promedio;
		}
		int getMonto(){
			return monto;
		}
		void imprimir(){
			cout<<"Soy el hijo 2."<<endl;
		}
};

int main (){
	
	Padre *p = new Padre(48);
	HijoUno *h1 = new HijoUno(21,500);
	HijoDos *h2 = new HijoDos(23,67);
	
	Padre *familia[] = {p,h1,h2};
	
	for(int i=0; i<3; i++){
		familia[i]->imprimir();
		cout<<endl;
	}
	
	return 0;
}
