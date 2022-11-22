#include <iostream>
#include <fstream>

using namespace std;

void Agregar(ofstream &ficheroEscritura);
bool Comprobar(string _placa);
void Imprimir(ifstream &ficheroLectura);
void Modificar(ifstream &ficheroLectura);
void Eliminar(ifstream &ficheroLectura);

int main()
{
    ofstream ficheroEscritura;
    ifstream ficheroLectura;
    Agregar(ficheroEscritura);
    Imprimir(ficheroLectura);
    Modificar(ficheroLectura);
    Eliminar(ficheroLectura);
    Imprimir(ficheroLectura);

    return 0;
}

bool Comprobar(string _placa)
{
    ifstream FicheroLectura("Informacion.txt", ios::in);
    string placa;
    string marca;
    FicheroLectura >> placa;
    // Leer hasta llegar al final
    while (!FicheroLectura.eof())
    {
        FicheroLectura >> marca;
        if (placa == _placa)
        {
            cout << "✋ Placa ya existe";
            FicheroLectura.close();
            return false;
        }
        FicheroLectura >> placa;
    }
    FicheroLectura.close();
    // Permite escribir en el archivo
    return true;
}

void Agregar(ofstream &ficheroEscritura)
{
    string placa;
    string marca;
    ficheroEscritura.open("Informacion.txt", ios::out | ios::app);
    cout << "Ingresa el número de placa " << endl;
    cin >> placa;
    cout << "Ingresa la marca " << endl;
    cin >> marca;
    if (Comprobar(placa))
    {
        ficheroEscritura << placa << " " << marca << " "
                         << "\n";
    }
    ficheroEscritura.close();
}

void Modificar(ifstream &ficheroLectura)
{
    string placa; // Placa a modificar 
    string marca; // Marca a modificar 
    string temp_p; // Placa temporal 
    string temp_m; // Marca temporal 

    // Abrir el archivo en modo lectura 
    ficheroLectura.open("Informacion.txt", ios::in); 
    // Abrir el archivo en modo escritura 
    ofstream temp("tmp.txt", ios::out);

    if (ficheroLectura.is_open()) //Comprobar si el archivo se abrió 
    {
        cout << "Ingrese el numero de placa"; // Pedir placa a modificar 
        cin >> temp_p; // Guardar placa a modificar 
        ficheroLectura >> placa; // Leer placa del archivo de texto 
        while (!ficheroLectura.eof()) // Mientras no sea el final del archivo 
        {
            ficheroLectura >> marca; // Leer marca del archivo de texto
            if (placa == temp_p) // Si la placa es igual a la placa a modificar 
            {
                cout << "Ingrese la marca"; // Pedir marca a modificar 
                cin >> temp_m; // Guardar marca a modificar 
                cout << "Registro actualizado" << endl; // Mostrar mensaje de actualización 
                temp << temp_p << " " << temp_m << " " 
                     << "\n"; // Escribir en el archivo temporal 
            }
            else // Si la placa no es igual a la placa a modificar 
            {
                temp << placa << " " << marca << " "
                     << "\n"; // Escribir en el archivo temporal 
            }
            ficheroLectura >> placa; // Leer placa del archivo de texto
        }
        ficheroLectura.close(); // Cerrar archivo de lectura 
        temp.close(); // Cerrar archivo temporal 
    }
    else
    {
        cout << "Error al abrir el archivo"; // Mostrar mensaje de error 
    }

    remove("Informacion.txt"); // Eliminar archivo original 
    rename("tmp.txt", "Informacion.txt"); // Renombrar archivo temporal 
}

void Eliminar(ifstream &ficheroLectura)
{
    string placa;
    string marca;
    string temp_p;

    ficheroLectura.open("Informacion.txt", ios::in);
    ofstream temp("tmp.txt", ios::out);

    if (ficheroLectura.is_open())
    {
        cout << "Ingrese el numero de placa";
        cin >> temp_p;
        ficheroLectura >> placa;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> marca;
            if (placa == temp_p)
            {
                cout << "Registro eliminado";
            }
            else
            {
                temp << placa << " " << marca << " "
                     << "\n";
            }
            ficheroLectura >> placa;
        }
        ficheroLectura.close();
        temp.close();
    }
    else
    {
        cout << "Error al abrir el archivo";
    }
    remove("Informacion.txt");
    rename("tmp.txt", "Informacion.txt");
}

void Imprimir(ifstream &ficheroLectura)
{
    string placa;
    string marca;
    ficheroLectura.open("Informacion.txt", ios::in);
    if (ficheroLectura.is_open())
    {
        ficheroLectura >> placa;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> marca;
            cout << "Placa : " << placa << endl;
            cout << "Marca : " << marca << endl;
            cout << "*******" << endl;
            ficheroLectura >> placa;
        }

        ficheroLectura.close();
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}