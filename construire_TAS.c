#include<stdio.h>
#define N 8

int t[N+1]={0, 44, 55, 12, 42, 94, 18, 66,1};
int g, d; // g : indice gauche  d:indice droit
// 8/2 + 1 == 5

void sift()//decendre dans le tas
{
     //on ajoute t[g] et on restructure le TAS t[i+1], t[i+2],..., t[N]
    int i,j; // i=papa  j=un fils (j=2i)
    int x;
    i=g;
    j=2*i; //j est le fils g de i
    x=t[i];
    while (j<=d) //(j<=d)
    {
        /* tester si le fd de i existe */
        if(j<d) //(j<d)
            if(t[j] < t[j+1])
                j=j+1;
            if (x >= t[j])
            break;
            t[i]=t[j];
            i=j; j=2*i;
    }
    t[i]=x; //inserer x dans lindice i
}

int main()
{
    int i, x; // i un indice
    /* construire TAS t[1,...,N]
    t[N/2 +1,..., N] deja TAS */
    g=N/2+1; d=N;

    while(g>1)
    {
        g=g-1;//ajouter t[g]
        sift(); 

    
    } // construction terminee
      //affichage tas
        for (i = 1; i <= N; i++)
        {
            printf("%d ", t[i]);
        }
  
    
    /*  TRI  */
        d=N;
    while (d > 1)
    {
        /* echanger t[1], t[d] */
        x=t[1]; t[1]=t[d];
        t[d]=x;
        d=d-1;
        sift();

          //affichage tas
        for (i = 1; i <= N; i++)
        {
            printf("%d\n", t[i]);
        }
    }
}