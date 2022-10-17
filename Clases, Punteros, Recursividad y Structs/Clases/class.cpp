#include <iostream>
using namespace std;

class Person{
    private: //Atributos
        int edad;
        string nombre;
    public://Metodos
        Person(int, string);//Metodo Constructor
        void comer();
        void leer();
};

Person::Person(int _edad, string _nombre){
    edad = _edad;
    nombre = _nombre;
}

void Person::comer(){
    cout<<"Mi nombre es: "<<nombre<<" y tengo "<<edad<<" y estoy comiendo"<<endl;
}

void Person::leer(){
    cout<<"Mi nombre es: "<<nombre<<" y tengo "<<edad<<" y estoy leyendo"<<endl;
}

int main()
{
    Person p1 = Person(30, "Andrea");
    Person p2(45, "Carlos");

    p1.comer();
    p2.leer();

    return 0;
}
