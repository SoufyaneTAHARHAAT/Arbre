#include<stdio.h>
#define N 10

int t[N+1]={0, 94, 55, 66, 42, 44, 18, 12, 10, 5, 22};

void monter_TAS(int i)
{
    // t[1..N] un TAS
    // on a augmenté la valeur de t[i]
    // on restructure t en un TAS
    int x=t[i]; // x est la nouvelle valeur de t[i]
    while(i > 1)
    {
        if(t[i/2] < x)
        {
            t[i]=t[i/2];
            i=i/2;
        }
        else break;
    }
    t[i]=x;
}

int main()
{
    t[7]=92;
    monter_TAS(7);
    for (int i = 0; i <= N; i++)
    {
        printf("t[%d] = %d\n",i,t[i]);
    }
    
}