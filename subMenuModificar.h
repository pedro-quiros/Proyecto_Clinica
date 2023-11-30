#ifndef SUBMENUMODIFICAR_H_INCLUDED
#define SUBMENUMODIFICAR_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

void modificarTuME(){

 int num;
    cout<<endl;
    cout<<"+----------------------------------+"<<endl;
    cout<<"|  1- MODIFICAR turnos.            |"<<endl;
    cout<<"|  2- MODIFICAR Especilista.       |"<<endl;
    cout<<"|  0- Volver.                      |"<<endl;
    cout<<"+----------------------------------+"<<endl;
    cin>>num;

     while(cin.fail()) {
        cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
        // Limpiar el buffer de entrada
        cin.clear();
        // Descartar el contenido no válido en el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Volver a intentar leer
        cin >> num;
        }

    system("cls");

    switch(num){

    case 1: modificarTurno();
            break;
    case 2: modificarEspecialista();
            break;
    default:
            break;
    }

}



#endif // SUBMENUMODIFICAR_H_INCLUDED
