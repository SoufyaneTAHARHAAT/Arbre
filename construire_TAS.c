#include<stdio.h>
#define N 12

int t[N+1], g, d; // g : indice gauche  d:indice droit

void tamis(int g, int d)
{
    int i,j,x;
    //on ajoute t[g] et on restructure le TAS
    i=g;
    j=2*i;
    x=t[i];

}

int main()
{
    int t[N+1]={0,5,2,7,1,3,10,5,6,10,9,8,9};
    g=7;
    d=12;
    while(g>=1)
    {
        g=g-1;
        tamis(g,d);
    }
    //affichage
    for(g=1; i<=g++)
    {

    }
}