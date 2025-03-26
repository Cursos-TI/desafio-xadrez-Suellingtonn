#include <stdio.h>

// Função recursiva para movimentação da Torre
void movimento_torre(int x, int y, int x_destino, int y_destino) {
    // Caso base: se atingirmos o destino, paramos a recursão
    if (x == x_destino && y == y_destino) {
        return;
    }

    // Movimentação na direção vertical (cima ou baixo)
    if (x < x_destino) {
        printf("Baixo\n");
        movimento_torre(x + 1, y, x_destino, y_destino);
    } else if (x > x_destino) {
        printf("Cima\n");
        movimento_torre(x - 1, y, x_destino, y_destino);
    }
    // Movimentação na direção horizontal (esquerda ou direita)
    else if (y < y_destino) {
        printf("Direita\n");
        movimento_torre(x, y + 1, x_destino, y_destino);
    } else if (y > y_destino) {
        printf("Esquerda\n");
        movimento_torre(x, y - 1, x_destino, y_destino);
    }
}

// Função recursiva para movimentação do Bispo com loops aninhados
void movimento_bispo(int x, int y, int tamanho_tabuleiro, int i, int j) {
    // Caso base: se os índices estiverem fora do tabuleiro, paramos
    if (i < 0 || j < 0 || i >= tamanho_tabuleiro || j >= tamanho_tabuleiro) {
        return;
    }

    // Exibindo o movimento do bispo
    if (i != x || j != y) {
        if (i > x && j > y) {
            printf("Baixo\n");
        } else if (i < x && j < y) {
            printf("Cima\n");
        } else if (i > x && j < y) {
            printf("Direita\n");
        } else if (i < x && j > y) {
            printf("Esquerda\n");
        }
    }

    // Movendo-se recursivamente para os próximos valores
    movimento_bispo(x, y, tamanho_tabuleiro, i + 1, j + 1);  // Diagonal inferior direita
    movimento_bispo(x, y, tamanho_tabuleiro, i - 1, j - 1);  // Diagonal superior esquerda
    movimento_bispo(x, y, tamanho_tabuleiro, i + 1, j - 1);  // Diagonal inferior esquerda
    movimento_bispo(x, y, tamanho_tabuleiro, i - 1, j + 1);  // Diagonal superior direita
}

// Função recursiva para movimentação da Rainha (combinação de Torre e Bispo)
void movimento_rainha(int x, int y, int x_destino, int y_destino) {
    movimento_torre(x, y, x_destino, y_destino);  // Primeiro a Torre (horizontal/vertical)
    movimento_bispo(x, y, 8, x, y);  // Depois o Bispo (diagonal)
}

// Função com loops aninhados para movimentação do Cavalo em "L" (duas casas para cima e uma para a direita)
void movimento_cavalo(int x, int y, int tamanho_tabuleiro) {
    int movimentos[8][2] = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};
    
    for (int i = 0; i < 8; i++) {
        int nova_x = x + movimentos[i][0];
        int nova_y = y + movimentos[i][1];

        // Verifica se o movimento é dentro dos limites do tabuleiro
        if (nova_x >= 0 && nova_x < tamanho_tabuleiro && nova_y >= 0 && nova_y < tamanho_tabuleiro) {
            if (movimentos[i][0] == -2 && movimentos[i][1] == 1) {
                printf("Cima\n");
                continue;
            }
            if (movimentos[i][0] == 2 && movimentos[i][1] == 1) {
                printf("Baixo\n");
                continue;
            }
            printf("Direita\n");
        }
    }
}

int main() {
    int tamanho_tabuleiro = 8;
    int x = 3, y = 3;  // Posição inicial para todas as peças
    
    // Movimentação do Bispo
    printf("\nMovimentação do Bispo (recursiva e aninhada):\n");
    movimento_bispo(x, y, tamanho_tabuleiro, x, y);
    printf("\n");

    // Movimentação da Torre
    printf("\nMovimentação da Torre (recursiva):\n");
    movimento_torre(x, y, 7, 7);  // Para destino (7, 7) como exemplo
    printf("\n");

    // Movimentação da Rainha
    printf("\nMovimentação da Rainha (recursiva):\n");
    movimento_rainha(x, y, 7, 7);  // Para destino (7, 7) como exemplo
    printf("\n");

    // Movimentação do Cavalo
    printf("\nMovimentação do Cavalo (com loops aninhados):\n");
    movimento_cavalo(x, y, tamanho_tabuleiro);
    printf("\n");

    return 0;
}
