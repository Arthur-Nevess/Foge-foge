#include <stdio.h>
#include <stdlib.h>
#include "funções.h"

 mapa m;

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

void controla(char direção)
{
    int x=0;
    int y=0;

    for (int i=0;i<m.linhas;i++)
    {
        for (int j=0;j<m.colunas;j++)
        {
            if(m.matriz[i][j]=='@')
            {
                x=i;
                y=j;
                break;
            }
        }
    }

    switch(direção)
    {
        case 'w':
        {
            m.matriz[x-1][y]='@';
            break;
        }

        case 's':
        {
            m.matriz[x+1][y]='@';
            break;
        }

        case 'a':
        {
            m.matriz[x][y-1]='@';
            break;
        }

        case 'd':
        {
            m.matriz[x][y+1]='@';
            break;
        }

        default :
        {
            m.matriz[x][y]='@';      
        }
    
    }

    m.matriz[x][y]=' ';
}