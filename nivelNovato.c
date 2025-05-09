#include <stdio.h>

// Definindo as constantes usando #define.

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {

    // Declarando o tabuleiro

    int Tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Iniciando Jogo...

    printf("###=== BEM-VINDO AO DESAFIO DE BATALHA NAVAL !!! ===###\n\n");
    printf("- Você está prestes a posicionar dois navios no tabuleiro com escala de 10x10.\n\n");
    printf("- Um navio será posicionado na Horizontal e o outro navio será posicionado na Vertical.\n\n");
    printf("- Cada navio ocupa 3 posições.\n\n");
    printf("- VAMOS COMEÇAR, E QUE VENÇA O MELHOR JOGADOR!!! ;)\n\n");

    // Inicializando o Tabuleiro.

    printf("- Inicializando o tabuleiro com água (0)...\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            Tabuleiro[linha][coluna] = 0;
        }
    }

    printf("- Tabuleiro inicializado com sucesso!\n");

    // Declarando os navios como vetores.

    int Navio_Horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int Navio_Vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Definindo as coordenadas iniciais dos navios.

    int Linha_Horizontal = 2;
    int Coluna_Horizontal = 4;
    int Linha_Vertical = 5;
    int Coluna_Vertical = 6;

    // Posicionar o navio Horizontal.

    printf("- Posicionando o Navio Horizontal (Tamanho 3)...\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n", Linha_Horizontal, Coluna_Horizontal);

    if (Coluna_Horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Horizontal][Coluna_Horizontal + i] = Navio_Horizontal[i];
        }
        printf("- Navio Horizontal posicionado com sucesso!\n");
    } else {
        printf("- Erro! Navio Horizontal não cabe na coordenada escolhida.\n");
        return 1;
    }

    // Posicionar o navio Vertical.

    printf("- Posicionando o Navio Vertical (Tamanho 3)...\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n", Linha_Vertical, Coluna_Vertical);

    if (Linha_Vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (Tabuleiro[Linha_Vertical + i][Coluna_Vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("- Erro! Sobreposição de navios detectada. O Navio Vertical não pode ser posicionado.\n");
            return 1;
        } else {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                Tabuleiro[Linha_Vertical + i][Coluna_Vertical] = Navio_Vertical[i];
            }
            printf("- Navio Vertical posicionado com sucesso!\n");
        }
    } else {
        printf("- Erro! Navio Vertical não cabe na coordenada escolhida.\n");
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
