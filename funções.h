
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