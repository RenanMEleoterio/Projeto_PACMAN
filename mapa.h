#define JOGADOR '@'
#define VAZIO '.'

struct mapa
{
    char **matriz;
    int linha;
    int coluna;
};

typedef struct mapa MAPA;

struct posicao
{
    int linha;
    int coluna;
};

typedef struct posicao POSICAO;

int acabou();
void le_mapa(MAPA *m);
void aloca_mapa(MAPA *m);
void libera_mapa(MAPA *m);
void imprime_mapa(MAPA *m);
int encontra_personagem(MAPA *m, POSICAO *posicao, char personagem);
void anda_pelo_mapa(MAPA *m, int linha_atual, int coluna_atual, char caminho);
