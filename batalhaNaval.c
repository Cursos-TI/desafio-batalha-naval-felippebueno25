#include <stdio.h>

#define LINHA 10
#define COLUNA 10

void imprimeMatriz(int matriz[LINHA][COLUNA]){
    int i, j;
    printf("-=-=-=-=-=-=-=-=-=-=-=-\n     Batalha Naval\n-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" X  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ", i + 1);
        for (j = 0; j < 10; j++){
            if (matriz[i][j] == 0)
                printf("0 ");
            else
                printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void imprimeMatrizWaves(int matriz[LINHA][COLUNA]){
    int i, j;
    printf("-=-=-=-=-=-=-=-=-=-=-=-\n     Batalha Naval\n-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" X  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ", i + 1);
        for (j = 0; j < 10; j++){
            if (matriz[i][j] == 0)
                printf("~ ");
            else
                printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void navioVertical(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    if (linha <= 7 && coluna <= 9) { // Verifica se o navio cabe na vertical
        for (i = 0; i < 3; i++){
            if (matriz[linha + i][coluna] != 0) {
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            matriz[linha + i][coluna] = 2;
        }
    } else {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna);
    }
}

void navioHorizontal(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    if (linha <= 9 && coluna <= 7) { // Verifica se o navio cabe na horizontal
        for (i = 0; i < 3; i++){
            if (matriz[linha][coluna + i] != 0) {
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha, coluna + i);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            matriz[linha][coluna + i] = 1;
        }
    } else {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna);
    }
}

void navioDiagonal(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    if (linha <= 7 && coluna <= 7) {  // Verifica se o navio cabe na diagonal
        for (i = 0; i < 3; i++){
            if (matriz[linha + i][coluna + i] != 0) {
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna + i);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            matriz[linha + i][coluna + i] = 3;
        }
    } else {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna);
    }
}

int main() {
    int matriz[LINHA][COLUNA];
    int i, j;
    // Inicializa matriz com 0 (vazio)
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            matriz[i][j] = 0;
        }
    }

    // Imprime matriz zerada
    imprimeMatriz(matriz);
    printf("\n");
    
    // Posiciona Navio 1 - horizontal
    navioHorizontal(2, 3, matriz);
    
    // Posiciona Navio 2  - vertical
    navioVertical(4, 7, matriz);

    // Posiciona Navio 3 - diagonal
    navioDiagonal(7, 2, matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatriz(matriz);
    // Com ondinhas fica legal ein :P
    // imprimeMatrizWaves(matriz);

    return 0;
}
