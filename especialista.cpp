#include<iostream>
#include<cstring>
#include <limits>

using namespace std;
#include"especialista.h"

void Especialista::setIdMatricula(int ma){
    idMatricula=ma;
}
void Especialista::setEspecialidad(int e){
    if(0<e && e<=5){
        especialidad=e;
    }
    else{especialidad=0;}
}
void Especialista::setEstado(bool e){
      estado=e;
}

int Especialista::getIdMatricula(){
    return idMatricula;
}

int Especialista::getEspecialidad(){
    return especialidad;
}

bool Especialista::getEstado(){
    return estado;
}


void Especialista::cargarEspecialista(){
    cout<<endl;
    int num1,num2;

    cout<<"Ingresar el Numero de Matricula: ";
    cin>>num1;

     while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >> num1;
        }

     setIdMatricula(num1);

    cout<<endl;
    cout<<"Ingresar el especialista [1,5]: "<<endl;
    cout<<"1-Clinico. "<<endl;
    cout<<"2-Urologo. "<<endl;
    cout<<"3-Ginecologo. "<<endl;
    cout<<"4-Cardiologo. "<<endl;
    cout<<"5-Dermatologo. "<<endl;
    cin>>num2;

     while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >> num2;
        }

    setEspecialidad(num2);

    Persona::cargarPersona();
    estado=true;
}

void Especialista::mostrarEspecialista(){
    cout<<especialidad<<"  ";
    cout<<idMatricula<<"  ";
    cout<<Persona::getNombre()<<"  ";
    cout<<Persona::getApellido()<<"  ";
    cout<<Persona::getDni()<<"  ";
    cout<<Persona::getFecha().getDia()<<"/";
    cout<<Persona::getFecha().getMes()<<"/";
    cout<<Persona::getFecha().getAnio()<<endl;
    cout<<endl;
}
