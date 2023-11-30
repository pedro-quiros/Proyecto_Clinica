#ifndef SUBMENUBAJA_H_INCLUDED
#define SUBMENUBAJA_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

void bajasTuME(){

 int num;
    cout<<endl;
    cout<<"+-----------------------------+"<<endl;
    cout<<"|  1- BAJA turnos.            |"<<endl;
    cout<<"|  2- BAJA Especialista.      |"<<endl;
    cout<<"|  0- Volver.                 |"<<endl;
    cout<<"+-----------------------------+"<<endl;
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

    case 1: bajaLogica();
            break;
    case 2: bajaLogicaEspecialista();
            break;
    default:
            break;
    }

}



#endif // SUBMENUBAJA_H_INCLUDED
