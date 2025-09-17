#include <stdio.h>

#define LINHA 10
#define COLUNA 10

void imprimeMatriz(int matriz[LINHA][COLUNA]){
    int i,j;
    printf("-----------------------\n     Batalha Naval\n-----------------------\n");
    printf(" X  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ",i+1);
        for (j = 0; j < 10; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void navioVertical(int linha, int coluna, int matriz[LINHA][COLUNA]){
int i;
    for (i = 0; i < 3; i++){
        matriz[i + linha][coluna] = 3;
    }
}

void navioHorizontal(int linha, int coluna, int matriz[LINHA][COLUNA]){
    int i;
    for (i = 0; i < 3; i++){
        matriz[linha][i + coluna] = 3;
    }
}

int main() {

    int matriz[LINHA][COLUNA]={0};

    // Imprime matriz zerada
    imprimeMatriz(matriz);
    printf("\n");
    
    // Posiciona Navio 1 - horizontal
    navioHorizontal(2, 3, matriz);

    // Posiciona Navio 2  - vertical
    navioVertical(4, 7, matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatriz(matriz);


    return 0;
}
