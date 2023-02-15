#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int v;
    struct node *fg;
    struct node *fd;
}Node;

int t[8]={2,1,7,5,6,10,9,4};

Node* tournoi(int t[], int g, int d)
{
    Node *p;
    int mi=(g+d)/2; 
    //g: indice gauche d : indice droit m: milieu

    p=(Node*)malloc(sizeof(Node));
    p->v=t[mi];
    p->fg=NULL;
    p->fd=NULL;

    if(g==d) return p;
    else
    {
        p->fg= tournoi(t,g,mi);
        p->fd= tournoi(t,mi+1,d);
        int a= p->fg->v;
        int b= p->fd->v;

        if(a>b) 
            {p->v=a;}
        else
            {p->v=b;}

        return p;
    }
}

void print_tree(Node * p, int h)
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

int main()
{
    Node *r=NULL;
    
    r=tournoi(t,0,7);
    print_tree(r,0);
}