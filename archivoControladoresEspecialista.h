#ifndef ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED
#define ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED

#include"especialista.h"

bool altaEspecialista(){
    Especialista e;
    FILE *em;
    em=fopen("especialista.dat","ab");
    if(em==NULL){
        cout<<endl;
        cout<<"ERROR no abrio arcivo."<<endl;
        return false;
    }
    e.cargarEspecialista();

    fwrite(&e,sizeof e,1,em);

    fclose(em);
    return true;
}

int buscarEspecialista(int n){
    Especialista e;
    FILE *p;

    p=fopen("especialista.dat","rb");
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

Especialista leerRegistroE(int pos){
    Especialista e;
    e.setEstado(false);
    FILE *p;

    p=fopen("especialista.dat","rb");
    if(p==NULL){
        return e;
    }

    fseek(p,sizeof e*pos,0);
    fread(&e,sizeof e,1,p);

    fclose(p);
    return e;
}

bool mostrarEspecialista(){
    Especialista e;
    FILE *p;

    p=fopen("especialista.dat","rb");
    if(p==NULL){
      return false;
    }

    while(fread(&e,sizeof e,1,p)==1){
        if(e.getEstado()){

            cout<<endl;
            e.mostrarEspecialista();
        }
    }
    fclose(p);
    return true;
}

bool sobreEscribirEspecialista(Especialista e,int pos){
     FILE *p;
     p=fopen("especialista.dat","rb+");
     if(p==NULL){
        return false;
     }
    fseek(p,sizeof e*pos,0);
    bool escribio = fwrite(&e,sizeof e,1,p);
    fclose(p);
    return escribio;
}


bool bajaLogicaEspecialista(){
    int numero, pos;
    cout<<endl;
    cout<<"Especialista a dar de baja INGRESE DNI: ";
    cin>>numero;

   pos=buscarEspecialista(numero);
   if(pos==-1 || pos==-2){
     cout<<endl;
     cout<<"No existe el DNI."<<endl;
     return false;
   }

   Especialista e;
   e=leerRegistroE(pos);

   cout<<"Especialista a Borrar: "<<endl;
   cout<<"***********************************"<<endl;
   cout<<"ESP. - MATRICULA - NOMBRE - DNI - FECHA NAC."<<endl;
   e.mostrarEspecialista();

    if (e.getEstado() == 0) {
        cout << "Estado: Desactivado" << endl;
    } else if (e.getEstado() == 1) {
        cout << "Estado: Activo" << endl;
    }
   cout<<"***********************************"<<endl;

   cout<<endl;
   char opc;


   cout<<"Desea borrarlo(S/N): ";
   cin>>opc;

   if(opc=='s' || opc=='S'){
      e.setEstado(false);


      bool quePaso= sobreEscribirEspecialista(e,pos);
      return quePaso;
   }
 return false;
}

bool modificarEspecialista(){
      int numero, pos;
      cout<<endl;
      cout<<" DNI del especilista a modificar: ";
      cin>>numero;

   pos=buscarEspecialista(numero);
   if(pos==-1 || pos==-2){
     cout<<endl;
     cout<<"No existe el numero de DNI."<<endl;
     return false;
   }

   Especialista e;
   e=leerRegistroE(pos);

   cout<<"Especialista a modificar: "<<endl;
   e.mostrarEspecialista();

   cout<<"Ingrese nuevo Especialista: ";
   cout<<endl;
   e.cargarEspecialista();

   bool quePaso= sobreEscribirEspecialista(e,pos);
   return quePaso;
}





#endif // ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED
