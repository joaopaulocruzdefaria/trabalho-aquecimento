#include "../include/incendio.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"

Incendio::Incendio(Matriz &_matriz) : matrizRef(_matriz){}

bool Incendio::PodePegarFogo(short int x, short int y)
{
    if (x < 0 || x >= matrizRef.getLinhas() || y < 0 || y >= matrizRef.getColunas())
    {
        cerr << "Posição fora dos limites da matriz." << endl;
        return false;
    }
    else if (matrizRef.getMatriz()[x][y] == 1)
    {
        if ((x + 1 < matrizRef.getLinhas() && matrizRef.getMatriz()[x + 1][y] == 2) ||
            (x - 1 >= 0 && matrizRef.getMatriz()[x - 1][y] == 2) ||
            (y + 1 < matrizRef.getColunas() && matrizRef.getMatriz()[x][y + 1] == 2) ||
            (y - 1 >= 0 && matrizRef.getMatriz()[x][y - 1] == 2))
        {
            return true;
        }
    }
    return false;
}

void Incendio::IterarFogo()
{
    vector<Pos> arvoresQueimando;

    // Transformar os '2' que estão com posicoes marcadas no vetor aux em '3'

    for (const Pos &p : arvoresQueimando)
    {
        if (matrizRef.getItem(p.x,p.y) == 2)
        {
            matrizRef.setItem(p.x,p.y,3);
        }
    }

    arvoresQueimando.clear();

    cout << endl;

    for (short int i = 0; i < matrizRef.getLinhas(); i++)
    {
        for (short int j = 0; j < matrizRef.getColunas() ; j++)
        {
            if (matrizRef.getItem(i,j) == 2)
            {
                Pos p;
                p.x = i;
                p.y = j;
                arvoresQueimando.push_back(p);
            }

            if (PodePegarFogo(i, j))
            {
                matrizRef.setItem(i,j,2); // pega fogo
            }
        }
    }
    cout << endl;

    cout << "Turno: " << turno << endl;
    turno++;

    matrizRef.printarMatriz();

    // Setar as novas arvores queimadas em um vetor aux
}