#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
};

void Menu();
nodo *crearNodo(int );
void agregarNodo(nodo *&, int);
void MostrarArbol(nodo *, int);
bool busqueda(nodo *, int);

nodo *arbol = NULL;

int main(){
	Menu();
	
	return 0;
}

void Menu(){
	int dato, opcion, contador = 0;
	
	do{
		cout<<"1. Agregar elementos al arbol. "<<endl;
		cout<<"2. Mostrar Arbol."<<endl;
		cout<<"3. Buscar en Arbol.."<<endl;
		cout<<"4. Salir."<<endl;
		cout<<"\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:	cout<<"Numero a agregar: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					break;
					
			case 2:	cout<<"\n--------------------Mostrando Arbol--------------------"<<endl;
					MostrarArbol(arbol,contador);
					break;
					
			case 3: cout<<"\nNumero a Buscar: ";
					cin>>dato;
					if(busqueda(arbol,dato) == true){
						cout<<"Elemento '"<<dato<<"' SI fue encontrado.";
					}else{
						cout<<"Elemento '"<<dato<<"' NO fue encontrado.";
					}
					break;
					
			default: cout<<"Numero incorrecto!"<<endl;
			        break;
		}
	}while(opcion != 4);
}
nodo *crearNodo(int n){
	nodo *NuevoNodo = new nodo();
	NuevoNodo->dato = n;
	NuevoNodo->der = NULL;
	NuevoNodo->izq = NULL;
	
	return NuevoNodo;
}
void agregarNodo(nodo *&arbol, int n){
	if(arbol == NULL){// Verifica si el arbol esta vacio.
		nodo *nuevoNodo = crearNodo(n);//El nuevo nodo se crea en la raiz del arbol.
		arbol = nuevoNodo;
	}else{
		int ValorDeRaiz = arbol->dato;//tendra el dato de la raiz
		if(n < ValorDeRaiz){//Cuando el Valor es menor va al lado izquierdo.
			agregarNodo(arbol->izq,n);//Se Agrega al lado izquierdo.
		}else{
			agregarNodo(arbol->der,n);//Se Agrega al lado derecho.
		}
	}
}

void MostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){//Saber si el arbol esta vacio.
		return;
	}else{//Si no esta vacio.
		MostrarArbol(arbol->der,cont+1);
		for(int i=0 ; i<cont ; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		MostrarArbol(arbol->izq,cont+1);
	}
}

bool busqueda(nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}else if(n == arbol->dato){
		return true;
	}else if( n < arbol->dato){
		busqueda(arbol->izq,n);
	}else{
		busqueda(arbol->der,n);
	}
}
