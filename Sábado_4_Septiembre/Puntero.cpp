#include <iostream>
using namespace std;

int *puntero, nArray;

void pedirDatos(){
    cout<<"Digite el tamano: ";
    cin>>nArray;

    //Reservar en memoria para arreglo
    puntero = new int [nArray];

    cout<<"Digite los valores del arreglo"<<endl;
    for (int i = 0; i < nArray; i++)
    {
        cout<<"Numero del Arreglo: ";
        cin>>*(puntero + i); //array[0]
    }
}

void mostrarArreglo(int *puntero, int nArray){
    cout<<"IMPRIMIENDO ARREGLO"<<endl;
    for (int i = 0; i < nArray; i++)
    {
        cout<<"Arreglo: "<<*(puntero + i)<<endl;
        cout<<"Direccion: "<<(puntero + i)<<endl;
    }
    
}

int main()
{
    pedirDatos();
    mostrarArreglo(puntero, nArray);

    delete [] puntero;

    return 0;
}
