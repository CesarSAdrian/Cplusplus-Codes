/*Guess the number by Cesar Sanchez 

El programa genera un numero al azar dentro de un rango predeterminado. El usuario introduce un numero dentro de ese rango.
Si ambos n�meros son compatibles, el usuario gana. Si no lo son, la m�quina gana.

USO DE IF-ELSE

Juego de adivinanzas con C++*/

#include <iostream> //Encargado de incializar las funciones de datos (transferencia) - cout (character output), cin (character input).
#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

//Lista de palabras reservadas
using namespace std;

int main(){

    int num, num_r;
	char op;

	cout<<"\nBienvenido al juego de las adivinanzas!";
    cout<<"\nEn este juego el usuario introduce un numero del 1 al 5. La maquina pensara un numero\n" 
	<<"dentro del mismo rango. Si el usuario adivina el numero que piensa la maquina, gana; de lo contrario, pierde."<<endl;
	
	do{
		cout<<"\nListx para jugar? (s - Si): ";
		cin>>op;
		
		if(op == 's' || op == 'S'){
			
		    cout<<"\nLa maquina esta pensando un numero..."; //Primer art�culo
		    
			//Inicializa la funci�n de random
	  		srand (time(NULL));
	
	  		//Genera un n�mero secreto del 1 al 5
	  		num_r = rand() % 5 + 1;
	  		
	  		cout<<"\n\nIngrese un numero cualquiera (del 1 al 5): "; //Segundo art�culo
	    	cin>>num;
			
			if(num == num_r){
				cout<<"\nFelicidades! El usuario gana!";
			}else{
				cout<<"\nSuerte para la proxima! La maquina gana.";
			}
			
			cout<<"\nDeseas conocer el numero que penso la maquina?: ";
			cin>>op;
			
			if(op == 's' || op == 'S'){
				cout<<"\nEl numero era: "<<num_r<<".";
			}
			
		}
		else{
			cout<<"\nVuelve pronto viajero!";
		}
	
	cout<<"\n\nQuieres jugar? (s - Si): ";
	cin>>op;
	
	}while(op == 's' || op == 'S');
	
cout<<"\nGracias por usar el programa!"<<endl;
    
return 0;

}
