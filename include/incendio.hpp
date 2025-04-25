#ifndef INCENDIO_HPP    
#define INCENDIO_HPP

#include "matriz.hpp"
#include "global.hpp"
#include "incendio.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Incendio{
    
    private:
        Matriz &matrizRef;
        Pos inicioFogo;
        int turno=0;

    public:
        Incendio(Matriz &_matriz);
        void IterarFogo();
        void IniciarIncendio();
        void setInicioFogo(short int x, short int y) { inicioFogo.x = x; inicioFogo.y = y; }
        Pos getInicioFogo() { return inicioFogo; }
        bool PodePegarFogo(short int x, short int y);
        vector<Pos> arvoresQueimando;
};

#endif