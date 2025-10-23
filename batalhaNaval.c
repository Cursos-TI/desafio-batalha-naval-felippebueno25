#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define HABL 5
#define HABC 5
#define SEPARADOR "-=-=-=-=-=-=-=-=-=-=-=-"
int i, j;


void imprimeMatrizWaves(int matriz[i][j]){
    printf("%s\n     Batalha Naval      \n%s\n", SEPARADOR, SEPARADOR);
    printf(" X  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ", i + 1); // Imprime número da linha
        for (j = 0; j < 10; j++){ //    Imprime os elementos da linha
            if (matriz[i][j] == 0) // Verifica se é água
                printf("~ ");
            else
                printf("%d ", matriz[i][j]); // Imprime o valor do navio
        }
        printf("\n");
    }
    printf("%s\n", SEPARADOR);
}

void navioVertical(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    if (linha <= 7 && coluna <= 9) { // Verifica se o navio cabe na vertical
        for (i = 0; i < 3; i++){ 
            if (matriz[linha + i][coluna] != 0) { // Verifica se a posição já está ocupada
                printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna);
                return;
            }
        }
        for (i = 0; i < 3; i++){
            matriz[linha + i][coluna] = 8; // Posiciona o navio
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
            matriz[linha][coluna + i] = 8;
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
            matriz[linha + i][coluna + i] = 8;
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
    imprimeMatrizWaves(matriz);
    printf("\n");
    // Posiciona Navio 1 - horizontal
    navioHorizontal(2, 3, matriz);
    
    // Posiciona Navio 2  - vertical
    navioVertical(4, 7, matriz);

    // Posiciona Navio 3 - diagonal
    navioDiagonal(7, 2, matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatrizWaves(matriz);
    

    int hab[HABL][HABC];
    // Inicializa matriz hab com 0 (vazio)
    for (i = 0; i < HABL; i++){
        for (j = 0; j < HABC; j++){
            matriz[i][j] = 0;
        }
    }


    return 0;
}
