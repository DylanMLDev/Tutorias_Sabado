#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void menu();
void insertList(int);
void showListFront();
void showListEnd();
void searchList(int);
void updateNodeList(int);

Node *list = NULL;
Node *ultimo = NULL;

int main(){

    menu();

    return 0;
}

void menu(){
    int option, dataNumber;

    do{
        cout<<"------------------Menu------------------"<<endl;
        cout<<"1) Insertar elementos a la lista\n";
        cout<<"2) Mostrar elementos de la lista desde inicio a fin\n";
        cout<<"3) Mostrar elementos de la lista desde fin a inicio\n";
        cout<<"4) Buscar un nodo de la lista\n";
        cout<<"5) Actualizar un nodo de la lista\n";
        cout<<"0) Salir\n";
        cout<<"Opcion: ";
        cin>>option;

        switch (option){
            case 1: cout<<"\nNumero: ";
                    cin>>dataNumber;
                    insertList(dataNumber);
                    cout<<"\n";
                break;
        
            case 2: showListFront();
                    cout<<"\n";
                break;

            case 3: showListEnd();
                    cout<<"\n";
                break;

            case 4: cout<<"\nNumero a buscar: ";
                    cin>>dataNumber;
                    searchList(dataNumber);
                    cout<<"\n";
                break;

            case 5: cout<<"\nNumero a buscar para actualizar: ";
                    cin>>dataNumber;
                    updateNodeList(dataNumber);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (option != 0);
}

void insertList(int n){
    Node *new_node = new Node();

    new_node->data = n;

    if (list == NULL){
        list = new_node;
        ultimo = new_node;
        list->next = list;
        list->prev = ultimo;
    }else{
        ultimo->next = new_node;
        new_node->prev = ultimo;
        new_node->next = list;
        ultimo = new_node;
        list->prev = ultimo;
    }
    
    cout<<"\tNodo "<<n<<" insertado a la lista"<<endl;
}

void showListFront(){
    Node *current = new Node();
    current = list;

    if(list != NULL){
        do{
            cout<<current->data<<" -> ";
            current = current->next;
        }while (current != list);
    }else{
        cout<<"\n La lista se encuentra vacia\n\n";
    }
}

void showListEnd(){
    Node *current = new Node();
    current = ultimo;

    if(ultimo != NULL){
        do{
            cout<<current->data<<" -> ";
            current = current->prev;
        }while (current != ultimo);
    }else{
        cout<<"\n La lista se encuentra vacia\n\n";
    }
}

void searchList(int n){
    bool result = false;

    Node *current = new Node();
    current = list;

    do{
        if (current->data == n){
            result = true;
        }
        current = current->next;
    }while (current != list);

    if(result == true){
        cout<<"\nEl numero "<<n<<" SI ha sido encontrado\n";
    }else{
        cout<<"\nEl numero "<<n<<" NO ha sido encontrado\n";
    }   
}

void updateNodeList(int n){
    Node *current = new Node();
    current = list;

    do{
        if (current->data == n){
            cout<<"Inserta el nuevo valor de ese nodo: ";
            cin>>current->data;
        }

        current = current->next;
        
    }while (current != list);  
}