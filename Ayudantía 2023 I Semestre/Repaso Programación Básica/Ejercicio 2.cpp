#include<iostream>
using namespace std;

/*
4. Se tiene una interfaz que permite llenar
tu carrito. Con un total de cinco espacios,
se va agregando el valor del producto. Cree una
función aparte que verifique que, si el producto
tiene un precio mayor a 5000, se tenga un 15% de descuento.
Además de la opción de agregar, hay una opción para vaciar el
carrito, lo que significa pagarlo, solo debe mostrar el total
a pagar y la cantidad de productos que se compraron.
*/

int main (){
	
	int opcion;
	
	int carrito[7];
	int productos=0;
	
	while(true){
		system("cls");
		
		cout << "BIENVENIDO AL CARRITO"<<endl;
		cout <<"1) Agregar producto "<<endl;
		cout <<"2) Vaciar carrito y comprar."<<endl;
		cout <<"3) Salir."	<<endl<<endl<<endl;
		
		cout<<"Carrito actual: "<<endl;
		
		for(int i=0; i<productos; i++){
			cout << carrito[i]<<endl;
		}
		
		cin >> opcion;
		
		if(opcion==3){
			break;
		}	
		
		if(opcion==1){
			system("cls");
			
			if(productos<7){
				cout << "Ingrese su producto: "<<endl;
				
				cin>>carrito[productos];
				
				productos++;
				
			}else{
				cout << "No se puede agregar mas producto."<<endl;
				system("pause");
			}	
		}else if(opcion==2){
			system("cls");
			int total=0;
			//vaciar y comprar
			
			for(int i=0; i<productos; i++){
				
				total = total + carrito[i];
				
			}
			
			cout << "El total es: "<<total<<endl;
			
			productos = 0;
			
			system("pause");
		}
		
	}
	
	
	return 0;
}
