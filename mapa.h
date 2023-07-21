#define JOGADOR '@'
#define VAZIO '.'
#define PAREDE_HORIZONTAL '|'
#define PAREDE_VERTICAL '_'
#define DIVISAO_PAREDE '-'
#define FANTASMA '&'

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
int anda_no_mapa(MAPA *m, int linha_atual, int coluna_atual, int proxima_linha, int proxima_coluna);
int posicao_vazia(MAPA *m,int proxima_linha, int proxima_coluna, char personagem);


