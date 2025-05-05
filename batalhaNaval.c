#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[][10], int tamanho) {
    printf("  ");
    for (int j = 0; j < tamanho; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", i);
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    printf("--- Nível Novato ---\n");
    int tabuleiroNovato[5][5] = {0};

    // Posicionando um navio verticalmente (tamanho 3)
    tabuleiroNovato[1][2] = 3;
    tabuleiroNovato[2][2] = 3;
    tabuleiroNovato[3][2] = 3;
    printf("Navio vertical posicionado em (1,2), (2,2), (3,2)\n");

    // Posicionando um navio horizontalmente (tamanho 2)
    tabuleiroNovato[0][0] = 3;
    tabuleiroNovato[0][1] = 3;
    printf("Navio horizontal posicionado em (0,0), (0,1)\n\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    printf("--- Nível Aventureiro ---\n");
    int tabuleiroAventureiro[10][10] = {0};

    // Posicionando navios
    // Navio horizontal (tamanho 4)
    tabuleiroAventureiro[2][1] = 3;
    tabuleiroAventureiro[2][2] = 3;
    tabuleiroAventureiro[2][3] = 3;
    tabuleiroAventureiro[2][4] = 3;

    // Navio vertical (tamanho 3)
    tabuleiroAventureiro[6][7] = 3;
    tabuleiroAventureiro[7][7] = 3;
    tabuleiroAventureiro[8][7] = 3;

    // Navio diagonal (tamanho 2 - sudoeste para nordeste)
    tabuleiroAventureiro[1][5] = 3;
    tabuleiroAventureiro[2][6] = 3;

    // Navio diagonal (tamanho 2 - noroeste para sudeste)
    tabuleiroAventureiro[7][1] = 3;
    tabuleiroAventureiro[8][2] = 3;

    printf("Tabuleiro 10x10 com navios posicionados:\n");
    exibirTabuleiro(tabuleiroAventureiro, 10);

    // Nível Mestre - Habilidades Especiais com Matrizes
    printf("--- Nível Mestre ---\n");
    int tabuleiroHabilidades[10][10] = {0};
    int linhaCentral = 4;
    int colunaCentral = 4;

    printf("Habilidade em Cone (centro em %d,%d):\n", linhaCentral, colunaCentral);
    for (int i = 0; i < 5; i++) {
        for (int j = colunaCentral - i; j <= colunaCentral + i; j++) {
            if (i + linhaCentral < 10 && j >= 0 && j < 10) {
                tabuleiroHabilidades[i + linhaCentral][j] = 1;
            }
        }
    }
    exibirTabuleiro(tabuleiroHabilidades, 10);

    // Resetando o tabuleiro para a próxima habilidade
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiroHabilidades[i][j] = 0;
        }
    }

    printf("Habilidade em Octaedro (centro em %d,%d):\n", linhaCentral, colunaCentral);
    for (int i = 0; i < 5; i++) {
        for (int j = colunaCentral - (2 - abs(i - 2)); j <= colunaCentral + (2 - abs(i - 2)); j++) {
            if (linhaCentral - 2 + i >= 0 && linhaCentral - 2 + i < 10 && j >= 0 && j < 10) {
                tabuleiroHabilidades[linhaCentral - 2 + i][j] = 1;
            }
        }
    }
    exibirTabuleiro(tabuleiroHabilidades, 10);

    // Resetando o tabuleiro para a próxima habilidade
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiroHabilidades[i][j] = 0;
        }
    }

    printf("Habilidade em Cruz (centro em %d,%d):\n", linhaCentral, colunaCentral);
    for (int i = 0; i < 10; i++) {
        tabuleiroHabilidades[linhaCentral][i] = 1; // Linha central
        tabuleiroHabilidades[i][colunaCentral] = 1; // Coluna central
    }
    tabuleiroHabilidades[linhaCentral][colunaCentral] = 1; // Garante que o centro seja 1
    exibirTabuleiro(tabuleiroHabilidades, 10);

    return 0;
}