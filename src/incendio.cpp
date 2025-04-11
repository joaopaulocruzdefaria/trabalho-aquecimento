#include "../include/incendio.hpp"
#include "../include/matriz.hpp"
#include "../include/global.hpp"

Incendio::Incendio(Matriz &_matriz)  :  
            matrizRef(_matriz),
            matrizTemp(_matriz.getMatriz()),
            linhasTemp(_matriz.getLinhas()),
            colunasTemp(_matriz.getColunas()) {}


bool Incendio::PodePegarFogo(short int x, short int y){
    if (matrizRef.getMatriz()[x][y] == nullptr)
    {
        return false;  
    } else
    
    if (x < 0 || x >= linhasTemp || y < 0 || y >= colunasTemp)
    {
        cerr << "Posição fora dos limites da matriz." << endl;
        return false;
    } else if (*matrizRef.getMatriz()[x][y] == 1) {
        if ((x + 1 < linhasTemp && *matrizRef.getMatriz()[x + 1][y] == 2) ||
            (x - 1 >= 0 && *matrizRef.getMatriz()[x - 1][y] == 2) ||
            (y + 1 < colunasTemp && *matrizRef.getMatriz()[x][y + 1] == 2) ||
            (y - 1 >= 0 && *matrizRef.getMatriz()[x][y - 1] == 2)) {
            return true;
        }
    }return false;
}

void Incendio::printarMatrizTemp()
{
    matrizRef.printarMatriz();
    cout << endl;
}


void Incendio::IterarFogo(){

    printarMatrizTemp();
    cout << endl;

    for (short int i = 0; i < linhasTemp; i++)
    {
        for (short int j = 0; j < colunasTemp; j++)
        {
            if(PodePegarFogo(i,j)){
                matrizTemp[i][j] = new short int(2); // pega fogo
            }
                     
        }
        
    }
    cout << endl;
    
    
    matrizRef.setMatriz(matrizTemp);
    cout << "Turno: " << turno << endl;
    turno++;

    printarMatrizTemp();
    

}