#include<iostream>
#include<map>
using namespace std;

class Producto{
	private:
		int monto;
	public:
		Producto(int monto){
			this->monto =monto;
		}
		int getMonto(){
			return monto;
		}
};

//definir
typedef pair<string,Producto> par;
typedef map<string,Producto> Inventario;

int main (){
	//productos
	Producto p1 = Producto(4500);
	Producto p2 = Producto(3500);
	Producto p3 = Producto(2500);
	Producto p4 = Producto(1500);
	
	//crear
	Inventario productos;
	
	//insertar
	productos.insert( par("313#$_21", p1) );
	productos.insert( par("14_2#", p2) );
	productos.insert( par("5!4-1", p3) );
	productos.insert( par("62$_0", p4) );
	
	//eliminar
	productos.erase("5!4-1");
	
	//recorrer y mostrar
	
	map<string,Producto>::iterator i;
	for(i = productos.begin(); i != productos.end(); i++){
		cout<<" Codigo: "<< i->first <<" Precio: "<< i->second.getMonto() <<endl;
	}
	
	//buscar
	i = productos.find("5!4-1");
	
	if(i != productos.end()){
        cout<<"Precio buscado: "<<i->second.getMonto()<<endl;
    }
    else {
        cout<<"Producto no encontrado"<<endl;
    }
	
	//tambien tenemos el size() y el clear()
	
	return 0;
}
