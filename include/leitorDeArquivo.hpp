#ifndef LEITORDEARQUIVO_HPP
#define LEITORDEARQUIVO_HPP

#include "matriz.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class leitorDeArquivo {
public:
    void lerArquivo(string &nomeArquivo, Matriz& _matriz);
    void escreverArquivo( string &nomeArquivo);
};

#endif