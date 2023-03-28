//-----------ABR-------------

#include<stdio.h>
#include<stdlib.h>
#define N 20 // la taille maximum de la pile


typedef struct node
{
    int v;
    int counter;
    struct node * fg;
    struct node * fd;
}Node;

Node * pile[N]; // pile de noeuds
int tete; // tete de la pile

/* initialisation */
void pile_initialisation()
{
    tete = 0;
}

/* pile vide  */
int pile_vide()
{
    if(tete == 0) return 1;
    return 0;
}

/* empiler un noeud */
void push(Node * p)
{
    pile[tete++] = p; 
}

/* depiler un noeud */
Node * pop()
{
    return pile[--tete];
}

Node * node_insert(Node *racine, int x)
{   
    if(racine == NULL)
    {
        racine=(Node*)malloc(sizeof(Node));
        racine->v=x;
        racine->counter=1;
        racine->fg=NULL;
        racine->fd=NULL;
    }
    else
    {
        if(x< racine->v)
           racine->fg= node_insert(racine->fg , x);
        else
        {
            if(x> racine->v)
            racine->fd= node_insert(racine->fd , x);
            else
            racine->counter++;
        }
        
    }return racine;
}

void print_tree(Node * racine, int h)
{
    int i;
    if(racine != NULL)
    {
        print_tree(racine->fg , h+1);
        for(i=0; i<h; i++)
        {
            printf("   ");
        }
        printf("%d\n", racine->v);
        print_tree(racine->fd, h+1);
    }
}

/* parcours prefixe avec pile */
void prefixe_pile(Node * t)
{
    push(t);
    while(!pile_vide())
    {
        t = pop();
        printf("%d  ", t->v);
        if(t->fd != NULL) push(t->fd);
        if(t->fg != NULL) push(t->fg);
    }
}

void print_tree_prefixe_recursive(Node * racine)
{
    if(racine != NULL)
    {
        printf("%d  ", racine->v);
        print_tree_prefixe_recursive(racine->fg);
        print_tree_prefixe_recursive(racine->fd);
    }
}

int main()
{
    Node * racine = NULL;

    racine = node_insert(racine, 8);
    racine = node_insert(racine, 6);
//  racine = node_insert(racine, 1);
    racine = node_insert(racine, 7);
    racine = node_insert(racine, 9);
    racine = node_insert(racine, 11);
    racine = node_insert(racine, 2);
    racine = node_insert(racine, 3);
    racine = node_insert(racine, 12);
    racine = node_insert(racine, 0);
    racine = node_insert(racine, 1);

    print_tree(racine, 0);
    //printf("\n%d  %d\n", racine->v, racine->counter);

    pile_initialisation();
    prefixe_pile(racine);
    printf("\n");
    print_tree_prefixe_recursive(racine);
}