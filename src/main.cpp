#include "../include/simulacao.hpp"
#include "../include/leitorDeArquivo.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"
#include "../include/incendio.hpp"
#include "../include/animal.hpp"

#include <iostream>

using namespace std;

int main()
{
    {
        ofstream ofs("output.dat", ios::trunc);
    }

    leitorDeArquivo leitor;
    string nomeArquivo = "input.dat";
    Matriz matriz;

    leitor.lerArquivo(nomeArquivo, matriz);
    Incendio incendio(matriz);

    matriz.printarMatriz();

    Animal animal(matriz);
    
    incendio.IniciarIncendio();
    animal.randomizarPosAnimal();

    int numIteracoes = 0;
    animal.iterarMatrizFogo();
    do
    {
        animal.iterarMatrizFogo();
        animal.mover();
        incendio.IterarFogo();
        numIteracoes++;
        if (animal.getVida() == false)
        {
            cout << "Animal morreu!" << endl;
            break;
        }

    } while (!incendio.arvoresQueimando.empty());

    cout << "\nResumo da simulação:\n";
    cout << "Caminho do animal (" << animal.getPassos() << " passos):\n";
    for (size_t i = 0; i < animal.getCaminho().size(); i++)
    {
        Pos p = animal.getCaminho()[i];
        cout << "  " << i << ": (" << p.x << ", " << p.y << ")\n";
    }
    cout << "Total de passos: " << animal.getPassos() << "\n";
    if (animal.isVivo())
        cout << "O animal sobreviveu!\n";
    else
        cout << "O animal não sobreviveu.\n";

    // E para gravar no arquivo:
    // #include <fstream>
    ofstream outFile("output.dat", ios::app);
    if (outFile)
    {
        outFile << "\nResumo da simulação:\n";
        outFile << "Caminho do animal (" << animal.getPassos() << " passos):\n";
        for (size_t i = 0; i < animal.getCaminho().size(); i++)
        {
            Pos p = animal.getCaminho()[i];
            outFile << "  " << i << ": (" << p.x << ", " << p.y << ")\n";
        }
        outFile << "Total de passos: " << animal.getPassos() << "\n";
        if (animal.isVivo())
            outFile << "O animal sobreviveu!\n";
        else
            outFile << "O animal não sobreviveu.\n";
        outFile.close();
    }

    return 0;
}