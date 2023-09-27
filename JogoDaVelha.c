#include <stdio.h>

char tabuleiro[3][3];  // Tabuleiro 3x3

// Função para inicializar o tabuleiro
void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Função para verificar se o jogo terminou
int verificarFimDeJogo() {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ')
            return 1;
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;

    // Verificar empate
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0; // Ainda há espaços em branco, o jogo não terminou
        }
    }

    return -1; // Empate
}

int main() {
    int jogador = 1; // 1 para o jogador 1, 2 para o jogador 2
    int linha, coluna;
    int resultado = 0; // 0 para jogo em andamento, 1 para vitória do jogador 1, 2 para vitória do jogador 2, -1 para empate

    inicializarTabuleiro();

    printf("Jogo da Velha\n");
    printf("Jogador 1: X, Jogador 2: O\n");

    do {
        imprimirTabuleiro();
        printf("Jogador %d, insira a linha e a coluna (0-2) separadas por espaço: ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Movimento inválido. Tente novamente.\n");
            continue;
        }

        if (jogador == 1) {
            tabuleiro[linha][coluna] = 'X';
            jogador = 2;
        } else {
            tabuleiro[linha][coluna] = 'O';
            jogador = 1;
        }

        resultado = verificarFimDeJogo();
    } while (resultado == 0);

    imprimirTabuleiro();

    if (resultado == 1) {
        printf("Jogador 1 (X) venceu!\n");
    } else if (resultado == 2) {
        printf("Jogador 2 (O) venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}