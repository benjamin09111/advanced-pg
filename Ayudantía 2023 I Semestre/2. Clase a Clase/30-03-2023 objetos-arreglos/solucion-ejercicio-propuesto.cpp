#include<iostream>
using namespace std;

class Mascota{
	private:
		string nombre, color;
		int edad;
	public:
		Mascota(string nombre, int edad, string color){
			this->nombre = nombre;
			this->edad = edad;
			this->color = color;
		}
		string getNombre(){
			return nombre;
		}
		int getEdad(){
			return edad;
		}
		void cumplirAnios(){
			edad++;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void imprimir(){
			cout<<"{"<<endl;
			cout<<"	Nombre: "<<nombre<<endl;
			cout<<"	Edad: "<<edad<<endl;
			cout<<"	Color: "<<color<<endl;
			cout<<"}"<<endl;
		}
};

int main (){
	int n;
	cout << "Ingrese su cantidad de mascotas: " <<endl;
	cin >> n;
	
	//crear arreglo
	Mascota *Casa[3];
	
	//llenar arreglo
	string nombre, color;
	int edad;
	
	for (int i=0; i<n; i++){
		
		cout << "Ingrese el nombre de la mascota "<<i+1<<endl;
		cin>>nombre;
		
		cout << "Ingrese la edad de la mascota "<<i+1<<endl;
		cin>>edad;
		
		cout << "Ingrese el color de la mascota "<<i+1<<endl;
		cin>>color;
		
		Casa[i] = new Mascota(nombre,edad,color);
		
		/*
		otra forma:
			
			Mascota *m = new Mascota(nombre,edad,color);
			
			Casa[i] = m;
		
		*/
		
	}
	
	//imprimir las mascotas
	
	for(int i=0; i<n; i++){
		
		Casa[i]->imprimir();
		
		cout<<endl;
	}
	
	cout<<endl;
	
	//promedio en int
	int promedio=0;
	
	for(int i=0; i<n; i++){
		
		promedio = promedio + Casa[i]->getEdad();
		
	}
	
	cout<<"\nEl promedio de las edades es: "<< promedio/n <<endl;
	
	//cumplir años
	string name;
	cout << "\nIngrese el nombre de la mascota de cumpleanos: "<<endl;
	cin>>name;
		
	bool encontrado = false;
		
	for(int i=0; i<n; i++){
			
		if(Casa[i]->getNombre() == name){
				
			Casa[i]->cumplirAnios();
			encontrado=true;
			break;
				
		}
			
	}
	
	if(encontrado==true){
		cout << "Ha aumentado su edad." <<endl;
	}else{
		cout << "No se ha encontrado esa mascota." <<endl;
	}
	
	string cambio;
	
	cout << "Cambiar el nombre de la mascota " <<n-1<<": "<<endl; //n-1 es la ultima posicion del arreglo.
	
	cin >> cambio;
	
	if(cambio != Casa[n-1]->getNombre()){
		Casa[n-1]->setNombre(cambio);
	}else{
		cout<<"No puede cambiarse por un nombre igual al que ya posee."<<endl;
	}
	
	cout <<endl;
	
	//imprimir las mascotas nuevamente
	
	for(int i=0; i<n; i++){
		
		Casa[i]->imprimir();
		
		cout<<endl;
	}
	
		
	
	
	return 0;
}
