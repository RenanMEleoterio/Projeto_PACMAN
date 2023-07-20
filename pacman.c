#include <stdio.h>
#include "pacman.h"
#include "mapa.h"
#include <stdlib.h>

MAPA mapa;
POSICAO posicao;

int main(){

    le_mapa(&mapa);

    encontra_personagem(&mapa, &posicao, JOGADOR);

    do
    {
        imprime_mapa(&mapa);

    } while (!acabou());

    printf("%c\n", mapa.matriz [posicao.linha] [posicao.coluna]);

    libera_mapa(&mapa);
    
    return 0;

}