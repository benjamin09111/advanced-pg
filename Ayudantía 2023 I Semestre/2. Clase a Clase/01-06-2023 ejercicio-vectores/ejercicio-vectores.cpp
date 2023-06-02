#include<iostream>
#include<vector>
using namespace std;

/*
Cree una clase Programador que tiene un nombre y salario.
Tiene una variable int que indica la cantidad de tareas pendientes.
Ademas tiene un bool que indica si esta en hora de trabajo o no.
Cree las funciones:
	- empezar a trabajar, dejar de trabajar
	- imprimir informacion
	- mostrar cantidad de tareas pendientes.
	- disminuir una tarea, aumentar una tarea.
	
Cree la clase Empresa que contiene un vector de Programadores. Cree:
	- agregar Programador
	- quitar Programador
	- mostrar todas las tareas pendientes de la empresa.
	- mostrar el Programador que tiene mayor salario.
	- mostrar Promedio de los salarios.
	- mostrar cantidad de trabajadores en tiempo de trabajo.
	- consultar por un nombre y permitir acceder a funciones de
	disminuir o agregar tareas, empezar a trabajar o dejar de trabajar.
	- funcion que imprime todos los trabajadores	

*/

class Programador{
	private:
		string nombre;
		int salario;
		int cantidad_tareas;
		bool trabajando; //true -> esta en horario de trabajo, false no
	public:
		Programador(string nombre, int salario){
			this->nombre = nombre;
			this->salario = salario;
			cantidad_tareas = 0;
			trabajando = false;
		}
		//imprimir
		void imprimir(){
			cout<<"Trabajador: "<<nombre<<endl;
			cout<<"Salario: "<<salario<<endl;
			cout<<"Tareas pendientes: "<<cantidad_tareas<<endl;
			if(trabajando){
				cout<<"Actualemnte en horario de trabajo."<<endl;
			}else{
				cout<<"No se encuentra en horario de trabajo."<<endl;
			}
		}
		string getNombre(){
			return nombre;
		}
		int getCantidadTareas(){
			return cantidad_tareas;
		}
		int getSalario(){
			return salario;
		}
		bool getTrabajando(){
			return trabajando;
		}
		//modificar atributos
		void trabajar(){
			if(trabajando){
				cout<<"Ya esta en horario de trabajo."<<endl;
			}else{
				trabajando = true;
			}
		}
		void descansar(){
			if(trabajando){
				trabajando = false;
			}else{
				cout<<"Ya esta en horario de descanso."<<endl;
			}
		}
		//modificar tareas
		void agregarTarea(){
			cantidad_tareas++;
		}
		void quitarTarea(){
			if(cantidad_tareas==0){
				cout<<"Ya no tiene tareas pendientes."<<endl;
			}else{
				cantidad_tareas--;
			}
		}
};

class Empresa{
	private:
		vector<Programador*>* programadores = new vector<Programador*>;
	public:
		Empresa(){}
		//metodos del ejercicio
		void agregarProgramador(Programador *p){
			programadores->push_back(p);
		}
		//quitar por detras
		void quitarProgramador(){
			if(programadores->size()==0){
				cout<<"No hay programadores."<<endl;
			}else{
				programadores->pop_back();
			}
		}
		//tareas pendientes
		int getTareasPendientes(){
			int total=0;
			
			for(int i=0; i<programadores->size(); i++){
				total = total + programadores->at(i)->getCantidadTareas();	
			}
			
			return total;
		}
		//programador nombre con mayor salario
		void mayorProgramadorGanancia(){
			int referencia = 0;
			int pos;
			
			for(int i=0; i<programadores->size(); i++){
				if(referencia < programadores->at(i)->getSalario()){
					referencia = programadores->at(i)->getSalario();
					pos = i;
				}
			}
			
			cout<<"El programador que mas gana es "
			<<programadores->at(pos)->getNombre()<<endl;
		}
		
		float promedioSalarios(){
			float promedio=0;
			
			for(int i=0; i<programadores->size(); i++){
				promedio = promedio + programadores->at(i)->getSalario();
			}
			
			return promedio/programadores->size();
		}
		
		int programadoresEnTrabajo(){
			int trabajando=0;
			
			for(int i=0; i<programadores->size(); i++){
				if(programadores->at(i)->getTrabajando()){
					trabajando++;
				}
			}
			
			return trabajando;
		}
		void modificar(string nombre){
			int posicion=-1;
			
			for(int i=0; i<programadores->size(); i++){
				if(programadores->at(i)->getNombre()==nombre){
					posicion=i;
				}
			}
			
			if(posicion==-1){
				cout<<"No existe ese programador."<<endl;
			}else{
				int opc;
				cout<<"1) Agregar una tarea."<<endl;
				cout<<"2) Quitar una tarea."<<endl;
				cout<<"3) Comenzar a trabajar."<<endl;
				cout<<"4) Dejar de trabajar."<<endl;
				cin>>opc;
				
				if(opc==1){
					programadores->at(posicion)->agregarTarea();
				}else if(opc==2){
					programadores->at(posicion)->quitarTarea();
				}else if(opc==3){
					programadores->at(posicion)->trabajar();
				}else if(opc==4){
					programadores->at(posicion)->descansar();
				}else{
					cout<<"Mal ingresado."<<endl;
				}	
			}	
		}
};

int main() {
    // Crear programadores
    Programador* programador1 = new Programador("Juan", 2000);
    Programador* programador2 = new Programador("Pedro", 2500);
    Programador* programador3 = new Programador("María", 1800);
    
    // Crear empresa
    Empresa empresa;
    
    // Agregar programadores a la empresa
    empresa.agregarProgramador(programador1);
    empresa.agregarProgramador(programador2);
    empresa.agregarProgramador(programador3);
    
    //
    empresa.modificar("Juan");
    
    // Mostrar cantidad de tareas pendientes en la empresa
    cout << "Total de tareas pendientes: " << empresa.getTareasPendientes() << endl;
    
    // Mostrar programador con mayor salario
    empresa.mayorProgramadorGanancia();
    
    // Mostrar promedio de salarios en la empresa
    cout << "Promedio de salarios: " << empresa.promedioSalarios() << endl;
    
    // Liberar memoria de los programadores
    delete programador1;
    delete programador2;
    delete programador3;
    
    return 0;
}

