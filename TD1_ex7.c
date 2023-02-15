#include<stdio.h>
#include<stdlib.h>

struct noeud
{
    int v;
    int compteur;
    struct noeud *fg;
    struct noeud *fd;
};
typedef struct noeud * lien;

int x;
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

lien recherche(lien p, int x)
{
    if(p==NULL) return NULL;
    else if(p->v <x) return recherche(p->fd , x) ;
        else if(p->v <x) return recherche(p->fg , x) ;
            else return p;
}


int main()
{
    lien r;
    r=NULL;

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
        printf("\n");
        print_tree(r,0);
     /*    printf("\n");
        if(search_tree(r,0,9))
        printf("\nTrouve");
        else printf("\nPas Trouve"); */

      //  int t[5]
        
}