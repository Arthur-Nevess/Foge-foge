
struct mapa
{
    int linhas;
    int colunas;
    char** matriz;
};
typedef struct mapa mapa;



void aloca_mapa();
void libera();
void ler_mapa();
void imprime_mapa();
int acabou();
void controla(char direção);