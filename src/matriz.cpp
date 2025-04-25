#include "../include/matriz.hpp"
#include "../include/global.hpp"

short int Matriz::getItem(int i, int j) {
    if (i >= 0 && i < linhas && j >= 0 && j < colunas)
        return m[i][j];
    else {
        cout << "Tentativa de acessar [" << i << "," << j << "] FORA da matriz!" << endl;
        return -1; // ou lança exceção
    }
}


void Matriz::printarMatriz()
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << getItem(i, j) << " ";
        }
        cout << endl;
    }
}

void Matriz::inicializarMatriz(short int _linhas, short int _colunas)
{
    m = vector<vector<short int>>(_linhas, vector<short int>(_colunas, 0));
}

void Matriz::setMatriz(vector<vector<short int>> outra)
{

    m.clear();
    m.resize(outra.size());

    for (size_t i = 0; i < outra.size(); ++i)
    {
        for (size_t j = 0; j < outra[i].size(); ++j)
        {
            m[i].push_back(outra[i][j]);
        }
    }
}
