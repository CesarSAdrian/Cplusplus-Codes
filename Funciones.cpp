/*Ejemplo en el que se puede apreciar el uso de funciones dentro de un c�digo.

Clase de Programaci�n Estructurada.
*/

#include <iostream>
#include <string>

using namespace std;

//Zona de declaraciones globales

string nombre(void); //Declaracion de una funci�n que no recibe par�metros y devuelve resultados.


int main(){
	
	string name;
	name = nombre(); //Invocaci�n de la funci�n nombre()
	
	cout<<"\nHola "<<name<<endl;
	
	return 0;
	
}

//Zona de definici�n de funciones
string nombre(){
	
	string n;
	
	cout<<"\nIngresa tu primer nombre por favor: ";
	cin>>n;
	
	return n;
	
}
