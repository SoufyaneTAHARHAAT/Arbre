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
            racine->fg= node_insert(racine->fg , x);
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

/* void print_tree(Node * racine)
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

    racine=node_insert(racine, 8);
   racine= node_insert(racine, 6);
   racine= node_insert(racine, 1);
   racine= node_insert(racine, 0);
   racine= node_insert(racine, 7);
   racine= node_insert(racine, 9);
   racine= node_insert(racine, 11);
   racine= node_insert(racine, 2);
   racine= node_insert(racine, 12);
   racine= node_insert(racine, 3);
   racine= node_insert(racine, 5);
  //  racine=node_insert(racine, 1);
   print_tree(racine, 0);
    printf("\n%d  %d", racine->v, racine->counter);
 //   print_tree(racine);
}

