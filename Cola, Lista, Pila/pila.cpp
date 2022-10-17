#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void menu();
void insertStack(Node *&, int);
void showStack(Node *);
void deleteStackNode(Node *&);
void sumaNode(Node *);

Node *stack = NULL;

int main(){
    
    menu();

    return 0;
}

void menu(){
    int option, stackNumber;

    do{
        cout<<"------------------Menu------------------"<<endl;
        cout<<"1) Insertar elementos a la pila\n";
        cout<<"2) Mostrar elementos de la pila\n";
        cout<<"3) Eliminar ultimo nodo de la pila\n";
        cout<<"4) Suma\n";
        cout<<"0) Salir\n";
        cout<<"Opcion: ";
        cin>>option;

        switch (option){
            case 1: cout<<"\nNumero para la pila: ";
                    cin>>stackNumber;
                    insertStack(stack, stackNumber);
                    cout<<"\n";
                break;
        
            case 2: showStack(stack);
                    cout<<"\n";
                break;

            case 3: cout<<"\nEliminando el ultimo nodo";
                    deleteStackNode(stack);
                    cout<<"\n";
                break;

            case 4: sumaNode(stack);
                    cout<<"\n";
                break;

            case 0: cout<<"------------------Saliendo------------------";
                break;

            default: cout<<"Numero incorrecto!!";
                break;
        }
    } while (option != 0);
}

void insertStack(Node *&stack, int n){
    Node *new_stack = new Node();
    new_stack->data = n;
    new_stack->next = stack;
    stack = new_stack;
}

void showStack(Node *stack){
    Node *current = new Node();
    current = stack;

    while (current != NULL){ 
        cout<<current->data<<" -> ";
        current = current->next;
    }
}

void deleteStackNode(Node *&stack){
    Node *aux = stack;
    stack = aux->next;
    delete aux;
}

void sumaNode(Node *stack){
    Node *current = stack;
    int result = 0;

    while (current != NULL){ 
        int aux = current->data;
        result += aux;//result = result + aux
        current = current->next;
    }

    cout<<"\nResultado: "<<result<<endl;
}