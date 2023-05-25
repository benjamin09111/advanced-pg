#include<iostream>
#include<vector>
using namespace std;

/*
ee la clase PRODUCTO que posee un precio y una id.
En la ciudad existen tres tiendas, todas parten con 0
productos.

Cree una interfaz que permita ingresar uno a uno los
productos según la tienda indicada. Además se puede:

- Mostrar todos los productos de cada tienda.
- Mostrar la tienda que posee 0 productos.
- Mostrar el dinero total de cada tienda según sus productos.
*/

class Producto{
	private:
		int precio;
		string id;
	public:
		Producto(int precio, string id){
			this->precio = precio;
			this->id = id;
		}
		int getPrecio(){
			return precio;
		}
		void imprimir(){
			cout<<"Precio: "<<precio<<endl;
			cout<<"Id: "<<id<<endl;
		}
};

int main(){
	int opc;
	
	vector<Producto> t1;
	vector<Producto> t2;
	vector<Producto> t3;
	
	while(true){
		cout<<"1) Agregar producto a tienda 1."<<endl;
		cout<<"2) Agregar producto a tienda 2."<<endl;
		cout<<"3) Agregar producto a tienda 3."<<endl;
		cout<<"4) Salir"<<endl;
		cin>>opc;
		
		int precio;
		string id;
		
		if(opc==4) break;
		
		cout<<"Ingrese precio: "<<endl;
		cin>>precio;
		cout<<"Ingrese id: "<<endl;
		cin>>id;
			
		Producto p = Producto(precio,id);
		
		if(opc==1){
			t1.push_back(p);
		}
		else if(opc==2){
			t2.push_back(p);
		}
		else if(opc==3){
			t3.push_back(p);
		}
		else{
			cout<<"Mal ingresado."<<endl;
		}
	}
	
	cout<<endl<<endl;
	
	cout<<"TIENDA 1: "<<endl;
	cout<<"__________________\n"<<endl;
	
	for(int i=0; i<t1.size(); i++){
		t1[i].imprimir();
		cout<<endl;
	}
	
	cout<<"__________________"<<endl<<endl;
	
		cout<<"TIENDA 2: "<<endl;
	cout<<"__________________\n"<<endl;
	
	for(int i=0; i<t2.size(); i++){
		t2[i].imprimir();
		cout<<endl;
	}
	
	cout<<"__________________"<<endl<<endl;
	
		cout<<"TIENDA 3: "<<endl;
	cout<<"__________________\n"<<endl;
	
	for(int i=0; i<t3.size(); i++){
		t3[i].imprimir();
		cout<<endl;
	}
	
	cout<<"__________________"<<endl<<endl<<endl;
	
	if(t1.size()==0){
		cout<<"La tienda 1 no tiene productos."<<endl;
	}
	if(t2.size()==0){
		cout<<"La tienda 2 no tiene productos."<<endl;
	}
	if(t3.size()==0){
		cout<<"La tienda 3 no tiene productos."<<endl;
	}
	
	cout<<endl<<endl;

	int precio1=0, precio2=0, precio3=0;
	
	cout<<"DINERO TOTAL TIENDA 1: ";
	
	for(int i=0; i<t1.size(); i++){
		precio1 = precio1 + t1[i].getPrecio();
	}
	
	cout<<precio1<<endl<<endl;
	
	cout<<"DINERO TOTAL TIENDA 2: ";
	
	for(int i=0; i<t2.size(); i++){
		precio2 = precio2 + t2[i].getPrecio();
	}
	
	cout<<precio2<<endl<<endl;
	
	cout<<"DINERO TOTAL TIENDA 3: ";
	
	for(int i=0; i<t3.size(); i++){
		precio3 = precio3 + t3[i].getPrecio();
	}
	
	cout<<precio3<<endl<<endl;
	
	
	return 0;
}
