#ifndef SUBLISTAS_H_INCLUDED
#define SUBLISTAS_H_INCLUDED

#include"listadosControladores.h"
#include"listadosControlaTurno2.h"

void subMenuLista(){

    int num;
    cout<<endl;
    cout<<"+-----------------------------+"<<endl;
    cout<<"|  1- Mostrar todos.          |"<<endl;
    cout<<"|  2- Lista por Apellidos.    |"<<endl;
    cout<<"|  3- Lista por DNI.          |"<<endl;
    cout<<"|  4- Lista Menores Edad.     |"<<endl;
    cout<<"|  5- Lista de Medico.        |"<<endl;
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

    case 1: mostrarPacient();
            break;
    case 2: listaPorApellido();
            break;
    case 3: listarPorDni();
            break;
    case 4: listarMenores();
            break;
    case 5: listaDeMedico();
            break;
    default:
            break;
    }
}

#endif // SUBLISTAS_H_INCLUDED
