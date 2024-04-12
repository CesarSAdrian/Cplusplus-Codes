/*Ejemplo

Uso de estructuras para la organización y manejo compacto de la información.
En este ejemplo se escribe un programa que permita almacenar:
Título, autor, precio, número de edición, existencia (un conjunto de 5 libros).

Se registran los datos y se despliega una yabla de ellos.

Clase de Programación Estructurada | Dra. Karla Cantún.

*/

#include <iostream>
#include <string>
#include <iomanip>

#define tbooks 2

using namespace std;

struct books{ //Nombre de la estructura
	
	//Miembros de la estructura
	
	string titulo;
	string autor;
	float precio;
	int ed;
	bool st=true;
	
}libros[tbooks]; //Declaración de los objetos de la estructura


//Declaración de funciones
void registro();
void imprimir();
void editar();

int main(){
	
	char m;
	
	cout<<"\n\t\t\t\t\t***** REGISTRO DE LIBROS *****"<<endl;
	
	registro();
	imprimir();
	
	rep: cout<<"\nDesea modificar algun valor de la tabla?\n"
	<<"Pulse s para modificar: ";
	cin>>m;
	if(m == 's'){
		editar();
		goto rep;
	}
	
	return 0;
}

//Descripción de funciones

void registro(){
	
	for(int i=0; i<tbooks; i++){

		cout<<"\nIngrese el titulo del libro: ";
		getline(cin, libros[i].titulo);
		
		cout<<"Ingrese el autor del libro \""<<libros[i].titulo<<"\": ";
		getline(cin, libros[i].autor);	
		
		cout<<"Ingrese el precio del libro \""<<libros[i].titulo<<"\": ";
		cin>>libros[i].precio;	
		
		cout<<"Ingrese el anio del libro \""<<libros[i].titulo<<"\": ";
		cin>>libros[i].ed;	

		cin.clear();
		cin.ignore();
	
	}
	
}

void imprimir(){
	
	cout<<"\n\n\t\t\t\t\t***** LIRBOS REGISTRADOS *****\n\n"
	<<setw(4)<<left<<"iD"<<setw(30)<<"Titulo"<<setw(20)<<"Autor"<<setw(8)
	<<right<<"Precio"<<setw(8)<<"Estatus"<<endl;
	
	for(int i=0; i<tbooks; i++){
		
		cout<<setw(4)<<left<<i+1<<setw(30)<<libros[i].titulo<<setw(20)<<libros[i].autor<<setw(8)
		<<right<<libros[i].precio<<setw(8)<<libros[i].st<<endl;
		
	}
	
}

void editar(){
	
	int j;
	char m;
	
	cout<<"\nIngrese eel numero correspondiente al libro que desea editar: ";
	cin>>j;
	j--;
	if(j-1<0 || j-1>=tbooks){
		
		cout<<"No existe ese ejemplar."<<endl;
	
	}else{
		
		cout<<"Elige el valor asociado al campo que desea modificar:\n"
		<<"t)\tTitulo\na)\tAutor\np)\tPrecio\n";
		cin>>m;
		if(m=='t'){
			
			cin.clear();
			cin.ignore();
			
			cout<<"\nIngresa el nuevo titulo del libro: ";
			getline(cin, libros[j].titulo);
			
		}else if(m=='a'){
			
			cout<<"\nIngresa el nuevo autor del libro: ";
			getline(cin, libros[j].autor);
			
		}else if(m=='p'){
			
			cout<<"\nIngresa el nuevo precio del libro: ";
			cin>>libros[j].precio;
		
		}
		
		imprimir();
		
	}
	
}
