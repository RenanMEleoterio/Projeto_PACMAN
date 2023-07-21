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

    for(int i = 0; i < mapa.linha; i++){
        for (int j = 0; j < mapa.coluna; j++)
        {
            if(mapa.matriz [i] [j] == JOGADOR){
                
                posicao.linha = i;
                posicao.coluna = j;
                break;
            }
        }
        
    }

    switch (caminho)
    {
    case CIMA:
        mapa.matriz[posicao.linha -1] [posicao.coluna] = JOGADOR;
        break;

    case BAIXO:
        mapa.matriz[posicao.linha + 1] [posicao.coluna] = JOGADOR;
        break;
    
    case ESQUERDA:
        mapa.matriz[posicao.linha] [posicao.coluna -1] = JOGADOR;
        break;

    case DIREITA:
        mapa.matriz[posicao.linha] [posicao.coluna +1] = JOGADOR;
    }

    mapa.matriz[posicao.linha] [posicao.coluna] = '.';

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