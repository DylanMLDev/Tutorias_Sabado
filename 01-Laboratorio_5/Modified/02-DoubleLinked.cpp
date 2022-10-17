#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void menu();
void insertList(Node *&, Node *&, int);
void showListFront(Node *);
void showListEnd(Node *);
void searchList(Node *, int);
void updateNodeList(Node *, int);

Node *started = NULL;
Node *ended = NULL;

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
                    insertList(started, ended, dataNumber);
                    cout<<"\n";
                break;
        
            case 2: showListFront(started);
                    cout<<"\n";
                break;

            case 3: showListEnd(ended);
                    cout<<"\n";
                break;

            case 4: cout<<"\nNumero a buscar: ";
                    cin>>dataNumber;
                    searchList(started, dataNumber);
                    cout<<"\n";
                break;

            case 5: cout<<"\nNumero a buscar para actualizar: ";
                    cin>>dataNumber;
                    updateNodeList(ended, dataNumber);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (option != 0);
}

void insertList(Node *&started, Node *&ended, int n){
    Node *new_node = new Node(); 
    Node *aux = ended;

    new_node->data = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(started == NULL){
        started = new_node;
        ended = started;
    }else{
        aux->next = new_node;
        new_node->prev = ended;
        ended = aux->next;
    }

    cout<<"\tNodo "<<n<<" insertado a la lista"<<endl;
}

void showListFront(Node *started){
    Node *current = new Node();
    current = started;

    cout<<"Start -> ";

    while (current != NULL){
        cout<<current->data<<" -> ";
        current = current->next;
    }

}

void showListEnd(Node *ended){
    Node *current = new Node();
    current = ended;

    cout<<"End -> ";

    while (current != NULL){
        cout<<current->data<<" -> ";
        current = current->prev;
    }

}

void searchList(Node *started, int n){
    bool result = false;

    Node *current = new Node();
    current = started; //Señalar a la primer valor de la lista

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

void updateNodeList(Node *ended, int n){
    Node *current = new Node();
    current = ended;

    while (current != NULL){
        if (current->data == n){
            cout<<"Inserta el nuevo valor de ese nodo: ";
            cin>>current->data;
        }
        current = current->prev;
    }  
}
