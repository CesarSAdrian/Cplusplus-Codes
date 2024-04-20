/*FUNCIONES RECURSIVAS

Elabora un proyecto que permita al usuario calcular el seno de un angulo empleando la serie de Taylor.

Los valores de x y n los proporciona el usuario (n<15).
El programa debe imrpimir los términos que vaya calculando y además debe imprimir el resultado que arroje 
la función de cabecera sin(x) de la librería cmath.

Porgramación Estructurada

Los swifties aprendieron a programar.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

//Declaración de funciones
bool proposito();
void inicio();
double radianes(string ang);
void taylor(double x, int n);
int factorial(int n);

int main(){
	
	while(proposito()){
		
		inicio();
	
	}
	
	cout<<"\n\nGracias por usar el programa!"<<endl;
	
	return 0;
}

//Definición de funciones

bool proposito(){ //¿Ingresa o no?
	
	string r;
	bool op;
	
	cout<<"\n\tFuncion sin(x)\n\n"
	<<"Este programa te permite calcular el seno de un angulo x,"
	<<"\nempleanod la funcion de la libreria cmath o a traves de"
	<<"\nla expansion en serie de Taylor.\n\nPulsa 1 para ingresar: ";
	getline(cin, r);
	
	return (r[0]=='1')?true:false;

}

void inicio(){ 
	
	int n;
	string ang;
	double x;
	
	solicitar: cout<<"\n\nIngresa el valor del angulo en radianes: ";
	cin>>ang;
	
	x = radianes(ang);
	if(x==-1)goto solicitar;
	
	do{
	
		cout<<"\nIngresa el numero de terminos que se utilizaran en la expansion"
		<<"\n(debe ser menor de 15): ";
		cin>>n;
	
	}while(n<=0 || n>15);
	
	cout<<"\nEl seno de "<<x<<" radianes, empleando la funcion de libreria es: \n"
	<<"sin("<<x<<") = "<<sin(x)<<endl<<endl;
	
	taylor(x,n);
}

double radianes(string ang){
	double xd;
	int xi;
	bool pf = false;
	
	//Usamos stod (string to double)
	if(isdigit(ang[0])){
		
		int lang=ang.length(); //Determina el largo de la cadena de caracteres.
		
		for(int i=0; i<lang; i++){
			
			if(ang[i] == '.'){
				pf = true; //Encuentra el punto flotante en el valor ingresado
				break;
			}
			
		}
		
		if(pf) stringstream (ang)>>xd;
		else{
			stringstream (ang)>>xi;
			xd = (xi*M_PI)/180.0;
		}
		
	}else{
	
		cout<<"\n\nValor no valido\n\n";
		xd=-1;
	
	}
	
	return xd;
	
}

void taylor(double x, int n){
	
	double sint = 0;
	cout<<"sin("<<x<<"):\n";
	
	//Imprime término a término lo que se está calculando
	for(int i=0; i<n; i++){
		
		cout<<"n="<<i+1<<": sin("<<x<<") = "<<(pow(-1, i)*pow(x, (2*i+1)))/factorial(2*i+1)<<endl;
		sint+=(pow(-1, i)*pow(x, (2*i+1)))/factorial(2*i+1); //Da el positivo o el negativo junto con el término.
		
	}
	
	cout<<sint;
	
}

//Función recursiva
int factorial(int n){
	
	if(n>1)return(n*factorial(n-1));
	else return 1;
	
}
