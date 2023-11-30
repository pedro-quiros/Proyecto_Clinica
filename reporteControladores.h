#ifndef REPORTECONTROLADORES_H_INCLUDED
#define REPORTECONTROLADORES_H_INCLUDED

#include"archivoClassEspecialista.h"
#include"especialista.h"
#include"archivoClassPacientess.h"
#include"paciente.h"


//Prototipos funciones
void pacientesPorAnio();
void cantidadDeConsultaPaciente();
void cantidadPorEspecialidad();


void pacientesPorAnio(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int mes,anio,hastaMes,hastaAnio,ma;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

         if (es.getEstado()){
            es.mostrarEspecialista();
        }
    }

    cout<<endl;
    cout<<"Ingresar matricula del Especialista: ";
    cin>>ma;
    cout<<"Ingresa desde que mes: ";
    cin>>mes;
    cout<<"Ingresa desde que anio: ";
    cin>>anio;
    cout<<"Ingresa hasta que mes: ";
    cin>>hastaMes;
    cout<<"Ingresa hasta que anio: ";
    cin>>hastaAnio;

    int cont=0;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

           if(es.getIdMatricula()==pa.getIdMatricula() && es.getIdMatricula()==ma
              && pa.getTurnoAsignado().getFechaTurno().getMes()>=mes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()>=anio
              && pa.getTurnoAsignado().getFechaTurno().getDia()<=hastaMes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()<=hastaAnio){

                cont++;
              }
        }
    }
    cout<<endl;
    cout<<"En el periodo indicado atendio: "<<cont<<endl;
    cout<<endl;

}

void cantidadDeConsultaPaciente(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"Ingrese el dni del paciente: ";
    cin>>num;

    int cont=0;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        if(pa.getDni()==num){

            cont++;
        }
    }
    cout<<endl;
    cout<<"cantidad de consultas: "<<cont<<endl;
    cout<<endl;
}

void cantidadPorEspecialidad(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"Ingresar especialidad: "<<endl;
    cout<<"     1-clinico. "<<endl;
    cout<<"     2-urologo. "<<endl;
    cout<<"     3-ginecologo. "<<endl;
    cout<<"     4-cardiologo. "<<endl;
    cout<<"     5-dermatologo."<<endl;
    cin>>num;
    cout<<endl;

    int cont=0;

     for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getEspecialidad()==num){

            cout<<"Especialistas: "<<num<<endl;
        }

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

            if(pa.getEspecialista()==num){

                cont++;
            }
        }
    }
    cout<<endl;
    cout<<"Los especialistas con ese numero tuvieron: "<<cont<<" consultas."<<endl;
    cout<<endl;
}


#endif // REPORTECONTROLADORES_H_INCLUDED
