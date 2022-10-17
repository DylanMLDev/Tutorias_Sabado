#include <iostream>
using namespace std;

struct DateOfBirth
{
    int day;
    string month;
    int year;
};

struct Person
{
    string firstName;
    string lastName;
    struct DateOfBirth birth_person;
}person[2];

int main()
{
    for (int i = 0; i < 2; i++)
    {
        cout<<"DATOS PERSONALES"<<endl;
        cout<<"Nombre: ";
        cin>>person[i].firstName;
        cout<<"Apellido: ";
        cin>>person[i].lastName;
        cout<<"Día: ";
        cin>>person[i].birth_person.day;
        cout<<"Mes: ";
        cin>>person[i].birth_person.month;
        cout<<"Año: ";
        cin>>person[i].birth_person.year;
    }
    
    for (int i = 0; i < 2; i++)
    {
        cout<<"\n\n------------------IMPRIMIENDO DATOS--------------------------"<<endl;
        cout<<"Nombre: "<<person[i].firstName<<endl;
        cout<<"Apellido: "<<person[i].lastName<<endl;
        cout<<"Día: "<<person[i].birth_person.day<<endl;
        cout<<"Mes: "<<person[i].birth_person.month<<endl;
        cout<<"Año: "<<person[i].birth_person.year<<endl;
    }

    return 0;
}

