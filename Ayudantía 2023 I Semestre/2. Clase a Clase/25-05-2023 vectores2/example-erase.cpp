#include<iostream>
#include<vector>

using namespace std;

int main (){
	
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); //i=3 -> begin+i
	v.push_back(5);
	v.push_back(6);
	
	//erase: begin representa posicion cero
	//uno o dos par�metros
	v.erase(v.begin()+3);
	
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	
	
	return 0;
}
