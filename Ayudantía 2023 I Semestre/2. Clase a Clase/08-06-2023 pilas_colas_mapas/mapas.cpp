#include<iostream>
#include<map>
using namespace std;

//definir
typedef pair<string,int> par;
typedef map<string,int> Inventario;

int main (){
	//crear
	Inventario productos;
	
	//insertar
	productos.insert( par("313#$_21", 1500) );
	productos.insert( par("14_2#", 3000) );
	productos.insert( par("5!4-1", 4000) );
	productos.insert( par("62$_0", 5200) );
	
	//eliminar
	productos.erase("5!4-1");
	
	//recorrer y mostrar
	
	map<string,int>::iterator i;
	for(i = productos.begin(); i != productos.end(); i++){
		cout<<" Codigo: "<< i->first <<" Precio: "<< i->second <<endl;
	}
	
	//buscar
	i = productos.find("5!4-1");
	
	if(i != productos.end()){
        cout<<"Precio buscado: "<<i->second<<endl;
    }
    else {
        cout<<"Producto no encontrado"<<endl;
    }
	
	cout<<"Precio buscado: "<<i->second<<endl;
	
	//tambien tenemos el size() y el clear()
	
	return 0;
}
