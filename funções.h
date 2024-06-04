
struct mapa
{
    int linhas;
    int colunas;
    char** matriz;
};
typedef struct mapa mapa;

struct posição
{
    int x;
    int y;
};
typedef struct posição herói;

int pode_andar(int x,int y,char personagem);
int fantasma_anda(int x_origem, int y_origem, int*x_destino,int *y_destino);
void fantasmas();
void copia_mapa(mapa *origem, mapa*destino);
void aloca_mapa(mapa *m);
void libera(mapa *m);
void ler_mapa (mapa *m);
void imprime_mapa(mapa *m);
int acabou(mapa *m,herói *p);
int pac_no_mapa(mapa *m,herói *p);
void controla(char direção);
int eh_direção(char direção);
int p_valida(int x, int y);
int eh_vazia(int x, int y);
void percorre_mapa(int x_origem,int y_origem,int x_destino, int y_destino,mapa *m);
void esta_maiusculo(char direção);
int eh_parede(int x, int y);
int eh_personagem(int x,int y,char personagem);