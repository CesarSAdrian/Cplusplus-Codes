/*Código para utilizar sentencias de repetición y arreglos para calcular las
temperaturas de tres días diferentes y el promedio de estas en tres ciudades diferentes.

Código de la clase de Programación Estructurada. Inspired in Dra. Karla Cantún code, 
modified by Cesar Sanchez.

Con manipuladores de impresión.
goto = tp - Llevarte a una parte del programa.
*/

#include <iostream>
#include <string>
#include <iomanip>

#define F 3 //Número de ciudades
#define C 4 //Cantidad de días (3) más el promedio

using namespace std;

//Declaración de funciones
bool presentacion(void);
void inicio();
void imprimir(string title[], string nc[], int op, float tmp[][C]);
void cleaning();
void temp(string title[], string nc[], int op, float tmp[][C]);

int main(){
	
	while(presentacion()){
		inicio();
	}
	
	
	
	/*float temperature[3][4] = {};
	string cities[3];*/	
	
	return 0;
}

bool presentacion(){
	
	bool st;
	char r;
	
	cout<<"\n***** Temperatura Promedio *****\n\nPulsa 1 para ingresar a la app que "
	<<"te permite calcular la temp. promedio\nregistrada en "<<F<<" ciudades"
	<<" diferentes, en "<<C<<" dias: ";
	cin>>r;
	
	st = (r=='1')?true:false;
	
	return st;
}

void inicio(){
	
	char r;
	int m;
	string titulo[] = {"ID", "Ciudad", "TD1", "TD2", "TD3", "TAv"};
	string cities[F]; //Nombre de las ciudades
	float temperature[F][C] = {0}; //Temperaturas registradas + la temperatura promedio
	//imprimir(titulo);
	
	cleaning();
	
	cout<<"\nRegistra el nombre de las ciudades:\n";
	for(int i=0; i<F; i++){
		cout<<"Ciudad "<<i+1<<": ";
		getline(cin, cities[i], '\n');
	}
	repetir:cout<<"\n----- Ciudades registradas -----"<<endl;
	imprimir(titulo, cities, 1, temperature);
	cout<<"\nPulse M para modificar algun nombre: ";
	cin>>r;
	if(r == 'M'){
		cout<<"\nIngresa el numero de la ciudad a modificar: ";
		cin>>m;
		if(m>=0 && m<=F){
			cout<<"\nIngresa el nuevo nombre: ";
			cleaning();
			getline(cin, cities[m-1]);
			//imprimir(titulo, cities, 1);
			goto repetir;
		}
	}
	temp(titulo, cities, 1, temperature);
}

void imprimir(string title[], string nc[], int op, float tmp[][C]){
	/*for(int k=0; k<F+C; k++){
		cout<<title[k]<<" ";
	}*/
	if(op == 1){
		//Solo ciudades
		for(int i=0; i<F; i++){
			cout<<i+1<<"\t"<<nc[i]<<endl;
		}
	}else if(op == 2){
		//Tabla de registros
		cout<<endl<<endl;
		cout<<setw(4)<<left<<title[0]<<setw(25)<<left<<title[1];
		for(int k=2; k<(C+1); k++)cout<<setw(8)<<right<<title[k];
		cout<<endl;
		
		for(int i=0; i<F; i++){
			cout<<setw(4)<<left<<i+1<<setw(25)<<left<<nc[i];
			
			for(int j=0; j<(C-1); j++){
				cout<<setw(8)<<right<<tmp[i][j];
			}
			cout<<endl;
		}
	}else if(op == 3){
		///Tabla de registros
		cout<<endl<<endl;
		cout<<setw(4)<<left<<title[0]<<setw(25)<<left<<title[1];
		for(int k=2; k<(C+2); k++)cout<<setw(8)<<right<<title[k];
		cout<<endl;
		
		for(int i=0; i<F; i++){
			cout<<setw(4)<<left<<i+1<<setw(25)<<left<<nc[i];
			
			for(int j=0; j<(C); j++){
				cout<<setw(8)<<right<<tmp[i][j];
			}
			cout<<endl;
		}
	}
}

void cleaning(){
	cin.clear();
	cin.ignore();
}

void temp(string title[], string nc[], int op, float tmp[][C]){
	
	cout<<"\n***** Resgitro de Temperaturas *****"<<endl;
	
	for(int i=0; i<F; i++){
		cout<<"\nTemperaturas de "<<nc[i]<<": ";
		
		for(int j=0; j<C-1; j++){
			cout<<"\nDia "<<j+1<<": ";
			cin>>tmp[i][j];
			tmp[i][C-1]+=tmp[i][j]; 	//Acumulo las temperaturas
			if(j==(C-2))tmp[i][C-1]/=(C-1);
		}
	}
	cout<<"\n***** Valores registrados *****"<<endl;
	imprimir(title, nc, 2, tmp);
	cout<<"\n***** Temperaturas Promedio *****"<<endl;
	imprimir(title, nc, 3, tmp);
}
