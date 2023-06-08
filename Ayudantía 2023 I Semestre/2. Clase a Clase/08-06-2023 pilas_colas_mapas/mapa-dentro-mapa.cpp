#include<iostream>
#include<map>
using namespace std;

//hacer para cada mapa: crear y pares
typedef pair<string, map<string,int> > par1;
typedef map<string, map<string,int> > mapa1;

typedef pair<string,int>  par2;
typedef map<string,int> mapa2;

//iterador para cada mapa
map<string, map<string,int> >::iterator i;
map<string,int>::iterator j;

int main(){
	mapa1 mapa_grande;
	
	//crear valores mapas
	mapa2 ej1;
	mapa2 ej2;
	
	ej1.insert(par2("1",1));
	ej1.insert(par2("2",2));
	ej1.insert(par2("3",3));
	
	ej2.insert(par2("1",4));
	ej2.insert(par2("2",5));
	ej2.insert(par2("3",6));
	
	//ingresar al mapa grande
	
	mapa_grande.insert(par1("primerMapa",ej1));
	mapa_grande.insert(par1("segundoMapa",ej2));
	
	//recorrer mapa grande y mostrar todo
	
	for(i = mapa_grande.begin(); i!= mapa_grande.end(); i++){
		cout<<"Llave: "<<i->first<<", sus valores son: "<<endl;
		for(j = i->second.begin(); j != i->second.end(); j++){
			cout<<"Clave: "<<j->first<<" | Valor: "<<j->second<<endl;
		}
		cout<<endl;
	}
	
}
