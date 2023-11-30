#include<iostream>
#include<cstring>
#include <limits>

#include <iomanip>

using namespace std;

#include"rlutil.h"
#include"paciente.h"
#include"archivoClassPacientess.h"

#include"especialista.h"
#include"archivoClassEspecialista.h"

void Paciente::setEspecialista(int e){
     especialista=e;
}
void Paciente::setIdMatricula(int m){
     idMatricula=m;
}
void Paciente::setTurnoAsignado(Turno t){
    turnoAsignado=t;
}

void Paciente::setEstado(bool e){
    estado=e;
}

int Paciente::getEspecialista(){
    return especialista;
}

int Paciente::getIdMatricula(){
    return idMatricula;
}

Turno Paciente::getTurnoAsignado(){
    return turnoAsignado;
}

bool Paciente::getEstado(){
    return estado;
}

void Paciente::cargarPaciente(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Persona::cargarPersona();

    int num1;
    cout<<endl;
    cout<<"--------Ingresa Numero de la especialidad para el TURNO-------: "<<endl;
    cout<<"        1-clinico. "<<endl;
    cout<<"        2-urologo. "<<endl;
    cout<<"        3-ginecologo. "<<endl;
    cout<<"        4-cardiologo. "<<endl;
    cout<<"        5-dermatologo."<<endl;
    cin>>num1;
    cout<<endl;

     while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >> num1;
        }

    setEspecialista(num1);

    system("cls");

    cout<<"----------ESPECIALISTAS----------"<<endl;
    cout<<endl;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

       if(es.getEstado() && es.getEspecialidad()==num1){
            es.mostrarEspecialista();
        }
    }

    turnoAsignado.cargarTurno();
    estado=true;

    cout<<endl;
}

 void Paciente::mostrarPaciente(){

    /*cout<<"Nombre: "<<Persona::getNombre()<<endl;
    cout<<"Apellido: "<<Persona::getApellido()<<endl;
    cout<<"DNI: "<<Persona::getDni()<<endl;
    cout<<"Numero ESPECIALISTA: "<<getEspecialista()<<endl;
    cout<<"Especilista Matricula: "<<getIdMatricula()<<endl;
    cout<<"TURNO ASIGNADO: ";
    turnoAsignado.mostrarTurno();*/

    // Configurar ancho de columna para una presentación ordenada
    const int anchoColumna = 20;

        cout << left << setw(anchoColumna) << getNombre()
                  << setw(anchoColumna) << getApellido()
                  << setw(anchoColumna) << getDni()
                  << setw(anchoColumna) << getEspecialista()
                  << setw(15) << getIdMatricula()
                  << setw(0);

        turnoAsignado.mostrarTurno();

        // Restaurar colores originales
        //rlutil::resetColor();
 }





