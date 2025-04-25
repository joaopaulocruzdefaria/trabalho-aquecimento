// Animal.hpp
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "matriz.hpp"
#include "global.hpp"
#include "incendio.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal
{
private:
    Matriz &matrizRef;
    vector<vector<short int>> matrizTemp;
    bool vida = true;
    Pos animalPos;
    int tempoSeguro = 0; // até 3 iterações parado em célula 0
    int passos = 0;
    vector<Pos> caminho; // armazena o caminho percorrido

public:
    Animal(Matriz &_matriz);
    int getPassos() const;
    bool isVivo() const;
    const vector<Pos> &getCaminho() const;
    Pos getPosicao() const;
    bool getVida() { return vida; }

    void randomizarPosAnimal();
    void mover();
    void iterarMatrizFogo();
    void printarMatrizTemp()    {
        for (int i = 0; i < TAM_TEMP; i++)
        {
            for (int j = 0; j < TAM_TEMP; j++)
            {
                cout << matrizTemp[i][j] << " ";
            }
            cout << endl;
        }
    }};

#endif // ANIMAL_HPP