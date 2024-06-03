#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "funções.h"
#include "foge.h"


 mapa m;
 herói p;

void fantasmas()
{
    mapa copia;

    copia_mapa(&m,&copia);
    for(int i=0;i<m.linhas;i++)
    {
        for(int j=0;j<m.colunas;j++)
        {
            if(copia.matriz[i][j]==fantasma)
            {
                if(eh_vazia(i,(j+1)) && p_valida(i,(j+1)))
                {
                    percorre_mapa(i,j,i,(j+1),&m);
                }
            }
        }
    }
    libera(destino);
}

void configurar_terminal() 
{
    struct termios newtio;
    tcgetattr(STDIN_FILENO, &newtio); // Pega a configuração atual do terminal
    newtio.c_lflag &= ~ICANON; // Desativa o modo canônico
    newtio.c_lflag &= ~ECHO;   // Desativa o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio); // Aplica a nova configuração
}

void restaurar_terminal()
{
    struct termios newtio;
    tcgetattr(STDIN_FILENO, &newtio); // Pega a configuração atual do terminal
    newtio.c_lflag |= ICANON; // Ativa o modo canônico
    newtio.c_lflag |= ECHO;   // Ativa o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio); // Aplica a nova configuração
}

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
        configurar_terminal();
        scanf(" %c", &comando);
        fantasmas();
        restaurar_terminal();
        controla(comando);

    }while(!acabou());
    
    libera(&m);

    return 0;
}