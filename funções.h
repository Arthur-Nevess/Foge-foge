
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

void fantasmas();
void copia_mapa(mapa *origem, mapa*destino);
void aloca_mapa(mapa *m);
void libera(mapa *m);
void ler_mapa (mapa *m);
void imprime_mapa(mapa *m);
int acabou();
void posição(mapa *m,herói *p);
void controla(char direção);
int eh_direção(char direção);
int p_valida(int x, int y);
int eh_vazia(int x, int y);
void percorre_mapa(int x_origem,int y_origem,int x_destino, int y_destino,mapa *m);
void esta_maiusculo(char direção);