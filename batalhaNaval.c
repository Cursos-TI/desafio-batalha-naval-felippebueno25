#include <stdio.h>

void imprimeMatriz(int matriz[10][10]){
    int i,j;
    printf("-----------------------\n");
    printf("     Batalha Naval\n");
    printf("-----------------------\n");
    printf("    A B C D E F G H I J\n");
    for (i = 0; i < 10; i++){
        printf("%2d  ",i+1);
        for (j = 0; j < 10; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void navioVertical(int matriz[10][10]){
    int i;
    for (i = 0; i < 3; i++){
        matriz[i+5][7] = 3;
    }
}

void navioHorizontal(int matriz[10][10]){
    int i;
    for (i = 0; i < 3; i++){
        matriz[2][i+3] = 3;
    }
}

int main() {
    int matriz[10][10]={0};

    // Imprime matriz zerada
    imprimeMatriz(matriz);
    printf("\n");
    
    // Posiciona Navio 1 - horizontal
    navioHorizontal(matriz);

    // Posiciona Navio 2  - vertical
    navioVertical(matriz);
       
    // Imprime matriz com navios posicionados
    imprimeMatriz(matriz);


    return 0;
}
