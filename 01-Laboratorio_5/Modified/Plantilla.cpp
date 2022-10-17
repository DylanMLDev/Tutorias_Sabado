#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string nombre;
    int edad;
    Node *next;
};

//Variable Global
Node *list = NULL;

void insertarLista(Node *&list, int edad, string nombre){
    
}

void mostrarLista(Node *list){
    
}

void mostrarPersonasMayores(Node *list){
    
}

void mostrarSumaDeEdades(Node *list){
    
}

void personasDeLaTerceraEdad(Node *list){
   
}

void personasAdolescentes(Node *list){
    
}

void menu(){
    int opcion, edad;
    string nombre;

    do{
        cout<<"------------------Menu------------------"<<endl;
        cout<<"1) Insertar elementos a la lista\n";
        cout<<"2) Mostrar elementos de la lista\n";
        cout<<"3) Mostrar Persona Mayores\n";
        cout<<"4) Mostrar Suma de todas las edades\n";
        cout<<"5) Mostrar Personas de la Tercera Edad\n";
        cout<<"6) Mostrar Personas Adolescentes\n";
        cout<<"0) Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1: cout<<"\nNombre: ";
                    cin>>nombre;
                    cout<<"Edad: ";
                    cin>>edad;
                    insertarLista(list, edad, nombre);
                    cout<<"\n";
                break;
        
            case 2: mostrarLista(list);
                    cout<<"\n";
                break;

            case 3: mostrarPersonasMayores(list);
                    cout<<"\n";
                break;

            case 4: mostrarSumaDeEdades(list);
                    cout<<"\n";
                break;

            case 5: personasDeLaTerceraEdad(list);
                    cout<<"\n";
                break;

            case 6: personasAdolescentes(list);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (opcion != 0);
}

int main(){

    menu();

    return 0;
}