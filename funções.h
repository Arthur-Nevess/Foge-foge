
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


void aloca_mapa();
void libera();
void ler_mapa();
void imprime_mapa();
int acabou();
void posição();
void controla(char direção);
int eh_direção(char direção);
int p_valida(int x, int y);
int eh_vazia(int x, int y);
void percorre_mapa(int x_origem,int y_origem,int x_destino, int y_destino);
void esta_maiusculo(char direção);