//encontrar el mayor de un arreglo y la sumar ese arreglo

#include <iostream>
using namespace std;

int sum(int numero1, int numero2[], int x){
    if(x == 5){
        return numero1;
    }else{
        //1,3,6,10,15
        numero1 = numero1 + numero2[x];
        sum(numero1, numero2, x+1);
    }
}

//1,2,3,4,5 valor
//0,1,2,3,4 posicion
int max(int arr[], int mayor, int n){
    if(n == 5){
        return mayor;
    }else{
        if(arr[n] > mayor){
            mayor = arr[n];
        }
    max(arr, mayor, n+1);
    }
}


int main(){
    int arreglo[5], suma, mayor;

    for(int i = 0; i < 5; i++){
        cout<<"Ingrese Numero: ";
        cin>>arreglo[i];
    }

    suma = sum(0, arreglo, 0);
    cout<<"La suma es: "<<suma<<endl;

    mayor = max(arreglo, arreglo[0], 0);
    cout<<"El mayor es: "<<mayor;

}