#include<iostream>
using namespace std;

/*
2.- Cree una Tienda de herramientas. Esta posee el nombre y además la información de
sus Herramientas. Estas indican
la cantidad de herramientas y el precio de cada una (todas valen lo mismo
.Cree ambas clases.
Cree un método que permita comparar con otra Tienda, y muestre cuál tiene mayor
precio total de todas sus herramientas.
*/

class Herramientas{
	private:
		int cantidad;
		int precio;
	public:
		Herramientas(int cantidad, int precio){
			this->cantidad = cantidad;
			this->precio = precio;
		}
		int getPrecio(){
			return precio;
		}
		int getCantidad(){
			return cantidad;
		}
		int getTotal(){
			return precio*cantidad;
		}
};

class Tienda{
	private:
		string nombre;
		Herramientas *h;
	public:
		Tienda(string nombre, int cantidad, int precio){
			this->nombre = nombre;
			h = new Herramientas(cantidad,precio);
			
			/*
			forma alternativa
			
			Herramientas *nuevah = new Herramientas(cantidad,precio);
			this->h = nuevah;
			*/
		}
		void imprimir(){
			cout<<"Nombre de la tienda: "<<nombre<<endl;
			cout<<"Cantidad herramientas: "<<h->getCantidad()<<endl;
			cout<<"Precio de las herramientas: "<<h->getPrecio()<<endl;
		}
		void comparar(Tienda *t){
			
			int total1 = h->getTotal();
			int total2 = t->h->getTotal();
			
			if(total1>total2){
				
				cout<<"Mayor tienda: "<<endl;
				imprimir();
				
			}else if(total1==total2){
				
				cout<<"Ambos tienen el mismo valor total."<<endl;
				
			}else{
				
				cout<<"Mayor tienda: "<<endl;
				t->imprimir();
			}
			
		}
};

int main(){	
	Tienda *t1 = new Tienda("Tienda uno",5,2500);
	Tienda *t2 = new Tienda("Tienda dos",3,1000);
	
	t1->comparar(t2);
	
	return 0;
}
