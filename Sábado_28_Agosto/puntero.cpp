//Puntero: es una variable que contiene la direccion de memoria en cual se almacena un valor de un variable

//&variable = la dirección de memoria
//*variable = la variable contendra el valor de una variable

//puntero puede contener una direccion 0x0002343 _----> 20
//para acceder a la direccion de una variable &valor = 0x0002343
//*valor =  20

#include <iostream>
using namespace std;

int main(){
    int numero = 20;
    int array[] = {1,2,3,4,5,6,7};
    int *puntero;
    int *puntero2;

    puntero = &numero;
    puntero2 = &array[0]; // puntero2 = array

    for(int i = 0; i < 7 ; i++){
        cout<<"Numero: "<<puntero2[i]<<" Direccion: "<<&puntero2[i]<<endl;
    }

    cout<<"Direccion: "<<puntero<<endl;
    cout<<"Valor: "<<*puntero;



    return 0;
}