//-----------ABR-------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char c;
    struct node * fg;
    struct node * fd;
}Node;

char * a; // tableau de caracteres
int i;

int eval() //evaluer une expression prefixe avec seulement + et *
{
    int x = 0;
    if (a[i] == '#')
    {
        i++; //ignorer les espaces
    }
    if (a[i] == '+')
    {
        i++;
        return eval() + eval();
    }
    if (a[i] == '*')
    {
        i++;
        return eval() * eval();
    }
    while (a[i] <= '9' && a[i] >= '0')
    {
        x = 10 * x + (a[i++] - '0');
       
    } return x;
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
    // a = * + 705 * * 45 67 + 8 9 50
    a = argv[1];
    i = 0;
//    racine = parse();
//    print_tree(racine, 0);
    int exp = eval();
    printf("\nresultat : %d\n", exp);
}

