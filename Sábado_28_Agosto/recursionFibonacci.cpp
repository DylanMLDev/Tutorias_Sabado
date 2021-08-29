// 0,1,1,2,3,5,8,13,.....
//

#include <iostream>
using namespace std;

//supongamos que la posicion es pos = 6
int fibonacci(int pos){ // Inicialmente pos = 6
    if(pos > 1){
        return fibonacci(pos - 1) + fibonacci(pos - 2);
        //fibo(6) = fibo(5) = 5 + fibo(4) = 3 => 8
        //fibo(5) = fibo(4) = 3 + fibo(3) = 2 => 5 
        //fibo(4) = fibo(3) = 2 + fibo(2) = 1 => 3 
        //fibo(3) = fibo(2) = 1 + fibo(1) = 1 => 2 
        //fibo(2) = fibo(1) = 1 + fibo(0) = 0 => 1
        //fibo(1) = 1
        //fibo(0) = 0
    }else{
        if(pos == 0){
            return 0;
        }

        if (pos == 1)
        {
            return 1;
        }
        
    }

}


int main(){
    int pos;

    cout<<"Ingrese un numero de la posicion de las series de Fibo: ";
    cin>>pos;

    cout<<"El numero de Fibonaccio es: "<<fibonacci(pos);

    return 0;
}