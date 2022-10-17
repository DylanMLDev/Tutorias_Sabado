#include <iostream>
using namespace std;

double CalcularPotencia(int base, int potencia);

int main()
{
    int base, potencia;

    cout<<"Numero Base: ";
    cin>>base;
    cout<<"Potencia: ";
    cin>>potencia;

    cout<<"Resultado: "<<CalcularPotencia(base, potencia);
    
    return 0;
}

double CalcularPotencia(int base, int potencia){
    if(potencia == 0){
        return 1;
    }else if(potencia == 1){
        return base;
    }else if(potencia < 0){
        return CalcularPotencia(base, potencia + 1) / base;
    }else{
        return base * CalcularPotencia(base, potencia - 1);//2*2+1
    }
}
