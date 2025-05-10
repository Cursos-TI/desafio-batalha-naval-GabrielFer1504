#include <stdio.h>

// Definindo as constantes usando #define.

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se a posição é válida para o navio.

int verificarPosicao(int linha, int coluna, int horizontal, int diagonal) {

    // Verifica se o navio horizontal ou vertical cabe no tabuleiro.

    if (horizontal) {
        if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            return 1;
        }
    }

    // Para navios verticais.

    if (!horizontal && !diagonal) {
        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            return 1;
        }
    }

    // Para navios diagonais (crescendo).

    if (diagonal) {

        // Diagonal crescente (linha +, coluna +).

        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            return 1;
        }

        // Diagonal decrescente (linha +, coluna -).

        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna - (TAMANHO_NAVIO - 1) >= 0) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar a sobreposição dos navios.

int verificarSobreposicao(int linha, int coluna, int horizontal, int diagonal, int Tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    if (horizontal) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (Tabuleiro[linha][coluna + i] != 0) {
                return 1;
            }
        }
    }

    if (!horizontal) {
        if (!diagonal) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                if (Tabuleiro[linha + i][coluna] != 0) {
                    return 1;
                }
            }
        } else {

            // Verifica se é diagonal crescente ou decrescente com base nas coordenadas.

            if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {  
                
                // Diagonal crescente.
                
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    if (Tabuleiro[linha + i][coluna + i] != 0) {
                        return 1;
                    }
                }
            } else {  

                // Diagonal decrescente.

                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    if (Tabuleiro[linha + i][coluna - i] != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {

    // Declarando o tabuleiro.

    int Tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Iniciando Jogo...

    printf("###=== BEM-VINDO AO DESAFIO DE BATALHA NAVAL !!! ===###\n\n");
    printf("- Você está prestes a posicionar quatro navios no tabuleiro com escala de 10x10.\n\n");
    printf("- Dois navios serão posicionados na Horizontal ou Vertical.\n\n");
    printf("- Dois navios serão posicionados na Diagonal (crescente ou decrescente).\n\n");
    printf("- Cada navio ocupa 3 posições.\n\n");
    printf("- VAMOS COMEÇAR, E QUE VENÇA O MELHOR JOGADOR!!! ;)\n\n");

    // Inicializando o Tabuleiro.

    printf("- Inicializando o tabuleiro com água (0)...\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            Tabuleiro[linha][coluna] = 0;
        }
    }
    printf("- Tabuleiro inicializado com sucesso!\n\n");

    // Definindo as coordenadas iniciais dos navios.

    // Navios horizontais.

    int Linha_Horizontal = 2;
    int Coluna_Horizontal = 4;

    // Navios verticais.

    int Linha_Vertical = 5;
    int Coluna_Vertical = 6;

    // Navios diagonais (crescendo).

    int Linha_Diagonal_Crescente = 0;
    int Coluna_Diagonal_Crescente = 0;

    // Navios diagonais (decrescendo).

    int Linha_Diagonal_Decrescente = 0;
    int Coluna_Diagonal_Decrescente = 9;

    // Posicionando o Navio Horizontal.

    printf("- Posicionando o Navio Horizontal (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Horizontal, Coluna_Horizontal);

    if (verificarPosicao(Linha_Horizontal, Coluna_Horizontal, 1, 0) && !verificarSobreposicao(Linha_Horizontal, Coluna_Horizontal, 1, 0, Tabuleiro)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Horizontal][Coluna_Horizontal + i] = 3;
        }
        printf("- Navio Horizontal posicionado com sucesso!\n\n");
    } else {
        printf("- Erro! Navio Horizontal não cabe ou está sobrepondo.\n\n");
        return 1;
    }

    // Posicionando o Navio Vertical.

    printf("- Posicionando o Navio Vertical (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Vertical, Coluna_Vertical);

    if (verificarPosicao(Linha_Vertical, Coluna_Vertical, 0, 0) && !verificarSobreposicao(Linha_Vertical, Coluna_Vertical, 0, 0, Tabuleiro)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Vertical + i][Coluna_Vertical] = 3;
        }
        printf("- Navio Vertical posicionado com sucesso!\n\n");
    } else {
        printf("- Erro! Navio Vertical não cabe ou está sobrepondo.\n\n");
        return 1;
    }

    // Posicionando o Navio Diagonal Crescente.

    printf("- Posicionando o Navio Diagonal Crescente (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Diagonal_Crescente, Coluna_Diagonal_Crescente);

    if (verificarPosicao(Linha_Diagonal_Crescente, Coluna_Diagonal_Crescente, 0, 1) && !verificarSobreposicao(Linha_Diagonal_Crescente, Coluna_Diagonal_Crescente, 0, 1, Tabuleiro)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Diagonal_Crescente + i][Coluna_Diagonal_Crescente + i] = 3;
        }
        printf("- Navio Diagonal Crescente posicionado com sucesso!\n\n");
    } else {
        printf("- Erro! Navio Diagonal Crescente não cabe ou está sobrepondo.\n\n");
        return 1;
    }

    // Posicionando o Navio Diagonal Decrescente.

    printf("- Posicionando o Navio Diagonal Decrescente (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Diagonal_Decrescente, Coluna_Diagonal_Decrescente);

    if (verificarPosicao(Linha_Diagonal_Decrescente, Coluna_Diagonal_Decrescente, 0, 1) && !verificarSobreposicao(Linha_Diagonal_Decrescente, Coluna_Diagonal_Decrescente, 0, 1, Tabuleiro)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Diagonal_Decrescente + i][Coluna_Diagonal_Decrescente - i] = 3;
        }
        printf("- Navio Diagonal Decrescente posicionado com sucesso!\n\n");
    } else {
        printf("- Erro! Navio Diagonal Decrescente não cabe ou está sobrepondo.\n\n");
        return 1;
    }

    // Exibindo o Tabuleiro.

    printf("- Exibindo o tabuleiro com os navios posicionados:\n\n");
    printf("   ");
    for (int c = 0; c < TAMANHO_TABULEIRO; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha);
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%2d ", Tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}