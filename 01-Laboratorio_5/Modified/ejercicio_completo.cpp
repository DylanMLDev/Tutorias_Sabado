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

void insertarLista(Node *&list, int n, string nombre){
    Node *new_node = new Node(); 
    new_node->nombre = nombre;
    new_node->edad = n;
    new_node->next = NULL;

    if (list == NULL){
        list = new_node;
    }else{
        Node *aux1 = list;
        Node *aux2 = NULL;

        while(aux1 != NULL){
            aux2 = aux1;
            aux1 = aux1->next;
        }
        aux2->next = new_node;
    }

    cout<<"\tNodo "<<n<<" insertado a la lista"<<endl;
}

void mostrarLista(Node *list){
    Node *current = list;

    while (current != NULL){ 
        cout<<"Nombre: "<<current->nombre<<"\n";
        cout<<"Edad: "<<current->edad<<"\n";
        current = current->next;
    }
}

void mostrarPersonasMayores(Node *list){
    Node *current = list;

    while (current != NULL){ 
        if(current->edad >= 18){
            cout<<"Nombre: "<<current->nombre<<"\n";
            cout<<"Edad: "<<current->edad<<"\n";
        }
        current = current->next;
    }
}

void mostrarSumaDeEdades(Node *list){
    Node *current = list;
    int suma = 0;

    while (current != NULL){ 
        suma += current->edad;
        current = current->next;
    }

    cout<<"\nLa suma total de las edades es: "<<suma;
}

void personasDeLaTerceraEdad(Node *list){
    Node *current = list;

    while (current != NULL){ 
        if(current->edad >= 65){
            cout<<"Nombre: "<<current->nombre<<"\n";
            cout<<"Edad: "<<current->edad<<"\n";
        }
        current = current->next;
    }
}

void personasAdolescentes(Node *list){
    Node *current = list;

    while (current != NULL){
        if((current->edad >= 12) && (current->edad <= 17)){
            cout<<"Nombre: "<<current->nombre<<"\n";
            cout<<"Edad: "<<current->edad<<"\n";
        }
        current = current->next;
    }
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