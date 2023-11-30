#include<iostream>
#include<cstring>
#include <limits>

using namespace std;
#include"persona.h"
#include"fecha.h"

void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

const char* Persona::getNombre(){
    return _nombre;
}
const char* Persona::getApellido(){
    return _apellido;
}
Fecha Persona::getFecha(){
    return nacimiento;
}
int Persona::getDni(){
    return _dni;
}


void Persona::setNombre(const char *n){
    strcpy(_nombre,n);
}
void Persona::setApellido(const char *a){
    strcpy(_apellido,a);
}
void Persona::setFecha(Fecha f){
    nacimiento=f;
}
void Persona::setDni(int d){
      _dni=d;
}

void Persona::cargarPersona(){
    cout<<endl;
    cout<<"Ingrese Nombre: ";
    cargarCadena(_nombre,19);

    // --------------------------------------VALIDACION
    // Validar que el nombre no esté vacío
    while (strlen(_nombre) == 0) {
        cout << "El nombre no puede estar vacío. Por favor, ingreselo nuevamente: ";
        cargarCadena(_nombre, 19);
    }
    // --------------------------------------FIN VALIDACION

    cout<<"Ingresar Apellido: ";
    cargarCadena(_apellido,19);


    cout<<"Ingresar DNI: ";
    cin>>_dni;

     while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >> _dni;
        }

    cout<<endl;
    cout<<"CARGAR Fecha de nacimiento: "<<endl;
    nacimiento.cargarFecha();
}





