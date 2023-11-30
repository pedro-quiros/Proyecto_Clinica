#include<iostream>
#include <limits>

using namespace std;
#include"hora.h"

void Hora::setHora(int h){
     if(8<=h && h<=22){
        _hora=h;
     }
     else{_hora=0;}
}
void Hora::setMinuto(int m){
    if(0<=m && m<60){
        _minuto=m;
    }
    else{_minuto=-1;}
}

int Hora::getHora(){return _hora;}
int Hora::getMinuto(){return _minuto;}

void Hora::cargarHora(){
    cout<<endl;
    int hora,minuto;

    cout<<"Ingresar hora del turno: ";
    cin>>hora;

    while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin>>hora;
        }

    cout<<"Ingresar minutos: ";
    cin>>minuto;

    while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin>>minuto;
        }

    setHora(_hora);
    setMinuto(_minuto);
}
