#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 100//max nbr of nodes

int papa[N+1];
int lf[N]; //  array of leafs
int k=0; // nmbr of leafs

void saisie_papa()
{
    int n, i;
    printf("How many nodes : ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        printf("papa[%d] = ",i);
        scanf("%d", &papa[i]);
    }
}

void affichage(int papa[], int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        printf("papa[%d] = %d\n",i,papa[i]);
    }
}

void find_leafs(int n)
{
    int i, j;
    bool leaf=1;

    for(i=1; i<=n; i++)
    {
        leaf=1;
        for(j=1; j<=n ;j++)
        {
            if(i==papa[j])
            {
                leaf=0;
                break;
            }
        }
        if(leaf)
        {
            lf[k]=i;
            k++;
        }
    }

    for(int i=0; i<k; i++)
    {
        printf("%d is a leaf\n", lf[i]);
    }
}

int hauteur(int f)
{
    int h=0;
    while(f!=1)
    {
        f=papa[f];
        h++;
    }
    return h;
}

int hauteur_arbre()
{
    int h=0;
    int i;
    for(i=0; i<k; i++)
    {
        if(h<hauteur(lf[i]))
            h=hauteur(lf[i]);
    }
    return h;
}

int main()
{
    saisie_papa();
    printf("\n");
  //  affichage(papa, 16);
   // printf("\n");
    find_leafs(17);
    printf("\n");
    printf("the height is %d ",hauteur_arbre());
}