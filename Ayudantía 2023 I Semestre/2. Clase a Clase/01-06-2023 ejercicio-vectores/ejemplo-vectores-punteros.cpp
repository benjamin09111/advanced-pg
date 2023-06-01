#include<iostream>}
#include<vector>
using namespace std;

class Objeto{
	private:
		string nombre;
	public:
		Objeto(string n){
			nombre = n;
		}
		void imprimir(){
			cout<<nombre<<endl;
		}
};

int main(){	
	vector<Objeto*>* v = new vector<Objeto*>;
	
	Objeto *o = new Objeto("pepe");
	
	v->push_back(o);
	
	v->at(0)->imprimir();
	 
	
	return 0;
}
