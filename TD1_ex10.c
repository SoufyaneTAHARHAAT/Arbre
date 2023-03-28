#include<stdio.h>
#include<stdlib.h>
#define N 15

struct noeud
{
    int v;
    struct noeud * suivant;
};
typedef struct noeud node;
node * fils[N]; // tableau de fils

int n; // le nombre de noeuds actuel n<=N

void saisie()
{
    int i, d, a; // i pour la boucle, (d, a) d'un arc
    node *t;

    printf("Entrez n : ");
    scanf("%d", &n);

    //initialisation du tableau fils
    for (i = 1; i <= n; i++)
    {
        fils[i] = NULL;
    }

     // saisie des arcs: (pointeurs)
    for (i = 1; i <= n-1; i++)
    {
        printf("\nEntrez larc %d : ", i);
        scanf("%d%d", &d, &a); // depart et arrivee de l'arc
        // 1-->4; 1-->3; 1-->2 
        //methode pile
        t = (node *)malloc(sizeof(node));
        t->v = a;
        t->suivant = fils[d];
        fils[d] = t;
        //fin de saisie
    }
}

void print_tree()
{
    int i; //pour la boucle

    node *t;
    //imprimer le fls de chaque noeud
    for ( i = 1; i <= n; i++)
    {
        printf("\nLe fis de %d : ", i);
        t = fils[i];
        if(t == NULL) printf("Pas de fils !\n");
        else
        {
            while(t != NULL)
            {
                printf(" %d", t->v);
                t = t->suivant;
            }
            printf("\n");
        }
    }  
}

void prefixe_prof( int i) // i le noeud de racine de depart
{
    node *t;
    printf("%d ", i);
    for (t = fils[i]; t !=NULL; t = t->suivant)
    {
        prefixe_prof(t->v);
    }
    
}

void postfixe_prof( int i) // i le noeud de racine de depart
{
    node *t;
    for (t = fils[i]; t !=NULL; t = t->suivant)
    {
        postfixe_prof(t->v);
    }
    printf("%d ", i);
}

int main()
{
    saisie();
    print_tree();

    printf("Prefixe : ");
    prefixe_prof(1);
    printf("\n");
    printf("Postfixe : ");
    postfixe_prof(1);
    printf("\n");
}