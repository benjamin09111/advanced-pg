#include<iostream>
using namespace std;

/*
3.- Hay diferentes alimentos dentro de una tienda. Frutas, que poseen un color, Galletas,
que posee una cantidad por bolsa y
Lácteos, que poseen cantidad de proteínas. Todas las frutas tienen un precio y un stock asociado. 
Cree en el main las clases con su respectivo stock. Cree una interfaz con: 1. comprar n frutas.
2. mostrar todas las frutas y 
stock. 3. salir.Tome en cuenta que tiene todo el dinero del mundo para comprar,
solo disminuye el stock.
*/

class Alimento{
	protected:
		int stock;
		int precio;
	public:
		Alimento(int stock, int precio){
			this->stock = stock;
			this->precio = precio;
		}
		void disminuirStock(int disminuir){
			if(stock-disminuir>=0){
				stock = stock - disminuir;
			}else{
				cout<<"No hay stock suficiente."<<endl;
			}
		}
};

class Fruta : public Alimento{
	private:
		string color;
	public:
		Fruta(string color, int precio, int stock) : Alimento(precio,stock){
			this->color = color;
		}
		void imprimir(){
			cout<<"FRUTAS"<<endl;
			cout<<"Stock: "<<stock<<endl;
			cout<<"Precio: "<<precio<<endl;
		}
};

class Galleta : public Alimento{
	protected:
		int cantidad;
		int p_descuento;
	public:
		Galleta(int cantidad, int p_descuento, int stock, int precio) : Alimento(stock,precio){
			this->cantidad = cantidad;
			this->p_descuento = p_descuento;
		}
		void imprimir(){
			cout<<"GALLETAS"<<endl;
			cout<<"Stock: "<<stock<<endl;
			cout<<"Precio: "<<precio<<endl;
			cout<<"Descuento: "<<p_descuento<<endl;
		}
};

class Lacteo : public Galleta{
	private:
		int proteinas;
	public:
		Lacteo(int proteinas ,int cantidad, int p_descuento, int stock, int precio) : Galleta(cantidad,p_descuento,stock,precio){
			this->proteinas = proteinas;
		}
		void imprimir(){
			cout<<"LACTEOS"<<endl;
			cout<<"Stock: "<<stock<<endl;
			cout<<"Precio: "<<precio<<endl;
			cout<<"Descuento: "<<p_descuento<<endl;
		}
};


int main (){
	int sf, sg, sl;
	
	cout<<"Ingrese el stock de frutas: "<<endl;
	cin>>sf;
	
	cout<<"Ingrese el stock de galletas: "<<endl;
	cin>>sg;
	
	cout<<"Ingrese el stock de lacteos: "<<endl;
	cin>>sl;
	
	Fruta *frutas = new Fruta("varios",500,sf);
	Galleta *galletas = new Galleta(30,10,sg,1000);
	Lacteo *lacteos = new Lacteo(100,50,20,sl,300);
	
	int opc;
	
	while(true){
		cout<<"TIENDA DE PEPE"<<endl;
		cout<<"_______________"<<endl;
		
		cout<<endl;
		cout<<"1"<<endl;
		frutas->imprimir();
		cout<<endl;
		cout<<"2"<<endl;
		galletas->imprimir();
		cout<<endl;
		cout<<"3"<<endl;
		lacteos->imprimir();
		cout<<endl;
		
		
		cout<<"_______________"<<endl;
		cout<<"1) Comprar producto."<<endl;
		cout<<"2) Salir."<<endl;
		cin>>opc;
		
		if(opc==2){
			break;
		}
		
		if(opc==1){
			int acomprar,cant;
			cout<<"Producto a comprar: "<<endl;
			cin>>acomprar;
			
			cout<<"Cantidad a comprar: "<<endl;
			cin>>cant;
			
			if(acomprar==1){
				
				frutas->disminuirStock(cant);
				
			}else if(acomprar==2){
				
				galletas->disminuirStock(cant);
				
			}else if(acomprar==3){
				
				lacteos->disminuirStock(cant);
				
			}else{
				cout<<"Mal ingresado."<<endl;
			}
			
		}
	}
	
	
	return 0;
}
