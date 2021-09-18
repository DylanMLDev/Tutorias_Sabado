#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void menu();
void insertList(Node *&, int);
void showList(Node *);
void searchList(Node *, int);
void deleteNode(Node *&, int);

//Variable Global
Node *list = NULL; //Creando lista apuntando a null

int main(){

    menu();

    return 0;
}

void menu(){
    int option, dataNumber;

    do{
        cout<<"------------------Menu------------------"<<endl;
        cout<<"1) Insertar elementos a la lista\n";
        cout<<"2) Mostrar elementos de la lista\n";
        cout<<"3) Buscar un elemento de la lista\n";
        cout<<"4) Eliminar un nodo de la lista\n";
        cout<<"0) Salir\n";
        cout<<"Opcion: ";
        cin>>option;

        switch (option){
            case 1: cout<<"\nNumero: ";
                    cin>>dataNumber;
                    insertList(list, dataNumber);
                    cout<<"\n";
                break;
        
            case 2: showList(list);
                    cout<<"\n";
                break;

            case 3: cout<<"\nNumero a buscar: ";
                    cin>>dataNumber;
                    searchList(list, dataNumber);
                    cout<<"\n";
                break;

            case 4: cout<<"\nNumero a eliminar: ";
                    cin>>dataNumber;
                    deleteNode(list, dataNumber);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (option != 0);
}

void insertList(Node *&list, int n){
    Node *new_node = new Node(); //Crear un nuevo nodo y reservando memoria del new_node
    new_node->data = n; //Asignar el valor de n al campo del new_node data

    //Nodos auxiliares
    Node *aux1 = list; //Igualar a lista
    Node *aux2;

    while ((aux1 != NULL) && (aux1->data < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (list == aux1){
        list = new_node;
    }else{
        aux2->next = new_node;
    }
    
    new_node->next = aux1;

    cout<<"\tNodo "<<n<<" insertado a la lista"<<endl;
}

void showList(Node *list){
    Node *current = new Node();
    //A ese actual tiene que estar señalando la primera posicion de mi lista
    current = list;

    while (current != NULL){ //recorrer la lista hasta que sea NULL
        cout<<current->data<<" -> ";
        current = current->next;
    }

}

void searchList(Node *list, int n){
    bool result = false;

    Node *current = new Node();
    current = list; //Señalar a la primer valor de la lista

    while ((current != NULL) && (current->data <= n)){
        if (current->data == n){
            result = true;
        }
        current = current->next;
    }

    if(result == true){
        cout<<"\nEl numero "<<n<<" SI ha sido encontrado\n";
    }else{
        cout<<"\nEl numero "<<n<<" NO ha sido encontrado\n";
    }   
}

void deleteNode(Node *&list, int n){
    //Verificar si la lista no está vacía
    if(list != NULL){
        Node *aux_delete;
        Node *previous = NULL;

        aux_delete = list; //Señalar el primero de la lista

        while ((aux_delete != NULL) && (aux_delete->data != n)){//Recorrer la lista
            previous = aux_delete;
            aux_delete = aux_delete->next;
        }
        if(aux_delete == NULL){//El elemeno no ha sido encontrado
            cout<<"El elemento no ha sido encontrado\n";
        }else if(previous == NULL){//El primer elemento es el que vamos a eliminar
            list = list->next;
            delete aux_delete;
        }else{//el elemento esta en la lista pero no es el primer nodo
            previous->next = aux_delete->next;
            delete aux_delete;
        }
    }
}