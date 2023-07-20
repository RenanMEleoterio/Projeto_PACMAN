#include <stdio.h>
#include "pacman.h"
#include "mapa.h"
#include <stdlib.h>

MAPA mapa;

int main(){

    le_mapa(&mapa);

    imprime_mapa(&mapa);
    
    for (int i = 0; i < mapa.linhas; i++)
    {
        free(mapa.matriz[i]);
    }
    free(mapa.matriz);
    
    return 0;

}