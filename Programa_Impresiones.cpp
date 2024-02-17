/*Aplicacion que le permita al usuario hacer impresiones

a) Ver su nombre en un rect�ngulo.
b) Imprimir un tri�ngulo invertido.
c) Una pir�mide trunca de altura a

Code updated by Cesar Sanchez | Student*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	string name;
	char op;
	int size, h, a;
	
	do{
		//Presentaci�n
		cout<<"\nBienvenido!\nEste programa realiza impresiones de figuras."
		<<"Entre las opciones se encuentran: "
		<<"\n\na) Imprimir tu nombre dentro de un rectangulo."
		<<"\nb) Imprimir un triangulo invertido de altura h."
		<<"\nc) Piramide trunca de altura a."
		<<"\n\nIngrese una opcion: ";
		
		cin>>op;
		
			//Casos
			switch(op){
				
				case 'a':
					cin.clear();
					cin.ignore();
					
					//Nombre dentro de un rect�ngulo
					cout<<"\nIngresa tu nombre: ";
					getline(cin, name, '\n');
					
					cout<<"\n\n";
					
					//Captura del tama�o del nombre
					size = name.length();
					
					//Parte superior del rect�ngulo
					for(int i=0; i<=size+1; i++){
						cout<<"*";	
					}
					
					//Nombre
					cout<<"\n*"<<name<<"*\n";
					
					//Parte inferior del rect�ngulo
					for(int i=-0; i<=size+1; i++){
						cout<<"*";	
					}
					
					break;
					
				case 'b':
					//Triangulo invertido
					cout<<"\nIngrese la altura del triangulo: ";
					cin>>h;
					
					cout<<"\nEl triangulo de altura "<<h<<" es: \n";
					
					//Numero de filas
					for(int i=h; i>=1; i--){
						
						//Asteriscos por fila
						for(int j=i; j>=1; j--){
							
							cout<<"*";
						}
						cout<<"\n";
					}
					break;
				
				case 'c':
					//Piramide trunca
					cout<<"\nIntroduzca la altura (a) de la piramide trunca: ";
					cin>>a;
					
					cout<<"\nLa piramide trunca de altura 'a' es: \n";
					
					//Altura de la piramide trunca
					for (int i=1; i<=a; i++)
					{	
					
						//Ayuda a presentar las filas del lado izquierdo
						for(int j=1; j<=a-i; j++){
							cout<<" ";
						}
					
						//Filas de la piramide del lado derecho
					    for (int k=1; k<=(2*i-1); k++)
					    {
					        cout<<"*";
					    }
						cout<<"\n";
					}
					break;
						
				default:
					cout<<"\nOpcion no valida.";	
			}
		
		cout<<"\n\t\t\tGracias por utilizar este programa!";
			
		cout<<"\n\nDesea visualizar el menu de opciones? (s - si, n - salir): ";
		cin>>op;
			
	}while(op == 's' || op == 'S');
	
	//Si la respuesta del usuario es n, sale del programa sin entrar a las opciones.
	if(op == 'n' || op == 'N'){
		
		cout<<"\n\t\t\tGracias por utilizar este programa!";
	}
	
	return 0;
}

