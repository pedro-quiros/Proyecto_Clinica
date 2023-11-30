#ifndef LISTADOSCONTROLATURNO2_H_INCLUDED
#define LISTADOSCONTROLATURNO2_H_INCLUDED

#include"archivoClassEspecialista.h"
#include"especialista.h"
#include"archivoClassPacientess.h"
#include"paciente.h"

//funciones prototipos
void listaDeMedico();
void consultaPacientePorMedico();
void consultaPorDia();
void consultaPorEspecialidad();
void consultaHorariosOcupados();
void consultaPorDni();
void consultaEspecialistaDni();
void consultaPorMatriculaES();
void consultaPorMatriculaDiaHora();


void listaDeMedico(){
    Especialista e;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Especialista *p;
    p= new Especialista[contEs];
    if(p==NULL){exit(1);}

    for(int i=0;i<contEs;i++){
        e= archiEs.leerRegistro(i);

        p[i]=e;
    }

    for(int i=0;i<contEs;i++){

            if(p[i].getEstado()){
                p[i].mostrarEspecialista();
            }
    }
    delete p;
}

void consultaPacientePorMedico(){
    cout<<"ESP. - MATRICULA - NOMBRE - DNI - FECHA NAC."<<endl;
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if (es.getEstado()){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(es.getEstado() && es.getIdMatricula()==pa.getIdMatricula()){

                    pa.mostrarPaciente();
            }
        }
    }
}

void consultaPorDia(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dia;
    cout<<"Ingresar el dia: ";
    cin>>dia;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && es.getIdMatricula()==pa.getIdMatricula()
                && pa.getTurnoAsignado().getFechaTurno().getDia()==dia){

                    pa.mostrarPaciente();
                }
        }
    }
}

void consultaPorEspecialidad(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int espe;
    cout<<"Ingresar numero de especialidad: "<<endl;
    cout<<"1-Clinico. "<<endl;
    cout<<"2-Urologo. "<<endl;
    cout<<"3-Ginecologo. "<<endl;
    cout<<"4-Cardiologo. "<<endl;
    cout<<"5-Dermatologo. "<<endl;
    cin>>espe;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getEspecialidad()==espe){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && es.getIdMatricula()==pa.getIdMatricula()
                && pa.getEspecialista()==espe){

                    pa.mostrarPaciente();
                }
        }
    }
}

void consultaHorariosOcupados(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dia,mes,hora;

    cout<<"Ingresar dia: ";
    cin>>dia;
    cout<<"Ingresar mes: ";
    cin>>mes;
    cout<<"Ingrese hora a consultar: ";
    cin>>hora;
    cout<<endl;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);
        cout<<endl;

        if(es.getEstado()){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
                && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
                && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
                && pa.getTurnoAsignado().getHoraTurno().getHora()==hora){

                    pa.mostrarPaciente();
                }
        }
    }
}

void consultaPorDni(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"Ingresar DNI a buscar consulta: ";
    cin>>num;


     for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);
        cout<<endl;

        if(es.getEstado()){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && pa.getDni()==num){

               pa.mostrarPaciente();
            }
        }
     }
}

void consultaEspecialistaDni(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dni;
    cout<<"Ingresar DNI del ESPECIALISTA: ";
    cin>>dni;


      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);
        cout<<endl;

        if(es.getEstado() && es.getDni()==dni){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && es.getDni()==dni){

               pa.mostrarPaciente();
            }
        }
     }
}

void consultaPorMatriculaES(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int matri;
    cout<<"Ingresar matricula del ESPECIALISTA: ";
    cin>>matri;


      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);
        cout<<endl;

        if(es.getEstado() && es.getIdMatricula()==matri){
            es.mostrarEspecialista();
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && es.getIdMatricula()==matri){

               pa.mostrarPaciente();
            }
        }
     }
}

void consultaPorMatriculaDiaHora(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        es.mostrarEspecialista();
    }

    cout<<endl;
    int matri,dia,mes,hora,minuto;
    cout<<"Ingresar matricula del ESPECIALISTA: ";
    cin>>matri;
    cout<<"Ingresar dia posible turno: ";
    cin>>dia;
    cout<<"Ingresar mes posible turno: ";
    cin>>mes;
    cout<<"Ingresar hora posible turno: ";
    cin>>hora;
    cout<<"Ingresar minutos posible turno: ";
    cin>>minuto;

    bool bandera= true;

        for(int i=0;i<contEs;i++){
            es= archiEs.leerRegistro(i);
            cout<<endl;

            for(int j=0;j<contPa;j++){
                 pa= archiPa.leerRegistro(j);

                if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
                   && es.getIdMatricula()==matri
                   && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
                   && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
                   && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
                   && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

                 cout<<"DIA y HORARIO ocupados... "<<endl;
                 bandera=false;
                 cout<<endl;
                }
            }
        }
        if(bandera){
            cout<<"DIA y HORA LIBRES..."<<endl;
            cout<<endl;
        }

}








#endif // LISTADOSCONTROLATURNO2_H_INCLUDED
