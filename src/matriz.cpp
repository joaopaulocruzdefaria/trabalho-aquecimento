#include "../include/matriz.hpp"
#include "../include/global.hpp"

void Matriz::printarMatriz()
{
    for (const auto &linha : m)
    {
        for (const auto &ptr : linha)
        {
            if (ptr)
            {
                std::cout << *ptr << ' '; // imprime o valor apontado
            }
            else
            {
                std::cout << "null "; // só pra segurança, se o ponteiro for nulo
            }
        }
        std::cout << '\n';
    }
}

void Matriz::setMatriz(vector<vector<short int *>> outra)
{
    for (auto &linha : m)
    {
        for (auto &ptr : linha)
        {
            delete ptr;
        }
    }

    m.clear();
    m.resize(outra.size());

    for (size_t i = 0; i < outra.size(); ++i)
    {
        for (size_t j = 0; j < outra[i].size(); ++j)
        {
            m[i].push_back(new short int(*outra[i][j]));
        }
    }
}
