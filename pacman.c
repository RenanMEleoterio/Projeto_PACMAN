#include <stdio.h>
#include "pacman.h"
#include "mapa.h"

MAPA mapa;

int main(){

    FILE * f;

    f = fopen("mapa.txt", "r");

    if(f == NULL){

        printf("ERRO! Ao abrir o arquivo");

    }
    
    fscanf(f, "%d %d", &(mapa.linhas), &(mapa.colunas));

    fclose(f);


    return 0;

}