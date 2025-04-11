#include "../include/simulacao.hpp"
#include "../include/leitorDeArquivo.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"
#include "../include/incendio.hpp"

#include <iostream>

using namespace std;

int main()
{
    leitorDeArquivo leitor;
    string nomeArquivo = "input.dat";
    Matriz matriz;
    leitor.lerArquivo(nomeArquivo , matriz);
    Incendio incendio(matriz);

    matriz.printarMatriz();

    incendio.IterarFogo();
    incendio.IterarFogo();
    incendio.IterarFogo();

    return 0;
}