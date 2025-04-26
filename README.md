<h1 align='center'> Simulação de Propagação de Incéndio
</h1>


<div align='center'>

[![IDE][vscode-badge]][vscode-url]
[![Make][make-badge]][make-url]
[![Linguagem][cpp-badge]][cpp-url]

Algoritmos e Estruturas de Dados I

</div>

<details>
  <summary>
    <b style='font-size: 15px'>📑 Sumário</b>
  </summary>
  <ol>
    <li><a href="#introdução">🔍 Introdução</a></li>
    <li>
      <a href="#metodologia">⚙️ Metodologia</a>
      <ul>
        <li><a href="#arquivos-do-projeto">📂 Arquivos do Projeto</a></li>
        <li>
          <a href="#detalhes-de-implementação">🚀 Detalhes de Implementação</a>
          <ul>
            <li><a href="#1-leitura-inicial-do-arquivo">1️⃣ Leitura inicial do Arquivo</a></li>
            <li><a href="#1.1-inicialização-das-classes-incêndio-e-animal">1.1️⃣ Inicialização das classes Incêndio e Animal</a></li>
            <li><a href="#1.2-inicialização-do-incêndio">1.2️⃣ Inicialização do Incêndio</a></li>
            <li><a href="#2-iteracao-inicial-do-animal">2️⃣ Iteração inicial do Animal</a></li>
            <li><a href="#3-loop-de-execução">3️⃣ Loop de Execução</a></li>
            <li><a href="#3.1-ordem-das-funções">3.1️⃣ Ordem das Funções</a></li>
            <li><a href="#4-escrita-no-final-do-arquivo">4️⃣ Escrita no Final do Arquivo</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li>
      <a href="#testes">🧪 Testes</a>
      <ul>
        <li><a href="#exemplo-de-inputdat">📝 Exemplo de `input.dat`</a></li>
        <li><a href="#exemplo-de-propagação-normal">🔥 Exemplo de Propagação Normal</a></li>
        <li><a href="#exemplo-de-propagação-com-vento">💨 Exemplo de Propagação com Vento</a>[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp
        <li>
          <a href="#possíveis-melhorias-no-algoritmo">🔧 Possíveis Melhorias no Algoritmo</a>
          <ul>
            <li><a href="#1-implementar-uma-fuga-para-o-animal">🐾 1. Implementar uma Fuga para o Animal</a></li>
            <li><a href="#2-uso-da-busca-em-largura-bfs">📈 2. Uso da Busca em Largura (BFS)</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li><a href="#conclusão">📚 Conclusão</a></li>
    <li><a href="#referências">🔗 Referências</a></li>
    <li>
      <a href="#método-de-compilação">🛠 Método de Compilação</a>
      <ul>
        <li><a href="#como-compilar">⚙️ Como Compilar</a></li>
      </ul>
    </li>
    <li><a href="#contato">📞 Contato</a></li>
  </ol>
</details>
</br>

# 📘 Introdução #

Este trabalho foi proposto na disciplina de Algoritmos e Estruturas de Dados I (AEDSI), ministrada pelo professor Michel Pires da Silva.

Basicamente, o projeto consiste em desenvolver um simulador de propagação de incêndio e, simultaneamente, implementar a lógica de movimentação aleatória de um animal dentro da floresta.

O problema é modelado a partir de uma matriz de inteiros composta por cinco valores, que representam abstrações de elementos da vida real: 1 (árvore saudável), 2 (árvore em chamas), 3 (árvore queimada), 4 (água) e 0 (espaço vazio). Para a movimentação do animal, é criada uma matriz 3x3 que simula sua visão dentro da matriz principal da simulação. Essa submatriz recebe os valores da matriz original com base nas coordenadas x e y da posição atual do animal.

# ⚙️ Metodologia #

Para a solução proposta os seguintes diretórios/arquivos foram utilizados: 

### Arquivos do Projeto

- [`src/animal.cpp`](src/animal.cpp) : Classe que tipifica o animal e contém toda a lógica de movimentação do animal.

- [`include/global.hpp`](include/global.hpp) : Arquivo que contém todas os define's de valores globais, como o vetor de direções e um valor K de interações.

- [`src/incendio.cpp`](src/incendio.cpp) : Classe responsável por montar toda a lógica de propagação de incendio.

- [`src/leitorDeArquivo.cpp`](src/leitorDeArquivo.cpp) : Classe responsável somente por ler a matriz, os limites dela e o inicio do fogo, e registrar nos objetos matriz e incendio.

- [`src/matriz.cpp`](src/matriz.cpp) : Classe responsável por tipificar a matriz, e excluir a necessidade de implementar métodos iguais em classes diferentes.

- [`src/simulacao.cpp`](src/simulacao.cpp) : Classe responsável pela lógica da ordem de acontecimentos (Ordem em que o animal anda, e o fogo se espalha), além conter o loop das interações.

- [`src/main.cpp`](src/main.cpp) :  Arquivo em que se encontra a função `main()` que executa comandos cruciais do programa.

- [`input.dat`](input.dat) : Arquivo que o programa extrai as informações para montar a matriz.
- [`output.dat`](output.dat) : Arquivo resultante da simulação.

- [`Makefile`](Makefile) : Arquivo com os comandos para a compilação e execução do programa.

### Funções

Abaixo estão as funções essenciais para o funcionamento do programa. Com a finalidade de simplificar a escrita, os parâmetros de cada uma delas foram ocultados.

  - `int main()`: função principal do programa que cria variáveis e faz chamadas de funções importantes para o programa;
  - `void randomizarPosAnimal()`: função busca dentro da matriz lida todas as posições vazias (Representadas por '0'), e randomiza uma delas, com base no horário do computador, para que o animal inicialize;
  - `void mover()`: função que contém toda a lógica de movimentação do animal, e insere as movimentações e posições visitadas pelo animal dentro do arquivo de saída.;
  - `void iterarMatrizFogo()`: função responsável por atualizar a visão local do animal (Matriz 3x3 do animal), e conferir se o fogo atingiu a posição atual do animal, caso tenha ocorrido ele verifica se tem alguma casa que o animal possa fugir (Se não tiver nenhuma casa, o animal é constatado morto);
  - `void iniciarIncendio()`: função que inicializa o incendio apartir da posição passada no arquivo input.dat;
  - `void PodePegarFogo()`: função que verifica se a posição passada é uma arvore saudável e se tem alguma árvore em chamas nas casas ortogonais;
  - `void iterarFogo()`: função responsável por fazer com que o fogo alastre durante 1 unica iteração, e por registrar isso dentro de um arquivo de saída;
  - `void mostraMatriz()`: função que mostra a matriz na tela;
  - `void lerArquivo()`: função que lê todos os dados do arquivo input.dat e  inicializa a matriz;
  - `void inicializarMatriz()`: Inicializa a matriz cheia de '0' e com o tamanho passado;
  - `void set()`: Todas as funções que o nome inicia com set insere valor à um atributo;
  - `void get()`: Todas as funções que o nome inicia com get extrai o valor de um atributo;

### Detalhes de Implementação ###
#### 1. Leitura inicial do Arquivo   

- No inicio do programa, o arquivo output.dat é limpo (em caso de execuções anteriores), depois o arquivo é lido e todas as informações extraidas são jogadas em uma classe matriz, que por sua vez é jogada dentro de um objeto incendio e um objeto animal (Ambos usam uma matriz de referência para fazer suas movimentações e alterações no objeto matriz original).

#### 1.1 Inicialização das classes Incendio e Animal

- Dentro das duas classes são inicializada as matrizes cópia da original, por meio de uma passam por referência.

- O resto dos atributos permanecem zerados ou nulos.

#### 1.2 Inicialização do incéndio

- O pega a posição inicial do incéndio, confere se é uma arvore saudavel e se for transforma ela em uma arvore em chamas.

- E logo em sequência, percorre a matriz lida e busca todas as posições que contém espaços vazios(0), onde ele encontra espaço vazio o programa joga a posicao desse espaço vazio dentro de um vetor de posições, e randomiza com base no horário do computador uma posição desse vetor onde o animal é inicializado.

#### 2. Iteração inicial do animal
- Antes do primeiro loop, o animal atualiza a visão dele, com base na posição em que foi randomizada anteriormente, basicamente copiando uma submatriz 3x3 da matriz original do incéndio.

#### 3. Loop de execução

- Aqui é onde ocorre toda a movimentação do animal, propagação do incendio e a contagem de iterações que ja aconteceram. O loop tem como condição de parada a morte do animal, não existir mais arvores a serem queimadas ou atingir o maximo K de iterações.

#### 3.1 Ordem das funções

- Aqui as funções são chamadas na seguinte ordem:

    [`animal.iterarMatrizFogo();`] </br>
    [`animal.mover();`]</br>
    [`incendio.IterarFogo();`]</br>
    [`numIteracoes++;`] </br>


#### 4. Escrita no final do arquivo

- Por fim o código pega as informações das variáveis que acompanham os passos do animal e o caminho percorrido por ele e insere elas dentro do arquivo de saída.




# 🧪 Testes

Para testar o programa:
1. Crie um arquivo chamado `input.dat`.
2. No início do arquivo, escreva:
   - As **dimensões da matriz** (largura e altura),
   - E a **posição inicial** do incêndio (linha e coluna),
   separados por espaços.
3. Em seguida, insira a **matriz**, usando apenas números de `0` a `4`, respeitando o tamanho definido.

## Exemplo de `input.dat`
| 5 | 5 | 0 | 0 |  | 
|---|---|---|---|---|
| 1 | 1 | 0 | 4 | 0 |
| 0 | 1 | 1 | 0 | 4 |
| 1 | 1 | 1 | 0 | 1 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 0 | 1 |

Nesse exemplo o fogo iniciaria na primeira célula da matriz.

## Exemplo de propagação normal

As iterações do incêndio são representadas abaixo:

<table align="center">
<tr>
<th>Início do Fogo</th>
<th>Iteração 1</th>
<th>Iteração 2</th>
<th>Iteração 3</th>
</tr>
<tr>

<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 2 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 2 | 1 | 1 | 4 |
| 2 | 3 | 2 | 1 | 1 |
| 1 | 2 | 1 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 2 | 3 | 2 | 1 | 4 |
| 3 | 3 | 3 | 2 | 1 |
| 2 | 3 | 2 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 3 | 3 | 3 | 2 | 4 |
| 3 | 3 | 3 | 3 | 2 |
| 3 | 3 | 3 | 2 | 4 |
| 0 | 0 | 2 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
</tr>
</table>

<table align="center">
<tr>
<th>Iteração 4</th>
<th>Iteração 5</th>
</tr>

<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 3 | 3 | 3 | 3 | 4 |
| 3 | 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 | 4 |
| 0 | 0 | 3 | 3 | 2 |
| 1 | 4 | 3 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 3 | 3 | 3 | 3 | 4 |
| 3 | 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 | 4 |
| 0 | 0 | 3 | 3 | 3 |
| 1 | 4 | 3 | 0 | 4 |

</td>

</table>

Neste caso, o fogo percorreu a matriz por 5 iterações ate queimar todas as árvores saudáveis possiveis.

Resultados finais do arquivo output.dat:

```
Resumo da simulação:
Caminho do animal (2 passos):
  - 0: (4, 3)
  - 1: (4, 4)
  - 2: (4, 3)
Total de passos: 2, O animal sobreviveu!
```
## Exemplo de propagação com vento
Propagação com o vento:



<table align="center">
<tr>
<th>Início do Fogo</th>
<th>Iteração 1</th>
<th>Iteração 2</th>
<th>Iteração 3</th>
</tr>
<tr>

<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 2 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 2 | 1 | 1 |
| 1 | 2 | 1 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 3 | 2 | 1 |
| 1 | 3 | 2 | 1 | 4 |
| 0 | 0 | 1 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 3 | 3 | 2 |
| 1 | 3 | 3 | 2 | 4 |
| 0 | 0 | 2 | 1 | 1 |
| 1 | 4 | 1 | 0 | 4 |

</td>
</tr>
</table>

<table align="center">
<tr>
<th>Iteração 4</th>
<th>Iteração 5</th>
<th>Iteração 6</th>
</tr>

<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 3 | 3 | 3 |
| 1 | 3 | 3 | 3 | 4 |
| 0 | 0 | 3 | 2 | 1 |
| 1 | 4 | 2 | 0 | 4 |

</td>
<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 3 | 3 | 3 |
| 1 | 3 | 3 | 3 | 4 |
| 0 | 0 | 3 | 3 | 2 |
| 1 | 4 | 3 | 0 | 4 |

</td>

<td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 | 4 |
| 1 | 3 | 3 | 3 | 3 |
| 1 | 3 | 3 | 3 | 4 |
| 0 | 0 | 3 | 3 | 3 |
| 1 | 4 | 3 | 0 | 4 |

</td>

</table>

Neste caso, o fogo percorreu a matriz por 6 iterações ate queimar todas as árvores saudáveis possiveis.

Resultados finais do arquivo output.dat:

```
Resumo da simulação:
Caminho do animal (2 passos):
  - 0: (4, 3)
  - 1: (4, 4)
  - 2: (4, 3)
Total de passos: 2, O animal sobreviveu!
```

# 💡 Considerações finais #

Levando em conta os conhecimentos adquiridos ao longo das aulas teóricas de AEDS I, cheguei a algumas conclusões:

  - Praticamente todas as funções em que percorro a matriz poderiam ser otimizadas, pois utilizam lógicas de custo n².

  - O código poderia ter sido estruturado de forma melhor, pois trabalhar usando uma classe matriz me causou vários problemas de segmentation fault, ao tentar acessar posições que não existiam na matriz.

  - E, por fim, e mais importante, as inteligências artificiais são ferramentas fenomenais, porém podem mais atrapalhar do que ajudar no processo de desenvolvimento de um algoritmo para solucionar um problema grande como esse, pois dificilmente entendem todo o contexto da solução e muito menos compreendem qual caminho você pretende seguir para resolver o problema.

## Possiveis Melhorias no algoritmo:

### 1. Implementar uma fuga para o animal
Inserir uma lógica onde o animal consegue perceber o fogo se proximando e busca fugir do fogo, pode ser um desafio interessante e tornaria o problema em algo mais realista.

### 2. Uso da Busca em Largura (BFS)
A implementação pode tornar a movimentação do animal mais eficiente na hora de encontrar àgua e evitar o fogo, encontrando caminhos seguros para se salvar.

# 📚 Conclusão #
Através do trabalho desenvolvido foi possível não só atingir o objetivo principal: utilizar os conceitos básicos de programação para concluir o problema proposto, mas também começar a pensar em formas mais eficientes de se construir algoritmos.
# 🔗 Referências #
**Busca em largura.** *Wikipédia, a enciclopédia livre*. Disponível em: <https://pt.wikipedia.org/wiki/Busca_em_largura>. Acesso em: 26 de abril de 2025.

**Brandão, Leônidas de Oliveira.** *Introdução ao conceito de eficiência de algoritmos*. Material didático do curso MAC2166: Introdução à Programação, IME-USP, 1º semestre de 2017. Disponível em: <https://www.ime.usp.br/~leo/mac2166/2017-1/line_introducao_eficiencia_algoritmos.html>. Acesso em: 26 de abril de 2025.



# 🛠 Método de compilação #

> [!IMPORTANTE] 
> Para que os testes tenham validade, considere as especificações técnicas do computador utilizado

O trabalho foi desenvolvido, compilado e executado em um ambiente com as seguintes especificações:

<div align='center'>

![Ubuntu][ubuntu-badge]
![Ryzen][ryzen-badge]


SO | CPU | RAM
--- | --- | ---
Ubuntu 22.04.4 LTS | Ryzen 5 3600 3.6GHz | 2x8GB 2666MHz

</div>


## Como compilar


Nesta seção estão exemplificados os meios através dos quais se tornam possíveis a compilação e execução do programa apresentado.

### Pré-requisitos

Inicialmente, algumas considerações importantes sobre como se deve preparar o ambiente para compilar e executar o programa:

> [!NOTE]
> Recomenda-se usar uma distribuição de sistema operacional Linux ou o Windows Subsystem for Linux (WSL), pois os comandos no [`makefile`] foram selecionados para funcionar em um ambiente [_shell/bash_].

Considerando um ambiente _shell_, garanta que os seguintes comandos já foram executados:
  - Atualize os pacotes antes da instalação dos compiladores:
  ```console
  sudo apt update
  ```
  - Instale a coleção de compiladores ___GNU/g++___ e o ___make___:
  ```console
  sudo apt install build-essential
  ```
  - Se necessário, instale o ___make___ individualmente:
  ```console
  sudo apt install make
  ```
  ### Instalando

Com o ambiente preparado, os seguintes passos são para a instalação, compilação e execução do programa localmente:

<!-- Ensinar a clonar a pasta do repositório -->
1. Clone a _branch_ [`trabalho-aquecimento`] o repositório no diretório desejado:
  ```console
  git clone -b JogoDaVida https://github.com/joaopaulocruzdefaria/trabalho-aquecimento
  ```
2. Compile o programa com o ___make___, o que gera a pasta `build`, que contém arquivos de objeto e um arquivo executável:
  ```console
  make
  ```
3. Execute o programa da pasta `build` após a compilação:
  ```console
  make run
  ```
4. Se necessário, apague a última compilação da pasta `build`:
  ```console
  make clean
  ```

O programa estará pronto para ser testado.


# 📞 Contato

<div align="center">
   <i>João Paulo Cruz de Faria - 3º Período de Engenharia de Computação @ CEFET-MG</i>
<br><br>

[![Gmail][gmail-badge]][gmail-autor]
[![Linkedin][linkedin-badge]][linkedin-autor]
[![Instagram][instagram-badge]][instagram-autor]
</div>

[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[ryzen-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_3600-ED1C24?style=for-the-badge&logo=amd&logoColor=white

[instagram-badge]: https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white

[instagram-autor]: https://www.instagram.com/joao_cruz_df/


[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[linkedin-autor]: https://www.linkedin.com/in/jo%C3%A3o-paulo-6a68711a3/
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white
[gmail-autor]: mailto:joaopaulocruzdefaria@gmail.com

[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp