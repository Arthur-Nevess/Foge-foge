#include <stdio.h>
#include <stdlib.h>
#include "funções.h"
  char** mapa;
  int linhas=0;
  int colunas=0;


void aloca_mapa()
{

    mapa = malloc(sizeof(char*)*linhas);
    for(int i=0;i<linhas;i++)
    {
        mapa[i] = malloc(sizeof(char)*(colunas+1));
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

    fscanf(p,"%d %d", &linhas, &colunas);

     aloca_mapa();

    for(int i=0;i<6;i++)
    {
        fscanf(p,"%s", mapa[i]);
    }
    fclose(p);
}

void libera()
    {
        for (int i=0;i<linhas;i++)
        {
            free(mapa[i]);
        }
        free(mapa);
    }

void imprime_mapa()
{
    //Espaço para variaveis
    int x=0;
    int y=0;

    for(int i=0;i<6;i++)
    {
        printf("%s\n", mapa[i]);
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

    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if(mapa[i][j]=='@')
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
            mapa[x-1][y]='@';
            break;
        }

        case 's':
        {
            mapa[x+1][y]='@';
            break;
        }

        case 'a':
        {
            mapa[x][y-1]='@';
            break;
        }

        case 'd':
        {
            mapa[x][y+1]='@';
            break;
        }
    
    }

    mapa[x][y]=' ';
}