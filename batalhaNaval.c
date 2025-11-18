#include <stdio.h>
#include <stdlib.h>

#define LINHA 10
#define COLUNA 10
#define HABL 3
#define HABC 5
#define SEPARADOR "-=-=-=-=-=-=-=-=-=-=-=-="
int i, j;


void imprimeMatrizWaves(int matriz[i][j]){
    // Imprime o cabeçalho da matriz
    printf("%s\n     Batalha Naval      \n%s\n", SEPARADOR, SEPARADOR);
    printf(" 0  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        // Imprime número da linha
        printf("%2d  ", i + 1);
        // Imprime os elementos da linha
        for (j = 0; j < 10; j++){
            // Verifica se é água
            if (matriz[i][j] == 0)
                printf("~ ");
            else
                // Imprime o valor do navio
                printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("%s\n", SEPARADOR);
}

void navioVertical(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    // Verifica se o navio cabe na vertical
    if (linha <= 7 && coluna <= 9) {
        for (i = 0; i < 3; i++){ 
            // Verifica se a posição já está ocupada
            if (matriz[linha + i][coluna] != 0) {
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            // Posiciona uma parte do navio
            matriz[linha + i][coluna] = 6; 
        }
    } else {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna);
    }
}

void navioHorizontal(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    // Verifica se o navio cabe na horizontal
    if (linha <= 9 && coluna <= 7) {
        for (i = 0; i < 3; i++){
            // Verifica se a posição já está ocupada
            if (matriz[linha][coluna + i] != 0) {
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha, coluna + i);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            matriz[linha][coluna + i] = 6;
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
            matriz[linha + i][coluna + i] = 6;
        }
    } else {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna);
    }
}

void habCone(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i, j;
    // Verifica se a habilidade cabe na matriz
    if (linha > 7 || coluna > 5) {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna); 
    } else {
        for (i = 0; i < 3; i++){
            for (j = 0; j < 5; j++){
                // Verifica se está dentro do cone
                if (i >= abs(j - 2)) {
                    matriz[linha + i][coluna + j] = 9; 
                } else {
                    matriz[linha + i][coluna + j] = 0; 
                }
            }
        }     
    }
}

void habCruz(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i, j;
    // Verifica se a habilidade cabe na matriz
    if (linha > 7 || coluna > 5) {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna); 
    } else {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            // Verifica se está na linha ou coluna do meio
            if (i == 1 || j == 2) {
                matriz[linha + i][coluna + j] = 9; 
            } else {
                matriz[linha + i][coluna + j] = 0; 
            }
        }
    }
    }
}

void habOcta(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i, j;
    // Verifica se a habilidade cabe na matriz
    if (linha > 7 || coluna > 5) {
        printf("Erro: Navio nao cabe na posicao (%d, %d)!\n", linha, coluna); 
    } else {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            // Verifica se está na linha ou coluna do meio
            if ((j == 2) || (i == 1 && j >= 1 && j <= 3)) {
                matriz[linha + i][coluna + j] = 9; 
            } else {
                matriz[linha + i][coluna + j] = 0; 
            }
        }
    }
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
    imprimeMatrizWaves(matriz);
    printf("\n");
    
    // Posiciona Navio 1 - horizontal
    navioHorizontal(0, 0, matriz);
    
    // Posiciona Navio 2  - vertical
    navioVertical(0, 9, matriz);

    // Posiciona Navio 3 - diagonal
    navioDiagonal(2, 1, matriz);

    // Posiciona Navio 4 - cone
    habCone(1, 4, matriz);

    // Habilidade Cruz
    habCruz(5, 5, matriz);

    // Habilidade Octa
    habOcta(7, 0, matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatrizWaves(matriz);

    return 0;
}
