//-----------ABR-------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char c;
    struct node * fg;
    struct node * fd;
}Node;

//char * a = "++2*34*51";
char * a; // tableau de caracteres
int i;

Node * parse()
{
    char t = a[i++];
    /* creer un noeud pour t */

    Node * p = (Node *)malloc(sizeof(Node));
    p->c = t;
    p->fg = NULL;
    p->fd = NULL;

    /* tester si t est un operateur */
    if(t == '+' || t == '*')
    {
        p->fg = parse();
        p->fd = parse();
        return p;
    }
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


int main(int argc, char * argv[])
{
    Node * racine = NULL;

    a = argv[1];
    /* a = ++a*bc*de */
    i = 0;
    racine = parse();
   print_tree(racine, 0);
}

