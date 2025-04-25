#include "../include/leitorDeArquivo.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void leitorDeArquivo::lerArquivo(string &nomeArquivo, Matriz& _matriz)
{
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    // 1) Lê header: Linhas Colunas startX startY
    int linhas, colunas, startX, startY;
    if (!(arquivo >> linhas >> colunas >> startX >> startY)) {
        cerr << "Formato inválido na primeira linha." << endl;
        return;
    }
    cout << "Linhas: " << linhas << ", Colunas: " << colunas << endl;
    cout << "Inicio do fogo: " << startX << ", " << startY << endl;

    _matriz.setLinhas(linhas);
    _matriz.setColunas(colunas);
    _matriz.setInicioFogo(startX, startY);

    // Pula o restante da primeira linha (o '\n' depois do header)
    string linha;
    getline(arquivo, linha);

    // 2) Inicializa a matriz com as dimensões já lidas
    _matriz.inicializarMatriz(linhas, colunas);

    // 3) Lê cada linha da matriz como string, sem depender de espaços
    for (int i = 0; i < linhas; ++i) {
        if (!getline(arquivo, linha)) {
            cerr << "Erro ao ler a linha " << i + 1 << " do arquivo." << endl;
            return;
        }
        int pos = 0;
        for (int j = 0; j < colunas; ++j) {
            // pula espaços em branco (caso existam)
            while (pos < (int)linha.size() && isspace((unsigned char)linha[pos])) {
                pos++;
            }
            if (pos >= (int)linha.size() || linha[pos] < '0' || linha[pos] > '4') {
                cerr << "Valor inválido em (" << i << "," << j << "): '"
                     << (pos < (int)linha.size() ? linha[pos] : ' ')
                     << "'." << endl;
                return;
            }
            _matriz.setItem(i, j, linha[pos] - '0');
            pos++;
        }
    }

    arquivo.close();
}
