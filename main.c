# include <stdio.h>
# include <stdlib.h>
# include "funções.h"
#include "main.h"

 mapa m;
 herói p;

 int eh_vazia(int x, int y)
{
   return m.matriz[x][y] == vazio;
}

void controla(char direção)
{
    
    if (!eh_direção(direção))
    return;

    int proximox = p.x;
    int proximoy = p.y;

    esta_maiusculo(direção);

    switch(direção)
    {
        case cima:
        {
           proximox--;
            break;
        }

        case baixo:
        {
           proximox++;
            break;
        }

        case esquerda:
        {
            proximoy--;
            break;
        }

        case direita:
        {
           proximoy++;
            break;
        }
    }

    if(!p_valida(proximox, proximoy))
    return;
    if(!eh_vazia(proximox, proximoy))
    return;
    percorre_mapa(p.x,p.y,proximox,proximoy,&m);
    p.x=proximox;
    p.y=proximoy;
}

int p_valida (int x, int y)
{
    if(x >= m.linhas)
    return 0;
    if(y>=m.colunas)
    return 0;

    return 1;
}

int main()
{
    ler_mapa(&m);
    posição(&m,&p);
    do
    {
        char comando;
        imprime_mapa(&m);
        scanf(" %c", &comando);
        controla(comando);

    }while(!acabou());
    
    libera(&m);

    return 0;
}