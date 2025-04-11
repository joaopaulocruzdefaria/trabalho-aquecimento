#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <iostream>

using namespace std;

class Matriz{
    public:
        Matriz() : linhas(0), colunas(0) {};
        Matriz( short int _linhas ,  short int _colunas , vector<vector< short int *>> _matriz) : 
        linhas(_linhas), colunas(_colunas), m(_matriz) {};

        void setLinhas( short int _linhas) { linhas = _linhas; }
        void setColunas( short int _colunas) { colunas = _colunas; }
        void setMatriz(vector<vector< short int *>> outra);

        int getLinhas() { return linhas; }
        int getColunas() { return colunas; }
        vector<vector< short int *>> getMatriz() { return m; }

        void printarMatriz();

    private:
        short int linhas;
        short int colunas;
        vector<vector< short int *>> m;
};


#endif