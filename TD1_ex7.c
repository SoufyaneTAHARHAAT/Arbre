#include<stdio.h>
#include<stdlib.h>

int cp=0 ;

struct noeud
{
    int v;
    int compteur;
    struct noeud *fg;
    struct noeud *fd;
};
typedef struct noeud * lien;

int x;
 // compteur noeuds
//int t[15]={7,3,8,2,9,1,0,2,7,6,2,8,3,6,2};

lien abr(lien p, int x)
{
    if(p==NULL)
    {
        p=(lien)malloc(sizeof(*p));
        p->v=x;
        p->compteur=1;
        p->fg=NULL;
        p->fd=NULL;
    }
    else
    {
        if(x< p->v)
        {
            p->fg=abr(p->fg , x);
        }
        else
        {
            if(x> p->v) 
            p->fd=abr(p->fd , x);
            else // x= p->v
            ++ p->compteur;
        }
    }
    return p;
}

void print_tree(lien p, int h)
{
    int i;
    if(p!=NULL)
    {
        print_tree(p->fg ,h+1);
        for(i=1;i<=h;i++)
        {
            printf("   ");
        }
        printf("%d\n", p->v);
        print_tree(p->fd, h+1);
    }
}

/* int search_tree(lien p, int h, int k)
{
    int i;
    int trouve=0;
    if(p!=NULL)
    {
        if(p->v == k)
        {
            trouve=1;
         //   break;
        }
        search_tree(p->fg ,h+1,k);
        search_tree(p->fd, h+1,k);
    }
} */

lien recherche(lien p, int x) // recherche recursive
{
    if(p==NULL) return NULL;
    else if(p->v <x) return recherche(p->fd , x) ;
        else if(p->v <x) return recherche(p->fg , x) ;
            else return p;
}

lien rech_nr (lien p, int x) // recherche iterative TD2_ex2
{
    /* chercher lentier x dans larbre pointe par p */
    int trouve; // trouve =0 si non trouve
    // initialisation de 'trouve'
    trouve =0; // non trouve
    while((p!=NULL)  && (!trouve))
    {
        if(p->v == x) trouve =1;
        else if(x < p->v) p=p->fg;
            else p=p->fd;
    }
    return p;
}

void nbr_noeuds(lien p) // TD2_ex3
{
    if(p!=NULL)
    {
        nbr_noeuds(p->fg);
        nbr_noeuds(p->fd);
        cp++;
    } 
}

int nbr_noeuds_2(lien p) // Methode prof
{
    if(p==NULL) return 0;
    int u=nbr_noeuds_2(p->fg);
    int v=nbr_noeuds_2(p->fd);
    return u+v+1;
}

int maximum(int a, int b)
{
    return ((a<b)?b:a);
}

int hauteur_abr(lien p) // TD2_ex4 my version
{
    if(p == NULL) return -1;
    else
    {
        return (1+ maximum(hauteur_abr(p->fg), hauteur_abr(p->fd)));
    }
}

int hauteur_abr_2(lien p) // TD2_ex4 teachers version
{
     if(p == NULL) return -1;
     int u=hauteur_abr_2(p->fg);
     int v=hauteur_abr_2(p->fd);
     if(u > v) return u+1;
     else return v+1;
}

int main()
{
    lien r;
    r=NULL;
    int x=21;
    int h_abr;

    //while(scanf("%d", &x) != EOF)
       r=abr(r,3);
       r=abr(r,1);
       r=abr(r,7);
       r=abr(r,8);
       r=abr(r,2);
       r=abr(r,0);
       r=abr(r,3);
       r=abr(r,7);
       r=abr(r,6);
       r=abr(r,10);
        printf("\n");
        print_tree(r,0);
    /*     printf("\n");
        if(search_tree(r,0,9))
        printf("\nTrouve");
        else printf("\nPas Trouve"); */

   /*  r=rech_nr(r,x);
    if(r==NULL) printf("\n%d nexiste pas !!!",x);
    else printf("%d existe ",x); */
    
    nbr_noeuds(r);
    printf("\nle nombre de noeuds est %d", cp);
    printf("\nle nombre de noeuds est %d", nbr_noeuds_2(r));

   printf("\nla hauteur de larbre est %d", hauteur_abr(r));
   printf("\nla hauteur de larbre est %d", hauteur_abr_2(r));

}