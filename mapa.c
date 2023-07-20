#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void le_mapa(MAPA *m){
    FILE * f;

    f = fopen("mapa.txt", "r");

    if(f == NULL){

        printf("ERRO! Ao abrir o arquivo");
        exit(1);

    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    aloca_mapa(m);

    for(int cont_linhas = 0; cont_linhas < m->linhas; cont_linhas++){

        fscanf(f, "%s", m->matriz [cont_linhas]);

    }
    
    fclose(f);
}

void aloca_mapa(MAPA * m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++)
    {
        m->matriz[i]= malloc(sizeof(char) * (m->colunas + 1));
    }
}

void imprime_mapa(MAPA * m){
    for(int contador_linhas = 0; contador_linhas < m->linhas; contador_linhas++){
        printf("%s\n", m->matriz[contador_linhas]);
    }
}