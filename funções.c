#include <stdio.h>
#include <stdlib.h>
#include "funções.h"
//#include "main.h"

 mapa m;
 herói p;
 

void aloca_mapa()
{

    m.matriz = malloc(sizeof(char*)*(m.linhas));
    for(int i=0;i<m.linhas;i++)
    {
        m.matriz[i] = malloc(sizeof(char)*(m.colunas+1));
    }

}

void ler_mapa ()
{
       FILE* p = fopen("mapa.txt", "r");
    if(p==NULL)
    {
        puts("Falha ao abrir arquivo");
        exit(1);
    }

    fscanf(p,"%d %d", &m.linhas, &m.colunas);

     aloca_mapa();

    for(int i=0;i<6;i++)
    {
        fscanf(p,"%s", m.matriz[i]);
    }
    fclose(p);
}

void libera()
    {
        for (int i=0;i<m.linhas;i++)
        {
            free(m.matriz[i]);
        }
        free(m.matriz);
    }

void imprime_mapa()
{
    //Espaço para variaveis
    int x=0;
    int y=0;

    for(int i=0;i<6;i++)
    {
        printf("%s\n", m.matriz[i]);
    }

}

int acabou()
{
    return 0;
}

void posição()
{
    for (int i=0;i<m.linhas;i++)
    {
        for (int j=0;j<m.colunas;j++)
        {
            if(m.matriz[i][j]=='@')
            {
                p.x=i;
                p.y=j;
                break;
            }
        }
    }

}

int eh_direção(char direção)
{
   return direção == 'w'||'W' || direção == 's'||'S' || direção == 'a'||'A' || direção == 'd'||'D';
}

int p_valida(int x, int y)
{
    if(x >= m.linhas)
    return 0;
    if(y>=m.colunas)
    return 0;

    return 1;
}

int eh_vazia(int x, int y)
{
   return m.matriz[x][y] == '.';
}

void percorre_mapa(int x_origem,int y_origem,int x_destino, int y_destino)
{
   char personagem = m.matriz[x_origem][y_origem];
    m.matriz[x_destino][y_destino]=personagem;
    m.matriz[x_origem][y_origem]='.';
}

void esta_maiusculo(char direção)
{
    if(direção=='W'||direção=='S'||direção=='A'||direção=='D')
    {
        puts("O capsLK está ligado");
    }


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
        case 'w':
        {
           proximox--;
            break;
        }

        case 's':
        {
           proximox++;
            break;
        }

        case 'a':
        {
            proximoy--;
            break;
        }

        case 'd':
        {
           proximoy++;
            break;
        }
    }

    if(!p_valida(proximox, proximoy))
    return;
    if(!eh_vazia(proximox, proximoy))
    return;
    percorre_mapa(p.x,p.y,proximox,proximoy);
    p.x=proximox;
    p.y=proximoy;
}