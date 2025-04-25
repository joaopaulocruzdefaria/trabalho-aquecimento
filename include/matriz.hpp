#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <iostream>
#include "global.hpp"

using namespace std;

class Matriz{
    public:
        Matriz() : linhas(0), colunas(0) {};
        Matriz( short int _linhas ,  short int _colunas , vector<vector< short int >> _matriz) : 
        linhas(_linhas), colunas(_colunas), m(_matriz) {};

        void setLinhas( short int _linhas) { linhas = _linhas; }
        void setColunas( short int _colunas) { colunas = _colunas; }
        void setMatriz(vector<vector< short int >> outra);
        void setItem( int i, int j, int item) { m[i][j] = item; }
        void setInicioFogo(short int x, short int y) { inicioFogo.x = x; inicioFogo.y = y; }

        int getLinhas() { return linhas; }
        int getColunas() { return colunas; }
        Pos getInicioFogo() { return inicioFogo; }
    
        short int getItem(int i, int j);
        vector<vector< short int >> getMatriz() { return m; }

        void inicializarMatriz(short int _linhas, short int _colunas);

        void printarMatriz();

    private:
        short int linhas;
        short int colunas;
        Pos inicioFogo;
        vector<vector< short int >> m;
};


#endif