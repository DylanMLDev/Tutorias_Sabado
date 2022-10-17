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
void updateNodeList(Node *, int);

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
        cout<<"6) Actualizar un elemento de la lista\n";
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

            case 6: cout<<"\nNumero a buscar para actualizar: ";
                    cin>>dataNumber;
                    updateNodeList(list, dataNumber);
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
    new_node->data = n;//Asignar el valor de n al campo del new_node data

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

void showList(Node *list){
    //A ese actual tiene que estar señalando la primera posicion de mi lista
    Node *current = list;

    while (current != NULL){ //recorrer la lista hasta que sea NULL
        cout<<current->data<<" -> ";
        current = current->next;
    }

}

void searchList(Node *list, int n){
    bool result = false;

    Node *current = list;

    while ((current != NULL)){
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

void updateNodeList(Node *list, int n){
    Node *current = list;

    while ((current != NULL)){
        if (current->data == n){
            cout<<"Inserta el nuevo valor de ese nodo: ";
            cin>>current->data;
        }
        current = current->next;
    }  
}
