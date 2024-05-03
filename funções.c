#include <stdio.h>
#include <stdlib.h>
#include "funções.h"
  char** mapa;
  int linhas;
  int colunas;

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

        
    for(int i=0;i<6;i++)
    {
        printf("%s\n", mapa[i]);
    }

}

void libera()
    {
        for (int i=0;i<linhas;i++)
        {
            free(mapa[i]);
        }
        free(mapa);
    }
