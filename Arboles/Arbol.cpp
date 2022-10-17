#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};

void menu();
Nodo *crearNodo(int,Nodo*);
void insertarNodo(Nodo*&, int,Nodo*);
void mostrarArbol(Nodo*, int);
bool busqueda(Nodo*, int);

void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);

Nodo* arbol = NULL;

int main()
{
    menu();
}

void menu() {
    int dato, opcion,contador= 0;

    do {
        cout << "\t.:MENU:." << endl;
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Mostrar el arbol" << endl;
        cout << "3.Buscar un elemento en el arbol" << endl;
        cout << "4.Eliminar un nodo del arbol" << endl;
        cout << "0.Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Digite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato,NULL);
            cout << "\n";
            break;
        case 2:
            cout << "Aqui tienes el arbol impreso de forma recursiva: " << endl;
            mostrarArbol(arbol, contador);
            cout << "\n";
            break;
        case 3:
            cout <<"\n" <<"Introduce el dato que estas buscando ";
            cin >> dato;
            if (busqueda(arbol, dato) == true) {
                cout << "\n" << "El elemento " << dato << " si se encuentra en el arbol" << endl;
            }
            else {
                cout << "\n" << "El elemento " << dato << " no se encuentra en el arbol" << endl;
            }
            break;
        case 4:
            cout << "\nDigite el numero que desea eliminar:";
            cin >> dato;
            eliminar(arbol, dato);
            cout << "\n";
            break;
        }
    } while (opcion != 0);
}

//Función para crear un nuevo nodo
Nodo* crearNodo(int n,Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

//Función para insertar nodos en el árbol
void insertarNodo(Nodo *&arbol, int n,Nodo*padre) {
    if (arbol == NULL) { //Si el arbol está vacío
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    }
    else { // Si el arbol tiene un nodo o más
        int valorRaiz = arbol->dato; // Obtener valor de la raíz
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n,arbol);
        }
        else {
            insertarNodo(arbol->der, n,arbol);
        }
    }
}

//Función para mostrar el arbol
void mostrarArbol(Nodo* arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout <<"    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// Función para buscar un dato en el arbol
bool busqueda(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n){
        return true;
    }
    else if (n <arbol->dato) {
        return busqueda(arbol->izq, n);
    }
    else {
        return busqueda(arbol->der, n);
    }
}

// Funcion para eliminar un nodo del arbol
void eliminar(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->dato) { //Si el valor es menor
        eliminar(arbol->izq, n); // Busca por la izquierda
    }
    else if (n > arbol->dato) { // Si el valor es mayor
        eliminar(arbol->der, n); //Busca por la derecha
    }
    else {
        eliminarNodo(arbol);
    }
}

// Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo* nodoEliminar) {
    //sub-arbol con dos hijos
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo* menor = minimo(nodoEliminar->der); // Primero te vas hacia la derecha
        nodoEliminar->dato = menor->dato;//el menor dato pasa al lugar del nodo a eliminar
        eliminarNodo(menor); //Elimina el menor 
    }
    //sub-arbol con un hijo
    else if (nodoEliminar->izq) {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else { // No tiene hijos
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

// Función para determinar el nodo más izquierdo posible
Nodo* minimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izq) { // Si tiene hijo izquierdo
        return minimo(arbol->izq); // retorna el hijo izquierdo
    }
    else { // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
        return arbol; // se retorna a sí mismo
    }
}

// Función para reemplazar dos nodos
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        //arbol->padre se le tiene que asignar su nuevo hijo
        if (arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        // Le asignamos su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}

// Función para destruir(eliminar) un nodo
void destruirNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}