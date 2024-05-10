#include <stdio.h>
#include <stdlib.h>
#include "funções.h"

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

void controla(char direção)
{
    
    if (direção != 'w' && direção != 's' && direção != 'a' && direção != 'd' )
    return;

    m.matriz[p.x][p.y]=' ';

    switch(direção)
    {
        case 'w':
        {
            m.matriz[p.x-1][p.y]='@';
            p.x--;
            break;
        }

        case 's':
        {
            m.matriz[p.x+1][p.y]='@';
            p.x++;
            break;
        }

        case 'a':
        {
            m.matriz[p.x][p.y-1]='@';
            p.y--;
            break;
        }

        case 'd':
        {
            m.matriz[p.x][p.y+1]='@';
            p.y++;
            break;
        }

    }
}