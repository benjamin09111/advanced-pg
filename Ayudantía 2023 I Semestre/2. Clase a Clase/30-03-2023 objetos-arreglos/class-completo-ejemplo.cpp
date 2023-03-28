#include<iostream>
using namespace std;

//bastante completo: pero hay que repasar de los ppt del profe para la evaluacion
//o lo que él haya pasado en clase

class Personaje{
	private:
		//atributos
		string nombre;
		int vida;
		bool vivo;
	public:
		//constructor (mas comun)
		Personaje(string nombre, int vida, bool vivo){
			this->nombre = nombre;
			this->vida = vida;
			this->vivo = vivo;
		}
		//constructor 2...
		Personaje(string nombre, int vida){
			this->nombre = nombre;
			this->vida = vida;
			
			this->vivo = true;
		}
		//constructor vacio
		Personaje();
		
		//gets
		string getNombre(){
			return nombre;
		}
		int getVida(){
			return vida;
		}
		bool getVivo(){
			return vivo;
		}
		//sets
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void setVida(int vida){
			this->vida = vida;
		}
		void setVivo(bool vivo){
			this->vivo = vivo;
		}
		//funciones extra: ejemplos
		
		void imprimir(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Vida: "<<vida<<endl;
			
			if(vivo){
				cout<<"Estado: Vivo"<<endl;
			}else{
				cout<<"Estado: Muerto"<<endl;
			}
			
		}
		
		string presentarseEpicamente(){
			return "Mi nombre es "+nombre+"!!!";
		}
		
		void recibirCuracion(int curacion){
			
			vida = vida + curacion;
			
			cout << "El personaje " << nombre
			<< "se ha curado por: " << curacion
			<<" puntos." <<endl;
			
		}
		
		void recibirDanio(int danio){
			
			if(vida-danio < 0){
				
				vida = vida - danio;
				
				cout << "El personaje " << nombre << " ha muerto!" <<endl;
				
			}else{
				
				cout << "El personaje " << nombre
				<< " ha recibido " << danio <<" de danio. "<<endl;
				
			}	
			
		}
		
		void revivir(){
			
			if(!vivo){ //lo mismo que vivo==false
			
				vivo = true;
				cout << "El personaje " << nombre <<" ha resucitado. " <<endl;
				
			}else{
				cout << "El personaje " << nombre <<" ya esta vivo.  " <<endl;
			}
			
		}
		
		void enfrentarseCon(Personaje *p){
			
			if( p->getVida() > this->vida){
				
				cout << this->nombre <<": Tienes mas vida que yo!" <<endl;
				
				cout << p->getNombre() <<": Vete de aqui!" <<endl;
				
			}else if(p->getVida() == this->vida){
				
				cout << this->nombre <<": Sera un enfrentamiento justo!" <<endl;
				
				cout << p->getNombre() <<": Asi sera!" <<endl;
				
			}else{
				
				cout << this->nombre <<": Tengo mas vida que tu, deberias correr!" <<endl;
				
				cout << p->getNombre() <<": Prefiero morir a correr! *grita mientras se aleja* " <<endl;
				
			}
			
		}
		
		void opinarDe(Personaje *characters[], int n){
			//recibo tamaño del arreglo, asumire que sé el tamaño del arreglo
			//y ademas sé cuantos elementos hay dentro, eso es n, estando lleno
			
			for (int i=0; i<n; i++){
				
				if (this->vida >= characters[i]->getVida()){
					
					cout << this->nombre <<": Ese es "<< characters[i]->getNombre() <<
					", sencillo! " <<endl;
					
				}else{
					
					cout << this->nombre <<": O no! Es " << characters[i]->getNombre() <<
					", adios! *se va corriendo* " <<endl;
					
				}
				
			}
			
		}	
					
};

//ESTO SE VERÁ MÁS ADELANTE

class Arena{
	private:
		Personaje *personajes[3];
	public:
		Arena(){
			
			for(int i=0; i<3; i++){
				personajes[i] = NULL;
			}
			
		}
		void imprimirPersonajes(){
			
			cout << "*****ARENA*****" << endl;
			
			for(int i=0; i<3; i++){
				personajes[i]->imprimir();
				
				cout<<endl;
			}
			
		}
};

int main (){
	
	Personaje *protagonista = new Personaje("Josefo",250,true);
	
	Personaje *villano1 = new Personaje("Malcom",400,true);
	
	Personaje *villano2 = new Personaje("Yan",200,true);
	
	Personaje *villano3 = new Personaje("Christy",300,true);

	
	//probar funciones
	
	//arreglos desde el main directo
	
	Personaje *villanos[] = {villano1,villano2,villano3};
	
	//trabajando con arreglos desde cero
	
	Personaje *array[3];
	
	//agregar
	
	array[0] = protagonista;
	
	array[1] = new Personaje("NombreRandom1",500,true);
	
	array[2] = new Personaje("NombreRandom2",600,true);
	
	//imprimir y acceder a posiciones
	
	for(int i=0; i<3; i++){
		
		array[i]->imprimir();
		
		cout<<endl;
	}
	
	//usuario ingresa tamanio
	
	int vida;
	string nombre;
	int n;
	
	cout << "Ingrese el tamanio de su arreglo: " << endl;
	
	cin >> n;
	
	Personaje *array2[n];
	
	for (int i=0; i<n; i++){
		
		cout << "Ingrese nombre del personaje "<<i+1<<endl;
		cin>>nombre;
		
		cout << "Ingrese vida del personaje "<<i+1<<endl;
		cin>>vida;
		
		array2[i] = new Personaje(nombre,vida,true);
		
	}
	
	cout <<endl <<endl;
	
	for(int i=0; i<n; i++){
		
		array2[i]->imprimir();
		
		cout<<endl;
	}
	
	//imprimir solo los dos primeros nombres
	
	if(n>=2){
		
		for(int i=0; i<n; i++){
		
		cout << "Nombre "<< i+1 <<": " << array2[i]->getNombre() << endl;
		
		cout << endl;
	}
		
	}else{
		
		cout <<"No se pueden imprimir los dos primeros nombres porque hay menos de 2 personajes."<<endl;
		
	}
	
	//operaciones cualquiera sea
	
	
	
	
	
	return 0;
}
