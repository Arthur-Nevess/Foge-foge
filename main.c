# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main()
{
    srand(time(0));
    int matriz[20][10];

    for (int i=0; i<5;i++)
    {
        for (int j=0;j<5;j++)
        { 
            int cont = rand()%10;  
            matriz[i][j]= cont;
        }
    }

    for (int i=0; i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        puts("");
    }
    return 0;
}