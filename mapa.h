struct mapa
{
    char ** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void le_mapa(MAPA *m);
void aloca_mapa(MAPA * m);
void imprime_mapa(MAPA * m);