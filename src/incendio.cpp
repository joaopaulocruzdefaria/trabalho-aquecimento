#include "../include/incendio.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Incendio::Incendio(Matriz &_matriz) : matrizRef(_matriz) {}

void Incendio::IniciarIncendio()
{
    Pos inicio = matrizRef.getInicioFogo();
    int x = inicio.x;
    int y = inicio.y;

    // Valida posição inicial
    if (x < 0 || x >= matrizRef.getLinhas() || y < 0 || y >= matrizRef.getColunas()) {
        cout << "Posição de início fora dos limites da matriz.\n";
        return;
    }
    if (matrizRef.getItem(x, y) != 1) {
        cout << "Posição de início inválida: não contém uma árvore saudável.\n";
        return;
    }

    // Incendeia a árvore inicial
    matrizRef.setItem(x, y, 2);
    arvoresQueimando.push_back(inicio);
}

bool Incendio::PodePegarFogo(short int x, short int y)
{
    if (x < 0 || x >= matrizRef.getLinhas() || y < 0 || y >= matrizRef.getColunas()) {
        cerr << "Posição fora dos limites da matriz." << endl;
        return false;
    }
    if (matrizRef.getItem(x, y) == 1) {
        for (auto &p : arvoresQueimando) {
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];
                if (nx == x && ny == y) return true;
            }
        }
    }
    return false;
}

void Incendio::IterarFogo()
{
    // Abre arquivo de saída em append
    ofstream outFile("output.dat", ios::app);
    if (!outFile) {
        cerr << "Não foi possível abrir output.dat para escrita." << endl;
    }

    vector<Pos> novosFocos;
    int iteracao = turno + 1;

    // Propagação do fogo e registro de cada árvore queimada
    for (short int i = 0; i < matrizRef.getLinhas(); i++) {
        for (short int j = 0; j < matrizRef.getColunas(); j++) {
            if (matrizRef.getItem(i, j) == 2) {
                for (int d = 0; d < 4; d++) {
                    short int nx = i + dx[d];
                    short int ny = j + dy[d];
                    if (nx >= 0 && nx < matrizRef.getLinhas() &&
                        ny >= 0 && ny < matrizRef.getColunas()) {
                        if (PodePegarFogo(nx, ny)) {
                            matrizRef.setItem(nx, ny, 2);
                            novosFocos.push_back(Pos{nx, ny});

                            // Direção textual
                            string dir;
                            if (dx[d] == -1 && dy[d] == 0) dir = "acima";
                            else if (dx[d] == 1 && dy[d] == 0) dir = "abaixo";
                            else if (dx[d] == 0 && dy[d] == -1) dir = "esquerda";
                            else if (dx[d] == 0 && dy[d] == 1) dir = "direita";

                            // Console
                            cout << "• (" << nx << "," << ny << ") vira 2 (" << dir << ")" << endl;
                            
                            // Arquivo
                            if (outFile) {
                                outFile << "• (" << nx << "," << ny << ") vira 2 (" << dir << ")" << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    // Converte focos antigos para árvores completamente queimadas
    for (auto &p : arvoresQueimando) {
        if (matrizRef.getItem(p.x, p.y) == 2) {
            matrizRef.setItem(p.x, p.y, 3);
        }
    }
    arvoresQueimando = move(novosFocos);

    // Escreve iteração e matriz no arquivo
    if (outFile) {
        outFile << "Iteração " << iteracao << ":" << endl;
        for (int i = 0; i < matrizRef.getLinhas(); i++) {
            for (int j = 0; j < matrizRef.getColunas(); j++) {
                outFile << matrizRef.getItem(i, j) << " ";
            }
            outFile << endl;
        }
        outFile << endl << "----------------------------------" << endl << endl;
        outFile.close();
    }

    // Console: iteração e matriz
    cout << endl << "Iteração " << iteracao << ":" << endl;
    matrizRef.printarMatriz();
    cout << "----------------------------------" << endl;

    turno++;
}
