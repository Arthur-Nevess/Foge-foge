# include <stdio.h>
# include <stdlib.h>
# include "funções.h"

int main()
{
    ler_mapa();
    do
    {
        char comando;
        imprime_mapa();
        scanf(" %c", &comando);
        controla(comando);

    }while(!acabou());
    
    libera();

    return 0;
}