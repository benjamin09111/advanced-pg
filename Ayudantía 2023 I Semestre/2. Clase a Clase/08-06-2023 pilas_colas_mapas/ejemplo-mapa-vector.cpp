#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
	rut -> [6.4 5.2 7.0]
	rut -> [6.4 5.2 7.0]
	rut -> [6.4 5.2 7.0]
	rut -> [6.4 5.2 7.0]
	rut -> [6.4 5.2 7.0]
	rut -> [6.4 5.2 7.0]
*/

typedef pair<string, vector<float> > par;
typedef map<string, vector<float> > mapa;

int main (){
	mapa notas;
	
	vector<float> v1;
	
	v1.push_back(6.7);
	v1.push_back(6.4);
	v1.push_back(6.2);
	
	vector<float> v2;
	
	v2.push_back(6.3);
	v2.push_back(6.1);
	v2.push_back(6.0);
	
	notas.insert( par("3192491-1",v1) );
	notas.insert( par("1314561-K",v2) );
	
	map<string,vector<float> >::iterator i;
	
	for(i = notas.begin(); i != notas.end(); i++){
		cout<<" Rut: "<< i->first<<endl;
		
		for(int j=0; j< i->second.size(); j++ ){
			cout<< i->second[j] <<" ";
		}
		
		cout<<endl;
	}
	
	
	return 0;
}
