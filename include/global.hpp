#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>

struct Pos
{
    int x, y;

    Pos() : x(-1), y(-1) {}
    Pos(int _x, int _y) : x(_x), y(_y) {}
};

const int direcoes[4][2] = {
    {-1, 0},  // cima
    {1, 0},   // baixo
    {0, -1},  // esquerda
    {0, 1},   // direita
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// Definições globais para o ambiente

const int TAM_TEMP = 3;
const int ALTURA_PADRAO = 100;
const int MAX_ITERACOES = 100;

#endif // GLOBAL_HPP
