#include<stdio.h>
#define N 11

int t[N]={0, 94, 55, 66, 42, 44, 18, 12, 10, 5, 22};

int est_TAS()
{
    int i;
    for ( i = 1; i <= N/2; i++)
    {
        int j = 2*i; // j = fg de i
        //tester si fd de i existe
        if (j < N) // fd de i existe
            if (t[j] < t[j+1])
                j=j+1;

        if (t[i] < t[j])
                return 0;
    }
    return 1;
}

int main()
{
    if(est_TAS()==1) printf("Le tableau est un TAS \n");
    else printf("Le tableau n est pas un TAS \n");
}