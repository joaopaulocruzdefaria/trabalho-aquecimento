#include "../include/leitorDeArquivo.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"

using namespace std;

void leitorDeArquivo::lerArquivo(string &nomeArquivo, Matriz& _matriz)
{
    ifstream arquivo(nomeArquivo);    

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    Pos inicioFogo;
    string linha;
    short int linhas, colunas;

    if (getline(arquivo, linha))
    {
        linhas = linha[0] - '0';
        colunas = linha[1] - '0';
        inicioFogo.x = linha[2] - '0';
        inicioFogo.y = linha[3] - '0';
        cout << "Linhas: " << linhas << ", Colunas: " << colunas << endl;
        cout << "Inicio do fogo: (" << inicioFogo.x << ", " << inicioFogo.y << ")" << endl;
    }
    else
    {
        cerr << "Erro ao ler a primeira linha do arquivo." << endl;
        return;
    }

    _matriz.inicializarMatriz(linhas,colunas);


    for (int i = 0; i < linhas; ++i)
    {
        if (getline(arquivo, linha))
        {
            for (int j = 0; j < colunas; ++j)
            {
                _matriz.setItem(i,j,linha[j]- '0');
            }
        }
        else
        {
            cerr << "Erro ao ler a linha " << i + 1 << " do arquivo." << endl;
            return;
        }
    }

    _matriz.setLinhas(linhas);
    _matriz.setColunas(colunas);   

    arquivo.close();
}