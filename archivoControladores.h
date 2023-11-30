#ifndef ARCHIVOCONTROLADORES_H_INCLUDED
#define ARCHIVOCONTROLADORES_H_INCLUDED

#include"paciente.h"

#include <iomanip>
#include"rlutil.h"

//prototipos
bool altaTurno();
int buscarPaciente(int n);
Paciente leerRegistro(int pos);
bool mostrarPacient();
bool sobreEscribir(Paciente e,int pos);
bool bajaLogica();
bool modificarTurno();


bool altaTurno(){
    Paciente p;
    FILE *em;
    em=fopen("turno.dat","ab");
    if(em==NULL){
        cout<<endl;
        cout<<"ERROR no abrio arcivo."<<endl;
        return false;
    }
    p.cargarPaciente();

    fwrite(&p,sizeof p,1,em);

    fclose(em);
    return true;
}

int buscarPaciente(int n){
    Paciente e;
    FILE *p;

    p=fopen("turno.dat","rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&e,sizeof e,1,p)==1){
        if(e.getDni()==n){
            fclose(p);
            return pos;
        }
     pos++;
    }
    fclose(p);
    return -1;
}

Paciente leerRegistro(int pos){
    Paciente e;
    e.setEstado(false);
    FILE *p;

    p=fopen("turno.dat","rb");
    if(p==NULL){
        return e;
    }

    fseek(p,sizeof e*pos,0);
    fread(&e,sizeof e,1,p);

    fclose(p);
    return e;
}

bool mostrarPacient(){
    Paciente e;
    FILE *p;

    p=fopen("turno.dat","rb");
    if(p==NULL){
      return false;
    }

   const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(0) << "TURNO"
              << "\n";

    while(fread(&e,sizeof e,1,p)==1){
        if(e.getEstado()){
            cout<<endl;
            e.mostrarPaciente();
        }
    }
    cout<<endl;
    fclose(p);
    return true;
}

bool sobreEscribir(Paciente e,int pos){
     FILE *p;
     p=fopen("turno.dat","rb+");
     if(p==NULL){
        return false;
     }
    fseek(p,sizeof e*pos,0);
    bool escribio = fwrite(&e,sizeof e,1,p);
    fclose(p);
    return escribio;
}


bool bajaLogica(){
    int numero, pos;
    cout<<endl;
    cout<<"Turno a dar de baja INGRESE DNI: ";
    cin>>numero;

   pos=buscarPaciente(numero);
   if(pos==-1 || pos==-2){
     cout<<endl;
     cout<<"No existe el DNI."<<endl;
     return false;
   }

   Paciente e;
   e=leerRegistro(pos);

   cout<<"Paciente a Borrar: "<<endl;
   e.mostrarPaciente();

   cout<<endl;
   char opc;

   cout<<"Desea borrarlo(S/N): ";
   cin>>opc;

   if(opc=='s' || opc=='S'){
      e.setEstado(false);

      bool quePaso= sobreEscribir(e,pos);
      return quePaso;
   }
 return false;
}

bool modificarTurno(){
      int numero, pos;
      cout<<endl;
      cout<<" DNI que desea modificar TURNO: ";
      cin>>numero;

   pos=buscarPaciente(numero);
   if(pos==-1 || pos==-2){
     cout<<endl;
     cout<<"No existe el numero de DNI."<<endl;
     return false;
   }

   Paciente e;
   e=leerRegistro(pos);

   cout<<"Paciente a modificar TURNO: "<<endl;
   e.mostrarPaciente();

   cout<<endl;
   Turno tu;

   cout<<"Ingrese nuevo DIA y HORARIO: ";
   tu.cargarTurno();

   e.setTurnoAsignado(tu);

   bool quePaso= sobreEscribir(e,pos);
   return quePaso;
}


#endif // ARCHIVOCONTROLADORES_H_INCLUDED
