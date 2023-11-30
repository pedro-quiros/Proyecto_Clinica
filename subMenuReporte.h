#ifndef SUBMENUREPORTE_H_INCLUDED
#define SUBMENUREPORTE_H_INCLUDED

#include"reporteControladores.h"



void reporte(){

    int num;
    cout<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  1- Cant. pacientes atendidos en un intervalo.|"<<endl;
    cout<<"|  2- Cant. consultas de un paciente.           |"<<endl;
    cout<<"|  3- Cant. consultas por especialidad.         |"<<endl;
    cout<<"|  0- Volver.                                   |"<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
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

    case 1: pacientesPorAnio();
            break;
    case 2: cantidadDeConsultaPaciente();
            break;
    case 3: cantidadPorEspecialidad();
            break;
    default:
            break;
    }

}





#endif // SUBMENUREPORTE_H_INCLUDED
