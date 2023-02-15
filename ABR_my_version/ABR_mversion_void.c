//-----------ABR-------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int v;
    int counter;
    struct node * fg;
    struct node * fd;
}Node;

void node_insert(Node **racine, int x)
{   
    if((*racine) == NULL)
    {
        (*racine)=(Node*)malloc(sizeof(Node));
        (*racine)->v=x;
        (*racine)->counter=1;
        (*racine)->fg=NULL;
        (*racine)->fd=NULL;
    }
    else
    {
        if(x< (*racine)->v)
            node_insert(&((*racine)->fg) , x);
        else
        {
            if(x> (*racine)->v)
            node_insert(&((*racine)->fd) , x);
            else
            (*racine)->counter++;
        }
        
    }
}

int maximum(int a, int b)
{
    return ((a<b)?b:a);
}

int hauteur(Node *racine)
{
    if(racine == NULL) return -1;
    else
    {
        return (1+ maximum(hauteur(racine->fg), hauteur(racine->fd)));
    }
}

Node * predecesseur(Node * racine)
{
    if(racine->fd == NULL) return racine;
    else
    {
        predecesseur(racine->fd);
    }
}

void node_delete(Node *racine, int x)
{

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

/* void print_tree(Node * racine) // in order
{
    if(racine != NULL)
    {
        print_tree(racine->fg);
        printf("%d  ", racine->v);
        print_tree(racine->fd);
    }
} */

int main()
{
    Node * racine=NULL;

    node_insert(&racine, 8);
    node_insert(&racine, 6);
    node_insert(&racine, 1);
    node_insert(&racine, 0);
    node_insert(&racine, 7);
    node_insert(&racine, 9);
    node_insert(&racine, 11);
    node_insert(&racine, 2);
    node_insert(&racine, 12);
    node_insert(&racine, 3);
    node_insert(&racine, 5);
    node_insert(&racine, 1);
    print_tree(racine, 0);
    printf("\n%d  %d", racine->fg->fg->v, racine->fg->fg->counter);
 //   print_tree(racine);
 printf("\nla hauteur est %d ", hauteur(racine));
}

