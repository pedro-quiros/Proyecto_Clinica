#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED

#include"listadosControlaTurno2.h"

void consulta(){

    int num;
    cout<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|  1- Consultas por medico.                  |"<<endl;
    cout<<"|  2- Consultas por dia.                     |"<<endl;
    cout<<"|  3- consultas por especialidad.            |"<<endl;
    cout<<"|  4- Consulta horas ocupadas todos/Esp.     |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|  5- Consultas por DNI/Pac.                 |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|  6- Consultas por DNI del Especialista.    |"<<endl;
    cout<<"|  7- Consultas por MATRICULA Especialista.  |"<<endl;
    cout<<"|  8- Consulta por MATRICULA,DIA,HORA.       |"<<endl;
    cout<<"|  0- Volver.                                |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
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

    case 1: consultaPacientePorMedico();
            break;
    case 2: consultaPorDia();
            break;
    case 3: consultaPorEspecialidad();
            break;
    case 4: consultaHorariosOcupados();
            break;
    case 5: consultaPorDni();
            break;
    case 6: consultaEspecialistaDni();
            break;
    case 7: consultaPorMatriculaES();
            break;
    case 8: consultaPorMatriculaDiaHora();
            break;
    default:
            break;
    }

}



#endif // CONSULTA_H_INCLUDED
