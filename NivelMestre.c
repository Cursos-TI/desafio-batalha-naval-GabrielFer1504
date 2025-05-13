#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho fixo 5x5 para habilidades

// Função para sobrepor matriz de habilidade ao tabuleiro.

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tabuleiro = origem_linha - offset + i;
            int coluna_tabuleiro = origem_coluna - offset + j;

            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1 && tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 0) {
                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
            }
        }
    }
}

int main() {
    int Tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    printf("###=== BEM-VINDO AO DESAFIO DE BATALHA NAVAL !!! ===###\n\n");
    printf("- Você está prestes a posicionar dois navios no tabuleiro com escala de 10x10.\n\n");
    printf("- Um navio será posicionado na Horizontal e o outro navio será posicionado na Vertical.\n\n");
    printf("- Cada navio ocupa 3 posições.\n\n");
    printf("- VAMOS COMEÇAR, E QUE VENÇA O MELHOR JOGADOR!!! ;)\n\n");

    printf("- Inicializando o tabuleiro com água (0)...\n\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            Tabuleiro[linha][coluna] = 0;
        }
    }

    printf("- Tabuleiro inicializado com sucesso!\n\n");

    int Navio_Horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int Navio_Vertical[TAMANHO_NAVIO] = {3, 3, 3};

    int Linha_Horizontal = 2;
    int Coluna_Horizontal = 4;
    int Linha_Vertical = 5;
    int Coluna_Vertical = 6;

    printf("- Posicionando o Navio Horizontal (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Horizontal, Coluna_Horizontal);

    if (Coluna_Horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            Tabuleiro[Linha_Horizontal][Coluna_Horizontal + i] = Navio_Horizontal[i];
        }
        printf("- Navio Horizontal posicionado com sucesso!\n\n");
    } else {
        printf("- Erro! Navio Horizontal não cabe na coordenada escolhida.\n");
        return 1;
    }

    printf("- Posicionando o Navio Vertical (Tamanho 3)...\n\n");
    printf("- Coordenadas escolhidas: Linha %d, Coluna %d\n\n", Linha_Vertical, Coluna_Vertical);

    if (Linha_Vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (Tabuleiro[Linha_Vertical + i][Coluna_Vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("- Erro! Sobreposição de navios detectada. O Navio Vertical não pode ser posicionado.\n\n");
            return 1;
        } else {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                Tabuleiro[Linha_Vertical + i][Coluna_Vertical] = Navio_Vertical[i];
            }
            printf("- Navio Vertical posicionado com sucesso!\n\n");
        }
    } else {
        printf("- Erro! Navio Vertical não cabe na coordenada escolhida.\n\n");
        return 1;
    }

    // Matriz para habilidade.

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    int centro = TAMANHO_HABILIDADE / 2;

    // Cone: base se expande para baixo.

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(j - centro) <= i) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz: linha e coluna centrais.

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (losango).

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicando as Habilidades.

    int origem_cone_linha = 1, origem_cone_coluna = 2;
    int origem_cruz_linha = 6, origem_cruz_coluna = 3;
    int origem_octaedro_linha = 4, origem_octaedro_coluna = 7;

    aplicarHabilidade(Tabuleiro, cone, origem_cone_linha, origem_cone_coluna);
    aplicarHabilidade(Tabuleiro, cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicarHabilidade(Tabuleiro, octaedro, origem_octaedro_linha, origem_octaedro_coluna);

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
            int valor = Tabuleiro[linha][coluna];
            if (valor == 0) {
                printf(" . ");
            } else if (valor == 3) {
                printf(" N ");
            } else if (valor == 5) {
                printf(" * ");
            } else {
                printf("%2d ", valor);
            }
        }
        printf("\n");
    }

    return 0;
}
