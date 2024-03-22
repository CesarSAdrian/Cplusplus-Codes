/*Este código ejecuta operaciones entre matrices (suma o multiplicación).

Código realizado por la Dra. Karla Cantún en la clase de Porgramación Estructurada.*/

#include <iostream>
#include <string>

#define F 50 //Tamaño de elementos predefinido.
#define C 50

using namespace std;

int f1, f2, c1, c2;

float a[F][C][2], d[F][C]={0};

//Definir funciones
bool presentacion();
void inicio();

void rango(char o);
void registro(char o);
void suma();
void producto();
void imprimir(string t, char smb);

int main(){
	
	while(presentacion()) inicio();	
	return 0;
}

bool presentacion(){
	bool r;
	char t;
	cout<<"\n***** Operaciones matriciales *****"
	<<"\n\nPulsa 1 para ingresar a la aplicacion\nCualquier otra tecla "
	<<"cerrara el programa.\n";
	
	cin>>t;
	r=(t=='1')?true:false;
	return r;
	
}

void inicio(){
	
	char op;
	cout<<"\nSelecciona la operacion que desee realizar: \n"
	<<"a)\tSuma de matrices (maximo 50 x 50 elementos).\n"
	<<"b)\tMultiplicacion de matrices (maximo 50 x 50 elementos).\n";
	cin>>op;

	if(op=='a'){
		
		rango(op);
		registro(op);
		suma();
		
	}else if(op=='b'){
		
		rango(op);
		registro(op);
		producto();
		
	}else{
		cout<<"\nOpcion incorrecta.\n\n";
	}

}

void rango(char o){
	
	bool s;
	
	do{
		cout<<"\nIngrese por favor el numero de filas de la primera matriz: ";
		cin>>f1;
		cout<<"\nIngrese por favor el numero de columnas de la primera matriz: ";
		cin>>c1;
		
		cout<<"\nIngrese por favor el numero de filas de la segunda matriz: ";
		cin>>f2;
		cout<<"\nIngrese por favor el numero de columnas de la segunda matriz: ";
		cin>>c2;
		
		if(o=='a'){
			
			s = (f1==f2 && c1==c2)?true:false;
		
		}else{
		
			s= (c1==f2)?true:false;
		
		}
		
		if(s==false)cout<<"\n\tNo se puede realizar la operacion.\n";
		
	}while(!s);
	
}

void registro(char o){
	
	int f, c;
	
	for(int k=0; k<2; k++){
		cout<<"\nInicia el registro de los elementos de la matriz "<<k+1<<".";
		cout<<endl<<endl;
		
		if(o=='a'){
			f=f1; c=c1;
		}else{
			f=(k==0)?f1:f2;
			c=(k==0)?c1:c2;
		}
		
		//Registro de las filas
		for(int i=0; i<f; i++){
			for(int j=0; j<c; j++){
				cout<<"\nIngresa el valor del elemento de posicion ["
				<<i+1<<"], ["<<j+1<<"] = ";
				cin>>a[i][j][k];	
			}
			
		}
	
		
	}
}

void suma(){
	
	for(int i=0; i<f1; i++){
		for(int j=0; j<c1; j++){
			d[i][j] = a[i][j][0] + a[i][j][1];
		}
	}
	imprimir("Suma de matrices", '+');
}

void producto(){
	
}

void imprimir(string t, char smb){
	cout<<"\n"<<t<<endl<<endl;
	for(int i=0; i<f1; i++){
		
		for(int j=0; j<c1; j++){
		
			cout<<a[i][j][0]<<" ";
			
		}
		cout<<endl;
	}
	cout<<endl<<"\t"<<smb<<endl<<endl;
	
	for(int i=0; i<f1; i++){
		
		for(int j=0; j<c1; j++){
		
			cout<<a[i][j][1]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"\t"<<smb<<endl<<endl;
	
	for(int i=0; i<f1; i++){
		
		for(int j=0; j<c1; j++){
		
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
}



