/*
Punteros Dobles: Tambien conocidos como puntero a puntero, funcion es contener las direcciones de memoria de otras variables puntero

Punteros Triples: Tabien su funcion es almacenar las direcciones de memoria de punteros dobles

*/

#include <iostream>
using namespace std;

int main(){
    int ***punteroTriple, **punteroDoble, *punteroSimple, valor = 20;

    punteroSimple = &valor;
    punteroDoble = &punteroSimple;
    punteroTriple = &punteroDoble;

    cout<<"-----------Salida de Valor-------------"<<endl;
    cout<<"Valor: "<<valor<<endl;
    cout<<"Direccion: "<<&valor<<endl;

    cout<<"-----------Puntero Simple-------------"<<endl;
    cout<<"Valor: "<<*punteroSimple<<endl;
    cout<<"Direccion: "<<punteroSimple<<endl;
    cout<<"Direccion: "<<&punteroSimple<<endl;

    cout<<"-----------Puntero Doble-------------"<<endl;
    cout<<"Valor: "<<**punteroDoble<<endl;
    cout<<"Valor: "<<*punteroDoble<<endl;
    cout<<"Direccion: "<<punteroDoble<<endl;
    cout<<"Direccion: "<<&punteroDoble<<endl;


    cout<<"-----------Puntero Triple-------------"<<endl;
    cout<<"Valor: "<<***punteroTriple<<endl;
    cout<<"Valor: "<<**punteroTriple<<endl;
    cout<<"Direccion: "<<*punteroTriple<<endl;
    cout<<"Direccion: "<<punteroTriple<<endl;
    cout<<"Direccion: "<<&punteroTriple<<endl;



    return 0;
}