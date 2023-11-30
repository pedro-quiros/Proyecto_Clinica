///Proyecto: Sistema clinica
///Autor: Hugo Orlando Benitez
///Grupo 7.
///Laboratorio de Computacion II -> UTN G.Pacheco.

#include <iostream>
#include<cstring>
#include<windows.h>
#include <limits>

using namespace std;

#include"rlutil.h"
#include"altaTu_Me.h"
#include"subListas.h"
#include"subMenuBaja.h"
#include"subMenuModificar.h"
#include"consulta.h"
#include"subMenuReporte.h"


/*void tituloPaciente(){
        rlutil::locate(20,1); //El primero
        cout << (char)201;
        rlutil::locate(20,2);//Vertical
        cout << (char)186;
        rlutil::locate(20,3);// L
        cout << (char)200;
        rlutil::locate(40,2);

        cout<<"PACIENTE";

        for(int j=21;j<70;j++){
            rlutil::locate(j,1);
            cout<< (char)205;
            rlutil::locate(j,3);
            cout<< (char)205;
             }
            rlutil::locate(70,1);
            cout<< (char)187;
            rlutil::locate(70,2);
            cout<< (char)186;
            rlutil::locate(70,3);
            cout<< (char)188;
}*/


int main(){

    rlutil::setColor(rlutil::YELLOW);
    rlutil::setBackgroundColor(rlutil::BLUE);

    int opc;
    while(true){
        system("cls");
        cout<<"MENU TURNOS "<<endl;
        cout<<"******************************"<<endl;
        cout<<"1. ALTAS TURNO/ESP."<<endl;
        cout<<"2. BAJA LOGICA TURNO/ESP."<<endl;
        cout<<"3. MODIFICAR TURNO/ESP "<<endl;
        cout<<"4. LISTAS DE TURNOS/ESP."<<endl;
        cout<<"5. CONSULTAS.           "<<endl;
        cout<<"6. REPORTES.           "<<endl;
        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        cout<<"******************************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;

        while(cin.fail()) {
             cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
             // Limpiar el buffer de entrada
             cin.clear();
             // Descartar el contenido no válido en el buffer
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Volver a intentar leer
            cin >> opc;
        }
        system("cls");

        switch(opc){

            case 1: altas();
                    break;
            case 2: bajasTuME();
                    break;
            case 3: modificarTuME();
                    break;
            case 4: subMenuLista();
                    break;
            case 5: consulta();
                    break;
            case 6: reporte();
                    break;

            case 0:
                    cout<<endl;
                    cout << "Saliendo del programa..." << endl;
                    cout<<endl;
                    return 0;
                    break;
            default:
                    cout<<endl;
                    cout << "Opcion no valida. Ociones validas 1,2,3,4,5,6 o 0-Salir." << endl;
                    cout<<endl;
        }
    system("pause");
    }

    return 0;
}
