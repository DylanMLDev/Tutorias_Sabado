#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void menu();
void insertQueue(Node *&, Node *&, int);
void showQueue(Node *);
void deleteFrontQueueNode(Node *&);

Node *frontQueue = NULL;
Node *endQueue = NULL;

int main(){
    
    menu();

    return 0;
}

void menu(){
    int option, stackNumber;

    do{
        cout<<"------------------Menu------------------"<<endl;
        cout<<"1) Insertar elementos a la cola\n";
        cout<<"2) Mostrar elementos de la cola\n";
        cout<<"3) Eliminar primer nodo de la cola\n";
        cout<<"0) Salir\n";
        cout<<"Opcion: ";
        cin>>option;

        switch (option){
            case 1: cout<<"\nNumero para la cola: ";
                    cin>>stackNumber;
                    insertQueue(frontQueue, endQueue, stackNumber);
                    cout<<"\n";
                break;
        
            case 2: showQueue(frontQueue);
                    cout<<"\n";
                break;

            case 3: cout<<"\nEliminando el primer nodo";
                    deleteFrontQueueNode(frontQueue);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (option != 0);
}


void insertQueue(Node *&frontQueue, Node *&endQueue, int n){
    Node *new_node = new Node();

    new_node->data = n;
    new_node->next = NULL;

    if (frontQueue == NULL){
        frontQueue = new_node;
        endQueue = frontQueue;
    }else{
        endQueue->next = new_node;
    }
    endQueue = new_node;
}

void showQueue(Node *frontQueue){
    Node *current = new Node();
    current = frontQueue;

    while (current != NULL){ 
        cout<<current->data<<" -> ";
        current = current->next;
    }
}

void deleteFrontQueueNode(Node *&frontQueue){
    Node *aux = frontQueue;
    frontQueue = aux->next;
    delete aux;
}
