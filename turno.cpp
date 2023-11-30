#include<iostream>
#include<cstring>

using namespace std;
#include"turno.h"
#include"paciente.h"
#include"archivoClassPacientess.h"
#include"especialista.h"
#include"archivoClassEspecialista.h"

void Turno::setDni(int d){
    _dni=d;
}

void Turno::setIdMatricula(int m){
     idMatricula=m;
}

void Turno::setFechaTurno(Fecha fe){
    fechaTurno=fe;
}

void Turno::setHoraTurno(Hora ho){
    horaTurno=ho;
}

int Turno::getDni(){
    return _dni;
}

int Turno::getIdMatricula(){
    return idMatricula;
}

Fecha Turno::getFechaTurno(){
    return fechaTurno;
}

Hora Turno::getHoraTurno(){
    return horaTurno;
}

void Turno::cargarTurno(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    Paciente *p;
    p= new Paciente[contPa];
    if(p==NULL){exit(1);}

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        p[i]=pa;
    }
    int dia,mes;

    cout<<"Ingresa el dia del POSIBLE turno: ";
    cin>>dia;
    cout<<"Ingresar el mes: ";
    cin>>mes;
    cout<<endl;

    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Especialista *pe;
    pe= new Especialista[contEs];
    if(pe==NULL){exit(1);}

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        pe[i]=es;
    }

    /*for(int i=0;i<contEs;i++){
        if(pe[i].getEstado()){
            pe[i].mostrarEspecialista();
        }
    }*/
    int ma;
    cout<<endl;
    cout<<"Ingresar la matricula del especialista: ";
    cin>>ma;

    cout<<endl;
    bool bandera=true;
    cout<<"----------Turnos ocupados:---------- "<<endl;

    for(int i=0;i<contPa;i++){

        if(p[i].getEstado() && p[i].getFecha().getDia()==dia
           && p[i].getFecha().getMes()==mes && p[i].getIdMatricula()==ma){

           p[i].mostrarPaciente();
           bandera=false;
        }
    }
    if(bandera){
        cout<<endl;
        cout<<"Sin turnos asignados..."<<endl;
    }
    delete p;
    delete pe;

    fechaTurno.cargarFecha();
    horaTurno.cargarHora();
}

void Turno::mostrarTurno(){
    cout<<" "<<fechaTurno.getDia()<<"-"<<fechaTurno.getMes()<<"-"<<fechaTurno.getAnio();
    cout<<"  "<<horaTurno.getHora()<<":"<<horaTurno.getMinuto()<<endl;
}

