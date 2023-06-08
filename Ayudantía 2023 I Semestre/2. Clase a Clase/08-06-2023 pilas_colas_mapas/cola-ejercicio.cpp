#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Cancion{
	private:
		string nombre;
		int popularidad;
	public:
		Cancion(string nombre, int popularidad){
			this->nombre = nombre;
			this->popularidad = popularidad;
		}
		string getNombre(){
			return nombre;
		}
		int getPopularidad(){
			return popularidad;
		}
};

class Playlist{
	private:
		string nombre;
		queue<Cancion> lista;
	public:
		Playlist(string nombre){
			this->nombre = nombre;
		}
		int size(){
			return lista.size();
		}
		void ingresarCancion(string nombre, int popularidad){
			Cancion c = Cancion(nombre,popularidad);
			lista.push(c);
		}
		void reproducirSiguiente(){
			if(lista.empty()==false){
				lista.pop();
			}else{
				cout<<"No hay mas canciones."<<endl;
			}
		}
		string cancionActual(){
			if(lista.empty()==false){
				return lista.front().getNombre();
			}else{
				return "No hay canciones actualmente";
			}
		}
		void imprimirCanciones(){
			vector<Cancion> respaldo; 

			while(!lista.empty()){
				respaldo.push_back(lista.front());
				cout<<"Cancion: "<<lista.front().getNombre()<<endl;
				lista.pop();
			}
			//volver a llenar
			for(int i=0; i<respaldo.size(); i++){
				lista.push(respaldo[i]);
			}
		}
		//obtener cancion con mayor popularidad...
		
};

int main(){
	Playlist p = Playlist("Mis canciones favoritas");
	
	p.ingresarCancion("s1",13);
	p.ingresarCancion("s2",15);
	p.ingresarCancion("s3",17);
	p.ingresarCancion("s4",10);
	p.ingresarCancion("s5",7);
	
	int opc;
	
	while(true){
		system("cls");
		cout<<"CANCION ACTUAL: "<<p.cancionActual()<<endl;
		cout<<"1) Siguiente cancion"<<endl;
		cout<<"2) Salir"<<endl;
		cin>>opc;
		
		if(opc==2) break;
		
		if(opc==1){
			p.reproducirSiguiente();
		}
	}
		
	return 0;
}
