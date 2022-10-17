/*
struct NombreStruct
    {
        char variable;
        int variable;
        float variable;
    }var1, var2 ,var3;

struct NombreStruct
    {
        char variable;
        int variable;
        float variable;
    };

    struct NombreStruct var1, var2, var3; 
    */

// #include <iostream>
// using namespace std;

// struct Mascota
// {
//     string nombre;
//     int edad;
// }pet1 = {"Firulais",5} , pet2 = {"Gato", 2};

// int main()
// {
//     cout<<"Nombre: "<<pet1.nombre<<endl;
//     cout<<"Edad: "<<pet1.edad<<endl<<endl;

//     cout<<"Nombre: "<<pet2.nombre<<endl;
//     cout<<"Edad: "<<pet2.edad<<endl;
//     return 0;
// }

#include <iostream>
using namespace std;

struct Mascota
{
    string nombre;
    int edad;
}pet1;

int main()
{
    cout<<"Digite el nombre de la mascota: ";
    cin>>pet1.nombre;

    cout<<"Digite la edad de la mascota: ";
    cin>>pet1.edad;

    cout<<"Nombre: "<<pet1.nombre<<endl;
    cout<<"Edad: "<<pet1.edad<<endl;
    
    return 0;
}
