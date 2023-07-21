#include <stdio.h>
#include "pacman.h"
#include "mapa.h"
#include <stdlib.h>

MAPA mapa;
POSICAO posicao;

int direcao_valida(char direcao){

    return direcao == CIMA || direcao == BAIXO || direcao == ESQUERDA || direcao == DIREITA;

}

void move(char caminho){
    if(!direcao_valida(caminho)) return;

    int proxima_linha = posicao.linha;
    int proxima_coluna = posicao.coluna;

    switch (caminho)
    {
    case CIMA:
        proxima_linha--;
        break;

    case BAIXO:
        proxima_coluna++;
        break;
    
    case ESQUERDA:
        proxima_coluna--;
        break;

    case DIREITA:
        proxima_coluna++;
        break;
    }

    anda_no_mapa(&mapa, posicao.linha, posicao.coluna, proxima_linha, proxima_coluna);

}

int acabou(){
    return 0;
}

int main(){

    le_mapa(&mapa);

    

    do
    {
        imprime_mapa(&mapa);

        encontra_personagem(&mapa, &posicao, JOGADOR);
        
        char caminho;
        scanf("%c", &caminho);

        move(caminho);

    } while (!acabou());

    printf(" %c\n", mapa.matriz [posicao.linha] [posicao.coluna]);

    libera_mapa(&mapa);
    
    return 0;

}