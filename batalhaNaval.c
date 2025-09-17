#include <stdio.h>

#define LINHA 10
#define COLUNA 10

void imprimeMatriz(char matriz[LINHA][COLUNA]){
    int i,j;
    printf("-----------------------\n     Batalha Naval\n-----------------------\n");
    printf(" X  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ",i+1);
        for (j = 0; j < 10; j++){
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void navioVertical(int linha, int coluna, char matriz[LINHA][COLUNA]){
    int i;
    if (matriz[linha + i][coluna] != '0') {
        printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna);
        return;
    }
    for (i = 0; i < 3; i++){
        matriz[linha + i][coluna] = 'V';
    }
}

void navioHorizontal(int linha, int coluna, char matriz[LINHA][COLUNA]){
    int i;
    if (matriz[linha][coluna + i] != '0') {
        printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha, coluna + i);
        return;
    }
    for (i = 0; i < 3; i++){
        matriz[linha][coluna + i] = 'H';
    }
}

void navioDiagonal(int linha, int coluna, char matriz[LINHA][COLUNA]){
    int i;
    for (i = 0; i < 3; i++){
        if (matriz[linha + i][coluna + i] != '0') {
            printf("Erro: Posicao (%d, %d) ja ocupada!\n", linha + i, coluna + i);
            return;
        }
        matriz[linha + i][coluna + i] = 'D';
    }
}

int main() {
    char matriz[LINHA][COLUNA];
    int i, j;
    // Inicializa matriz com '0' (vazio)
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            matriz[i][j] = '0';
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
    // Teste sobreposição
    // navioDiagonal(4, 7, matriz);
    navioDiagonal(4, 2, matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatriz(matriz);

    return 0;
}
