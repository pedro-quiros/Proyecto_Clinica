#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include"hora.h"
#include"fecha.h"

class Turno{
    private:
        int _dni;
        int idMatricula;
        Fecha fechaTurno;
        Hora horaTurno;

    public:
        void setDni(int);
        void setIdMatricula(int);
        void setFechaTurno(Fecha);
        void setHoraTurno(Hora);

        int getDni();
        int getIdMatricula();
        Fecha getFechaTurno();
        Hora getHoraTurno();

        void cargarTurno();
        void mostrarTurno();
};

#endif // TURNO_H_INCLUDED
