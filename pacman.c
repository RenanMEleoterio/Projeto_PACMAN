#include <stdio.h>
#include "pacman.h"
#include "mapa.h"

char mapa [22] [61];
int linhas;
int colunas;

int main(){

    FILE * f;

    f = fopen("mapa.txt", "r");

    if(f == NULL){

        printf("ERRO! Ao abrir o arquivo");

    }
    
    fscanf(f, "%d %d", &linhas, &colunas);

    printf("%d %d\n", linhas, colunas);

    fclose(f);


    return 0;

}