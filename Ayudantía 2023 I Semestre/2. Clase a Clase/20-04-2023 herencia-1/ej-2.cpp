#include<iostream>
using namespace std;

/*
2.- Existen diferentes herramientas: hacha, pala, las cuales tienen un precio,
y un martillo, el cual además tiene
una durabilidad. Cree las herencias. Cree una interfaz, con opciones: crear
y mostrar herramienta. Mostar 
el total de herramientas creadas. Salir.
*/

class Herramienta{
	protected:
		int precio;
	public:
		Herramienta(int precio){
			this->precio = precio;
		}
		void imprimir(){
			cout<<"Precio: "<<precio<<endl;
		}
};

class Martillo : public Herramienta{
	private:
		int durabilidad;
	public:
		Martillo(int durabilidad, int precio) : Herramienta(precio){
			this->durabilidad = durabilidad;
		}
		void imprimir(){
			cout<<"Precio: "<<precio<<endl;
			cout<<"Durabilidad: "<<durabilidad<<endl;
		}
};

int main (){
	int creadas=0;
	int precio, durabilidad;
	int opcion;
	
	while(true){
		cout<<"1) Crear herramienta."<<endl;
		cout<<"2) Mostrar cantidad de herramientas creadas."<<endl;
		cout<<"3) Salir."<<endl;
		cin>>opcion;
		
		if(opcion==3){
			break;
		}
		
		if(opcion==1){
			int opc;
			
			cout<<"1) Hacha"<<endl;
			cout<<"2) Pala"<<endl;
			cout<<"3) Martillo"<<endl;
			
			cin>>opc;
			
			if(opcion==1){
				cout<<"Ingrese el precio del hacha: "<<endl;
				cin>>precio;
				
				Herramienta *h = new Herramienta(precio);
				
				h->imprimir();
				
				creadas++;
				
			}else if(opcion==2){
				cout<<"Ingrese el precio del pala: "<<endl;
				cin>>precio;
				
				Herramienta *h = new Herramienta(precio);
				
				h->imprimir();
				
				creadas++;
				
			}else if(opcion==3){
				cout<<"Ingrese el precio del martillo: "<<endl;
				cin>>precio;
				cout<<"Ingrese la durabilidad del martillo: "<<endl;
				cin>>durabilidad;
				
				Martillo *m = new Martillo(durablidad,precio);
				
				m->imprimir();
				
				creadas++;
			}else{
				
				cout<<"Mal ingresado."<<endl;
				
			}
			
		}else if(opcion==2){
			
			cout<<"Cantidad de herramientas creadas: "<<creadas<<endl;
			
		}else{
			cout<<"Mal ingresado."<<endl;
		}
	}
	
	
	return 0;
}
