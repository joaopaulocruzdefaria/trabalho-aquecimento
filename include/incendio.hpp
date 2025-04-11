#ifndef INCENDIO_HPP    
#define INCENDIO_HPP

#include "matriz.hpp"
#include "global.hpp"
#include <iostream>
#include <vector>

class Incendio{
    
    private:
        Matriz &matrizRef;
        int turno=0;

    public:
        Incendio(Matriz &_matriz);
        void IterarFogo();
        bool PodePegarFogo(short int x, short int y);
};

#endif