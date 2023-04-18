//-----------ABR-------------

#include<stdio.h>
#include<stdlib.h>
#define N 20

typedef struct node
{
    char c;
    struct node * fg;
    struct node * fd;
}Node;

int i;

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

Node * parse_post_prof()
{
    char t;
    Node * p;
    for(pile_initialisation(); scanf("%1s", &t) != EOF;)
    {
        p = (Node *)malloc(sizeof(Node));
        p->c = t;
        p->fg = NULL;
        p->fd = NULL;

        if(t == '+' || t == '*')
        {
            p->fd = pop();
            p->fg = pop();
        }   
            push(p);
    }
    return p;
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
        printf("%c\n", racine->c);
        print_tree(racine->fd, h+1);
    }
}


int main()
{
    Node * racine = NULL;
    // a b c * a d * + e + +
    i = 0;
    racine = parse_post_prof();
    print_tree(racine, 0);

}

