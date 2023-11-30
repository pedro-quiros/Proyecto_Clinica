#include<iostream>
#include <limits>

using namespace std;
#include"fecha.h"

void Fecha::setDia(int d){
            if(0<d && d<=31){
                _dia=d;
            }
            else{_dia=0;}
}
void Fecha::setMes(int m){
            if(0<m && m<=12){_mes=m;}
            else{_mes=0;}
}
void Fecha::setAnio(int a){
        if(1920<a){_anio=a;}
        else{_anio=0;}
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::cargarFecha(){
    cout<<endl;
    int dia,mes,anio;

    cout<<"Ingresar dia: ";
    cin>>dia;

    while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >>dia;
        }

    cout<<"Ingresar mes: ";
    cin>>mes;

    while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin>>mes;
        }

    cout<<"Ingresar Anio: ";
    cin>>anio;

    while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin>>anio;
        }

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}


