#ifndef LISTADOSCONTROLADORES_H_INCLUDED
#define LISTADOSCONTROLADORES_H_INCLUDED

#include"archivoClassPacientess.h"
#include"paciente.h"

//prototipos
void cargarCadenaPa(char *palabra, int tam);
void listaPorApellido();
void listarPorDni();
void listarMenores();

void cargarCadenaPa(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


void listaPorApellido(){
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

    char ape[20];
    cout<<"Ingresar el apellido a buscar: ";
    cargarCadenaPa(ape,19);

    for(int i=0;i<contPa;i++){
        if(p[i].getEstado() && strcmp(p[i].getApellido(),ape)==0){
            p[i].mostrarPaciente();
        }
    }
    delete p;
}

void listarPorDni(){
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

    int num;
    cout<<"Ingresar el DNI a buscar: ";
    cin>>num;

    for(int i=0;i<contPa;i++){
        if(p[i].getEstado() && p[i].getDni()==num){
            p[i].mostrarPaciente();
        }
    }
    delete p;
}

void listarMenores(){
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
    cout<<endl;
    int num;
    cout<<"Ingresar anio actual: ";
    cin>>num;

    for(int i=0;i<contPa;i++){
        if(p[i].getEstado() && (num - p[i].getFecha().getAnio())<18){
            p[i].mostrarPaciente();
        }
    }
    delete p;
}








#endif // LISTADOSCONTROLADORES_H_INCLUDED
