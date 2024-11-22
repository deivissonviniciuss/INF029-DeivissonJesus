//QUESTÃO 7 - OPCIONAL - JOGO DA VELHA
#include <stdio.h>

#define JOGADOR_X 1
#define JOGADOR_O 2
#define VAZIO 0

int verificarVitoria(int tabuleiro[3][3], int jogador) {
    int i, j;

    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
    }

    for (j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return 1;
        }
    }

    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }

    return 0;
}

void exibirTabuleiro(int tabuleiro[3][3]) {
    char simbolos[] = {' ', 'X', 'O'};
    int i, j;

    printf("   1   2   3\n");
    for (i = 0; i < 3; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < 3; j++) {
            printf(" %c ", simbolos[tabuleiro[i][j]]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n  ---+---+---\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[3][3] = {{VAZIO, VAZIO, VAZIO}, {VAZIO, VAZIO, VAZIO}, {VAZIO, VAZIO, VAZIO}};
    char linha;
    int coluna, jogadorAtual = JOGADOR_X, rodadas = 0;
    int linhaIndice, jogadaValida;

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (1) {
        exibirTabuleiro(tabuleiro);

        if (verificarVitoria(tabuleiro, JOGADOR_X)) {
            printf("Jogador 1 (X) venceu!\n");
            break;
        } else if (verificarVitoria(tabuleiro, JOGADOR_O)) {
            printf("Jogador 2 (O) venceu!\n");
            break;
        } else if (rodadas == 9) {
            printf("Empate!\n");
            break;
        }

        do {
            if (jogadorAtual == JOGADOR_X)
                printf("Jogador %d (X), escolha sua jogada (ex: A1): ", jogadorAtual);
            else
                printf("Jogador %d (O), escolha sua jogada (ex: A1): ", jogadorAtual);
            
            scanf(" %c%d", &linha, &coluna);

            linhaIndice = linha - 'A';
            coluna--;

            jogadaValida = (linhaIndice >= 0 && linhaIndice < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linhaIndice][coluna] == VAZIO);

            if (!jogadaValida) {
                printf("Jogada inválida. Tente novamente.\n");
            }
        } while (!jogadaValida);

        tabuleiro[linhaIndice][coluna] = jogadorAtual;
        
        if (jogadorAtual == JOGADOR_X)
            jogadorAtual = JOGADOR_O;
        else 
            jogadorAtual = JOGADOR_X;
            
        rodadas++;
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}
