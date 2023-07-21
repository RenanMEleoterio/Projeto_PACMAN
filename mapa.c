#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "pacman.h"

void le_mapa(MAPA *m){
    FILE * f;

    f = fopen("mapa.txt", "r");

    if(f == NULL){

        printf("ERRO! Ao abrir o arquivo");
        exit(1);

    }

    fscanf(f, "%d %d", &(m->linha), &(m->coluna));

    aloca_mapa(m);

    for(int cont_linhas = 0; cont_linhas < m->linha; cont_linhas++){

        fscanf(f, "%s", m->matriz [cont_linhas]);

    }
    
    fclose(f);
}

void aloca_mapa(MAPA * m){
    m->matriz = malloc(sizeof(char*) * m->linha);
    for (int i = 0; i < m->linha; i++)
    {
        m->matriz[i]= malloc(sizeof(char) * (m->coluna + 1));
    }
}

void libera_mapa(MAPA *m){
    for (int i = 0; i < m->linha; i++)
        {
            free(m->matriz[i]);
        }
        free(m->matriz);
}

void imprime_mapa(MAPA * m){
    for(int contador_linhas = 0; contador_linhas < m->linha; contador_linhas++){
        printf("%s\n", m->matriz[contador_linhas]);
    }
}

int encontra_personagem(MAPA *m, POSICAO *posicao, char personagem){

    for(int cont_linha = 0; cont_linha < m->linha; cont_linha++){
        for (int cont_coluna = 0; cont_coluna < m->coluna; cont_coluna++)
        {
            if (m->matriz[cont_linha] [cont_coluna] == personagem)
            {
                posicao->linha = cont_linha;
                posicao->coluna = cont_coluna;

                return 1;
            }
        }
        
    }

    return 0;

}

int anda_no_mapa(MAPA *m, int linha_atual, int coluna_atual, int proxima_linha, int proxima_coluna){

    char personagem = m->matriz[linha_atual] [coluna_atual];

    m->matriz[proxima_linha] [proxima_coluna] = personagem;
    m->matriz[linha_atual] [coluna_atual] = VAZIO;

}

int posicao_vazia(MAPA *m,int proxima_linha, int proxima_coluna, char personagem){

    if(m->matriz[proxima_linha] [proxima_coluna] == VAZIO || m->matriz[proxima_linha] [proxima_coluna] == personagem){

        return 1;

    }

    return 0;
}
