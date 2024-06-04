#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<time.h>
#include "funções.h"
#include "foge.h"


 mapa m;
 herói p;

int eh_parede(int x, int y)
{
    return m.matriz[x][y]== parede_horizontal || m.matriz[x][y]== parede_vertical || m.matriz[x][y]== parede_lista;
}

int eh_personagem(int x,int y,char personagem)
{
    return m.matriz[x][y]==personagem;
}

int pode_andar(int x,int y,char personagem)
{
    return p_valida(x,y) && !eh_parede(x,y) && !eh_personagem(x,y,personagem);
}

int fantasma_anda(int x_origem, int y_origem, int*x_destino,int *y_destino)
{
    int posições [4][2]=
    {
        {x_origem,y_origem+1},
        {x_origem,y_origem-1},
        {x_origem+1,y_origem},
        {x_origem-1,y_origem}
    };

    srand(time(0));
    for(int i=0;i<15;i++)
    {
        int posição=rand()%4;

        if(pode_andar(posições[posição][0],posições[posição][1],fantasma))
        {
            *x_destino=posições[posição][0];
            *y_destino=posições[posição][1];
            return 1;
        }

       return 0; 
    }

}

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
                int x_destino;
                int y_destino;
                int encontrou=fantasma_anda(i,j,&x_destino,&y_destino);
                if(encontrou)
                {
                    percorre_mapa(i,j,x_destino,y_destino,&m);
                }
            }
        }
    }
    libera(&copia);
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

    if(!pode_andar(proximox,proximoy,heroi))
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
    pac_no_mapa(&m,&p);
    do
    {
        char comando;
        imprime_mapa(&m);
        configurar_terminal();
        scanf(" %c", &comando);
        fantasmas();
        restaurar_terminal();
        controla(comando);

    }while(!acabou(&m,&p));
    
    libera(&m);

    return 0;
}