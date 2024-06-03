#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funções.h"
#include "foge.h"


void copia_mapa(mapa *origem, mapa*destino)
{
    destino->colunas=origem->colunas;
    destino->linhas=origem->linhas;
    aloca_mapa(destino);
    for (int i=0;i<origem->linhas;i++)
    {
       strcpy(destino->matriz[i],origem->matriz[i]);
    }
}

void aloca_mapa(mapa *m)
{

    m->matriz = malloc(sizeof(char*)*(m->linhas));
    for(int i=0;i<m->linhas;i++)
    {
        m->matriz[i] = malloc(sizeof(char)*(m->colunas+1));
    }

}

void ler_mapa (mapa *m)
{
    FILE* f = fopen("mapa.txt", "r");
    if(f==NULL)
    {
        puts("Falha ao abrir arquivo");
        exit(1);
    }

    fscanf(f,"%d %d", &m->linhas, &m->colunas);
    aloca_mapa(m);
    for(int i=0;i<m->linhas;i++)
    {
        fscanf(f,"%s", m->matriz[i]);
    }
    fclose(f);
}

void libera(mapa *m)
    {
        for (int i=0;i<m->linhas;i++)
        {
            free(m->matriz[i]);
        }
        free(m->matriz);
    }

void imprime_mapa(mapa *m)
{
    //Espaço para variaveis
    int x=0;
    int y=0;

    for(int i=0;i<m->linhas;i++)
    {
        printf("%s\n", m->matriz[i]);
    }

}

int acabou()
{
    return 0;
}

void posição(mapa *m,herói *p)
{
    for (int i=0;i<m->linhas;i++)
    {
        for (int j=0;j<m->colunas;j++)
        {
            if(m->matriz[i][j]==heroi)
            {
                p->x=i;
                p->y=j;
                break;
            }
        }
    }

}

int eh_direção(char direção)
{
   return direção == 'w'||'W' || direção == 's'||'S' || direção == 'a'||'A' || direção == 'd'||'D';
}

void percorre_mapa(int x_origem,int y_origem,int x_destino, int y_destino,mapa *m)
{
   char personagem = m->matriz[x_origem][y_origem];
    m->matriz[x_destino][y_destino]=personagem;
    m->matriz[x_origem][y_origem]=vazio;
}

void esta_maiusculo(char direção)
{
    if(direção=='W'||direção=='S'||direção=='A'||direção=='D')
    {
        puts("O capsLK está ligado");
    }


}

