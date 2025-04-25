Introdução
Este trabalho foi proposto na disciplina de Algoritmos e Estruturas de Dados I (AEDSI), ministrada pelo professor Michel Pires da Silva.

Basicamente, o projeto consiste em desenvolver um simulador de propagação de incêndio e, simultaneamente, implementar a lógica de movimentação aleatória de um animal dentro da floresta.

O problema é modelado a partir de uma matriz de inteiros, composta por cinco valores que representam abstrações de elementos da vida real: 1 (árvore saudável), 2 (árvore em chamas), 3 (árvore queimada), 4 (água) e 0 (espaço vazio). Para a movimentação do animal, é criada uma matriz 3x3 que simula sua visão dentro da matriz principal da simulação. Essa submatriz recebe os valores da matriz original com base na posição x e y do animal.