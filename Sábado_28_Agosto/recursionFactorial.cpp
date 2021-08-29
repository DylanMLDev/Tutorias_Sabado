#include <iostream>
using namespace std;

int factorialRecursiva(int numero);

int main(){
    int numero = 0;

    cout<<"Digite un numero para hacerlo factorial: ";
    cin>>numero;

    cout<<factorialRecursiva(numero);

    return 0;
}

int factorialRecursiva(int numero){
    if(numero <= 0){
        return 1;
    }else{
        return numero * factorialRecursiva(numero -1); // 5 * factorialRecursiva(4) * factorialRecursiva(3)....... factorialRecursiva(0)
    }

}