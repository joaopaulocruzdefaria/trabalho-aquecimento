#include "animal.hpp"

Animal::Animal(Matriz &_matriz) : matrizRef(_matriz) {
    matrizTemp.assign(TAM_TEMP, vector<short int>(TAM_TEMP, -1));
    srand(time(nullptr));
}

int Animal::getPassos() const { return passos; }
bool Animal::isVivo() const { return vida; }
const vector<Pos>& Animal::getCaminho() const { return caminho; }
Pos Animal::getPosicao() const { return animalPos; }

void Animal::randomizarPosAnimal() {
    vector<Pos> possiveis;
    for (int i = 0; i < matrizRef.getLinhas(); i++) {
        for (int j = 0; j < matrizRef.getColunas(); j++) {
            if (matrizRef.getItem(i, j) == 0)
                possiveis.emplace_back(Pos{i, j});
        }
    }
    animalPos = possiveis[rand() % possiveis.size()];
    vida = true;
    passos = 0;
    tempoSeguro = 0;

    caminho.clear();
    caminho.push_back(animalPos);

    cout << "Posicao inicial do animal: (" << animalPos.x
         << ", " << animalPos.y << ")" << endl;
}

void Animal::mover() {
    // 1) Descanso em célula vazia (0)
    short int valorAtual = matrizRef.getItem(animalPos.x, animalPos.y);
    if (valorAtual == 0 && tempoSeguro < 3) {
        tempoSeguro++;
        cout << "Animal permaneceu na posicao vazia. Tempo parado: "
             << tempoSeguro << endl;
        return;
    }
    tempoSeguro = 0;

    // 2) Movimento normal por prioridade ortogonal
    static const int direcoes[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int prioridade[4] = {4,0,1,3};

    for (int p = 0; p < 4; p++) {
        int desejado = prioridade[p];
        vector<pair<int,int>> opcoes;
        for (int d = 0; d < 4; d++) {
            int dx = direcoes[d][0], dy = direcoes[d][1];
            int i = 1 + dx, j = 1 + dy;
            if (i>=0 && i<TAM_TEMP && j>=0 && j<TAM_TEMP &&
                matrizTemp[i][j] == desejado) {
                opcoes.emplace_back(dx, dy);
            }
        }
        if (!opcoes.empty()) {
            auto esc = opcoes[rand() % opcoes.size()];
            animalPos.x += esc.first;
            animalPos.y += esc.second;
            passos++;
            caminho.push_back(animalPos);
            cout << "Animal se moveu para (" << animalPos.x
                 << ", " << animalPos.y << ")" << endl;
            return;
        }
    }

    // 3) Sem opções → fica parado
    cout << "Animal não se moveu." << endl;
}

void Animal::iterarMatrizFogo() {
    // Atualiza visão local 3x3
    matrizTemp.assign(TAM_TEMP, vector<short int>(TAM_TEMP, -1));
    for (int di=-1; di<=1; di++) for (int dj=-1; dj<=1; dj++) {
        int ni=animalPos.x+di, nj=animalPos.y+dj;
        if (ni>=0&&ni<matrizRef.getLinhas()&&nj>=0&&nj<matrizRef.getColunas())
            matrizTemp[di+1][dj+1] = matrizRef.getItem(ni,nj);
    }
    matrizTemp[1][1]=7;

    // Segunda chance se fogo
    if (matrizRef.getItem(animalPos.x, animalPos.y)==2) {
        int cont=0;
        for (int d=0; d<4; d++) {
            int mi=1+dx[d], mj=1+dy[d];
            if (matrizTemp[mi][mj]==-1 || matrizTemp[mi][mj]==2) cont++;
        }
        if (cont==4) { vida=false; cout<<"Animal morreu queimado!"<<endl; return; }
        cout<<"O animal recebeu uma Segunda chance..."<<endl;
        mover();
        // reatualiza visão pós-fuga
        matrizTemp.assign(TAM_TEMP, vector<short int>(TAM_TEMP, -1));
        for (int di=-1; di<=1; di++) for (int dj=-1; dj<=1; dj++) {
            int ni=animalPos.x+di, nj=animalPos.y+dj;
            if (ni>=0&&ni<matrizRef.getLinhas()&&nj>=0&&nj<matrizRef.getColunas())
                matrizTemp[di+1][dj+1] = matrizRef.getItem(ni,nj);
        }
        matrizTemp[1][1]=7;
        return;
    }

    // Exibe visão
    cout<<"Matriz visão do animal:"<<endl;
    printarMatrizTemp();
}
